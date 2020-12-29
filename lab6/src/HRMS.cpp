#include <HRMS.hpp>


using namespace std;

void HRMS::add(Employee employee,string departmentId, double salary){
    string employee_ID = employee.id;

    if (salary < 0)
    {
        stringstream errorMsg;
        errorMsg << "Salary should be greater than 0" << endl;
        throw invalid_argument(errorMsg.str());
    }

    list<string>::iterator it;
    for (it = employees_id_check.begin(); it != employees_id_check.end(); it++)
    {
        if (*it == employee_ID)
        {
            stringstream errorMsg;
            errorMsg << "Could not create the second employee with the same ID! (id already exists)" << endl;
            throw invalid_argument(errorMsg.str());
        }
    }

    this->all_employees_map[employee_ID] = employee;
    this->employees_ID_DPT_map[employee_ID] = departmentId;
    this->employees_salaries_map[employee_ID] = salary;
}

void HRMS::printDepartment(string departmentId){

    map<string, string>::iterator it;


    cout << "All employees from department [" << departmentId << "]:" << endl;
    int counter=0;
    for (it = this->employees_ID_DPT_map.begin(); it != this-> employees_ID_DPT_map.end(); ++it)
    {
        if (it->second == departmentId)
        {
            cout << this->all_employees_map[it->first].name << " " << this->all_employees_map[it->first].surname << endl; //it->first to znaczy inaczej, że wypisuje z mapy Iddepartments tego pracownika ktory pracuje w dokladnie okreslonym departemancie, jego id moge pobrac z mapy it za pomoca it->first i wyprintowac jego imie i nazwisko
            counter++;
        }
    }
    if (counter > 0)
    cout << "Founded [" << counter << "] postions." << endl;
    else
    {
        cout << "Could not find any empolyees from " << departmentId << endl;
        cout << "At least one person works in this department?" << endl;
    }
    
}

void HRMS::changeSalary(string employeeId, double salary){
    
    if (salary < 0)
    {
        stringstream errorMsg;
        errorMsg << "Salary should be greater than 0" << endl;
        throw invalid_argument(errorMsg.str());

    }

    list<string>::iterator it;
    for (it = this->employees_id_check.begin(); it != this-> employees_id_check.end(); it++)
    {
        if (*it == employeeId)
        {
            stringstream errorMsg;
            errorMsg << "This ID does not exist in the system" << endl;
            throw invalid_argument(errorMsg.str());
        }
    }

    this->employees_salaries_map[employeeId] = salary;
}

void HRMS::printSalaries(){

    map<string, double>::iterator it;

    for (it = this->employees_salaries_map.begin(); it != this-> employees_salaries_map.end(); it++)
    {
        cout << "SALARY: " << it->second << " Position: " << this->all_employees_map[it->first].position <<
        " " << this->all_employees_map[it->first].name << " " << this->all_employees_map[it->first].surname <<
        " ID: " << this->all_employees_map[it->first].id << " DepartmentID: " << this->all_employees_map[it->first].departmentId << endl;

    }
}

void HRMS::printSalariesSorted(){

    vector<pair<string, double>> vec;
    map<string, double>::iterator it2;

    for (it2 = this->employees_salaries_map.begin(); it2 != this->employees_salaries_map.end(); it2++)
    {
        vec.push_back(make_pair(it2->first, it2->second));
    }

    sort(vec.begin(),vec.end(), sortByVal);

    vector<pair<string, double>>::iterator it;

    for (it = vec.begin(); it != vec.end(); it++)
    {
        cout << "SALARY: "<< it->second << " Position: " << this->all_employees_map[it->first].position <<
        " " << this->all_employees_map[it->first].name << " " << this->all_employees_map[it->first].surname << " ID: " <<
        this->all_employees_map[it->first].id << " DepartmentId: " << this->all_employees_map[it->first].departmentId << endl;
    }

}


bool HRMS::sortByVal(const pair<string, double> &a, const pair<string, double> &b)
{
    return (a.second > b.second);
}
