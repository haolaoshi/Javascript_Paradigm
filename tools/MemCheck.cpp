#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstddef>

using namespace std;
#undef new

bool traceFlag = true;
bool activeFlag = false;

namespace {

struct info{
    void* ptr;
    const char* file;
    long line;
};

const size_t MAXPTRS = 10000u;
info memMap[MAXPTRS];
size_t nptrs = 0;

int findPtr(void* p){
    for(size_t i = 0; i < nptrs; ++i)
	if(memMap[i].ptr == p)
	    return i;
    return -1;
}

void delPtr(void* p){
    int pos = findPtr(p);
    assert(pos >= 0);
    for(size_t i = pos ; i < nptrs; i++)
	memMap[i] = memMap[i+1];
    --nptrs;
}

void showline(const char* file, long line){
    FILE *f = fopen(file,"r");
    if(!f){
	printf("cannot open file %s\n",file);
	exit(2);
    }
    int c = EOF;
    while((line > 1) && ((c = fgetc(f)) != EOF)){
	if(c == '\n') line--;
    }
    printf("\033[0;31m");
    for(c =0 ; c != EOF && c != '\n'; c = fgetc(f))
	putchar(c);
    printf("\033[0m");
    printf("\nPlease check Grammar this line use your hand.\n");
}

struct Sentis{
    ~Sentis(){
	if(nptrs > 0){
	    printf("\033[0;33m");
	    printf("Leaked mem at : \n");
	    for(size_t i = 0; i < nptrs; i++){
		printf("\t%p (file: %s.  line%ld) \n",
		    memMap[i].ptr,memMap[i].file,memMap[i].line);
		showline(memMap[i].file,memMap[i].line);
	    }
	    printf("\033[0m");
	}else{
	    printf("\033[0;36m");
	    printf("No user mem leaks.\n");
	    printf("\033[0m");
	}
    }

};

Sentis s;


}

void *operator new(size_t siz, const char* file, long line){
    void *p = malloc(siz);
    if(activeFlag){
	if(nptrs == MAXPTRS){
	    printf("mem map too small (increase MAXPTRS ) \n");
	    exit(1);
	}
	memMap[nptrs].ptr = p;
	memMap[nptrs].file = file;
	memMap[nptrs].line = line;
	++nptrs;
    }
    if(traceFlag){
	printf("Allocated %u bytes at addr %p", siz, p);
	printf("(file %s, line %ld) \n", file, line);
    }
    return p;
}


void* operator new[](size_t siz, const char* file, long line){
    return operator new(siz,file,line);
}

void operator delete(void* p){
    if(findPtr(p) >= 0){
	free(p);
	assert(nptrs >= 0);
	delPtr(p);
	if(traceFlag)
	    printf("Deleted mem at address %p\n",p);
    }else{
	printf("attem to del unknown pointer : %p \n",p);
    }



}

void operator delete[] (void *p){
    operator delete(p);
}


