#include <HRMS.hpp>
#include <employee.hpp>
#include <iostream>



using namespace std;


int main()
{

    HRMS system;

    Employee first("M_PL1", "Adam", "Kowalski", "ID1", "tester");
    Employee second("id_3", "Jan", "Nowak", "ID1", "majster");
    Employee third("00213108795", "Marek", "Nowakowski", "ID2", "hipster");
    Employee fourth("M_LpEL", "Zbigniew", "Niedzielski", "ID2", "kucharz");
    Employee fifth("412", "Jarek", "Staszic", "ID3", "mistrz");
    Employee sixth("512", "Michal", "Budnicz", "ID4", "kierownik");
    Employee seventh("290", "Radoslaw", "Batowski", "ID4", "menager");
    Employee eighth("0013", "Tadeusz", "Brzeczyszczykiewicz", "ID5", "zarzadca");
    Employee nineth("ajdi", "Olek", "Amator", "ID5", "pracownik_1");
    Employee tenth("ID", "Bartosz", "Weglarzyk", "ID6", "pracownik_1");

    system.add(first, "ID1", 2100);
    system.add(second, "ID1", 1900);
    system.add(third, "ID2", 2300);
    system.add(fourth, "ID2", 3300);
    system.add(fifth, "ID3", 1500);
    system.add(sixth, "ID4", 2076);
    system.add(seventh, "ID4", 2077);
    system.add(eighth, "ID5", 1997);
    system.add(nineth, "ID5", 2000);
    system.add(tenth, "ID6", 2002);

    system.printSalaries();

    try
    {
    system.changeSalary("512", 2138);
    }
    catch (invalid_argument &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    cout << endl;
    cout << endl;

    system.printSalaries();

    cout << endl;
    cout << endl;

    system.printSalariesSorted();

    cout << endl;
    cout << endl;


    system.printDepartment("ID12");


}