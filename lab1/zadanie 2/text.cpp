#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char *argv[])
{
    //rezerwacja tablicy na znaki
    char* tablica_znak = (char*) malloc(sizeof(char));
    int suma_dobrych = 0;

    strcpy(tablica_znak,argv[1]); // skopiowanie argumentu do tablicy

    // wypisanie inputu na ekran
    int dlugosc_tablicy = sizeof(tablica_znak);
    cout << "input: ";
    for (int i = 0; i < dlugosc_tablicy; i++ ) 
    cout << tablica_znak[i];


// sprawdzenie palindromu
    int j = strlen(tablica_znak);
    cout << j << endl;
    for (int i = 0; i < j; i++)
    {
        char a = tablica_znak[i];
        char b = tablica_znak[j-i-1];

        if(a==b)
        {
        suma_dobrych++;
        }
        else
        {
        cout << "Wyraz nie jest palindromem" << endl;
        break;
        return 0;
        }
    }

    if (suma_dobrych == j) // warunek wystapienie palindromu - wszystkie literki są zgodne
    cout << "Wyraz jest palindromem" << endl;


    return 0;
}