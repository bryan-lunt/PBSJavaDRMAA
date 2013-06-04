#include <drmaa.h>

class JobTemplate{
	drmaa_job_template_t *jt;
	
	JobTemplate(){
		drmaa_allocate_job_template(&jt,NULL,0);
	}

	~JobTemplate(){
		drmaa_delete_job_template(jt,NULL,0);
	}

	int set_attribute(const char *name, const char *value){
		return drmaa_set_attribute(jt, name, value, NULL, 0);
	}

	char *get_attribute(const char *name){
                int reason;
                char *retval;
                retval = malloc(1024*sizeof(char));
                reason = drmaa_get_attribute(jt,name,retval,1024,NULL,0);
                return retval;
        }

	int set_vector_attribute(const char *name, const char *value[]){
           return drmaa_set_vector_attribute($self,name,value,NULL,0);
        }

	/*
 *         drmaa_attr_values_t *get_vector_attribute(const char *name){
 *                         drmaa_attr_values_t *values;
 *                                         drmaa_get_vector_attribute($self,name,&values,NULL,0);
 *                                                         return values;
 *                                                                 }
 *      */

	char *start(){
                int reason;
                char *retval;
                retval = malloc(256*sizeof(char));
                reason = drmaa_run_job(retval, 256, $self, NULL, 0);
                return retval;
        }
	
	
};
