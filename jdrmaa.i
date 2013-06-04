%module jdrmaa
%include "typemaps.i"
%{
#include "drmaa_impl_stolen.h"
#include <drmaa.h>
%}



%ignore drmaa_allocate_job_template;
%ignore drmaa_delete_job_template;
%ignore drmaa_set_attribute;
%ignore drmaa_get_attribute;
%ignore drmaa_set_vector_attribute;
%ignore drmaa_get_vector_attribute;
%ignore drmaa_run_job;

%include "drmaa_impl_stolen.h"
%include <drmaa.h>

%extend drmaa_job_template_s {
        drmaa_job_template_s(){
                drmaa_job_template_t *jt;
                drmaa_allocate_job_template(&jt,NULL,0);
                return jt;
        }

        ~drmma_job_template_s(){
                drmaa_delete_job_template($self,NULL,0);
        }

        int set_attribute(const char *name, const char *value){
            return drmaa_set_attribute($self, name, value, NULL, 0);
        }

        
        char *get_attribute(const char *name){
                int reason;
                char *retval;
                retval = malloc(1024*sizeof(char));
                reason = drmaa_get_attribute($self,name,retval,1024,NULL,0);
                return retval;
        }

        int set_vector_attribute(const char *name, const char *value[]){
           return drmaa_set_vector_attribute($self,name,value,NULL,0);
        }

        drmaa_attr_values_t *get_vector_attribute(const char *name){
                drmaa_attr_values_t *values;
                drmaa_get_vector_attribute($self,name,&values,NULL,0);
                return values;
        }

        char *start(){
                int reason;
                char *retval;
                retval = malloc(256*sizeof(char));
                reason = drmaa_run_job(retval, 256, $self, NULL, 0);
                return retval;
        }
};

drmaa_attr_names_t foo_get_attribute_names(){
        int reason;
        drmaa_attr_names_t *retval;
        reason = drmaa_get_attribute_names(&retval,NULL,0);
        return retval;
}

%extend drmaa_attr_names_s {
}
