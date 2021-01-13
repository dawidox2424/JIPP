#include <iostream>
#include <conio.h>
#include <windows.h>
#include "matrix.hpp"
//#include <include/matrix.hpp>
#include <fstream>
using namespace std;


matrix::matrix(int x,int y)
{ 
    if(x<=0)
    {
        throw invalid_argument("nie mozna utworzyc macierzy o wymiarze X zerowym lub ujemnym");
    }
    else if(y<=0)
    {
        throw invalid_argument("nie mozna utworzyc macierzy o wymiarze Y o zerowym lub ujemnym");
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
    if(x<=0)
    {
        throw invalid_argument("nie mozna utworzyc macierzy kwadratowej o wymiarze zerowym lub ujemnym");
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
           throw invalid_argument("Jestes poza wymiarem macierzy lub podajesz ujemne wspolrzedne komorki");
        }
    
    mac[x][y] = value;
}

double matrix::get(int x,int y)
{

    if (x < 0 || y < 0 || x > this->x || y > this->y)
        {
            throw invalid_argument("Jestes poza wymiarem macierzy lub podajesz ujemne wspolrzedne komorki");
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

matrix matrix::operator+(matrix m2)
{
    if (this->x != m2.x || this->y != m2.y)
        {
            throw invalid_argument("Nie mozna dodac macierzy o roznych rozmiarach!");
        }



    matrix m3(this->x,this->y);

    for (int i=0; i<x; i++)
        for (int j=0; j<y; j++)
            m3.mac[i][j] = m2.mac[i][j] + this->mac[i][j];

            return m3;
}

matrix matrix::operator-(matrix m2)
{

    if (this->x != m2.x || this->y != m2.y)
        {
            throw invalid_argument("Nie mozna odjac macierzy o roznych rozmiarach!");
        }


    matrix m3(this->x,this->y);

    for (int i=0; i<x; i++)
        for (int j=0; j<y; j++)
            m3.mac[i][j] = this->mac[i][j] - m2.mac[i][j];

            return m3;
}

matrix matrix::operator*(matrix m2)
{

    if (this->x != m2.x)
        {
            throw invalid_argument("Podane macierze nie spelniaja warunkow do mnozenia!");
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
         throw invalid_argument("Blad w otwarciu pliku");
    }
 
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

    if (input.good() == false)
    {
         throw invalid_argument("Nie mozna otworzyc pliku do inputa");
    }

}

ostream& operator<<(ostream &out, matrix m2)
{
    out << m2.cols() << " " << m2.rows() << endl;
    for (int i = 0; i < m2.cols(); i++) {
        for (int j = 0; j < m2.rows(); j++)
        {
            out << m2.get(i, j) << ' ';
        }
        out << endl;
    }
    return out;
}

bool matrix::operator==(matrix m2) {
    if (x != m2.x || y != m2.y) {
        cout << "111" << endl;
        return false;
    }

    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            if (mac[i][j] - m2.mac[i][j] > 0.0000000001)
                return false;

    return true;
}

double *matrix::operator[](int i) 
{
    if (i >= this->x) 
    {
    throw invalid_argument("Jestes poza zakresem macierzy");
    } else if (i < 0) 
    {
        throw invalid_argument("Jestes poza zakresem macierzy (wartosc ujemna!!)");
    }

    return mac[i];
}