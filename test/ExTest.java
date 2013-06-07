package test;

import jdrmaa.*;
 
public class ExTest {
   public static void main(String argv[]) {
	System.loadLibrary("jdrmaa");

     System.out.println(DRMAA.get_contact());
try{
     int foobar = DRMAA.init("bad value!");
     foobar = DRMAA.init("secondtime!");
	System.out.println("retcode : " + foobar);
}catch(DRMAAException e){
	System.out.println("A DRMAAException was raised on attempt to call DRMAA.init");
	e.printStackTrace();
	System.exit(1);
}


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

try{
     DRMAA.exit();
}catch(DRMAAException e) { System.out.println("Difficulty Exiting");}
	//System.out.println(example.getMy_variable());
     //System.out.println(example.fact(5));
     //System.out.println(example.get_time());
   }
 }
