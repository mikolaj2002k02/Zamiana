#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bitset>

using namespace std;
long minimumZPliku(string nazwaPliku, int system)
{
  long minimum;
  //otw�rz plik �r�d�owy do zmiennej ifstream
  //wyszukaj minimum w p�tli wczytuj�c jw. tylko zamiast w main() tutaj
  //zamknij plik �r�d�owy
  return minimum;
}
int main(int argc, char** argv)
{
 ifstream file; //plik wejsciowy
 ofstream fileOut; //plik wynikowy do zapisu
char* endptr; // to jest wska�nik na miejsce, gdzie przy konwersji z systemu czworkowego wyst�pi b��d - nieu�ywana zmienna
long  liczba, liczba1, liczba2, min; //liczba dziesietna, minimum z pliku
long minimum;
long min1 = minimumZPliku("nazwa_pliku.txt", 2); //z pliku o tej nazwie system dw�jkowy odczyta i minimum policzy
long min2 = minimumZPliku("druga_nazwa.txt",8);//system 8
string liczba3, liczba4; //dwie liczby w systemie czworkowym wczytujemy jako "string" bo mog� by� d�u�sze od long long
file.open("dane_systemy2.txt"); //otworz plik liczb
fileOut.open("wyjscie1.txt"); //otworz plik do wynikow

 bool pierwszy = true;  //do algorytmu MINIMUM - zak�adamy, �e pierwsza liczba jest najmniejsza z dotychczas przeczytanych
 
 if(file.good())  //sprawdzenie czy plik istnieje
     while(!file.eof())        //petla wykonuje sie az program dojedzie do konca pliku
     {
            file>>liczba3 >> liczba4;   // wczyta dwie liczby z pliku (w wierszu) do 2 string�w
            liczba =  strtol(liczba4.c_str(), &endptr, 2);
            liczba1 =  strtol(liczba4.c_str(), &endptr, 4);
            liczba2 =  strtol(liczba4.c_str(), &endptr, 8);


               //^konwersja z systemu czworkowego do dziesietnego, string (C++) trzeba zamieni� na char * (C) funkcja .c_str()
               //zmienna endptr wskazuje na znak w stringu, kt�ry nie pasuje do systemu czw�rkowego - tu niesprawdzone, bo zak�adamy, �e dane s� poprawne!
               if(pierwszy) //je�li to pierwsza liczba z pliku - b�dzie nowym MINIMUM
               {
                            min = liczba;
                            pierwszy = false;
               }
               else //je�li to kolejna liczba z pliku...
                  if(liczba < min) //... i jest mniejsza od dotychczasowego minimum...
                       min = liczba; // ... to nadpisz min
                       
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////                      
                       
                       
                       if(pierwszy) //je�li to pierwsza liczba z pliku - b�dzie nowym MINIMUM
               {
                            min1 = liczba1;
                            pierwszy = false;
               }
               else //je�li to kolejna liczba z pliku...
                  if(liczba1 < min1) //... i jest mniejsza od dotychczasowego minimum...
                       min1 = liczba1;
                       
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////                      
                       
                        if(pierwszy) //je�li to pierwsza liczba z pliku - b�dzie nowym MINIMUM
               {
                            min2 = liczba2;
                            pierwszy = false;
               }
               else //je�li to kolejna liczba z pliku...
                  if(liczba2 < min2) //... i jest mniejsza od dotychczasowego minimum...
                       min2 = liczba2;
                       
     }//eof() koniec pliku
 fileOut<< "Plik zerowy min: " << min <<endl; //zapisanie najmniejszej liczby z pliku czworkowego do pliku wynikowego
 fileOut << "Plik pierwszy min:" << min1 <<"\n";
fileOut << "Plik drugi min:" << min2 <<"\n";

 file.close();
 fileOut.close();
 return 0;
}
