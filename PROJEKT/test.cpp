#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

string tablica[100];
string temp;

int main()
{
    temp = "27";
    tablica[0] = "127";
    tablica[0].push_back('.');
    tablica[0]+=temp;

    cout << tablica[0];
    return 0;
}