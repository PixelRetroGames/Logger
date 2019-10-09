#ifndef LOG_QUERY_H
#define LOG_QUERY_H

#include <string>
#include <cstdarg>

namespace LOG
{
    enum Log_type {LT_INFO,LT_WARNING,LT_ERROR,LT_CRITICAL};

    struct Log_query
    {
     std::string name;
     Log_type type;
     int color;
     std::string message;
     const char *format;
     va_list args;
    };

    Log_query Make_log_query(std::string name,Log_type type,const char *format,...);

    int Get_number_of_arguments(const char *format);
}

#endif // LOG_QUERY_H
