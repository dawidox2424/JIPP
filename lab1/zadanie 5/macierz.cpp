#include <iostream>
#include <string.h>
using namespace std;




int main()
{

double tablica1[2][3] = {0};
double tablica2[2][3] = {0};
double tablicaS[2][3] = {0};
string napis = "ABCDEF";


cout << "Podaj elementy 1 macierzy :" << endl;

    for(int i=0; i<2 ;i++)
    {
        for(int j=0; j<3 ;j++)
        {
        cout << "Podaj element " << i+1 << " wiersza " << " oraz " << j+1 << " kolumny" << endl;
        cin >> tablica1[i][j];
        }
    }

cout << "Podaj elementy 2 macierzy :" << endl;

    for(int i=0; i<2 ;i++)
    {
        for(int j=0; j<3 ;j++)
        {
        cout << "Podaj element " << i+1 << " wiersza " << " oraz " << j+1 << " kolumny" << endl;
        cin >> tablica2[i][j];
        }
    }


for(int i=0; i<2 ;i++)
    {
        for(int j=0; j<3 ;j++)
        tablicaS[i][j] = tablica1[i][j] + tablica2[i][j];
    }

cout << "Oto suma:" << endl;

for(int i=0; i<2 ;i++)
    {
        for(int j=0; j<3 ;j++)
        cout << tablicaS[i][j] << ",";
        cout << endl;
    }
return 0;
}