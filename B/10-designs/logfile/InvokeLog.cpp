#include "UserLog1.h"
#include "LogFile.h"

using namespace std;

void g(){
    logfile() << __FILE__<< endl;
}

int main(){

    f();
    g();
}
