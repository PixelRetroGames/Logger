#ifndef LOGGER_H
#define LOGGER_H

#include "Color.h"
#include "Specialized_logger.h"

#include <vector>
#include <unordered_map>

namespace LOG
{
    class Logger
    {
     private:
     Console_painter console_painter;
     std::unordered_map<std::string,Specialized_logger*> loggers;
     static Logger *instance;

     public:
     void Init();
     void Add_logger(std::string name,FILE *out=NULL,bool file_and_console=false);
     Specialized_logger *Get_logger(std::string name);
     void Close();
     static Logger *Get_instance();

     protected:
     Logger(){}
    };

    void Init();
    void Add_logger(std::string name,std::string filename,bool file_and_console=false);
    void Add_logger(std::string name,FILE *out=NULL,bool file_and_console=false);
};

#define LOG_INFO(name,format,...)     LOG::Logger::Get_instance()->Get_logger(name)->Info(format, ##__VA_ARGS__)
#define LOG_WARNING(name,format,...)  LOG::Logger::Get_instance()->Get_logger(name)->Warning(format, ##__VA_ARGS__)
#define LOG_ERROR(name,format,...)    LOG::Logger::Get_instance()->Get_logger(name)->Error(format, ##__VA_ARGS__)
#define LOG_CRITICAL(name,format,...) LOG::Logger::Get_instance()->Get_logger(name)->Critical(format, ##__VA_ARGS__)


#endif // LOGGER_H
