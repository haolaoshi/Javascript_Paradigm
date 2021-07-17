
void t(int *){}

void u(const int* cip){
//   *cip = 2;
   int i = *cip;
//   int *ci = cip;
}

const char* v(){
    return "result ";
}

const int* const w(){
    static int i ;
    return &i;
}

int main(){
    int x = 0;
    int* ip = &x;

    const int* cip = &x;
    t(ip);

//    t(cip);    
    u(ip);
    u(cip);

    const char* cp = v();
    const int* const b = w();

    *w() = 1;
}
