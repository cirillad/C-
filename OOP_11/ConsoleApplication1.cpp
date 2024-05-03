#include <iostream>

using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    Person() : name(""), age(0) {}

    Person(string newName, int newAge) : name(newName), age(newAge) {}

    void display() const
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Employee : public Person
{
private:
    int id;
    double salary;

public:
    Employee() : Person(), id(0), salary(0) {}

    Employee(string newName, int newAge, int newId, double newSalary) : Person(newName, newAge), id(newId), salary(newSalary) {}

    void display() const
    {
        Person::display();
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl;
    }

    int getId() const
    {
        return id;
    }

    int getSalary() const
    {
        return salary;
    }

    void setId(int newId)
    {
        id = newId;
    }

    void setSalary(double newSalary)
    {
        salary = newSalary;
    }

    void raiseSalary(int numToIncrease)
    {
        salary += numToIncrease;
    }
};

class Manager : public Employee
{
private:
    string department;

public:
    Manager() : Employee(), department("") {}

    Manager(string newName, int newAge, int newId, double newSalary, string newDepartment) : Employee(newName, newAge, newId, newSalary), department(newDepartment) {}

    void display() const
    {
        Employee::display();
        cout << "Department: " << department << endl;
    }

    void changeDepartment(string newDepartment)
    {
        department = newDepartment;
    }

    void raiseSalary(int numToIncrease)
    {
        double increase = numToIncrease * 1.1;
        Employee::raiseSalary(increase);
    }
};

void displayEmployeeWithHighestSalary(const Employee employees[], int size)
{
    if (size <= 0)
    {
        cout << "No employees to display." << endl;
        return;
    }

    const Employee* highestSalaryEmployee = &employees[0];
    for (int i = 1; i < size; ++i)
    {
        if (employees[i].getSalary() > highestSalaryEmployee->getSalary())
        {
            highestSalaryEmployee = &employees[i];
        }
    }

    cout << "Employee with the highest salary:\n";
    highestSalaryEmployee->display();
}

void changeDepartmentById(Manager managers[], int size, int id, const string& newDepartment)
{
    if (size <= 0)
    {
        cout << "No managers to change department." << endl;
        return;
    }

    bool found = false;
    for (int i = 0; i < size; ++i)
    {
        if (managers[i].getId() == id)
        {
            managers[i].changeDepartment(newDepartment);
            cout << "Department of manager with ID " << id << " changed to " << newDepartment << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Manager with ID " << id << " not found." << endl;
    }
}

void mainMenu(Employee employees[], int numEmployees, Manager managers[], int numManagers, Person persons[], int numPersons)
{
    while (true)
    {
        int id = 0;
        cout << "\nMain Menu:\n";
        cout << "1. Display Employees\n";
        cout << "2. Display Managers\n";
        cout << "3. Display Persons\n";
        cout << "4. Change Manager's Department\n";
        cout << "5. Find Employee with Highest Salary\n";
        cout << "6. Increase Employee's Salary\n";
        cout << "7. Increase Manager's Salary\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Information about employees:" << endl;
            for (int i = 0; i < numEmployees; ++i)
            {
                employees[i].display();
                cout << endl;
            }
            break;
        case 2:
            cout << "Information about managers:" << endl;
            for (int i = 0; i < numManagers; ++i)
            {
                managers[i].display();
                cout << endl;
            }
            break;
        case 3:
            cout << "Information about persons:" << endl;
            for (int i = 0; i < numPersons; ++i)
            {
                persons[i].display();
                cout << endl;
            }
            break;
        case 4:
            cout << "Enter Manager ID: ";
            cin >> id;
            if (id <= 0) {
                cout << "Invalid ID. Please enter a positive integer.\n";
                break;
            }
            {
                string newDepartment;
                cout << "Enter new Department: ";
                cin >> newDepartment;
                changeDepartmentById(managers, numManagers, id, newDepartment);
            }
            break;
        case 5:
            displayEmployeeWithHighestSalary(employees, numEmployees);
            break;
        case 6:
            cout << "Enter Employee ID: ";
            cin >> id;
            if (id <= 0) {
                cout << "Invalid ID. Please enter a positive integer.\n";
                break;
            }
            {
                double raiseAmount;
                cout << "Enter raise amount: ";
                cin >> raiseAmount;
                bool found = false;
                for (int i = 0; i < numEmployees; ++i)
                {
                    if (employees[i].getId() == id)
                    {
                        employees[i].raiseSalary(raiseAmount);
                        cout << "Salary of employee with ID " << id << " increased by " << raiseAmount << endl;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Employee with ID " << id << " not found." << endl;
                }
            }
            break;
        case 7:
            cout << "Enter Manager ID: ";
            cin >> id;
            if (id <= 0) {
                cout << "Invalid ID. Please enter a positive integer.\n";
                break;
            }
            {
                double raiseAmount;
                cout << "Enter raise amount: ";
                cin >> raiseAmount;
                bool found = false;
                for (int i = 0; i < numManagers; ++i)
                {
                    if (managers[i].getId() == id)
                    {
                        managers[i].raiseSalary(raiseAmount);
                        cout << "Salary of manager with ID " << id << " increased by " << raiseAmount << endl;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Manager with ID " << id << " not found." << endl;
                }
            }
            break;
        case 8:
            cout << "Exiting program...\n";
            return;
        default:
            cout << "Invalid choice. Please enter again.\n";
            break;
        }
    }
}

int main()
{
    const int numPersons = 5;
    Person persons[numPersons] = {
        Person("John", 30),
        Person("Alice", 25),
        Person("Bob", 35),
        Person("Michael", 40),
        Person("Emily", 22)
    };

    const int numEmployees = 3;
    Employee employees[numEmployees] = {
        Employee("John", 30, 1, 50000),
        Employee("Alice", 25, 2, 60000),
        Employee("Bob", 35, 3, 55000) };

    const int numManagers = 2;
    Manager managers[numManagers] = {
        Manager("Manager1", 40, 101, 80000, "HR"),
        Manager("Manager2", 45, 102, 75000, "Finance") };

    mainMenu(employees, numEmployees, managers, numManagers, persons, numPersons);

    return 0;
}
