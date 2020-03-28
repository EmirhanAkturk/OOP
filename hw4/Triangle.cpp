#include "Triangle.h"
#include<iostream>
#include<map>
using namespace std;

Triangle::Triangle(const Point & a, const Point & b, const Point & c, const Color & color){
    this->color=color;
    setA(a);
    setB(b);
    setC(c);
}

Triangle::Triangle(const vector<Point> & pts, const Color & color){
    this->color=color;
    for(int i=0;i<NUMBER_OF_CORNERS;++i){
        this->pts[i].x=pts[i].x;
        this->pts[i].y=pts[i].y;
    }
    if(!isValid()){
        cout<<"Constructer warning!!"<<endl;
    }
}

Triangle::Triangle(const array<Point, NUMBER_OF_CORNERS> & pts, const Color & color){
    this->color=color;
    for(int i=0;i<NUMBER_OF_CORNERS;++i){
        this->pts[i].x=pts[i].x;
        this->pts[i].y=pts[i].y;
    }
    if(!isValid()){
        cout<<"Constructer warning!!"<<endl;
    }
}

Point Triangle::getA() const noexcept{
    return a;
}

Point Triangle::getB() const noexcept{
    return b;
}
Point Triangle::getC() const noexcept{
    return c;
}

Triangle::Color Triangle::getColor()const noexcept{
    return color;
}

string Triangle::getColorAsString() const noexcept{
     return colorToStringMap.at(getColor());
 }

double Triangle::getPerimeter()const noexcept{
    /*  
            a   

        b       c
        ucgeninin çevresi
    */
    return (a.distanceTo(b)+b.distanceTo(c)+c.distanceTo(a));
}

void Triangle::printInfo() const noexcept{
    cout<<"Rectangle\n"<<"Number of point:"<<NUMBER_OF_CORNERS<<endl;
    cout<<"Points:";
    for(auto p:pts)
		cout<<"("<<p.x<<","<<p.y<<"),";
    cout<<endl;
    cout<<"Peripheral:"<<getPerimeter()<<endl;
    cout<<"Color:"<<getColorAsString()<<endl;
}

bool Triangle::setA(const Point &pt){
    a.x=pt.x;
    a.y=pt.y;
    if(!isValid()){
        cout<<"setA warning!!"<<endl<<endl;
        a.x++;//noktalar aynı dogru uzerindeyse noktayı 1 birim saga taşı
        return false;}
    return true;
}

bool Triangle::setB(const Point &pt){
    b.x=pt.x;
    b.y=pt.y;
   if(!isValid()){
        cout<<"setB warning!!"<<endl<<endl;
        b.x++;//noktalar aynı dogru uzerindeyse noktayı 1 birim saga taşı
        return false;}
    return true;
}

bool Triangle::setC(const Point &pt){
    c.x=pt.x;
    c.y=pt.y;
    if(!isValid()){
        cout<<"setC warning!!"<<endl<<endl;
        c.x++;//noktalar aynı dogru uzerindeyse noktayı 1 birim saga taşı
        return false;}
    return true;
}

double slope(const Point &a,const Point &b){
    
  return (a.y-b.y)/(a.x-b.x);
}

bool Triangle::isValid()const{
try{ 
    if(slope(a,b)==slope(b,c)){
        throw invalid_argument("there should not be 3 points on the same line");
    }
}

catch(invalid_argument &e){
       cout<<"Error:"<<e.what()<<endl;
       return false;
   }
    return true;
}
