#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

class matrix
{
    public:

    int x,y;
    double **mac;

    matrix(int x,int y); // tworzenie mac o rozmiarze x/y

    matrix(int x); // mac kwadratowa

    void set(int x,int y, double value);

    double get(int x,int y);

    matrix add(matrix m2);
    matrix subtract(matrix m2);
    matrix multiply(matrix m2);

    int cols();

    int rows();

    void print();

    void store(string filename,string path);

    void input(string path);


};