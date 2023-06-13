# include <limits.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

# define CHARS 128
 

// bad character tablosunu olu�turmak i�in kullan�lacak fonksiyon
void badCharacterTable( char *str, int size, int badchar[CHARS])
{
    int i;
 
    // kelimede olmayan harflerin de�eri kelimenin uzunlu�u kadar oldu�u i�in b�t�n diziye uzunlu�u tan�ml�yorum
    for (i = 0; i < CHARS; i++)
         badchar[i] = size;
 
    // Bad match tablosu olu�turuyorum
    for (i = 0; i < size-1; i++)
         badchar[(int) str[i]] = size-i-1;
  
}
    // bad match tablosu yard�m�yla arama yapacak olan fonksiyon
int search( char *txt,  char *let)
{
	int counter=0, badchar[CHARS];
    int m = strlen(let);
    int n = strlen(txt);
 
    //bad match table
    badCharacterTable(let, m, badchar);
    // s kayd�rma i�lemi yaparken yard�mc� olacak de�er 
    int s = 0;  
    while(s <= (n - m))
    {
    	counter++;
        int j = m-1;
    // j de�erini e�le�me oldu�u s�rece azalt�yorum 
        while(j >= 0 && let[j] == txt[s+j]){
        	counter++;
        	  j--;
		}
              
            
        //E�er aranan kelime mevcut aranan yerde ise yukar�daki while d�ng�s�nden j indeksi -1 olacak ��kacakt�r.
        if (j < 0)
        {
            printf("\nKelime %d ve %d indeksleri arasinda bulunuyor", s,s+m+1);
 
            //Aranan kelimenenin metin i�inde tekrarlanma ihtimalini d���n�rek arama alan�n� kelime uzunlu�u kadar kayd�r�yorum
            s += m;
 
        }
 
        else
            //E�le�me sa�lanmad�. Arama alan�n�n en sa��ndaki karakterin 'Bad Character' tablosundaki de�eri kadar kayd�rma yap�yorum
            s += badchar[txt[s+m-1]];
	}
	return counter;
}
 
//main fonksiyon
int main()
{
	int j,counter;
	char txt[CHARS],let[CHARS];
	 
	
	printf("Arama yapilacak metini giriniz: ");
	gets(txt);
	printf("\nAradiginiz kelimeyi giriniz: ");
	gets(let);
    counter = search(txt, let);
    
    //zaman karma��kl��� analizi yapmak i�in d�ng�lere counter atad�m
	printf("\n\nZamana Bagli Yildiz Diyagrami: ");
		for(j=0; j<counter; j++){
			printf("*");
		}
		printf("\n");
	
    getchar();
    
    return 0;
}
