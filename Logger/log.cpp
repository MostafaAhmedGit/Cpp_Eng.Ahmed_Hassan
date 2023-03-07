#include "log.hpp"


std::mutex log_mutex;



CppLogger::CppLogger(std::string appId, LogLevel_t logLevel, LogMode_t logMode, std::string FileName)
{
    try {

    this->appId=appId;
    this->logLevel=logLevel;
    this->logMode=logMode;

    if(logMode==mFile)
    {
        fout.open(FileName + ".txt", std::ios::app);
    } 
}
catch (...) {
  std::cout<<"no input file name";
}



}

void CppLogger::SetLogLevel(std::string appId, LogLevel_t logLevel)
{
    this->appId = appId;
    this->logLevel=logLevel;
}

void CppLogger::SetLogMode(std::string appId, LogMode_t logMode)
{
    this->appId = appId;
    this->logMode=logMode;
}

std::ostream &operator <<(CppLogger &logObj, const char *msg)
{

    // To make sure only 1 thread is on the bus 
    std::lock_guard<std::mutex> guard(log_mutex);  

        time_t tmNow = time(NULL);
    struct tm my_time = *localtime(&tmNow);
    /* to return time stamp (current time) */

    static int16_t counterA = 0;  /* count when App1 enter this function */
    static int16_t counterB = 0;  /* count when App2 enter this function */
    static int16_t counter = 0;   /* generic counter get value of current APP counter to print it for user*/


       if (logObj.appId == "AppId1") { /* Here app1 (Thread 1) enter func */
        counterA++;
        // counter = counterA;

    } else if (logObj.appId == "AppId2") { /* Here app2 (Thread 2) enter func */
        counterB++;
        // counter = counterB;
    } else {
        std::cout<<"Wrong App Id, Ensure that the AppId ";
    }

    if(logObj.logMode==mConsole)
    {
        switch(logObj.logLevel)
        {
            case OffLevel:
            if(logObj.appId=="AppId1")
                std::cout << "| " << my_time.tm_hour << ":" << my_time.tm_min << ":" << my_time.tm_sec << " |" <<
                logObj.appId << " | " << counterA << " | " << "lOff" << " | " << msg << std::endl;

            else if(logObj.appId=="AppId2")
                std::cout << "| " << my_time.tm_hour << ":" << my_time.tm_min << ":" << my_time.tm_sec << " |" <<
                logObj.appId << " | " << counterB << " | " << "lOff" << " | " << msg << std::endl;
            break;

            case ErrorLevel:
            if(logObj.appId=="AppId1")
                std::cout << "| " << my_time.tm_hour << ":" << my_time.tm_min << ":" << my_time.tm_sec << " |" <<
                logObj.appId << " | " << counterA << " | " << "ErrorLevel" << " | " << msg << std::endl;
                
            else if(logObj.appId=="AppId2")
                std::cout << "| " << my_time.tm_hour << ":" << my_time.tm_min << ":" << my_time.tm_sec << " |" <<
                logObj.appId << " | " << counterB << " | " << "ErrorLevel" << " | " << msg << std::endl;
            break;

            case InfoLevel:
            if(logObj.appId=="AppId1")
                std::cout << "| " << my_time.tm_hour << ":" << my_time.tm_min << ":" << my_time.tm_sec << " |" <<
                logObj.appId << " | " << counterA << " | " << "InfoLevel" << " | " << msg << std::endl;
                
            else if(logObj.appId=="AppId2")
                std::cout << "| " << my_time.tm_hour << ":" << my_time.tm_min << ":" << my_time.tm_sec << " |" <<
                logObj.appId << " | " << counterB << " | " << "InfoLevel" << " | " << msg << std::endl;
            break;

            case DebugLevel:
            if(logObj.appId=="AppId1")
                std::cout << "| " << my_time.tm_hour << ":" << my_time.tm_min << ":" << my_time.tm_sec << " |" <<
                logObj.appId << " | " << counterA << " | " << "DebugLevel" << " | " << msg << std::endl;
                
            else if(logObj.appId=="AppId2")
                std::cout << "| " << my_time.tm_hour << ":" << my_time.tm_min << ":" << my_time.tm_sec << " |" <<
                logObj.appId << " | " << counterB << " | " << "DebugLevel" << " | " << msg << std::endl;
            break;

        }
    }

    else if(logObj.logMode==mFile)
    {
        switch(logObj.logLevel)
        {
            case OffLevel:
                logObj.fout << "| " << my_time.tm_hour << ":" << my_time.tm_min << ":" << my_time.tm_sec << " |" <<
                logObj.appId << " | " << counter << " | " << "lOff" << " | " << msg << std::endl;
            break;
            
            case ErrorLevel:

                logObj.fout << "| " << my_time.tm_hour << ":" << my_time.tm_min << ":" << my_time.tm_sec << " |" <<
                            logObj.appId << " | " << counter << " | " << "lError" << " | " << msg << std::endl;
                break;

            case WarnLevel:

                logObj.fout << "| " << my_time.tm_hour << ":" << my_time.tm_min << ":" << my_time.tm_sec << " |" <<
                            logObj.appId << " | " << counter << " | " << "lWarn" << " | " << msg << std::endl;
                break;

            case InfoLevel:

                logObj.fout << "| " << my_time.tm_hour << ":" << my_time.tm_min << ":" << my_time.tm_sec << " |" <<
                            logObj.appId << " | " << counter << " | " << "lInfo" << " | " << msg << std::endl;
                break;

            case DebugLevel:

                logObj.fout << "| " << my_time.tm_hour << ":" << my_time.tm_min << ":" << my_time.tm_sec << " |" <<
                            logObj.appId << " | " << counter << " | " << "lDebug" << " | " << msg << std::endl;
                break;
    }
    }

    return std::cout;
}
