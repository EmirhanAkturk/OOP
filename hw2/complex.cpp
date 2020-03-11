/*
Emirhan Aktürk
Complex sayılar
*/
#include<iostream>
#include "complex.h"
complex::complex(){
    this->imajiner=0;
    this->reel=0;}
complex::complex(int newVal){
    this->reel=newVal;}
complex::complex(string newVal){
    newVal.erase(remove(newVal.begin(),newVal.end(),' '),newVal.end());//remove space
     if(!newVal.compare("i"))
            this->imajiner=1;
        else if(!newVal.compare("-i"))
            this->imajiner=-1;
    else{
        this->reel=stoi(newVal);
        int a=reel,numberOfDigits=0;
        do{ a/=10;
            numberOfDigits++;}
        while(a>=1);
        newVal.erase(0,numberOfDigits);
        if(newVal.length()!=0)
            if(!newVal.compare("i"))
                this->imajiner=1;
            else if(!newVal.compare("-i"))
                this->imajiner=-1;
                else
                    this->imajiner=stoi(newVal);
        else this->imajiner=0;}
    }
complex::complex(double a,double b){
    this->reel=a;
    this->imajiner=b;}
complex::complex(double newVal){
    this->reel=newVal;}
void complex::add(complex &number){
    this->reel+=number.reel;
    this->imajiner+=number.imajiner;}
void complex::subtract(complex &number){
    this->reel-=number.reel;
    this->imajiner-=number.imajiner;}
void complex::divide(complex &number){
    double a=number.reel;
    double b=number.imajiner;
    if((a*a-b*b)==0){
        perror("Divide Zero:");
        return;}
    this->reel=(reel*a-imajiner*b)/(a*a-b*b);
    this->imajiner=(reel*b+imajiner*a)/(a*a-b*b);}
double complex::getReel()const{
    return reel;}
double complex::getImajiner()const{
    return imajiner;}
bool complex::setReel(double newVal){
    this->reel=newVal;
    return true;}
bool complex::setImaginer(double newVal){
    this->imajiner=newVal;
    return true;}
void complex::PrintInfo()const{
    if (reel==0)
        cout<<"complex number:"<<getImajiner()<<"i"<<endl;   
    else {
        if(imajiner<0)
        cout<<"complex number:"<<getReel()<<getImajiner()<<"i"<<endl;
        else if(imajiner==0)
        cout<<"complex number:"<<getReel()<<endl;
        else
        cout<<"complex number:"<<getReel()<<"+"<<getImajiner()<<"i"<<endl;}
}
