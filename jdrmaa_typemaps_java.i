%{
#include <exception>
%}

/*
*These typemaps are copied/fixed from http://www.swig.org/Doc1.3/Java.html#converting_java_string_arrays
*(Those examples assume C, not C++)
*/
%typemap(in) char ** (jint size) {
    int i = 0;
    size = jenv->GetArrayLength((_jarray*)$input);
    $1 = (char **) malloc((size+1)*sizeof(char *));
    /* make a copy of each string */
    for (i = 0; i<size; i++) {
        jstring j_string = (jstring)jenv->GetObjectArrayElement((_jobjectArray*)$input, i);
        const char * c_string = (char*)jenv->GetStringUTFChars(j_string, 0);
        $1[i] = (char*)malloc((strlen(c_string)+1)*sizeof(char));
        strcpy($1[i], c_string);
        jenv->ReleaseStringUTFChars(j_string, c_string);
        jenv->DeleteLocalRef(j_string);
    }
    $1[i] = NULL;
}

/* This cleans up the memory we malloc'd before the function call */
%typemap(freearg) char ** {
    int i;
    for (i=0; i<size$argnum-1; i++)
      free($1[i]);
    free($1);
}

/* These 3 typemaps tell SWIG what JNI and Java types to use */
%typemap(jni) char ** "jobjectArray"
%typemap(jtype) char ** "String[]"
%typemap(jstype) char ** "String[]"

/* These 2 typemaps handle the conversion of the jtype to jstype typemap type
   and vice versa */
%typemap(javain) char ** "$javainput"
%typemap(javaout) char ** {
    return $jnicall;
  }


/**
 *Exceptions
 */
%typemap(throws,throws="DRMAAException") DRMAAException {
        jclass excep = jenv->FindClass("jdrmaa/DRMAAException");
        if (excep)
                jenv->ThrowNew(excep, $1.what());
        return $null;
}

%typemap(throws,throws="java.lang.Exception") std::exception {
        jclass excep = jenv->FindClass("java/lang/Exception");
        if (excep)
                jenv->ThrowNew(excep, $1.what());
        return $null;
}

/* The next Typemaps make sure that exceptions Don't kill the underlying library, and that they propagate up to Java. */
%typemap(javabase) DRMAAException "java.lang.Exception";
%typemap(javacode) DRMAAException %{
//        public DRMAAException(String msg){
//                super(msg);
 //       }

        public String getMessage(){
                return what();
        }
%}
