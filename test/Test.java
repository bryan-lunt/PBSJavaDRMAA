package test;

import jdrmaa.*;
 
public class Test {
   public static void main(String argv[]) {
	System.loadLibrary("jdrmaa");
     DRMAA.init();

     JobTemplate jt = new JobTemplate();
     jt.set_attribute("drmaa_remote_command","/tmp/test.sh");
     jt.set_attribute("drmaa_job_name","Job Submit from DRMAA");
     System.out.println(jt.get_attribute("drmaa_job_name"));
     Job newJob = jt.start();
     System.out.println(newJob.getId());

     DRMAA.exit();
	//System.out.println(example.getMy_variable());
     //System.out.println(example.fact(5));
     //System.out.println(example.get_time());
   }
 }
