#include <iostream>
#include <conio.h>
#include <windows.h>
#include "matrix.hpp"
#include <fstream>
#include <exception>
#include <excpt.h>
using namespace std;

void test()
{
    try {
        matrix first_test(3,-5);
        }
    catch (invalid_argument &e)
        {
        cout << "error message: " << e.what() << endl;
        }

        matrix first(3,5);
        int cols = first.cols();
        int rows = first.rows();
        double temp = 3;
        cout << cols << endl;
        cout << rows << endl;

        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
            {
            first.set(i, j, temp);
            temp += 2.1;
            }
        }
    

    cout << "first matrix:" << endl;
    first.print();


    
    
    try {
        matrix second(-5);
        }
        catch (invalid_argument &e){
        cout << "error message: " << e.what() << endl;
    }

    matrix second(5);
    cols = second.cols();
    rows = second.rows();

    temp = 0;
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            second.set(i, j, temp);
            temp += 0.7;
        }
    }

    cout << "second matrix:" << endl;
    second.print();


    matrix third = first * second;
    cout << "matrix third = first * second" << endl;
    third.print();

    
    matrix fourth = third + first;


    cout << "fourth = first + third:" << endl;
    fourth.print();

    int l = first>2;
    cout << "Czy wszystkie elementy macierzy first sa wieksze od 2. ?" <<l << endl;

    int p = second<2;
    cout << "Czy wszystkie elementy macierzy second sa mniejsze od 2. ?" <<p << endl;

    double* test = first[2];
    cout << "first[2]: " << *test << endl;

    if(first==second)
    {
        cout << "macierz first i second sa identyczne" << endl;
    }else
    {
       cout << "macierz first i second nie sa identyczne" << endl;
    }
    

}


int main()
{
    test();

    return 0;
}

