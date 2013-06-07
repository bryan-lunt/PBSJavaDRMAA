#ifndef JDRMAA_HXX
#define JDRMAA_HXX

#include <drmaa.h>
#include <string.h>


enum attType {NAMES, VALUES, JOBS};
class DRMAAVector{
	public://not good style.
        attType type;
        union {
                drmaa_attr_names_t *asnames;
                drmaa_attr_values_t *asvalues;
                drmaa_job_ids_t *asjobs;
        };

        DRMAAVector(attType intype);
        ~DRMAAVector();

        char *next();
        size_t size();
};

class DRMAA{
public:
	static char *get_contact();

	static int init();
	static int init(const char *contact);
	static int exit();

	static DRMAAVector *get_attribute_names();
	static DRMAAVector *get_vector_attribute_names();

	static int synchronize(const char *job_ids[], signed long timeout, int dispose);

};

#define JOB_ID_SIZE 256
class Job{
	public:
	char *id;

	Job();
	Job(const char* inID);
	~Job();

	void control(int action);
	int ps();

};

class JobTemplate{
	private:
	drmaa_job_template_t *jt;

	public:	
	JobTemplate();
	~JobTemplate();

	int set_attribute(const char *name, const char *value);
	char *get_attribute(const char *name);

	int set_vector_attribute(const char *name, const char **value);
	DRMAAVector *get_vector_attribute(const char *name);

	Job* start();
};

#endif
