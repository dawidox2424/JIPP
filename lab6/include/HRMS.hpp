#include <employee.hpp>
#include <list>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <exception>
#include <excpt.h>
#include <sstream>

using namespace std;

#ifndef HRMS_HPP
#define HRMS_HPP

class HRMS {

    list<string> employees_id_check; //dodatkowa lista do exception

    map<string, Employee> all_employees_map;
    map<string, string> employees_ID_DPT_map;
    map<string, double> employees_salaries_map;

    static bool sortByVal(const pair<string, double> &a, const pair<string, double> &b);

public:
    void add(Employee employee,string departmentId, double salary);
    void printDepartment(string departmentId);
    void changeSalary(string employeeId, double salary);
    void printSalaries();
    void printSalariesSorted();
};
#endif