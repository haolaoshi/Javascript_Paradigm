#ifndef REQUIRE.H
#define REQUIRE.H

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>

inline void require(bool requirement,const std::string& msg = "Require failed")
{
    using namespace std;
    if(!requirement){
	fputs(msg.c_str(), stderr);
	fputs("\n",stderr);
	exit(1);
    }
}


inline void requireArgs(int argc,int args,const std::string& msg= "Must use %d arg")
{
    using namespace std;
    if(argc != args + 1){
	fprintf(stderr,msg.c_str(),args);
	fputs("\n",stderr);
	exit(1);
    }
}

inline void requireMinArgs(int argc,int minArgs,const std::string& msg="Must use at least %d arg")
{
    using namespace std;
    if(argc < minArgs){
	fprintf(stderr,msg.c_str() , minArgs);
	fputs("\n",stderr);
	exit(1);
    }
}

inline void assure(std::ifstream& in, const std::string& filename = "")
{
    using namespace std;
    if(!in){
	fprintf(stderr,"could not openf ile %s\n",filename.c_str());
	exit(1);
    }

}

inline void assure(std::ofstream& out, const std::string& filename = "" )
{
    using namespace std;
    if(!out){
	fprintf(stderr,"could not open file %s\n",filename.c_str());
	exit(1);
    }
}


#endif

