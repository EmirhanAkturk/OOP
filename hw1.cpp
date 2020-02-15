/*
    Ekrana yıldız karaktelerinden üçgen,ters ücgen,elmas bastırma
    Emirhan Aktürk
*/
#include<iostream>
using namespace std;
class sekil{
public:
    void DuzUcgen(int deger);
    void TersUcgen(int deger);
    void Elmas(int deger);
};
int main(){
    sekil ucgen;
    int secim,boyut,deneme=0;
    cout<<"Hangi şekli seçmek istersiniz:"<<
    "[1: Düz Üçgen, 2: Ters Üçgen, 3: Elmas, 0: Çıkış]"<<endl;
    cin>>secim;
    while (deneme<3)
    {
        if(secim==1 || secim==2 ){
            cout<<"Şekil için boyut giriniz(3 ile 15 arasındaki tek sayılar olabilir)"<<endl;
            cin>>boyut;
            if(boyut<=15 && boyut>=3 && boyut%2!=0)
                break;}
        else if(secim==3){
            cout<<"Şekil için boyut giriniz(5 ile 15 arasındaki tek sayılar olabilir)"<<endl;
            cin>>boyut;
            if(boyut<=15 && boyut>=5 && boyut%2!=0)
                break;}
        ++deneme;
    }
    switch (secim)
    {
    case 1:
        ucgen.DuzUcgen(boyut);
        break;
    case 2: 
        ucgen.TersUcgen(boyut);
        break;
    case 3: 
        ucgen.Elmas(boyut);
        break;
    case 0: 
        break;
    default:
        break;
    }
    return 0;
}
void sekil::DuzUcgen(int boyut){
    for(int i=0;i<=(boyut/2);i++){
        for(int j=0;j<(boyut/2)-i;j++)//boşluk kısmı
            cout<<" ";
        for(int j=0;j<(i*2)+1;j++)//yıldız kısmı  
            cout<<"*";
        if(i!=boyut/2)//alt satıra geçme
            cout<<endl;
    }
}
void sekil::TersUcgen(int boyut){
    int i=0,j;
    while (i<=(boyut)/2)
    {   j=(boyut/2)-i;
        while (j<(boyut/2))//boşluk kısmı
        {   cout<<" ";   
            ++j;}
        j=boyut;
        while (j>(2*i))//yıldız kısmı
        {   cout<<"*";
            --j;}
        if(i!=boyut/2)
            cout<<endl;
        ++i;
    }    
}
void sekil::Elmas(int boyut){
    DuzUcgen(boyut);
    cout<<endl;
    TersUcgen(boyut);
}
