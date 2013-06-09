#ifndef JDRMAA_HXX
#define JDRMAA_HXX

/**
 
This file is part of PBSJavaDRMAA.

(C) June 2013 by Bryan J. Lunt <blunt@cs.ucsd.edu>

    PBSJavaDRMAA is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    PBSJavaDRMAA is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with PBSJavaDRMAA.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <drmaa.h>
#include <string.h>


#include <exception>

class DRMAAException: public std::exception
{
	char *msg;
	public:
	DRMAAException(const char *in) throw(){
		int inLen = strlen(in);
		msg = (char*)malloc(inLen*sizeof(char));
		strncpy(msg,in,inLen);
	}
	~DRMAAException() throw(){
		free(msg);
	}
	virtual const char* what() const throw(){
		return msg;
	}
};

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

	static int init(const char *contact) throw(DRMAAException);
	static int init() throw(DRMAAException) { return init(NULL); }
	static int exit() throw(DRMAAException);

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
