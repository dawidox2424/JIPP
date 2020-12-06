#include <iostream>
#include <conio.h>
#include <windows.h>
#include "matrix.hpp"
//#include <include/matrix.hpp>
#include <fstream>
using namespace std;


matrix::matrix(int x,int y)
{
    if(x<=0 || y<=0)
    {
        cout << "Nie jestes w stanie stworzyc macierzy o jednym z rozmiarów jako ujemnym lub zerowym" << endl;
        exit(2);
    }
    this->x = x;
    this->y = y;

matrix::mac = new double*[x];
for (int t=0; t<x; t++)
{
matrix::mac[t] = new double[y];
}
    for (int n=0; n<x; n++)
        for (int k=0; k<y; k++)
        mac[n][k] = 0;
}

matrix::matrix(int x)
{
    if (x<=0)
    {
        cout << "Nie jestes w stanie stworzyc macierzy o ujemnym lub zerowym rozmiarze" << endl;
        exit(2);
    }
    matrix::x = x;
    matrix::y = x;
    matrix::mac = new double*[x];

    for (int t=0; t<x; t++)
{
matrix::mac[t] = new double[x];
}

    for (int n=0; n<x; n++)
        for (int k=0; k<x; k++)
        mac[n][k] = 0;

}

void matrix::set(int x,int y, double value)
{
    if (x < 0 || y < 0 || x > this->x || y > this->y)
    {
        cout << "Nie jestes w zakresie rozmiaru macierzy" << endl;
        exit(2);
    }
    mac[x][y] = value;
}

double matrix::get(int x,int y)
{
    if (x < 0 || y < 0 || x > this->x || y > this->y)
    {
        cout << "Nie jestes w zakresie rozmiaru macierzy" << endl;
        exit(2);
    }
    return mac[x][y];
}


int matrix::cols()
{
    return x;
}

int matrix::rows()
{
    return y;
}

void matrix::print()
{
    cout << endl;
    for (int i=0; i<x; i++)
    {
    for (int j=0; j<y; j++)
    {
    cout << mac[i][j] << " ";
    }
    cout << endl;
    }
}

matrix matrix::add(matrix m2)
{
    if(this->x != m2.x || this->y != m2.y)
    {
        cout << "Nie mozna dodac macierzy o roznych rozmiarach!!!" << endl;
        exit(2);
    }
    matrix m3(this->x,this->y);

    for (int i=0; i<x; i++)
        for (int j=0; j<y; j++)
            m3.mac[i][j] = m2.mac[i][j] + this->mac[i][j];

            return m3;
}

matrix matrix::subtract(matrix m2)
{
    if(this->x != m2.x || this->y != m2.y)
    {
        cout << "Nie mozna odjac macierzy o roznych rozmiarach!!!" << endl;
        exit(2);
    }
    matrix m3(this->x,this->y);

    for (int i=0; i<x; i++)
        for (int j=0; j<y; j++)
            m3.mac[i][j] = this->mac[i][j] - m2.mac[i][j];

            return m3;
}

matrix matrix::multiply(matrix m2)
{
    if ( this->x != m2.x)
    {
        cout << "Blad w roznicy wymiarow macierzy" << endl;
        exit(2);
    }

    double suma;
    matrix m3(this->x,m2.y);

    for (int i=0; i<this -> x; i++)
    {
        for (int j=0; j<m2.y; j++)
        {
            suma = 0;
            for (int k=0; k< m2.y ; k++)
            {
            suma += this->mac[i][k] * m2.mac[k][j];
            }
            m3.mac[i][j] = suma;
        }
    }
            return m3;
}


void matrix::store(string filename,string path)
{   
    //fstream plik;
    ofstream file(path);
 
    if(file.good() == false) 
    {
        cout << "can't open the file !" << endl;
        exit(2);
    }
    else   
    {
        file << this->x << " " << this->y << endl;
        file << endl;
        for (int i=0; i<x; i++)
        {
        for (int j=0; j<y; j++)
        {
        file << mac[i][j] << " ";
        }
        file << endl;
        }
        }

}


void matrix::input(string path)
{
    ifstream input;
    input.open(path);

    if (input.is_open())
    {
        input >> this->x; // odczytanie z pliku rozmiaru macierzy
        input >> this->y;


        matrix m3(this->x,this->y);
        for (int i=0; i<x; i++)
        {
        for (int j=0; j<y; j++)
            {
            input >> m3.mac[i][j];
            }
        }

        input.close();
    }
    else 
    {
        cout << "can't open the file !" << endl;
        exit(2);
    }

}

