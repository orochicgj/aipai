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

#define  LOG_TAG    "libgl2jni"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

typedef GLuint skeletons[8];

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
    "attribute vec4 vPosition;\n"
	"uniform vec4 pos_offset;\n"
    "void main() {\n"
    "  gl_Position = vPosition + pos_offset;\n"
    "}\n";

static const char gFragmentShader[] = 
    "precision mediump float;\n"
    "void main() {\n"
    "  gl_FragColor = vec4(0.0, 1.0, 0.0, 1.0);\n"
    "}\n";
GLuint gProgram;
GLuint gvPositionHandle;

GLuint vPosOffsetHandle;
GLuint vertexBuffer;
GLuint ebo;
GLfloat vertices[8][8] = {
		{-1.0f,1.0f, -1.0f,0.774f, 1.0f,0.774f, 1.0f,1.0f}, //0
		{0.6f,1.0f, 0.6f,-0.113f, 1.0f,-0.113f, 1.0f,1.0f}, //1
		{0.6f,0.113f, 0.6f,-1.0f, 1.0f,-1.0f, 1.0f,0.113f}, //2
		{-1.0f,-0.774f, -1.0f,-1.0f, 1.0f,-1.0f, 1.0f,-0.774f}, //3
		{-1.0f,0.113f, -1.0f,-1.0f, -0.6f,-1.0f, -0.6f,0.113f}, //4
		{-1.0f,1.0f, -1.0f,-0.113f, -0.6f,-0.113f, -0.6f,1.0f}, //5
		{-1.0f,0.113f, -1.0f,-0.113f, 1.0f,-0.113f, 1.0f,0.113f}, //6
		{0.6f,-0.774f, 0.6f,-1.0f, 1.0f,-1.0f, 1.0f,-0.774f} //7
};
GLuint elements[] = {
        0, 1, 2,
        2, 3, 0,
};

skeletons parts[] = {
		{1,2,3,4,5,6,0}, //0
		{2, 3, 0},  // 1
		{1, 2, 7, 5, 4, 0}, // 2
		{1,2,3,4,7,0}, // 3
		{2,3,6,7,0}, //4
		{1,3,4,6,7,0}, //5
		{1,3,4,5,6,7,0}, //6
		{1,2,3,0}, //7
		{1,2,3,4,5,6,7,0}, //8
		{1,2,3,4,6,7,0}, //9
		{8, 0} // .
};

bool drawNum(GLint value){

	if (!((value >= 0 && value <= 9) || value == -2))
		return false;

	if ( value == -2) {
		value = 10;
	}

	for (int i = 0; i < sizeof(skeletons); i++) {
		if (parts[value][i] == 0) {
			break;
		}
		int offset = (parts[value][i] - 1) * 32;
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE ,
										2 * sizeof(GLfloat ), (const void*)offset);
		glEnableVertexAttribArray(0);
		glDrawElements (GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	return true;
}

bool resetVertices(GLfloat factor){
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++){
			vertices[i][j] = vertices[i][j] * factor;
		}
	return true;
}

int flag = 0;
bool drawDigital(const char*str, GLfloat x, GLfloat y, GLfloat factor){
	glGenBuffers(1, &vertexBuffer);
	glGenBuffers(1,&ebo);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER , sizeof(vertices), vertices , GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER , sizeof(elements), elements , GL_STATIC_DRAW);
	GLuint length = 0;
	length = strlen(str);
	char * p = (char*)str;
	if(flag == 0){
		flag = 1;
		resetVertices(factor);
	}
	GLfloat offset1 = 0.4f * factor; //设置数字之间的间隔，间隔为数字1的宽度（因为数字的每个笔画都设为0.4个单位）
	GLfloat offset2 = 2.0f * factor; //每个数字缩小后所占的宽度
	GLfloat offset = 0.0f;
	for(int i = 0; i < length; i++){
		offset = (offset1 + offset2) * i;
		glUniform4f(vPosOffsetHandle,-0.9f + offset,0.9f,0.0f,0.0f);
		drawNum(*p - '0');
		++p;
	}
	glDeleteBuffers(1,&vertexBuffer);
	glDeleteBuffers(1,&ebo);
	return true;
}


GLuint loadShader(GLenum shaderType, const char* pSource) {
    GLuint shader = glCreateShader(shaderType);
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
    if (!vertexShader) {
        return 0;
    }

    GLuint pixelShader = loadShader(GL_FRAGMENT_SHADER, pFragmentSource);
    if (!pixelShader) {
        return 0;
    }

    GLuint program = glCreateProgram();
    if (program) {
        glAttachShader(program, vertexShader);
        checkGlError("glAttachShader");
        glAttachShader(program, pixelShader);
        checkGlError("glAttachShader");
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



bool setupGraphics(int w, int h) {
    printGLString("Version", GL_VERSION);
    printGLString("Vendor", GL_VENDOR);
    printGLString("Renderer", GL_RENDERER);
    printGLString("Extensions", GL_EXTENSIONS);

    LOGI("setupGraphics(%d, %d)", w, h);
    gProgram = createProgram(gVertexShader, gFragmentShader);
    if (!gProgram) {
        LOGE("Could not create program.");
        return false;
    }
    gvPositionHandle = glGetAttribLocation(gProgram, "vPosition");
    checkGlError("glGetAttribLocation");
    LOGI("glGetAttribLocation(\"vPosition\") = %d\n",
            gvPositionHandle);

    vPosOffsetHandle = glGetUniformLocation(gProgram, "pos_offset");
    checkGlError("glGetUniformLocation");
	LOGI("glGetUniformLocation(\"pos_offset\") = %d\n",
			vPosOffsetHandle);

    glViewport(0, 0, w, h);
    checkGlError("glViewport");
    return true;
}

const GLfloat gTriangleVertices[] = { 0.0f, 0.5f, -0.5f, -0.5f,
        0.5f, -0.5f };

void renderFrame() {
    static float grey;
    grey += 0.01f;
    if (grey > 1.0f) {
        grey = 0.0f;
    }
    glClearColor(grey, grey, grey, 1.0f);
    checkGlError("glClearColor");
    glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    checkGlError("glClear");

    glUseProgram(gProgram);
    checkGlError("glUseProgram");

    drawDigital("123.4567890",-0.5f,0.5f,0.03f);

//    glVertexAttribPointer(gvPositionHandle, 2, GL_FLOAT, GL_FALSE, 0, gTriangleVertices);
//    checkGlError("glVertexAttribPointer");
//    glEnableVertexAttribArray(gvPositionHandle);
//    checkGlError("glEnableVertexAttribArray");
//    glDrawArrays(GL_TRIANGLES, 0, 3);
//    checkGlError("glDrawArrays");
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
    renderFrame();
}
