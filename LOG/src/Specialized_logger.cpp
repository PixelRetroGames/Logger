#include "../include/Specialized_logger.h"

namespace LOG
{

    const int INFO_COLOR=TEXT_WHITE|TEXT_INTENSITY,WARNING_COLOR=TEXT_YELLOW|TEXT_INTENSITY,ERROR_COLOR=TEXT_RED|TEXT_INTENSITY,CRITICAL_COLOR=BG_RED|BG_INTENSITY;

    void Specialized_logger::Info(const char *format,...)
    {
     int n_args=Get_number_of_arguments(format);
     va_list args;
     va_start(args,n_args);
     Print(INFO_COLOR,"info",format,args);
    }
    void Specialized_logger::Warning(const char *format,...)
    {
     int n_args=Get_number_of_arguments(format);
     va_list args;
     va_start(args,n_args);
     Print(WARNING_COLOR,"warning",format,args);
    }

    void Specialized_logger::Error(const char *format,...)
    {
     int n_args=Get_number_of_arguments(format);
     va_list args;
     va_start(args,n_args);
     Print(ERROR_COLOR,"error",format,args);
    }

    void Specialized_logger::Critical(const char *format,...)
    {
     int n_args=Get_number_of_arguments(format);
     va_list args;
     va_start(args,n_args);
     Print(CRITICAL_COLOR,"critical",format,args);
    }

    void Specialized_logger::Print(int col,std::string message,const char *format,va_list args)
    {
     char timestamp[100];
     Get_current_time(timestamp);
     if(out==NULL || print_in_both)
        {
         console_painter->Change_color(col);
         fprintf(stderr,"[%s] ",timestamp);
         fprintf(stderr,"[%s] ",name.c_str());
         fprintf(stderr,"[%s] ",message.c_str());
         vfprintf(stderr,format,args);
         fprintf(stderr,"\n");
         console_painter->Reset_color();
        }
     if(out!=NULL || print_in_both)
        {
         fprintf(out,"[%s] ",timestamp);
         fprintf(out,"[%s] ",name.c_str());
         fprintf(out,"[%s] ",message.c_str());
         vfprintf(out,format,args);
         fprintf(out,"\n");
         fflush(out);
        }
    }

    void Specialized_logger::Get_current_time(char *ret)
    {
     timeval curTime;
     gettimeofday(&curTime,NULL);
     int milliseconds=curTime.tv_usec/1000;

     time_t raw;
     time(&raw);
     tm *now=localtime(&raw);
     int sq=strftime(ret,100,"%Y-%m-%d %H:%M:%S",now);
     sprintf(ret,"%s.%d",ret,milliseconds);
    }

    int Specialized_logger::Get_number_of_arguments(const char *format)
    {
     int i=0,ret=0;
     while(format[i]!=NULL)
           {
            if(format[i]=='%')
               ret++;
            i++;
           }
     return ret;
    };
}
