


const int* u;
int d = 100;
int* const w = &d;

const int* const x = &d;
int const* const x2 = &d;


class X{
    int i;
public:
    X(int i = 0 );
    void modify();
};

X::X(int ii ) { i = ii; }
void X::modify(){ i++; }

X f5(){
    return X();
}

const X  f6(){
    return X();
}

void f7(X &x){
    x.modify();
}

int main()
{
    f5() = X(1); // lvalue
    f5().modify();

//    f7(f5());
    f6() = X(2);
    f6().modify();
//    f7(f6());
}
