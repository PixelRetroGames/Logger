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

 int sq=0;
 for(int i=0;i<10;i++)
     {
      sq+=i;
     }

 LOG_INFO("Engine","seek");
 LOG_WARNING("Engine","music %d+%d=%d",2,3,2+3);
 LOG_ERROR("Engine","sq=%d",sq);
 LOG_CRITICAL("Engine","test");

 LOG_INFO("Debug","seek");
 LOG_WARNING("Debug","music %d+%d=%d",2,3,2+3);
 //f(100);
 LOG_ERROR("Debug","sq");
 LOG_CRITICAL("Debug","test");

 LOG::Logger::Get_instance()->Close();
}
