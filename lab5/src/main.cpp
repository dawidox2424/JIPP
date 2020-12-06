#include <iostream>
#include <conio.h>
#include <windows.h>
#include "matrix.hpp"
#include <fstream>
using namespace std;

void test()
{
    matrix first(-1,5);
    int cols = first.cols();
    int rows = first.rows();

    cout << cols << endl;
    cout << rows << endl;

    double temp = 3;

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

    matrix third = first.multiply(second);
    cout << "matrix third = first * second" << endl;
    third.print();

    matrix fourth =third.add(first);
    cout << "fourth = first + third:" << endl;
    fourth.print();

    matrix fifth = third.subtract(first);
    cout << "fifth = third - first" << endl;
    fifth.print();

    cout << "creating the store for fifth matrix..." << endl;
    fifth.store("fifth.txt","fifth.txt");

    cout << "reading matrix fifth from the file!" << endl;
    fifth.input("fifth.txt");
    fifth.print();
}


int main()
{
    test();

    return 0;
}

