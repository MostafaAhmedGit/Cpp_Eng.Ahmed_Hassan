#pragma once

#include <iostream>
#include <mutex>
#include <fstream>
#include <exception>
#include <stdio.h>

typedef enum {
    mFile,
    mConsole,
    mRemote
} LogMode_t;


typedef enum {
    OffLevel,
    ErrorLevel,
    WarnLevel,
    InfoLevel,
    DebugLevel
} LogLevel_t;


class CppLogger
{

    private:
        LogLevel_t logLevel;
        LogMode_t logMode;
        std::string appId;
        std::ofstream fout;

    public:

    CppLogger(std::string appId, LogLevel_t logLevel, LogMode_t logMode, std::string FileName);
    
    /*Change the Log Level during runtime */
    void SetLogLevel(std::string appId, LogLevel_t logLevel);

    /*Change the Log Mode during runtime */
    void SetLogMode(std::string appId, LogMode_t logMode);


    /*To print Logs */
     friend std::ostream &operator <<(CppLogger &logObj, const char *msg);

    /*To close the file at the end if opened Destructor*/
      
    
};
