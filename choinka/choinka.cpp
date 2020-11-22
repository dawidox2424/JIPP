#include <iostream>
using namespace std;

void poziom(int x) 
{
    int temp = 0;
    for(int i = 0; i <= x; i++) {
        for(int j = 0; j <= temp; j++)
            cout << "*";
    cout<<endl;
    temp+=2;
    }

}

int main()
{
    int y;
    cout << "podaj liczbe poziomow: ";
    cin >> y;
    for (int i = 0; i < y; i++) {
        poziom(i);
    }
    return 0;
}