# include <limits.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

# define CHARS 128
 

// bad character tablosunu oluþturmak için kullanýlacak fonksiyon
void badCharacterTable( char *str, int size, int badchar[CHARS])
{
    int i;
 
    // kelimede olmayan harflerin deðeri kelimenin uzunluðu kadar olduðu için bütün diziye uzunluðu tanýmlýyorum
    for (i = 0; i < CHARS; i++)
         badchar[i] = size;
 
    // Bad match tablosu oluþturuyorum
    for (i = 0; i < size-1; i++)
         badchar[(int) str[i]] = size-i-1;
  
}
    // bad match tablosu yardýmýyla arama yapacak olan fonksiyon
int search( char *txt,  char *let)
{
	int counter=0, badchar[CHARS];
    int m = strlen(let);
    int n = strlen(txt);
 
    //bad match table
    badCharacterTable(let, m, badchar);
    // s kaydýrma iþlemi yaparken yardýmcý olacak deðer 
    int s = 0;  
    while(s <= (n - m))
    {
    	counter++;
        int j = m-1;
    // j deðerini eþleþme olduðu sürece azaltýyorum 
        while(j >= 0 && let[j] == txt[s+j]){
        	counter++;
        	  j--;
		}
              
            
        //Eðer aranan kelime mevcut aranan yerde ise yukarýdaki while döngüsünden j indeksi -1 olacak çýkacaktýr.
        if (j < 0)
        {
            printf("\nKelime %d ve %d indeksleri arasinda bulunuyor", s,s+m+1);
 
            //Aranan kelimenenin metin içinde tekrarlanma ihtimalini düþünürek arama alanýný kelime uzunluðu kadar kaydýrýyorum
            s += m;
 
        }
 
        else
            //Eþleþme saðlanmadý. Arama alanýnýn en saðýndaki karakterin 'Bad Character' tablosundaki deðeri kadar kaydýrma yapýyorum
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
    
    //zaman karmaþýklýðý analizi yapmak için döngülere counter atadým
	printf("\n\nZamana Bagli Yildiz Diyagrami: ");
		for(j=0; j<counter; j++){
			printf("*");
		}
		printf("\n");
	
    getchar();
    
    return 0;
}
