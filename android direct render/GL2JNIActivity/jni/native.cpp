#include "native.h"

PFNEGLCREATEIMAGEKHRPROC _eglCreateImageKHR = NULL ;
PFNEGLDESTROYIMAGEKHRPROC _eglDestroyImageKHR = NULL ;
PFNGLEGLIMAGETARGETTEXTURE2DOESPROC _glEGLImageTargetTexture2DOES = NULL;

 int gWidth;
 int gHeight;
 char *pixels;

#define  LOG_TAG    "libgl2jni"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

static void checkGlError(const char* op) {
    for (GLint error = glGetError(); error; error
            = glGetError()) {
        LOGI("after %s() glError (0x%x)\n", op, error);
    }
}

void nativeRecord::init(){
	_eglCreateImageKHR = ( PFNEGLCREATEIMAGEKHRPROC) eglGetProcAddress ( "eglCreateImageKHR" );
	_eglDestroyImageKHR = ( PFNEGLDESTROYIMAGEKHRPROC) eglGetProcAddress( "eglDestroyImageKHR" );
	_glEGLImageTargetTexture2DOES = (PFNGLEGLIMAGETARGETTEXTURE2DOESPROC) eglGetProcAddress( "glEGLImageTargetTexture2DOES" );
	if(_eglCreateImageKHR == NULL){
		LOGD("_eglCreateImageKHR error");
		exit(1);
	}
	if(_eglDestroyImageKHR == NULL){
		LOGD("_eglDestroyImageKHR error");
		exit(1);
	}
	if(_glEGLImageTargetTexture2DOES == NULL){
		LOGD("_glEGLImageTargetTexture2DOES error");
		exit(1);
	}
	buffer =  new GraphicBuffer ( gWidth ,  gHeight ,
			HAL_PIXEL_FORMAT_BGRA_8888,
            GraphicBuffer :: USAGE_SW_READ_OFTEN |
            GraphicBuffer :: USAGE_HW_TEXTURE );
	if((buffer->initCheck ()) != NO_ERROR)
		exit (1);
	android_native_buffer_t * anb = buffer->getNativeBuffer();
	const EGLint attrs [] =
	{
			EGL_IMAGE_PRESERVED_KHR , EGL_TRUE,
			EGL_NONE, EGL_NONE
	};
	pEGLImage = _eglCreateImageKHR(eglGetCurrentDisplay(),EGL_NO_CONTEXT, EGL_NATIVE_BUFFER_ANDROID, (EGLClientBuffer)anb, attrs);

	if(EGL_SUCCESS != eglGetError()) {
		LOGI("_eglCreateImageKHR failed.");
				return;
	}
	glGenTextures(1 , &iFBOTex );
	checkGlError("glGenTextures(1 , &iFBOTex );");
	glBindTexture(GL_TEXTURE_2D , iFBOTex);
	checkGlError("glBindTexture(GL_TEXTURE_2D , iFBOTex);");
//	glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST );
//	glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER, GL_LINEAR );

	glTexImage2D(GL_TEXTURE_2D, 0, GL_BGRA_EXT, gWidth, gHeight,
				 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, NULL);
	if(GL_NO_ERROR != glGetError()) {
		LOGI("glTexImage2D failed.");
		return;
	}

	glGenFramebuffers (1, &iFBO);
	checkGlError("glGenFramebuffers (1, &iFBO);");
	glBindFramebuffer (GL_FRAMEBUFFER, iFBO);
	checkGlError("glBindFramebuffer (GL_FRAMEBUFFER, iFBO)");
	glFramebufferTexture2D (GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, iFBOTex, 0);

	GLuint status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
	if(status != GL_FRAMEBUFFER_COMPLETE) {
		LOGI("glCheckFramebufferStatus %d", status);
	}

	checkGlError("glFramebufferTexture2D");
	_glEGLImageTargetTexture2DOES (GL_TEXTURE_2D, pEGLImage);
	checkGlError("_glEGLImageTargetTexture2DOES");
	glBindFramebuffer (GL_FRAMEBUFFER,0);
	checkGlError("glBindFramebuffer (GL_FRAMEBUFFER,0)");

	pixels = (char*)malloc(720*1280*4);
	memset(pixels,0,720*1280*4);
}

void nativeRecord::start(){
	//glBindFramebuffer (GL_FRAMEBUFFER,iFBO);
	void* vaddr;
	buffer -> lock( GRALLOC_USAGE_SW_READ_OFTEN, &vaddr);
	if (vaddr == NULL)
	{
		buffer->unlock();
		LOGD("lock error");
		return;
	}
	unsigned char * b = (unsigned char*)vaddr;
//	LOGD("pixel = %d",(int)b[1111]);
//	LOGD("pixel = %d",(int)b[1112]);
//	LOGD("pixel = %d",(int)b[1113]);
//	LOGD("pixel = %d",(int)b[1114]);
//	LOGD("pixel = %d",(int)b[1116]);
//	LOGD("pixel = %d",(int)b[1117]);
//	LOGD("pixel = %d",(int)b[1118]);
//	LOGD("pixel = %d",(int)b[1119]);
	//glBindFramebuffer (GL_FRAMEBUFFER,0);
	memcpy(pixels,b,gHeight*gWidth);
//	LOGD("pixel = %d",pixels[5555]);
//	LOGD("pixel = %d",pixels[5556]);
//	LOGD("pixel = %d",pixels[5557]);
//	LOGD("pixel = %d",pixels[5558]);
	buffer -> unlock();
}


void nativeRecord::beforeRender()
{
	glBindFramebuffer (GL_FRAMEBUFFER, iFBO);
	checkGlError("glBindFramebuffer (GL_FRAMEBUFFER, iFBO) >>");

	GLuint status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
	if(status != GL_FRAMEBUFFER_COMPLETE) {
	LOGI("glCheckFramebufferStatus %d", status);
	}
}

void nativeRecord::afterRender()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
