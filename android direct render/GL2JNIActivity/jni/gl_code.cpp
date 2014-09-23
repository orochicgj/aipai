/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// OpenGL ES 2.0 code

#include <jni.h>
#include <android/log.h>

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "native.h"

#define  LOG_TAG    "libgl2jni"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

int gInitialized = false;

static void printGLString(const char *name, GLenum s) {
    const char *v = (const char *) glGetString(s);
    LOGI("GL %s = %s\n", name, v);
}

static void checkGlError(const char* op) {
    for (GLint error = glGetError(); error; error
            = glGetError()) {
        LOGI("after %s() glError (0x%x)\n", op, error);
    }
}

static const char gVertexShader[] =
      "attribute vec4 a_position;   \n"
      "attribute vec2 a_texCoord;   \n"
      "varying vec2 v_texCoord;     \n"
      "void main()                  \n"
      "{                            \n"
      "   gl_Position = a_position; \n"
      "   v_texCoord = a_texCoord;  \n"
      "}                            \n";

 static const char gFragmentShader[] =
      "precision mediump float;                            \n"
      "varying vec2 v_texCoord;                            \n"
      "uniform sampler2D s_texture;                        \n"
      "void main()                                         \n"
      "{                                                   \n"
      "  gl_FragColor = texture2D( s_texture, v_texCoord );\n"
      "}                                                   \n";

GLuint texID;
GLuint shader; //把原来的局部变量修改为全局

GLuint genTexture(){
	char * pixel = (char*)malloc(64*64*4);
	memset(pixel, 250, 64*64*4);
	glGenTextures(1, &texID);
	glBindTexture(GL_TEXTURE_2D,texID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 64, 64, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixel);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	return 0;
}

static GLuint RTtexture = 0;
static GLuint fboID = 0;
static GLuint rboID = 0;
static GLuint texture = 0;
static nativeRecord * obj = NULL;

/*新建一个renderbuffer绑定到fbo（其实就是模拟系统的工作原理）*/
GLuint initForRenderTOrenderBuffer(int w, int h){
	LOGI("initForRenderTOrenderBuffer");
	glBindFramebuffer(GL_FRAMEBUFFER,0);
	checkGlError("glBindFramebuffer");
	glGenRenderbuffers(1,&rboID);
	checkGlError("glGenRenderbuffers");
	glBindRenderbuffer(GL_RENDERBUFFER,rboID);
	checkGlError("glBindRenderbuffer");
	glRenderbufferStorage(GL_RENDERBUFFER,GL_RGBA4,w,h);
	checkGlError("glRenderbufferStorage");
	glGenFramebuffers(1,&fboID);
	checkGlError("glGenFramebuffers");
	glBindFramebuffer(GL_FRAMEBUFFER,fboID);
	checkGlError("glBindFramebuffer");
	glFramebufferRenderbuffer(GL_FRAMEBUFFER,GL_COLOR_ATTACHMENT0,GL_RENDERBUFFER,rboID);
	checkGlError("glFramebufferRenderbuffer");
	glGenTextures(1, &RTtexture);
	checkGlError("glGenTextures");
	gInitialized = true;
}

GLuint renderTOrenderBuffer(){

	glBindFramebuffer(GL_FRAMEBUFFER,fboID);
	//glBindRenderbuffer(GL_RENDERBUFFER,rboID);

	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBindTexture(GL_TEXTURE_2D, RTtexture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//把坐标（0，0）到（gWidth，gHeight）的屏幕像素拷贝到纹理
	glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 0, 0, gWidth, gHeight, 0);

//	char a[4] = { 0 };
//	char *p = a;
//	glReadPixels(110, 110, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, p);
//	LOGI("...........1= %d", p[0]);
//	LOGI("...........2= %d", p[1]);
//	LOGI("...........3= %d", p[2]);
//	LOGI("...........4= %d", p[3]);

	glBindFramebuffer(GL_FRAMEBUFFER,0);
}

GLuint loadShader(GLenum shaderType, const char* pSource) {
	//genTexture();
    shader = glCreateShader(shaderType);
    checkGlError("glCreateShader");
    if (shader) {
        glShaderSource(shader, 1, &pSource, NULL);
        glCompileShader(shader);
        GLint compiled = 0;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
        if (!compiled) {
            GLint infoLen = 0;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
            if (infoLen) {
                char* buf = (char*) malloc(infoLen);
                if (buf) {
                    glGetShaderInfoLog(shader, infoLen, NULL, buf);
                    LOGE("Could not compile shader %d:\n%s\n",
                            shaderType, buf);
                    free(buf);
                }
                glDeleteShader(shader);
                shader = 0;
            }
        }
    }
    return shader;
}

GLuint createProgram(const char* pVertexSource, const char* pFragmentSource) {
    GLuint vertexShader = loadShader(GL_VERTEX_SHADER, pVertexSource);
    //checkGlError("loadShader vertexShader");
    if (!vertexShader) {
        return 0;
    }

    GLuint pixelShader = loadShader(GL_FRAGMENT_SHADER, pFragmentSource);
    //checkGlError("loadShader pixelShader");
    if (!pixelShader) {
        return 0;
    }

    GLuint program = glCreateProgram();
    if (program) {
        glAttachShader(program, vertexShader);
        //checkGlError("glAttachShader11111");
        glAttachShader(program, pixelShader);
        //checkGlError("glAttachShader22222");
        glLinkProgram(program);
        GLint linkStatus = GL_FALSE;
        glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
        if (linkStatus != GL_TRUE) {
            GLint bufLength = 0;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufLength);
            if (bufLength) {
                char* buf = (char*) malloc(bufLength);
                if (buf) {
                    glGetProgramInfoLog(program, bufLength, NULL, buf);
                    LOGE("Could not link program:\n%s\n", buf);
                    free(buf);
                }
            }
            glDeleteProgram(program);
            program = 0;
        }
    }
    return program;
}

GLuint gProgram;
GLuint positionLoc;
GLuint texcoordLoc;
GLuint textureLoc;


bool setupGraphics(int w, int h) {
    printGLString("Version", GL_VERSION);
    printGLString("Vendor", GL_VENDOR);
    printGLString("Renderer", GL_RENDERER);
    printGLString("Extensions", GL_EXTENSIONS);

    gWidth = w;
    gHeight = h;

    glViewport(0, 0, w, h);
    checkGlError("glViewport");

    LOGI("setupGraphics(%d, %d)", w, h);
    gProgram = createProgram(gVertexShader, gFragmentShader);////////////////////////////////1
    if (!gProgram) {
        LOGE("Could not create program.");
        return false;
    }
    checkGlError("createProgram");
    ///////////////////////////////
    positionLoc = glGetAttribLocation(gProgram, "a_position");
    checkGlError("glGetAttribLocation a_position");
    texcoordLoc = glGetAttribLocation(gProgram, "a_texCoord");
    checkGlError("glGetAttribLocation a_texCoord");
    textureLoc = glGetUniformLocation ( gProgram, "s_texture" );
    checkGlError("glGetUniformLocation s_texture");
    ///////////////////////////////

    initForRenderTOrenderBuffer(w, h);
    checkGlError("initForRenderTOrenderBuffer");
    obj = new nativeRecord();
    obj -> init();
    return true;
}

const GLfloat vVertices[] = { -1.0f,  1.0f,  // Position 0
                            0.0f,  0.0f,        // TexCoord 0
                           -1.0f, -1.0f,  // Position 1
                            0.0f,  1.0f,        // TexCoord 1
                            1.0f, -1.0f,  // Position 2
                            1.0f,  1.0f,        // TexCoord 2
                            1.0f,  1.0f,  // Position 3
                            1.0f,  0.0f         // TexCoord 3
                         };

unsigned short v_index[] = {0,1,2,0,2,3};
void renderFrame() {
	if (gInitialized == false)
		return;

	renderTOrenderBuffer(); // RTtexture is available
	checkGlError("renderTOrenderBuffer");
   obj -> beforeRender(); // prepare framebuffer
	checkGlError("beforeRender");
	   glClear(GL_COLOR_BUFFER_BIT);
	  checkGlError("glClear 1");
    // Create a Vertex Buffer Object and copy the vertex data to it
    GLuint vbo;
    glGenBuffers(1, &vbo);

    GLfloat vertices[] = {
    //  Position   Color             Texcoords
        -1.0f,  1.0f, 0.0f, 0.0f, // Top-left
        1.0f,  1.0f, 1.0f, 0.0f, // Top-right
        1.0f, -1.0f, 1.0f, 1.0f, // Bottom-right
        -1.0f, -1.0f, 0.0f, 1.0f  // Bottom-left
    };

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    checkGlError("glBufferData(GL_ARRAY_BUFFER");

    // Create an element array
    GLuint ebo;
    glGenBuffers(1, &ebo);

    GLuint elements[] = {
        0, 1, 2,
        2, 3, 0
    };

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    checkGlError("glBindBuffer(GL_ELEMENT_ARRAY_BUFFER");
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
    checkGlError("glBufferData(GL_ELEMENT_ARRAY_BUFFER");
    glUseProgram(gProgram);
    checkGlError("glUseProgram");

    ///////////
    // Load the vertex position
    glVertexAttribPointer ( positionLoc, 2, GL_FLOAT,
						   GL_FALSE, 4 * sizeof(GLfloat), 0 );
    // Load the texture coordinate
    glVertexAttribPointer ( texcoordLoc, 2, GL_FLOAT,
						   GL_FALSE, 4 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)) );
    checkGlError("glVertexAttribPointer");
    glEnableVertexAttribArray ( positionLoc );
    glEnableVertexAttribArray ( texcoordLoc );
    // Bind the texture
    checkGlError("glEnableVertexAttribArray");

    glActiveTexture ( GL_TEXTURE0 );  /// //////0要跟下面glUniform1i的第二个参数对应
    glBindTexture ( GL_TEXTURE_2D, RTtexture );
    checkGlError("glBindTexture");

    // Set the sampler texture unit to 0
    glUniform1i ( textureLoc, 0 );     // /////
    checkGlError("glUniform1i");
    // Clear the screen to black
           glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
           checkGlError("glClearColor");
           glClear(GL_COLOR_BUFFER_BIT);
           checkGlError("glClear");
           // Draw a rectangle from the 2 triangles using 6 indices
           glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
           checkGlError("glDrawElements");
    //glDrawElements ( GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, v_index );
    ///////////
    obj -> start();
//    checkGlError("start");
//		char a[4] = { 0 };
//		char *p = a;
//		glReadPixels(110, 110, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, p);
//		LOGI("...........1= %d", p[0]);
//		LOGI("...........2= %d", p[1]);
//		LOGI("...........3= %d", p[2]);
//		LOGI("...........4= %d", p[3]);
   obj -> afterRender();
   checkGlError("afterRender");
}

extern "C" {
    JNIEXPORT void JNICALL Java_com_android_gl2jni_GL2JNILib_init(JNIEnv * env, jobject obj,  jint width, jint height);
    JNIEXPORT void JNICALL Java_com_android_gl2jni_GL2JNILib_step(JNIEnv * env, jobject obj);
};

JNIEXPORT void JNICALL Java_com_android_gl2jni_GL2JNILib_init(JNIEnv * env, jobject obj,  jint width, jint height)
{
    setupGraphics(width, height);
}

JNIEXPORT void JNICALL Java_com_android_gl2jni_GL2JNILib_step(JNIEnv * env, jobject obj)
{
	struct  timeval start;
	struct  timeval end;
	unsigned  long diff;
	gettimeofday(&start,NULL);
    renderFrame();

    gettimeofday(&end,NULL);
	diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
	LOGI("???????????? t = %ld",diff);
}
