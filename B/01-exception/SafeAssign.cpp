#include <iostream>
#include <new>
#include <cstring>
#include <cstddef>

using namespace std;

class HasPointers{

    struct MyData{
	const char* theString;
	const int*  theInts;
	size_t	numInts;
	MyData(const char* pString, const int* pInts,size_t nInts):
	    theString(pString),theInts(pInts),numInts(nInts){}
    } *theData;

    static MyData* clone(const char* otherString,const int* otherInts,size_t nInts){
	char* newChars = new char[strlen(otherString) + 1];
	int* newInts;
	try{
	    newInts = new int[nInts];
	}catch(bad_alloc&){
	    delete []newChars;
	    throw;
	}

	try{
	    strcpy(newChars,otherString);
	    for(size_t i = 0; i < nInts; ++i)
		newInts[i] = otherInts[i];
	}catch(...){
	    delete[] newInts;
	    delete[] newChars;
	    throw;
	}
	return new MyData(newChars,newInts,nInts);
    }

    static MyData* clone(const MyData* otherData){
	return clone(otherData->theString,otherData->theInts,otherData->numInts);
    }

    static void cleanup(const MyData* theData){
	delete[] theData->theString;
	delete[] theData->theInts;
	delete theData;

    }
public:
    HasPointers(const char* someString,const int* someInts,size_t numInts){
	theData = clone(someString,someInts,numInts);
    }

    HasPointers(const HasPointers& source){
	theData = clone(source.theData);
    }

    HasPointers& operator=(const HasPointers& rhs){
	if(this != &rhs){
	    MyData* newData = clone(rhs.theData->theString,rhs.theData->theInts,rhs.theData->numInts);
	    cleanup(theData);
	    theData = newData;
	}
	return *this;
    }
    ~HasPointers(){cleanup(theData);}

    friend ostream& 
    operator<<(ostream& os,const HasPointers& obj){
	os << obj.theData->theString << " : ";

	for(size_t i = 0; i < obj.theData->numInts; i++)
	    os << obj.theData->theInts[i] << ' ';
	return os;

    }
};


int main(){
    int someNums[]  = {1,2,3,4};
    size_t someCount = sizeof someNums / sizeof someNums[0];

    int someMoreNum[] = {5,6,7};
    size_t someMoreCount = sizeof someMoreNum / sizeof someMoreNum[0];

    HasPointers h1("Hello",someNums,someCount);
    HasPointers h2("Goodbye",someMoreNum,someCount);

    cout << h1 << endl;

    h1 = h2;
    cout << h1 << endl;

}
