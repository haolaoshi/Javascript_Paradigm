#include <iostream>
#include <vector>


using namespace std;


class Security{
protected:
    enum { BASEID = 0 };
public:
    virtual ~Security(){}
    virtual bool isA(int id){ return (id == BASEID); }
};


class Stock : public Security{
    typedef Security Super;
protected:
    enum { OFFSET = 1, TYPEID = BASEID + OFFSET };
public:
    bool isA(int id){
        return id == TYPEID || Super::isA(id);
    }
    static Stock* dynacast(Security* s){
        return (s->isA(TYPEID)) ? static_cast<Stock*>(s) : 0;
    }
};

class Bond : public Security{
    typedef Security Super;
protected:
    enum {OFFSET = 2, TYPEID = BASEID + OFFSET};
public:
    bool isA(int id){
        return id == TYPEID || Super::isA(id);
    }
    static Bond* dynacast(Security* s){
        return (s->isA(TYPEID)) ? static_cast<Bond*>(s) : 0;
    }
};

class Investment : public Security{
    typedef Security Super;
protected:
    enum { OFFSET = 3 , TYPEID = OFFSET + BASEID};
public:
    bool isA(int id) {
        return id == TYPEID || Super::isA(id);
    }

    static Investment* dynacast(Security *s){
        return (s->isA(TYPEID)) ? static_cast<Investment*>(s) : 0;
    }

    void special(){
        cout << " special investment fun. " << endl;
    }

};

class Metal : public Investment{
    typedef Investment Super;
protected:
    enum { OFFSET = 4, TYPEID = BASEID + OFFSET};
public:
    bool isA(int id){
        return (TYPEID == id) || Super::isA(id);
    }
    static Metal* dynacast(Security* s){
        return (s->isA(TYPEID)) ? static_cast<Metal*>(s) : 0;
    }
};

int main(){
    vector<Security*> potfolio;
    potfolio.push_back(new Metal);
    potfolio.push_back(new Investment);
    potfolio.push_back(new Bond);
    potfolio.push_back(new Stock);
    

    for(vector<Security*>::iterator it = potfolio.begin();
        it != potfolio.end(); it++){
        Investment* cm = Investment::dynacast(*it);
        if(cm)
            cm->special();
        else
            cout << " not a invest . " << endl;
    }
    cout << " cast from invtermediate pointer : " << endl;
    Security* sp = new Metal;
    Investment* cp = Investment::dynacast(sp);

    if(cp) cout << " Ites a invest " << endl;
    Metal* mp = Metal::dynacast(cp);
    if(mp)
        cout << " its a Metal tool !" << endl;
    
}
/**
 special investment fun. 
 special investment fun. 
 not a invest . 
 not a invest . 
 cast from invtermediate pointer : 
 Ites a invest 
 its a Metal tool !
**/
