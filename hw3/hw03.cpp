#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>

using namespace std;

//asagidaki satirlari yoruma alarak kodunuzu farkli sekillerde test edebilirsiniz.
//#define _TEST_ITERATIVE_
#define _TEST_RECURSIVE_

// Bu odevde global veya statik degisken tanimlanamaz!!!

/* Ozyinelemeli olarak zip zip kurbaganin kac farkli yoldan gittigini bulan fonksiyondur.
 * Bu fonksiyon icinde for ve while kullanamazsiniz ve en az bir kez recursiveFunction
 * fonksiyonu cagri yapilmalidir.
 */
long long recursiveFunction(int numberOfStones)
{	
	switch (numberOfStones)
		{
		case 1: return 1;//1 
		case 2: return 2;//1+1,2
		case 3: return 4;//1+1+1,1+2,2+1,3
		default: 
				return 	recursiveFunction(numberOfStones-1)+
						recursiveFunction(numberOfStones-2)+
						recursiveFunction(numberOfStones-3);
		/*
			i tane taş için ihtimal sayisi=
				i-1 tane taş için ihtimal sayisi+
				i-2 tane taş için ihtimal sayisi+
				i-3 tane taş için ihtimal sayisi
		*/			
		}
}

/* Yinelemeli olarak zip zip kurbaganin kac farkli yoldan gittigini bulan fonksiyondur.
 * Bu fonksiyon icinde for ve while dongusu kullanilmalidir.
 * Bu fonksiyon icinde baska bir fonksiyona (kendisi dahil) cagri yapilamaz.
 */
long long iterativeFunction(int numberOfStones)
{	vector<long long> arr(numberOfStones);
	arr[0]=1;//Possibilities when there is 1 stone:1
	arr[1]=2;//Possibilities when there is 2 stone:1+1,2
	arr[2]=4;//Possibilities when there is 3 stone:1+1+1,1+2,2+1,3
	for(int i=3;i<numberOfStones;i++)
		{arr[i]=arr[i-1]+arr[i-2]+arr[i-3];}
		/*
			i tane taş için ihtimal sayisi=
				i-1 tane taş için ihtimal sayisi+
				i-2 tane taş için ihtimal sayisi+
				i-3 tane taş için ihtimal sayisi
		*/
	return arr[numberOfStones-1];
}


int main()
{	
	const int MAX_NUMBER_OF_STONES{ 72 };

	cout << setfill(' ');

	cout.imbue(locale(""));

	for (auto i = 1; i <= MAX_NUMBER_OF_STONES; ++i)
	{

#ifdef _TEST_ITERATIVE_
		{
			long long tempResult = { 0 };

			auto start = std::chrono::steady_clock::now();
			tempResult = iterativeFunction(i);
			auto stop = std::chrono::steady_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();


			cout << "iterative" << setw(4) << i << " -> " << tempResult << " ( " << duration << "us )\n";
		}
#endif

#ifdef _TEST_RECURSIVE_
		{
			long long tempResult = { 0 };

			auto start = std::chrono::steady_clock::now();
			tempResult = recursiveFunction(i);
			auto stop = std::chrono::steady_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

			cout << "recursive" << setw(4) << i << " -> " << tempResult << " ( " << duration << "us )\n";
		}
#endif

	}

	return 0;
}