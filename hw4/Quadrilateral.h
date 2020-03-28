#pragma once
#include <array>
#include <string>
#include <map>
#include "Point.h"


class Quadrilateral
{
public:
	constexpr static int NUMBER_OF_CORNERS { 4 };
	enum class Color{RED,BLUE,WHITE,BLACK,GREEN};
    const map<Color,string>colorToStringMap={{Color::RED,"Red"},
    {Color::BLUE,"Blue"},
    {Color::WHITE,"White"},
    {Color::BLACK, "Black"},
	{Color::GREEN, "Green"}
    };

	// Constructors

	// Bir dikdortgen/kare olusturur a her zaman sol ust noktayı, c her zaman sag alt noktayı gosterir
	Quadrilateral(const Point & a={0,1}, const Point & c = { 1, 0 }, const Color & color = {Color::GREEN});

	// Verilen en ve boy degerlerine uygun olarak bir dikdortgen/kare olusturur a her zaman sol ust noktayı gosterir
	Quadrilateral(const Point & a, double width, double height, const Color & color = {Color::GREEN});

	// Verilen noktalara gore dortgen olusturur. Bu noktaların bir dortgen olusturdugu kontrol edilmeldir.
	Quadrilateral(const Point & a, const Point & b, const Point & c, const Point & d, const Color & color = Color::GREEN);
	Quadrilateral(const array<Point, NUMBER_OF_CORNERS> & pts, const Color & color = Color::GREEN);

	// Referanslar
	 Point & a = pts[0];
	 Point & b = pts[1];
	 Point & c = pts[2];
	 Point & d = pts[3];

	// Getter Functions
	Point getA() const noexcept; 
	Point getB() const noexcept; 
	Point getC() const noexcept; 
	Point getD() const noexcept; 

	// Dortgenin rengini string olarak donderir
	Color getColor() const noexcept;
	string getColorAsString() const noexcept; 

	// Dortgenin cevresini hesaplar ve gonderir
	double getPerimeter() const noexcept;


	/* Dortgen olup olmadadını kontrol eder.
	 * Bu fonksiyonun tum yapicilar ve setter fonksiyonlar icinde dogrudan/dolaylı olarak cagrılması zorunludur.
	 * Eger verilen degerler bir dortgen olusturmuyorsa invalid_argument exception fırlatılmalı ve bu bu exception kontrol edilmelidir
	 * Program sonlandırılmamalıdır.
	 */
	bool isValid()const;

	// Setter Functions
	bool setA(const Point & pt); 
	bool setB(const Point & pt); 
	bool setC(const Point & pt); 
	bool setD(const Point & pt); 

	void printInfo() const noexcept;
	// Ekrana sunu basar:
	/* Rectangle
	   Number of points: 4
	   Points: (3.00, 4.40), (3.00, 5.00), (3.80, 5.00), (3.80, 4.40)
	   Peripheral: 2.80
	   Color: Red
	*/
private:
	array<Point, NUMBER_OF_CORNERS> pts; 
	Color color;
};

