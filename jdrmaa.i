%module jdrmaa

%include "typemaps.i"

#if defined(SWIGJAVA)
        %include "jdrmaa_typemaps_java.i"
#else
        #warning No SWIG typemaps for this target language!!!!
#endif

%{
#include "jdrmaa.hxx"
%}


/**
 *These are true regardless of the target language.
 */

%newobject DRMAA::get_contact;
%newobject JobTemplate::get_attribute;
%newobject DRMAAVector::next;

%include "jdrmaa.hxx"
%include "constants.h"
