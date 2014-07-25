#include <jni.h>
#include <android/log.h>
#include <stdlib.h>
#define TAG "test"
#define LOGD(...) __android_log_print(ANDROID_LOG_ERROR  , TAG , __VA_ARGS__)
#define NELEM(x)  (sizeof(x)/sizeof(x[0]))

JNIEnv* env;
jclass clazz = NULL;
jmethodID nineToBitmap = NULL;
jmethodID getBuffer = NULL;

jbyteArray jba;
jbyte * array;

void nineToBitmap_native(){
	//env -> CallStaticObjectMethod(*env, clazz, nineToBitmap);
	env -> CallStaticVoidMethod(clazz,nineToBitmap);
}

void getBuffer_native(){

	//jba = (env) -> CallStaticByteMethodA(env, clazz, getBuffer);
	jba = (jbyteArray)env -> CallStaticObjectMethod(clazz, getBuffer);
	array = env -> GetByteArrayElements(jba,0);

}

int register_method(JNIEnv *env)
{
	clazz = env -> FindClass("com/example/ninetobitmap/MainActivity");
	if(clazz == NULL){
		LOGD("findClass error");
		return 1;
	}
	nineToBitmap = env -> GetStaticMethodID(clazz, "nineToBitmap", "(Ljava/lang/String;IILjava/lang/String;)V");
	if(nineToBitmap == NULL){
		LOGD("getStaticMethodId error1");
		return 1;
	}
	getBuffer = env -> GetStaticMethodID(clazz, "getBuffer", "([B)[B");
	if(getBuffer == NULL){
		LOGD("getStaticMethodID error2");
		return 1;
	}

}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    env = NULL;
    jint result = -1;

    if (vm->GetEnv(  ( void**) &env, JNI_VERSION_1_4) != JNI_OK) {
        return result;
    }

    LOGD("onLoad");
    register_method(env);

    // ·µ»ØjniµÄ°æ±¾
    return JNI_VERSION_1_4;
}
