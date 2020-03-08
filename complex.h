/*
Emirhan Aktürk
Complex sayılar
*/
#include<string>
using namespace  std;
class complex{
public:
    complex();
    complex(int newVal);
    complex(double newVal);
    complex(string newval);
    complex(double a,double b);
    void add(complex &number);
    void subtract(complex &number);
    void divide(complex &number);
    double getReel()const;
    double getImajiner()const;
    bool setReel(double newVal);
    bool setImaginer(double newVal);
    void PrintInfo()const;
private:
    double reel,imajiner;
};