#include "../include/Logger.h"

namespace LOG
{
    void Logger::Init()
    {
     console_painter.Init();
    }

    void Logger::Add_logger(std::string name,FILE *out,bool file_and_console)
    {
     if(loggers.count(name)==0)
        loggers[name]=new Specialized_logger(name,&console_painter,out,file_and_console);
    }

    Specialized_logger *Logger::Get_logger(std::string name)
    {
     return loggers[name];
    }

    void Logger::Close()
    {
     for(std::unordered_map<std::string,Specialized_logger*>::iterator i=loggers.begin();i!=loggers.end();i++)
         {
          delete i->second;
         }
     loggers.clear();
    }

    Logger *Logger::instance;

    Logger *Logger::Get_instance()
    {
     if(instance==nullptr)
        instance=new Logger();
     return instance;
    }

    void Init()
    {
     Logger::Get_instance()->Init();
    }

    void Add_logger(std::string name,std::string filename,bool file_and_console)
    {
     FILE *out=fopen(filename.c_str(),"a");
     Add_logger(name,out,file_and_console);
    }

    void Add_logger(std::string name,FILE *out=NULL,bool file_and_console)
    {
     Logger::Get_instance()->Add_logger(name,out,file_and_console);
    }

    void Close();
}
