package test;

import jdrmaa.*;
 
public class Test {
   public static void main(String argv[]) {
	System.loadLibrary("jdrmaa");
     jdrmaa.drmaa_init(null,null,0);

     drmaa_job_template_s myTemplate = new drmaa_job_template_s();
     myTemplate.set_attribute("drmaa_remote_command","/tmp/test.sh");
     myTemplate.set_attribute("drmaa_job_name","Job Submit from DRMAA");
     System.out.println(myTemplate.get_attribute("drmaa_job_name"));
     System.out.println(myTemplate.start());

	//System.out.println(example.getMy_variable());
     //System.out.println(example.fact(5));
     //System.out.println(example.get_time());
   }
 }
