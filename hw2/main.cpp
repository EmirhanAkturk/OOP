/*
Emirhan Aktürk
Complex sayılar
*/
#include "complex.h"
using namespace std;
int main(){
    complex sayi,sayi2(4),sayi3(5.2),sayi4(2,-4.2),sayi5("-i");
    string s="10-i";
    complex sayi6(s);
    sayi.setImaginer(5);
    sayi.setReel(4);
    sayi2.PrintInfo();
    sayi.add(sayi2);
    sayi.PrintInfo();
    sayi.subtract(sayi2);
    sayi.PrintInfo();
    sayi3.PrintInfo();
    sayi4.divide(sayi2);
    sayi4.PrintInfo();
    sayi5.PrintInfo();
    sayi6.PrintInfo();
    return 0;
}