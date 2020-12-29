#include <string>

using namespace std;

#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

class Employee {
public:
    string id, name, surname, departmentId, position;


    Employee(string id, string name, string surname, string departmentId, string position);
    Employee();

    //string getId();
    //string getName();
   // string getSurname();
   // string getPosition();
   // string getDepartmentId();
};

#endif