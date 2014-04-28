package test;

import jdrmaa.*;
 
public class Test {
   public static void main(String argv[]) throws Exception {
	System.loadLibrary("jdrmaa");

     System.out.println(DRMAA.get_contact());

     DRMAA.init(argv.length > 0 ? argv[0] : null);

     DRMAAVector attNames = DRMAA.get_attribute_names();
	System.out.println("Your DRMAA system has the following attributes.");
	System.out.println("####");
     for(int i = 0;i < attNames.size();i++){
	System.out.println(attNames.next());
}
	System.out.println("####");

     attNames = DRMAA.get_vector_attribute_names();
        System.out.println("Your DRMAA system has the following vector attributes.");
        System.out.println("####");
     for(int i = 0;i < attNames.size();i++){
        System.out.println(attNames.next());
}
        System.out.println("####");



     JobTemplate jt = new JobTemplate();
     jt.set_attribute("drmaa_remote_command","$HOME/test.sh");
     jt.set_attribute("drmaa_job_name","Job_Submit_from_DRMAA");
     String[] foo = {"BRYAN=thisisamessage"};
	jt.set_vector_attribute("drmaa_v_env",foo);
     System.out.println(jt.get_attribute("drmaa_job_name"));
     System.out.println(jt.get_attribute("drmaa_output_path"));
     Job newJob = jt.start();

     System.out.println(newJob.getId());
     System.out.println("" + newJob.ps());

     DRMAA.exit();
	//System.out.println(example.getMy_variable());
     //System.out.println(example.fact(5));
     //System.out.println(example.get_time());
   }
 }
