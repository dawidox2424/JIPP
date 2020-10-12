#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    //rezerwacja tablicy na liczby
    int* tablica_sort = (int*) malloc(sizeof(int));

    // wypisanie argumentow
    cout << "Liczba argumentow: " << (argc - 1) << endl;
    cout << "Argumenty: "<< endl;
    cout << "input: ";
    for (int i = 1; i < argc; ++i) 
    cout << argv[i] <<" ";

    // dodanie i konwersja argumentow do tablicy sort
    for (int i = 0; i < argc; i++)
    tablica_sort[i] = atoi(argv[i+1]);

    // sortowanie 
    sort(tablica_sort,tablica_sort + (argc-1));

    // wypisanie wyniku
    cout << endl;
    cout << "out: ";
    for( int i = 0; i < (argc - 1); i++ )
         cout << tablica_sort[i] << " ";

    return 0;
}