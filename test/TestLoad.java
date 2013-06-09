package test;

import cz.adamh.*;
import jdrmaa.*;
 
public class TestLoad {
   public static void main(String argv[]) throws Exception {
	//System.loadLibrary("jdrmaa");
	NativeUtils.loadLibraryFromJar("/libjdrmaa.so");

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


     DRMAA.exit();
	//System.out.println(example.getMy_variable());
     //System.out.println(example.fact(5));
     //System.out.println(example.get_time());
   }
 }
