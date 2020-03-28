#pragma once
#include <array>
#include <cmath>
// !!!!!!!!!!!!!!!! BU SAYFADA DUZENLEME YAPMAYINIZ !!!!!!!!!!!!!!!!

using namespace std;

// 2-boyutlu bir uzayda bir noktanın gosterilmesini saglayan yapı (struct)
typedef struct Point_st {
	/* Sınıflarda varsayılan erisim duzenleyicisi (access modifier) PRIVATE, 
	 * yapılarda ise PUBLIC olarak tanımlıdır.
	 */	
	array<double,2> coords;

	// Noktanın x, ve y konumlarına farklı bir sekilde erisim imkanı saglanmaktadır
	double & x = coords[0]; // Referanslar ya burada yapıldıgı gibi tanımlandıgında ilklendirilmeli ya da uye ilklendirme soz dizimi icinde bu islem yapılmalıdır 
	double & y = coords[1]; // Sonrasında referansın gosterdigi yer degistirilemez ama gosterdigi yerdeki deger degistirilebilir.

	// Diger bir nokta ile Euclidean uzaklıgını veren bir uye fonksiyon
	inline double distanceTo(const Point_st & other) const
	{
		return sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
	}

	/* Yapılarda da constructor ve diger uye fonksiyonları/operatorleri tanımlayabilirsiniz.
	 * Asagıdaki yapici fonksiyonlarda uye ilklendirme soz dizimi kullanmaktadir ve 
	 * bu fonksiyonlar bos bir ana bloga sahiptirler.
	 */
	Point_st(double x = 0, double y = 0) : coords{ x , y } //, x{ coords[0] }, y{ coords[1] } //Yukarıda verilen ilklendirmeyi kapatıp referansları burada da ilklendirebilirsiniz.
	{ 
		/* Bilerek bos bırakılmıstır. */ 
	}	

	// Donusturen yapıcı
	Point_st(const array<double, 2> & coords) : coords{ coords }//, x{ this->coords[0] }, y{ this->coords[1] }  //Yukarıda verilen ilklendirmeyi kapatıp referansları burada da ilklendirebilirsiniz.
	{ 
		/* Bilerek bos bırakılmıstır. */
	}
} Point;
