#include<iostream>
#include<bits/stdc++.h>
#include <sstream> 

using namespace std;

// bu fonksiyon girdi sifir ise true degeri dondurur.
bool sifirKontrolu(string girdi)
{
	int i=0;
	bool bayrak=1;
	while(i<girdi.length())
	{
		if(girdi[i] == '0')
		i++;
		else
		{
		bayrak=0; break;
		}
	}return bayrak;
}

// bu fonksiyon girdi tamsayi ise true degeri dondurur.
bool sayiKontrolu(string girdi) 
{ 
	int i=0;
	bool bayrak=1;
	while(i<girdi.length())
	{ 
		if(isdigit(girdi[i]) == true)
		i++;
		else
		{
			bayrak=0; return bayrak; break;
		}
	}return bayrak;
} 

// bu fonksiyon girdi harf ise true degeri dondurur.
bool harfKontrolu(string girdi)
{
	int i=0;
	bool bayrak=1;
	while(i<girdi.length())
	{
		if(isalpha(girdi[i]) == false)
		{
			bayrak=0; return bayrak; break;
		}
		else i++;
	}return bayrak;
}

//bu fonksiyon ondalik sayiyi roma rakamina cevirir.
int ondalikRoma(int girdi)
{
	int i=12, bol, sayi[] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
	string harf[] = {"I", "IV", "V", "IX", "X" ,"XL" ,"L" ,"XC" ,"C","CD","D","CM","M" };
	while (girdi > 0)
	{
		bol = girdi / sayi[i];
		girdi = girdi % sayi[i];
		while (bol--)
		{
			cout << harf[i];
		}i--;
	}
}

// bu fonksiyon roma rakamlarinin ondalik karsiligini belirler.
int degerler(char harf)
{
	if(harf == 'I') return 1;
	if(harf == 'V') return 5;
	if(harf == 'X') return 10;
	if(harf == 'L') return 50;
	if(harf == 'C') return 100;
	if(harf == 'D') return 500;
	if(harf == 'M') return 1000;
	return -1;
}

// bu fonksiyon roma rakamini ondalik sayiya cevirir.
int romaOndalik(string &girdi)
{
	int sonuc = 0, i, onceki, sonraki;
	for (i = 0; i < girdi.length(); i++)
	{
		onceki = degerler(girdi[i]);
		if (i + 1 < girdi.length())
		{
			sonraki = degerler(girdi[i + 1]);
			if (onceki >= sonraki)
			{
				sonuc = sonuc + onceki;
			}
			else
			{
				sonuc = sonuc + sonraki - onceki;
				i++;
			}
		}
		else
		{
			sonuc = sonuc + onceki;
		}
	}return sonuc;
}

int main() 
{ 
	cout << "ONDALIK veya ROMA RAKAMI SEKLINDE BIR SAYI GIRINIZ:" << endl;
	string girdi; 
	cin >> girdi;
	if(sifirKontrolu(girdi))
		cout << "SIFIRIN KARSILIGI YOKTUR. PROGRAM SONLANDI.";
	else if(sayiKontrolu(girdi))
	{
		string gecici = girdi;
		stringstream cevir(gecici);
		int x = 0;
		cevir >> x;
		if(x>=1 && x<4000)
		ondalikRoma(x);
		else
		cout << "SAYI 1-4000 ARASINDA OLMALIDIR. PROGRAM SONLANDI.";
	}
	else if(harfKontrolu(girdi))
	{
		int y = romaOndalik(girdi);
		if(y==-1)
		cout << "HATALI GIRIS! PROGRAM SONLANDI.";
		else if(y>=1 && y<4000)
		cout << romaOndalik(girdi);
		else
		cout << "SAYI I-MMMCMXCIX ARASINDA OLMALIDIR. PROGRAM SONLANDI.";
	}
	else
		cout << "HATALI GIRIS! PROGRAM SONLANDI.";
	return 0;
}

	/* kaynakca 
	cplusplus.com
	geeksforgeeks.org */


