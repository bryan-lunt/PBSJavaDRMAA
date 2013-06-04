#include <drmaa.h>


class DRMAA{
public:
	static char *get_contact(){
		char *contact = (char*)malloc(1024*sizeof(char));
		drmaa_get_contact(contact,1024,NULL,0);
		return contact;//I bet this memory leaks.
	}

	static int init(){
		return drmaa_init(NULL,NULL,0);
	}

	static int init(const char *contact){
		return drmaa_init(contact,NULL,0);
	}
	
	static int exit(){
		return drmaa_exit(NULL,0);
	}

	static void control(const char *job_id, int action){
		drmaa_control(job_id,action,NULL,0);
	}

	static int job_ps(const char *job_id){
		int retval;
		drmaa_job_ps(job_id, &retval,NULL,0);
		return retval;
	}

	static int synchronize(const char *job_ids[], signed long timeout, int dispose){
		return drmaa_synchronize(job_ids,timeout,dispose,NULL,0);
	}

	//static int wait(const char *job_id
};

#define JOB_ID_SIZE 256
class Job{
	public:
	char *id;

	Job(){
		id = (char*)malloc(JOB_ID_SIZE*sizeof(char));
	}

	~Job(){
		free(id);
	}	

};

class JobTemplate{
	private:
	drmaa_job_template_t *jt;

	public:	
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
                retval = (char*)malloc(1024*sizeof(char));
                reason = drmaa_get_attribute(jt,name,retval,1024,NULL,0);
                return retval;
        }

	int set_vector_attribute(const char *name, const char *value[]){
           return drmaa_set_vector_attribute(jt,name,value,NULL,0);
        }

	/*
 *         drmaa_attr_values_t *get_vector_attribute(const char *name){
 *                         drmaa_attr_values_t *values;
 *                                         drmaa_get_vector_attribute($self,name,&values,NULL,0);
 *                                                         return values;
 *                                                                 }
 *      */

	Job* start(){
                int reason;
                Job *retval = new Job();
                reason = drmaa_run_job(retval->id, JOB_ID_SIZE, jt, NULL, 0);
                return retval;
        }
};
