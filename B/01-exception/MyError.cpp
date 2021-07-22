
class MyError{
    const char* const data;
public:
    MyError(const char* const msg = 0) : data(msg) {}
};

void f(){
    throw MyError("something bad happend.");
}

int main(){
try{
    f();
}catch(...){
    
}
}
