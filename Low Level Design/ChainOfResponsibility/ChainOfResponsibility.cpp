// APPLICATION USAGE :
// 1. ATM / VENDING MACHINE
// 2. DESIGN LOGGER
#include <bits/stdc++.h>
using namespace std;

class LogProcessor
{
public:
    const static int INFO = 1;
    const static int DEBUG = 2;
    const static int ERROR = 3;

    LogProcessor *nextLoggerProcesssor;

    LogProcessor(LogProcessor *loggerProcessor)
    {
        this->nextLoggerProcesssor = loggerProcessor;
    }

    virtual void log(int loglevel, string message)
    {
        if (nextLoggerProcesssor)
        {
            nextLoggerProcesssor->log(loglevel, message);
        }
    }
};

class InfoLogProccessor : public LogProcessor
{
public:
    InfoLogProccessor(LogProcessor *nextLogProcessor) : LogProcessor(nextLogProcessor)
    {
    }

    void log(int loglevel, string message) override
    {
        if (loglevel == INFO)
        {
            cout << "INFO : " << message << endl;
        }
        else
        {
            LogProcessor ::log(loglevel, message);
        }
    }
};

class DebugLogProccessor : public LogProcessor
{
public:
    DebugLogProccessor(LogProcessor *nextLogProcessor) : LogProcessor(nextLogProcessor) {}

    void log(int loglevel, string message) override
    {
        if (loglevel == DEBUG)
            cout << "DEBUG : " << message << endl;
        else
            LogProcessor ::log(loglevel, message);
    }
};

class ErrorLogProcessor : public LogProcessor
{
public:
    ErrorLogProcessor(LogProcessor *nextLogProcessor) : LogProcessor(nextLogProcessor) {}

    void log(int loglevel, string message) override
    {
        if (loglevel == ERROR)
            cout << "ERROR : " << message << endl;
        else
            LogProcessor ::log(loglevel, message);
    }
};

int main()
{
    LogProcessor *logger = new InfoLogProccessor(new DebugLogProccessor(new ErrorLogProcessor(NULL)));

    logger->log(LogProcessor::ERROR, "exception happens");
    logger->log(LogProcessor::DEBUG, "need to debug this");
    logger->log(LogProcessor::INFO, "just for info");

    return 0;
}
