%module drmaa
%include "typemaps.i"
%{
#include "drmaa_impl_stolen.h"
#include <drmaa.h>
%}

%rename(JobTemplate) drmaa_job_template_s;

%include "drmaa_impl_stolen.h"
%include <drmaa.h>
%extend drmaa_job_template_s {
        int set_attribute(const char *name, const char *value){
            return drmaa_set_attribute($self, name, value, NULL, 0);
        };

        
        char *get_attribute(const char *name){
                int reason;
                char *retval;
                retval = malloc(1024*sizeof(char));
                reason = drmaa_get_attribute($self,name,retval,1024,NULL,0);
                return retval;
        };
};
