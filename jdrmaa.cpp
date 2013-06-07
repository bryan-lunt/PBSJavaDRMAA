#include <drmaa.h>
#include <string.h>

#include <stdlib.h>

#include "jdrmaa.hxx"

DRMAAVector::DRMAAVector(attType intype){
	type = intype;
}

DRMAAVector::~DRMAAVector(){
	switch(type){
                case NAMES:
                        drmaa_release_attr_names(asnames);
                        break;
                case VALUES:
                        drmaa_release_attr_values(asvalues);
                        break;
                case JOBS:
                        drmaa_release_job_ids(asjobs);
                        break;
        }
}

char *DRMAAVector::next(){
                int retsize = 256;
                if( type == VALUES )
                        retsize = 4096;

                char *retval = (char*)malloc(retsize*sizeof(char));
                switch(type){
                case NAMES:
                        drmaa_get_next_attr_name(asnames,retval,retsize);
                        break;
                case VALUES:
                        drmaa_get_next_attr_value(asvalues,retval,retsize);
                        break;
                case JOBS:
                        drmaa_get_next_job_id(asjobs,retval,retsize);
                        break;
                }

                return retval;
}

size_t DRMAAVector::size(){
                size_t retval;
                switch(type){
                case NAMES:
                        drmaa_get_num_attr_names(asnames,&retval);
                        break;
                case VALUES:
                        drmaa_get_num_attr_values(asvalues,&retval);
                        break;
                case JOBS:
                        drmaa_get_num_job_ids(asjobs,&retval);
                        break;
                }
                return retval;
}

/**
 *Main DRMAA Implementation
 *
 */

	char *DRMAA::get_contact(){
		char *contact = (char*)malloc(1024*sizeof(char));
		drmaa_get_contact(contact,1024,NULL,0);
		return contact;//I bet this memory leaks.
	}

	int DRMAA::init(){
		return drmaa_init(NULL,NULL,0);
	}

	int DRMAA::init(const char *contact){
		return drmaa_init(contact,NULL,0);
	}
	
	int DRMAA::exit(){
		return drmaa_exit(NULL,0);
	}

	DRMAAVector *DRMAA::get_attribute_names(){
		DRMAAVector *retval = new DRMAAVector(NAMES);
		drmaa_get_attribute_names(&(retval->asnames),NULL,0);
		return retval;
	}

	DRMAAVector *DRMAA::get_vector_attribute_names(){
		DRMAAVector *retval = new DRMAAVector(NAMES);
		drmaa_get_vector_attribute_names(&(retval->asnames),NULL,0);
		return retval;
	}

	int DRMAA::synchronize(const char *job_ids[], signed long timeout, int dispose){
		return drmaa_synchronize(job_ids,timeout,dispose,NULL,0);
	}


/**
 *Implementations for Job class
 */	

Job::Job(){
		id = (char*)malloc(JOB_ID_SIZE*sizeof(char));
	}

	Job::Job(const char* inID){
		size_t length = strlen(inID);
		id = (char*)malloc(length);
		strncpy(id,inID,length);
	}

	Job::~Job(){
		free(id);
	}	

	void Job::control(int action){
		drmaa_control(id,action,NULL,0);
	}

	int Job::ps(){
		int retval;
		drmaa_job_ps(id, &retval,NULL,0);
		return retval;
	}

/**
 *Implementations for JobTemplate
 *
 */
	JobTemplate::JobTemplate(){
		drmaa_allocate_job_template(&jt,NULL,0);
	}

	JobTemplate::~JobTemplate(){
		drmaa_delete_job_template(jt,NULL,0);
	}

	int JobTemplate::set_attribute(const char *name, const char *value){
		return drmaa_set_attribute(jt, name, value, NULL, 0);
	}

	char *JobTemplate::get_attribute(const char *name){
                int reason;
                char *retval;
                retval = (char*)malloc(1024*sizeof(char));
                reason = drmaa_get_attribute(jt,name,retval,1024,NULL,0);
                return retval;
        }

	int JobTemplate::set_vector_attribute(const char *name, const char **value){
		return drmaa_set_vector_attribute(jt,name,value,NULL,0);
        }

	DRMAAVector *JobTemplate::get_vector_attribute(const char *name){
		DRMAAVector *retval = new DRMAAVector(VALUES);

		drmaa_get_vector_attribute(jt,name,&(retval->asvalues),NULL,0);

		return retval;
	}


	Job* JobTemplate::start(){
                int reason;
                Job *retval = new Job();
                reason = drmaa_run_job(retval->id, JOB_ID_SIZE, jt, NULL, 0);
                return retval;
        }
