#include <iostream>
#include <vector>
#include <random>
#include "Triangle.h"
#include "Quadrilateral.h"

using namespace std;

// Rastgele olarak Triangle nesneleri olusturur ve parametre olarak verilen vektore ekler.
/* Triangle nesnelerinde yer alacak noktaların x ve y değerleri [0, 100] arasında olabilir.
   Şeklin renk değeri de rastgele olarak belirlenmelidir.
*/
void fillTriangles(vector<Triangle> &v, int numberOfItems = 100)
{	random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(1.0, 100.0);
	uniform_real_distribution<double> d(0,5);
	Point a,b,c;
	Triangle::Color color;
	for(int i=0;i<numberOfItems;++i){
		a.x=dist(mt); a.y=dist(mt);
		b.x=dist(mt); b.y=dist(mt);
		c.x=dist(mt); c.y=dist(mt);
		color=static_cast<Triangle::Color>(d(mt));
		Triangle t{a,b,c,color};
		v.push_back(t);
	}
	
}

// Rastgele olarak Quadrilateral nesneleri olusturur ve parametre olarak verilen vektore ekler.
/* Quadrilateral nesnelerinde yer alacak noktaların x ve y değerleri [0, 100] arasında olabilir.
   Şeklin renk değeri de rastgele olarak belirlenmelidir.
*/
void fillQuads(vector<Quadrilateral> &v, int numberOfItems = 100)
{	random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(1.0, 100.0);
	uniform_real_distribution<double> dist2(1,5);
	Point a,b,c,d;
	Quadrilateral::Color color;
	for(int i=0;i<numberOfItems;++i){
		a.x=dist(mt); a.y=dist(mt);
		b.x=dist(mt); b.y=dist(mt);
		c.x=dist(mt); c.y=dist(mt);
		d.x=dist(mt); d.y=dist(mt);
		color=static_cast<Quadrilateral::Color>(dist2(mt));
		Quadrilateral t{a,b,c,d,color};
		v.push_back(t);
	}
}


/* Verilen Triangle veya Rectangle vektörününde çevre uzunluğu ve renk değeri eşleşen ilk elemanın indeksini döndürür.
Eleman bulunamazsa -1 döndürülür.*/
template<class T>
int search(const vector<T> &v, const T & key)
{
	for(int i=0;i<v.size();i++){
		if(	key.getPerimeter()==v[i].getPerimeter() && 
			key.getColorAsString()==v[i].getColorAsString())
		   return i;
	}
	return -1;
}

template<class T>
int sortByPerimeter(vector<T> &v)
 {
	
	int i, j;  
	T key;
    for (i = 1; i < v.size(); i++) 
    {  
        key = v[i];  
        j = i - 1;  
  
        while (j >= 0 && v[j].getPerimeter() > key.getPerimeter()) 
        {  
            v.insert(j+1,v[j]);  
            j = j - 1;  
        }  
        v.insert(j+1,key);  
    }  

}

int main()
{
	Point class test
	auto p = Point{ 4.5, 6.2 };

	cout << p.x << " " << p.y << endl;
	cout << p.coords[0] << " " << p.coords[1] << endl;

	Sample Quad and Triangle Objects
	auto sampleQuad = Quadrilateral{ Point(4, 5), 20, 20 };
	cout << "Color of Sample Quad:" << sampleQuad.getColorAsString() << endl;

	auto sampleTriangle = Triangle{ Point(4, 5),  Point(9, 5),  Point(14, 15) };
	cout << "Color of Sample Triangle:" << sampleTriangle.getColorAsString() << endl;


	Filling vectors randomly
	auto vectorOfQuads = vector<Quadrilateral>{};
	auto vectorOfTriangles = vector<Triangle>{};


	fillTriangles(vectorOfTriangles);
	fillQuads(vectorOfQuads);

	cout<<"vectorOfTriangles size:"<<vectorOfTriangles.size()<<endl;
	cout<<"vectorOfQuads size:"<<vectorOfQuads.size()<<endl;
	// Search sample objects in the corresponding vectors
	cout << "Searching a triangle...\n";
	sampleQuad.printInfo();
	// int idx = search(vectorOfTriangles, vectorOfTriangles.at(5));
	if ( idx>= 0)
	  	cout << "A similar object is found at index-" << idx << endl;
	  else cout << "No similar object can be found" << endl;

	cout << "Searching a quadrilateral...\n";
	sampleQuad.printInfo();
	if (auto idx = search(vectorOfQuads, sampleQuad) >= 0)
		cout << "A similar object is found at index-" << idx << endl;
	else cout << "No similar object can be found" << endl;

	
	// Add sample Triangle object to the vector and sort the vector
	vectorOfTriangles.push_back(sampleTriangle);
	//sortByPerimeter(vectorOfTriangles);


	// Search sample item again. Now, you must have a hit.
	cout << "Searching a triangle...\n";
	sampleQuad.printInfo();
	if (auto idx = search(vectorOfTriangles, sampleTriangle) >= 0)
		cout << "A similar object is found at index-" << idx << endl;
	else cout << "No similar object can be found" << endl;



	// Add sample Quad object to the vector and sort the vector
	vectorOfQuads.push_back(sampleQuad);
	//sortByPerimeter(vectorOfQuads);

	// Search sample item again. Now, you must have a hit.
	cout << "Searching a quadrilateral...\n";
	sampleQuad.printInfo();
	if (auto idx = search(vectorOfQuads, sampleQuad) >= 0)
		cout << "A similar object is found at index-" << idx << endl;
	else cout << "No similar object can be found" << endl;


	// Invalid cases
	try
	{
		auto invalidTriangle1 = Triangle{ Point{4, 0},  Point{9, 0},  Point{14, 0} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid triangle: " << ex.what() << endl;
	}

	try
	{
		auto invalidTriangle2 = Triangle{ Point{4, 4},  Point{4, 4},  Point{4, 4} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid triangle: " << ex.what() << endl;
	}

	try
	{
		auto invalidTriangle3 = Triangle{ Point{4, 0},  Point{4, 4},  Point{4, 14} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid triangle: " << ex.what() << endl;
	}

	try
	{
		auto invalidQuad1 = Quadrilateral{ Point{4, 0},  Point{9, 0},  Point{14, 0}, Point{0, 0} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid Quad: " << ex.what() << endl;
	}


	try
	{
		auto invalidQuad1 = Quadrilateral{ Point{4, 0},  Point{9, 0},  Point{14, 0}, Point{0, 0} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid Quad: " << ex.what() << endl;
	}


	try
	{
		auto invalidQuad2 = Quadrilateral{ Point{4, 0},  Point{9, 0},  Point{3, 20}, Point{10, 20} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid Quad: " << ex.what() << endl;
	}

	return 0;
}
