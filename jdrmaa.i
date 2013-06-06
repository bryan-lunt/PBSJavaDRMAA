%module jdrmaa
%include "typemaps.i"
%{
#include "jdrmaa.h"
%}

%newobject DRMAA::get_contact;
%newobject JobTemplate::get_attribute;
%newobject DRMAAVector::next;

%include "jdrmaa.h"
%include "constants.h"
