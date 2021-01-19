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

int priorytet(char znak) {
  switch (znak)
  {
    case '-': ;
    case '+': 
        return 1;
    case '*': ;
    case '/': 
        return 2;
    case '^': 
        return 3;
    case 'q': ;
    case 'i': ;
    case 'o': ;
    case 't': ;    
    case 'g': 
        return 4;    
  }
  return 0;
}


int operatorCheck(int x)
{
    if (x < 48 || x > 57)
    {
        return 1;
    }
    return 0;
}

int numberCheck(int x)
{
    if (x > 47 && x < 58)
    {
        return 1;
    }
    return 0;
}

string wyrazenie = "(22.5-17+12)-(221*17)=";
int dlugosc = wyrazenie.length();

string temp;
int pom;
int liczba_cala;
string tablica[100];
int k;
int znak;
int ujemna;
int kropka;
int counter = 0;

string funkcje[] = {"sin", "cos", "tg", "ctg"};

int main()
{
    for (int a = 0; a<4; a++)
    {
        while((k = wyrazenie.find(funkcje[a])) != -1)
        {
            wyrazenie.replace(k, funkcje[a].length(), string(1,funkcje[a].at(1)));
        } 
    }

    cout << "Zakonczono zamiane"<< endl;
    cout << "wyrazenie:" << wyrazenie << endl;

    for(int i = 0; i<dlugosc;i++)
    {
        znak = wyrazenie[i];
        if(operatorCheck(znak) == 1)
        {
            if(znak == '-' && (i == 0 || (wyrazenie[i-1] == '(' && numberCheck(wyrazenie[i+1]) == 1)))
            {
                ujemna = 1; 
            }

            if (znak == '.')
            {
                kropka = 1;
                //counter++;
            }
            else if (ujemna != 1 && kropka != 1)
            {
            tablica[counter] = wyrazenie[i];
            cout << "Z:[" << wyrazenie[i] << "] ";
            counter++;
            }

            
            
        } 

        if(numberCheck(znak) == 1)
        {
            pom=0;
            do 
            {
                temp[pom] = wyrazenie[i];
                i++;
                pom++;
            } while(numberCheck(wyrazenie[i]) == 1);
            i--;
            liczba_cala = stoi(temp);
            
            if(kropka != 1 && ujemna != 1)
                {
                cout << "NL:[" << liczba_cala << "] ";
                tablica[counter] = to_string(liczba_cala); //
                counter++;
                }


            if(ujemna == 1)
                {
                ujemna = 0;

                liczba_cala = -(liczba_cala);
                cout << "NL:[" << liczba_cala << "]";
                tablica[counter] = to_string(liczba_cala);
                counter++;
                }
                
            if (kropka == 1)
                {
                kropka = 0;
                counter--; 
                
                tablica[counter].push_back('.'); 
                tablica[counter] += to_string(liczba_cala);
                cout <<"kropkowane:" << tablica[counter];
                counter++;
                }

                
            

            for(int y=0;y<=pom;y++)
                {
                    temp[y] = 0;
                }
        }

        


    }

    cout << "ostatecznie:";
    for (int i = 0; i< 20; i++)
    {
        cout << tablica[i];
    }

    string znak_ONP; // pojedynczy znak
    string stos[100]; // stos
    string ONP_ready[100]; // tu zapisze gotowe ONP

    int stos_licznik = 0; // licznik od stosu
    int ONP_licznik = 0; //licznik od tablicy onp
    // p - licznik od tablicy z podzielonym wyrazeniem

    for(int p=0; p<sizeof(tablica); p++)
    {
        znak_ONP = tablica[p];

        if(znak_ONP == "=") 
        {
            while (stos_licznik > 0)
            {
                ONP_ready[ONP_licznik] = stos[--stos_licznik];
            }
            break;
            //goto wynik
        }

        if(znak_ONP.size() == 1) //wtedy mamy do czynienia ze znakiem
        {
            switch(znak_ONP[0])
            {
            case '(': 
                    stos[stos_licznik] = '(';
                    break;
                
                case ')': 
                    while(stos[stos_licznik - 1][0] != '(') {
                        ONP_ready[ONP_licznik++] = stos[--stos_licznik];
                    }
                    stos_licznik--;
                    break;    
                
                case '+': ;                
                case '-': ;
                case '*': ;
                case '/': ;
                case '^': ;
                case 'q': ;
                case 'i': ;
                case 'o': ;
                case 'g': ;
                case 't':
                    while(stos_licznik >= 0) 
                    {
                        if (stos_licznik != 0 && priorytet(stos[stos_licznik - 1][0]) >= priorytet(znak_ONP[0]))
                        {
                            ONP_ready[ONP_licznik++] = stos[--stos_licznik];
                        } else 
                        {
                            break;
                        }        
                    }
                    stos[stos_licznik++] = znak_ONP;
                    break;
                default:
                    ONP_ready[ONP_licznik++] = znak_ONP;
                    break;
            }

        } else ONP_ready[ONP_licznik++] = znak_ONP;
    }

  return 0;  
}

