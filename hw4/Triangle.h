#pragma once
#include <array>
#include <vector>
#include <map>
#include <string>
#include "Point.h"

using namespace std;

class Triangle
{
public:
	constexpr static int NUMBER_OF_CORNERS { 3 };
	enum class Color{RED,BLUE,WHITE,BLACK,GREEN};
    const map<Color,string>colorToStringMap={{Color::RED,"Red"},
    {Color::BLUE,"Blue"},
    {Color::WHITE,"White"},
    {Color::BLACK, "Black"},
	{Color::GREEN, "Green"}
    };
	
	// Constructor
	Triangle(const Point & a = { 1, 0 }, const Point & b = { 0, 1 }, const Point & c = { 2, 1 }, const Color & color = Color::RED);
	Triangle(const vector<Point> & pts, const Color & color = Color::RED);
	Triangle(const array<Point, NUMBER_OF_CORNERS> & pts, const Color & color = Color::RED);
	
	Point & a = pts[0];
	Point & b = pts[1];
	Point & c = pts[2];

	// Getter Functions
	Point getA() const noexcept; 
	Point getB() const noexcept; 
	Point getC() const noexcept; 

	Color getColor() const noexcept;
	string getColorAsString() const noexcept;

	double getPerimeter() const noexcept;

	// Setter Functions
	bool setA(const Point & pt); 
	bool setB(const Point & pt); 
	bool setC(const Point & pt);

	/* Ucgen olup olmadıgını kontrol eder.
	 * Bu fonksiyonun tum yapıcılar ve setter fonksiyonlar icinde dogrudan/dolaylı olarak cagrılması zorunludur.
	 * Eger verilen degerler bir ucgen olusturmuyorsa invalid_argument exception fırlatılmalı ve bu bu exception kontrol edilmelidir
	 * Program sonlandırılmamalıdır.
	 */
	bool isValid() const;

	void printInfo() const noexcept;
	// Ekrana sunu basar:
	/* Triangle
	   Number of points: 3
	   Points: (3.00, 4.40), (2.00, 5.00), (4.80, 5.00)
	   Primeter: 5.86
	   Color: Red
	*/
private:
	array<Point, NUMBER_OF_CORNERS> pts; 
	Color color;
};

