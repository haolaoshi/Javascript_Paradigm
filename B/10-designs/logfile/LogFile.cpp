#include "LogFile.h"

std::ofstream& logfile(){
    static std::ofstream log("20210808.log");
    return log;
}
