%module drmaa
%{
#include "drmaa_impl_stolen.h"
#include <drmaa.h>
%}

%rename(JobTemplate) drmaa_job_template_s;

%include "drmaa_impl_stolen.h"
%include <drmaa.h>
%extend drmaa_job_template_s {
        int foobar(){
                return 5555;
        }
};
