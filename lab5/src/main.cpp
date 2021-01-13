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
        matrix first(3,-5);
        }
    catch (invalid_argument &e){
        cout << "error message: " << e.what() << endl;
    }
        matrix first(3,5);
        int cols = first.cols();
        int rows = first.rows();
        double temp = 3;
        cout << first.cols() << endl;
        cout << first.rows() << endl;

        for (int i = 0; i < rows; i++)
        {
        for (int j = 0; j < cols; j++)
        {
            first.set(i, j, temp);
            temp += 1.2;
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
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
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

    matrix *fifth;

    matrix fifth = third - first;
    cout << "fifth = third - first" << endl;
    fifth->print();

    cout << "creating the store for fifth matrix..." << endl;
    fifth->store("fifth.txt","fifth.txt");

    cout << "reading matrix fifth from the file!" << endl;
    fifth->input("fifth.txt");
    fifth->print();
    
}


int main()
{
    test();

    return 0;
}

