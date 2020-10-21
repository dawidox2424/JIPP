#include <iostream>
#include <algorithm>
using namespace std;

void zamien(int &a,int &b)
{
    swap(a,b);   
} 

int main()
{
    int a;
    int b;

    int &ref_a = a;
    int &ref_b = b;

    cout << "Podaj a:"; cin >> a;
    cout << endl;
    cout << "Podaj b:"; cin >> b;

    zamien(ref_a,ref_b);

    cout << "a:" << a << endl;
    cout << "b:" << b << endl;

return 0;
}
