#include "log.hpp"
#include <thread>

CppLogger App1("AppId1", ErrorLevel, mFile, "LoggerFile");
CppLogger App2("AppId2", ErrorLevel, mFile, "LoggerFile");

void log(int th) {

    if (th == 0)
     { /* thread one is processing now */

        App1 << "hello From Text File ";

        App1.SetLogLevel("AppId1", DebugLevel); /* try to test log level */
        App1 << "hello From new Log Level";

        App1.SetLogMode("AppId1", mConsole); /* try to test log Mode */
        App1 << "hello From Command Line ";


    } else if (th == 1) { /* thread two is processing now */

        App2 << "hello From Text File ";

        App2.SetLogLevel("AppId2", ErrorLevel); /* try to test log level */
        App2 << "hello From new Log Level";

        App2.SetLogMode("AppId2", mConsole);  /* try to test log Mode */
        App2 << "hello From Command Line ";

    }

}

int main(void)
{

    std::thread thread1(log, 0); /* create thread 1 */
    std::thread thread2(log, 1); /* create thread 2 */

    thread1.join();
    thread2.join();
    
    return 0;

}