#include <jni.h>
#include <android/log.h>
#include <pthread.h>

#define LOG_TAG  "native-jni"

#define LOG_D(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOG_E(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)


static jobject sJniCallbacksObj = NULL;           
static JavaVM *java_vm;
static pthread_key_t current_jni_env;
static jmethodID method_funcGenCallback;

static JNIEnv *get_jni_env (void) 
{
    JNIEnv *env;

    if ((env = (JNIEnv *)pthread_getspecific(current_jni_env)) == NULL)
	{
        if(java_vm->AttachCurrentThread (&env, NULL)!= JNI_OK)
		{
            LOG_E("AttachCurrentThread failed.");
        }

        pthread_setspecific (current_jni_env, env);
    }

    return env;
}

static int app_callback(int cmd, int node, float value, unsigned char *buf)
{
	LOG_D("app_callback: node = %d, value = %f", node, value);
	JNIEnv *env = get_jni_env();
	env->CallVoidMethod (sJniCallbacksObj, method_funcGenCallback, node, value);
}


static void com_systechn_smarthome_connector_classInitNative(JNIEnv *env, jclass clazz)
{


}

static jboolean com_systechn_smarthome_connector_connectServer(JNIEnv *env, jobject obj, jstring server_type, jstring server_ip)
{
	sJniCallbacksObj = env->NewGlobalRef(obj);
	
    const char *str = env->GetStringUTFChars(server_ip, 0);
    LOG_D("connect server_ip : %s", str);
	
	/****************************************************************/
	
	
	/****************************************************************/
	
    env->ReleaseStringUTFChars(server_ip, str);		
	
	return JNI_TRUE;
}


static jboolean com_systechn_smarthome_connector_disconnectServer(JNIEnv *env, jobject obj)
{
	LOG_D("disconnect....");	

	/****************************************************************/
	
	
	/****************************************************************/
	env->DeleteGlobalRef(sJniCallbacksObj);	
	return JNI_TRUE;
}

static jboolean com_systechn_smarthome_connector_bindDevice(JNIEnv *env, jobject obj, jint node, jstring json)
{
    const char *node_json = env->GetStringUTFChars(json, 0);
    LOG_D("node: %d, json: %s", node, node_json);	
	/****************************************************************/
	
	
	/****************************************************************/
	env->ReleaseStringUTFChars(json, node_json);		
	return JNI_TRUE;
}

static jboolean com_systechn_smarthome_connector_controlDevice(JNIEnv *env, jobject obj, jint node, jfloat value)
{
	/****************************************************************/
	
	
	/****************************************************************/
	return JNI_TRUE;
}

static jboolean com_systechn_smarthome_connector_readDeviceState(JNIEnv *env, jobject obj, jintArray data)
{
	/****************************************************************/
	
	
	/****************************************************************/
	return JNI_TRUE;
}


static JNINativeMethod native_methods[] = 
{
    {"classInitNative",		"()V",							(void *)com_systechn_smarthome_connector_classInitNative},
    {"connectServer",		"(Ljava/lang/String;Ljava/lang/String;)Z",	(void *)com_systechn_smarthome_connector_connectServer},
    {"disconnectServer",	"()Z",	    					(void *)com_systechn_smarthome_connector_disconnectServer},
    {"bindDevice",			"(ILjava/lang/String;)Z",		(void *)com_systechn_smarthome_connector_bindDevice},
    {"controlDevice",		"(IF)Z",	    				(void *)com_systechn_smarthome_connector_controlDevice},
    {"readDeviceState",		"([I)Z",						(void *)com_systechn_smarthome_connector_readDeviceState},	
};


static jboolean _native_class_init (JNIEnv* env, jclass klass)
{
    method_funcGenCallback      = env->GetMethodID (klass, "onDeviceStateEvent", "(IF)V");

    return JNI_TRUE;
}

static void detach_current_thread (void *env) 
{
    LOG_D("Detaching thread");
    if(java_vm->DetachCurrentThread() != JNI_OK)
	{
        LOG_E("DetachCurrentThread failed.");
    }
}

jint JNI_OnLoad(JavaVM *vm, void *reserved) 
{
    JNIEnv *env = NULL;
    java_vm = vm;

    if (vm->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK) 
	{
        LOG_E("Could not retrieve JNIEnv");
        return 0;
    }

    jclass klass = env->FindClass ("com/systechn/smarthome/connector/DevConnector");

    env->RegisterNatives (klass, native_methods, sizeof(native_methods)/sizeof(JNINativeMethod));

    pthread_key_create (&current_jni_env, detach_current_thread);

    _native_class_init(env, klass); /* 获取回调接口 */

    return JNI_VERSION_1_4;
}


void JNI_OnUnload(JavaVM* vm,void* reserved) 
{
    JNIEnv* env = NULL;
    if (vm->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK)
	{
        LOG_E("JNI_OnUnload failed.");
        return;
    }
	
    jclass connectorClazz = env->FindClass("com/systechn/smarthome/connector/DevConnector");
    jint ret = env->UnregisterNatives(connectorClazz);
    if(ret == 0)
	{
        LOG_D("native method unregister succeed.");
    } 
	else 
	{
        LOG_D("native method unregister failed.");
    }

    java_vm = NULL;
    method_funcGenCallback = 0;
}

