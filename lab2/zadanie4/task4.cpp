#include <iostream>
using namespace std;

double fun4(int &ref_a, int b)
 {
     double suma = ref_a + b;
     ref_a = b * ref_a;
     return suma;
 }

int main()
{
    int a=0;
    int b=0;

    int &ref_a = a;

    cout << "Podaj a:";
    cin >> a;
    cout << endl;
    cout << "Podaj b:";
    cin >> b;

    cout << "Po wyk. funkcji:" << endl;
    cout << "Suma = "<< fun4(ref_a, b) << ", iloczyn = " << ref_a << endl;
    

return 0;
}



