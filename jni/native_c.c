#include <jni.h>
#include <android/log.h>
#include <pthread.h>


#define LOG_TAG  "native-jni"
#define LOG_D(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOG_E(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)



JavaVM	*java_vm;

static jobject sJniCallbacksObj;
static pthread_key_t sThreadJniEnv;



static jmethodID method_funcGenCallback;





JNIEnv* checkCallbackThread(void)
{
    JNIEnv *pEnv;

    if ((pEnv = (JNIEnv *)pthread_getspecific(sThreadJniEnv)) == NULL)
	{
        if((*java_vm)->AttachCurrentThread (java_vm, &pEnv, NULL)!= JNI_OK)
		{
            LOG_E("AttachCurrentThread failed.");
        }

        pthread_setspecific (sThreadJniEnv, pEnv);
		pEnv = NULL;
    }

    return pEnv;
}


static int app_callback(int cmd, int node, float value, unsigned char *buf)
{
	int iRet = -1;
	JNIEnv *callbackEnv = NULL;

	LOG_D("app_callback: node = %d, value = %f", node, value);
	
	if(callbackEnv = checkCallbackThread())
	{
		(*callbackEnv)->CallVoidMethod(callbackEnv, sJniCallbacksObj, method_funcGenCallback, node, value);
		iRet = 0;		
	}

	return iRet;
}

static void detach_current_thread (void *env) 
{
    LOG_D("Detaching thread");
    if((*java_vm)->DetachCurrentThread(java_vm) != JNI_OK)
	{
        LOG_E("DetachCurrentThread failed.");
    }
}

JNIEXPORT void JNICALL Java_com_systechn_smarthome_connector_DevConnector_classInitNative(JNIEnv *env, jclass clazz)
{
	jclass jniCallbackClass = (*env)->FindClass(env, "com/systechn/smarthome/connector/DevConnector");
	
	method_funcGenCallback = (*env)->GetMethodID(env, jniCallbackClass, "onDeviceStateEvent", "(IF)V"); 
	
	pthread_key_create (&sThreadJniEnv, detach_current_thread);
}

JNIEXPORT jboolean JNICALL Java_com_systechn_smarthome_connector_DevConnector_connectServer(JNIEnv *env, jobject obj, jstring server_type, jstring server_ip)
{
	(*env)->GetJavaVM(env, &java_vm);

	sJniCallbacksObj = (*env)->NewGlobalRef(env, obj);
	
    const char *str = (*env)->GetStringUTFChars(env, server_ip, 0);
	
    LOG_D("connect server_ip : %s", str);
	/****************************************************************/
	
	
	/****************************************************************/
	(*env)->ReleaseStringUTFChars(env, server_ip, str);		
	return JNI_TRUE;
}

JNIEXPORT jboolean JNICALL Java_com_systechn_smarthome_connector_DevConnector_disconnectServer(JNIEnv *env, jobject obj)
{
	LOG_D("disconnect....");	

	/****************************************************************/
	
	
	/****************************************************************/
	(*env)->DeleteGlobalRef(env, sJniCallbacksObj);	

	return JNI_TRUE;
}

JNIEXPORT jboolean JNICALL Java_com_systechn_smarthome_connector_DevConnector_bindDevice(JNIEnv *env, jobject obj, jint node, jstring json)
{
    const char *node_json = (*env)->GetStringUTFChars(env, json, 0);
    LOG_D("node: %d, json: %s", node, node_json);	
	/****************************************************************/
	
	
	/****************************************************************/
	(*env)->ReleaseStringUTFChars(env, json, node_json);	
	return JNI_TRUE;
}

JNIEXPORT jboolean JNICALL Java_com_systechn_smarthome_connector_DevConnector_controlDevice(JNIEnv *env, jobject obj, jint node, jfloat value)
{
	
	/****************************************************************/
	
	
	/****************************************************************/
	return JNI_TRUE;
	
}

JNIEXPORT jboolean JNICALL Java_com_systechn_smarthome_connector_DevConnector_readDeviceState(JNIEnv *env, jobject obj, jintArray data)
{
	/****************************************************************/
	
	
	/****************************************************************/

	return JNI_TRUE;
}






