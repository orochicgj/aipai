#ifndef _NATIVERECORD_H_
#define _NATIVERECORD_H_

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <ui/GraphicBuffer.h>
#include <android/log.h>
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, "testJNI", __VA_ARGS__)
using namespace android;
class nativeRecord{
public:
	GLuint texID;
	void init();
	void start();
	void beforeRender();
	void afterRender();
private:
	GLuint iFBO ;
	GLuint iFBOTex ;
	GraphicBuffer * buffer;
	EGLImageKHR pEGLImage;
};

extern int gWidth;
extern int gHeight;

#endif
