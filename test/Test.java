package test;

import jdrmaa.*;
 
public class Test {
   public static void main(String argv[]) {
	System.loadLibrary("jdrmaa");

     System.out.println(DRMAA.get_contact());

     DRMAA.init();

     DRMAAVector attNames = DRMAA.get_attribute_names();
     for(int i = 0;i < attNames.size();i++){
	System.out.println("Has Attribute :" + attNames.next());
}


     JobTemplate jt = new JobTemplate();
     jt.set_attribute("drmaa_remote_command","/tmp/test.sh");
     jt.set_attribute("drmaa_job_name","Job Submit from DRMAA");
     jt.set_attribute("drmaa_v_env","BRYAN=thisisamessage");
     System.out.println(jt.get_attribute("drmaa_job_name"));
     Job newJob = jt.start();
     System.out.println(newJob.getId());

     DRMAA.exit();
	//System.out.println(example.getMy_variable());
     //System.out.println(example.fact(5));
     //System.out.println(example.get_time());
   }
 }
