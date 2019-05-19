#include "LOG/LOG.h"

int f(int x)
{
 return 1+f(x);
}

int main()
{
 LOG::Init();
 LOG::Add_logger("Engine","test.txt",true);
 LOG::Add_logger("Debug","test.txt",true);
 LOG::Add_logger("Alabala","test.txt",true);
 //LOG::Add_logger("Alabalaportocala","test.txt",true);

 int sq=0;
 for(int i=0;i<10;i++)
     {
      sq+=i;
     }

 LOG_INFO("Engine","The red jumpy fox jumped over the brown weird dog");
 LOG_WARNING("Engine","music %d",sq+45);
 LOG_ERROR("Engine","sq=%d",sq);
 LOG_CRITICAL("Engine","The red jumpy fox jumped over the brown weird dog");

 LOG_INFO("Debug","Jimmy is a lonely boy who walks his hamster outside everyday");
 LOG_WARNING("Debug","music %d+%d=%d",2,3,2+3);
 //f(100);
 LOG_ERROR("Debug","sq");
 LOG_CRITICAL("Debug","test");

 LOG_ERROR("Alabala","sq");
 LOG_CRITICAL("Alabala","test");

 LOG_ERROR("Alabalaportocala","sq");
 LOG_CRITICAL("Alabalaportocala","test");

 LOG::Add_logger("prr");
 LOG::Add_logger("psi");
 LOG::Add_logger("test1");
 LOG::Add_logger("test2");
 LOG::Add_logger("test3");
 LOG::Add_logger("test4");
 LOG::Add_logger("test5");
 LOG::Add_logger("test6");
 LOG::Add_logger("test7");
 LOG::Add_logger("test8");
 LOG::Add_logger("test9");
 LOG::Add_logger("test10");
 LOG::Add_logger("test11");
 LOG::Add_logger("test12");
 LOG::Add_logger("test13");
 LOG::Add_logger("test14");
 LOG::Add_logger("test15");
 LOG::Add_logger("test16");
 LOG::Add_logger("test17");
 LOG::Add_logger("test18");
 LOG::Add_logger("Debug");

 LOG_INFO("prr","mau");
 LOG_CRITICAL("prr","MAU");

 LOG_INFO("Debug","It should not be logged");

 LOG_INFO("psi","The red jumpy fox jumped over the brown weird dog");
 LOG_WARNING("psi","music %d",sq+45);
 LOG_ERROR("psi","sq=%d",sq);
 LOG_CRITICAL("psi","The red jumpy fox jumped over the brown weird dog");

 LOG_INFO("test1","The red jumpy fox jumped over the brown weird dog");
 LOG_WARNING("test1","music %d",sq+45);
 LOG_ERROR("test1","sq=%d",sq);
 LOG_CRITICAL("test1","The red jumpy fox jumped over the brown weird dog");

 LOG_INFO("test2","The red jumpy fox jumped over the brown weird dog");
 LOG_WARNING("test2","music %d",sq+45);
 LOG_ERROR("test2","sq=%d",sq);
 LOG_CRITICAL("test2","The red jumpy fox jumped over the brown weird dog");

 LOG_INFO("test3","The red jumpy fox jumped over the brown weird dog");
 LOG_WARNING("test3","music %d",sq+45);
 LOG_ERROR("test3","sq=%d",sq);
 LOG_CRITICAL("test3","The red jumpy fox jumped over the brown weird dog");

 LOG_INFO("test4","The red jumpy fox jumped over the brown weird dog");
 LOG_WARNING("test4","music %d",sq+45);
 LOG_ERROR("test4","sq=%d",sq);
 LOG_CRITICAL("test4","The red jumpy fox jumped over the brown weird dog");

 LOG_INFO("test5","The red jumpy fox jumped over the brown weird dog");
 LOG_WARNING("test5","music %d",sq+45);
 LOG_ERROR("test5","sq=%d",sq);
 LOG_CRITICAL("test5","The red jumpy fox jumped over the brown weird dog");

 LOG_INFO("test6","The red jumpy fox jumped over the brown weird dog");
 LOG_WARNING("test6","music %d",sq+45);
 LOG_ERROR("test6","sq=%d",sq);
 LOG_CRITICAL("test6","The red jumpy fox jumped over the brown weird dog");

 LOG_INFO("test7","The red jumpy fox jumped over the brown weird dog");
 LOG_WARNING("test7","music %d",sq+45);
 LOG_ERROR("test7","sq=%d",sq);
 LOG_CRITICAL("test7","The red jumpy fox jumped over the brown weird dog");

 LOG_INFO("test8","The red jumpy fox jumped over the brown weird dog");
 LOG_WARNING("test8","music %d",sq+45);
 LOG_ERROR("test8","sq=%d",sq);
 LOG_CRITICAL("test8","The red jumpy fox jumped over the brown weird dog");

 //------

 LOG_INFO("test9","The red jumpy fox jumped over the brown weird dog");
 LOG_WARNING("test9","music %d",sq+45);
 LOG_ERROR("test9","sq=%d",sq);
 LOG_CRITICAL("test9","The red jumpy fox jumped over the brown weird dog");

 LOG_INFO("test10","The red jumpy fox jumped over the brown weird dog");
 LOG_WARNING("test10","music %d",sq+45);
 LOG_ERROR("test10","sq=%d",sq);
 LOG_CRITICAL("test10","The red jumpy fox jumped over the brown weird dog");

 LOG_INFO("test11","The red jumpy fox jumped over the brown weird dog");
 LOG_WARNING("test11","music %d",sq+45);
 LOG_ERROR("test11","sq=%d",sq);
 LOG_CRITICAL("test11","The red jumpy fox jumped over the brown weird dog");

 LOG_INFO("test12","The red jumpy fox jumped over the brown weird dog");
 LOG_WARNING("test12","music %d",sq+45);
 LOG_ERROR("test12","sq=%d",sq);
 LOG_CRITICAL("test12","The red jumpy fox jumped over the brown weird dog");

 LOG_INFO("test13","The red jumpy fox jumped over the brown weird dog");
 LOG_WARNING("test13","music %d",sq+45);
 LOG_ERROR("test13","sq=%d",sq);
 LOG_CRITICAL("test13","The red jumpy fox jumped over the brown weird dog");

 LOG_INFO("test14","The red jumpy fox jumped over the brown weird dog");
 LOG_WARNING("test14","music %d",sq+45);
 LOG_ERROR("test14","sq=%d",sq);
 LOG_CRITICAL("test14","The red jumpy fox jumped over the brown weird dog");

 LOG_INFO("test15","The red jumpy fox jumped over the brown weird dog");
 LOG_WARNING("test15","music %d",sq+45);
 LOG_ERROR("test15","sq=%d",sq);
 LOG_CRITICAL("test15","The red jumpy fox jumped over the brown weird dog");

 LOG_INFO("test16","The red jumpy fox jumped over the brown weird dog");
 LOG_WARNING("test16","music %d",sq+45);
 LOG_ERROR("test16","sq=%d",sq);
 LOG_CRITICAL("test16","The red jumpy fox jumped over the brown weird dog");

 LOG_INFO("test17","The red jumpy fox jumped over the brown weird dog");
 LOG_WARNING("test17","music %d",sq+45);
 LOG_ERROR("test17","sq=%d",sq);
 LOG_CRITICAL("test17","The red jumpy fox jumped over the brown weird dog");

 LOG_INFO("test18","The red jumpy fox jumped over the brown weird dog");
 LOG_WARNING("test18","music %d",sq+45);
 LOG_ERROR("test18","sq=%d",sq);
 LOG_CRITICAL("test18","The red jumpy fox jumped over the brown weird dog");

 LOG::Close();

 return 0;
}
