#include <iostream>

using namespace std;

enum note { c, cpp , csharp };

class Instrument{
public:
    virtual void play(note) const{
	cout << " Instrument :: play() " << endl;
    }
};

class Wind : public Instrument{
public:
    void play(note) const{
	cout << " Wind :: play() " << endl;
    }

};

void tune(Instrument& i){
    i.play(cpp);
}

int main()
{
    Wind w;
    tune(w);
}
