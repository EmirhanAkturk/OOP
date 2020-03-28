#include"Quadrilateral.h"
#include<iostream>
#include<map>
using namespace std;

double max(double a,double b,double c,double d){
    double max=a;
    if(max<b)
        max=b;
    if(max<c)
        max=c;
    if(max<d)
        max=d;    
    return max;
}
double min(double a,double b,double c,double d){
    double min=a;
    if(min>b)
        min=b;
    if(min>c)
        min=c;
    if(min>d)
        min=d;
    return min;
}

inline double slope(const Point &a,const Point &b){
    //if(a.x-b.x==0) return (a.y-b.y);
    return (a.y-b.y)/(a.x-b.x);
}
Quadrilateral::Quadrilateral(const Point & a , const Point & c , const Color & color){
     /*  
        a     d
        b     c
    */
    this->color=color;
    setA(a);
    setC(c);
    b.x=a.x;
    b.y=c.y;
    d.x=c.x;
    d.y=a.y;
    a.x=(a.x==min(a.x,b.x,c.x,d.x)) ? a.x:min(a.x,b.x,c.x,d.x)-1.0; //en solda olan değeri ata
    a.y=(a.y==max(a.y,b.y,c.y,d.y)) ? a.y:max(a.y,b.y,c.y,d.y)+1.0;//en yukarıda olan değeri ata
    c.x=(c.x==max(a.x,b.x,c.x,d.x)) ? c.x:max(a.x,b.x,c.x,d.x)+1.0; //en sagda olan değeri ata
    c.y=(c.y==min(a.y,b.y,c.y,d.y)) ? c.y:min(a.y,b.y,c.y,d.y)-1.0;//en asagıda olan değeri ata
}
 
Quadrilateral::Quadrilateral(const Point & a, double width, double height, const Color & color){
    /*  
        a     d
        b     c
    */
    this->color=color;
    setA(a);
    b.x=a.x;
    b.y=(a.y-height);
    c.x=(b.x+width);
    c.y=b.y;
    d.x=c.x;
    d.y=a.y;
}

Quadrilateral::Quadrilateral(const Point & a, const Point & b, const Point & c, const Point & d, const Color & color ){
    this->color=color;
    setA(a);
    setC(c);
    setB(b);
    setD(d);
}

Quadrilateral::Quadrilateral(const array<Point, NUMBER_OF_CORNERS> & pts, const Color & color ){
    this->color=color;
    for(int i=0;i<NUMBER_OF_CORNERS;++i){
        this->pts[i].x=pts[i].x;
        this->pts[i].y=pts[i].y;
    }
}

Point Quadrilateral::getA() const noexcept{
    return a;
} 

Point Quadrilateral::getB() const noexcept{
    return b;
}

Point Quadrilateral::getC() const noexcept{
    return c;
}

Point Quadrilateral::getD() const noexcept{
    return d;
}

Quadrilateral::Color Quadrilateral::getColor()const noexcept{
    return color;
}

string Quadrilateral::getColorAsString() const noexcept{
    return colorToStringMap.at(getColor());
}

double Quadrilateral::getPerimeter()const noexcept{
    /*  
        a     b
        d     c
        dörtgeninin çevresi
    */
    return (a.distanceTo(b)+b.distanceTo(c)+c.distanceTo(d)+d.distanceTo(a));
}

void Quadrilateral::printInfo() const noexcept{
    cout<<"Rectangle\n"<<"Number of point:"<<NUMBER_OF_CORNERS<<endl;
    cout<<"Points:";
    for(auto p:pts)
		cout<<"("<<p.x<<","<<p.y<<"),";
    cout<<endl;
    cout<<"Peripheral:"<<getPerimeter()<<endl;
    cout<<"Color:"<<getColorAsString()<<endl;
}

bool Quadrilateral::setA(const Point &pt){
    this->a.x=pt.x;
    this->a.y=pt.y;
        if(!isValid()){
            cout<<"setA warning!!"<<endl<<endl;
            return false;}
    return true;
}

bool Quadrilateral::setB(const Point &pt){
    this->b.x=pt.x;
    this->b.y=pt.y;
   if(!isValid()){
        cout<<"setB warning!!"<<endl<<endl;
        return false;}
    return true;
}

bool Quadrilateral::setC(const Point &pt){
    this->c.x=pt.x;
    this->c.y=pt.y;
        if(!isValid()){
            cout<<"setC warning!!"<<endl<<endl;
            return false;}
    return true;
}

bool Quadrilateral::setD(const Point &pt){
    d.x=pt.x;
    d.y=pt.y;
    if(!isValid()){
        cout<<"setD warning!!"<<endl<<endl;
        return false;}
    return true;
}


bool Quadrilateral::isValid()const{
try{ 
    if( slope(a,b)==slope(b,c) || slope(a,d)==slope(d,c) ||
        slope(a,d)==slope(d,b) || slope(b,d)==slope(d,c) ){

        if(slope(a,b)==slope(b,c)|| slope(a,d)==slope(d,c)||slope(a,d)==slope(d,b)){ 
            a.x--;//eğer a ile 2 nokta aynı dogru uzerindeysea noktası 1 birim sola kayar
        }
        else //eger b-d-c noktaları aynı dogru uzerindeyse c 1 birim saga kayar
            c.x++;
        
        throw invalid_argument("there should not be 3 points on the same line");
    }
    else if(a.x==c.x)//weight=0 ise a 1 birim sola kayar
    {   a.x--;
        throw invalid_argument("weight=0"); }

    else if(a.y==c.y)//height=0 ise a 1 birim yukarı kayar
    {   a.y++;
        throw invalid_argument("height=0"); }
    
}
catch(invalid_argument &e){
       cout<<"Error:"<<e.what()<<endl;
       return false;
   }
    return true;
}
