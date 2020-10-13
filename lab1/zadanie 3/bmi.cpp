#include <iostream>
#include <string.h>
using namespace std;

int main()
{

double masa_ciala = 0;
double wzrost = 0;
double BMI = 0;
    
cout << "Prosze, podaj swoja wage w KG:" << endl;
cin >> masa_ciala;
cout << "Prosze, podaj swoj wzrost w [cm]:" << endl;
cin >> wzrost;

wzrost = wzrost/100;

BMI = (masa_ciala)/(wzrost * wzrost); // masa_ciala [kg], wzrost [m]

cout << "Obliczone BMI: " << BMI << endl;

//switch 
if (BMI == 0)  cout << "BRAK DANYCH!";
else if (BMI <16) cout << "wygłodzenie";
else if (BMI>16 & BMI < 16.99) cout << "wychudzenie";
else if (BMI>17 & BMI < 18.49) cout << "niedowaga";
else if (BMI>18.5 & BMI < 24.99) cout << "wartość prawidłowa";
else if (BMI>25 & BMI < 29.99) cout << "nadwaga";
else if (BMI>30 & BMI < 34.99) cout << "I stopień otyłości";
else if (BMI>35 & BMI < 39.99) cout << "II stopień otyłości";
else if (BMI>40) cout << "otyłość skrajna";
else cout << "Sprawdz poprawnosc wpisanych danych";

return 0;
}