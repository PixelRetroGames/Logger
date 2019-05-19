#include "../include/Specialized_logger.h"

namespace LOG
{
    const int INFO_COLOR=TEXT_WHITE|TEXT_INTENSITY,WARNING_COLOR=TEXT_YELLOW|TEXT_INTENSITY,ERROR_COLOR=TEXT_RED|TEXT_INTENSITY,CRITICAL_COLOR=BG_RED|BG_INTENSITY;

    const int Specialized_logger::name_colors[NUMBER_OF_NAME_COLORS]={TEXT_GREEN,TEXT_MAGENTA,TEXT_CYAN,TEXT_BLUE,BG_GREEN,BG_MAGENTA,BG_CYAN,BG_BLUE,BG_INTENSITY|TEXT_INTENSITY|TEXT_GREEN,
                                                   BG_INTENSITY|TEXT_INTENSITY|TEXT_MAGENTA,BG_INTENSITY|TEXT_INTENSITY|TEXT_CYAN,BG_INTENSITY|TEXT_INTENSITY|TEXT_BLUE,
                                                   TEXT_INTENSITY|TEXT_GREEN,TEXT_INTENSITY|TEXT_MAGENTA,TEXT_INTENSITY|TEXT_CYAN,TEXT_INTENSITY|TEXT_BLUE};

    int Specialized_logger::longest_name_length=0;

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

    void Specialized_logger::Reset_longest_name_length()
    {
     longest_name_length=0;
    }

    void Specialized_logger::Print(int col,std::string message,const char *format,va_list args)
    {
     if(this==nullptr)
        return;
     char timestamp[100];
     Get_current_time(timestamp);

     const int MESSAGE_LONGEST_LENGTH=8;
     std::string spaces_name,spaces_message;
     for(int i=0;i<longest_name_length;i++)
         spaces_name+=' ';
     for(int i=0;i<MESSAGE_LONGEST_LENGTH;i++)
         spaces_message+=' ';

     if(out==NULL || print_in_both)
        {
         console_painter->Change_color(name_colors[name_color]);
         //console_painter->Change_color(TEXT_BLUE|TEXT_INTENSITY);
         fprintf(stderr,"[%s]",timestamp);

         console_painter->Reset_color();
         fprintf(stderr," ");
         console_painter->Change_color(name_colors[name_color]);

         fprintf(stderr,"[%s]",name.c_str());
         console_painter->Reset_color();
         fprintf(stderr,"%s ",spaces_name.c_str()+name.length());
         console_painter->Change_color(col);
         fprintf(stderr,"[%s]%s",message.c_str(),spaces_message.c_str()+message.length());
         console_painter->Reset_color();
         fprintf(stderr," ");
         console_painter->Change_color(col);
         vfprintf(stderr,format,args);
         fprintf(stderr,"\n");
         console_painter->Reset_color();
        }
     if(out!=NULL || print_in_both)
        {
         fprintf(out,"[%s] ",timestamp);
         fprintf(out," [%s]%s ",name.c_str(),spaces_name.c_str()+name.length());
         fprintf(out,"[%s]%s ",message.c_str(),spaces_message.c_str()+message.length());
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
     strftime(ret,100,"%Y-%m-%d %H:%M:%S",now);
     sprintf(ret,"%s.%.3d",ret,milliseconds);
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
