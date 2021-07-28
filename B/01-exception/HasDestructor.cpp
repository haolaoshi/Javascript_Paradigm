class HasDestructor{
public:
    ~HasDestructor(){}
};

void g();

void f(){
    HasDestructor h;
    g();
}

int main(){
    f();
}
