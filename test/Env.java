package test;

import jdrmaa.*;
 
public class Env {
   public static void main(String argv[]) {
	System.loadLibrary("jdrmaa");

     System.out.println(DRMAA.get_contact());

     DRMAA.init();

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


     DRMAA.exit();
	//System.out.println(example.getMy_variable());
     //System.out.println(example.fact(5));
     //System.out.println(example.get_time());
   }
 }
