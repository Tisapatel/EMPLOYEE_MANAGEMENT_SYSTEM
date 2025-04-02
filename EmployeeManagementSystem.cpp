#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Employee
{
public:
    int empID;
    string name;
    int age;
    string department;
    float salary;
    int attendance;
    float bonus;



    // Default Constructor
    //   Employee() {
    //     empID = 0;
    //     age = 0;
    //     salary = 0.0;
    //     attendance = 0;
    //     bonus = 0.0;
    // }
    // aa banne thi kari sakay but aa ak line ma pati jase
    
    Employee() : empID(0), age(0), salary(0.0), attendance(0), bonus(0.0) {}

    void addEmployee()
    {
        cout << " Enter Employee ID: ";
        cin >> empID;
        cin.ignore();
        cout << " Enter Name: ";
        getline(cin, name);
        cout << " Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << " Enter Department: ";
        getline(cin, department);
        cout << " Enter Salary: ";
        cin >> salary;

        saveToFile();
        cout << " Employee added successfully!\n";
    }

    void markAttendance(int days)
    {
        attendance += days;
        cout <<" Attendance marked for " << days << " days.\n";
    }

    void calculateSalary()
    {
        float finalSalary = salary + bonus;
        cout <<" Final Salary: " << finalSalary << "\n";
    }

    void applyIncrement(float percent)
    {
        salary += salary * (percent / 100);
        cout <<" Salary incremented by " << percent << "%.\n";
    }

    void grantBonus(float amount)
    {
        bonus += amount;
        cout <<" Bonus granted: " << amount << "\n";
    }

    void displayEmployee()
    {

        {
            ifstream inFile("employees.txt");
            string line;
            cout << "\nEmployee Records:\n";
            while (getline(inFile, line))
            {
                cout << line << endl;
            }
            inFile.close();
        }
        
    }
    private:
    void saveToFile()
    {
        ofstream outFile("employees.txt", ios::app);
        outFile << "ID: " << empID << ", Name: " << name << ", Age: " << age
                << ", Dept: " << department << ", Salary: " << salary << "\n";
        outFile.close();
    }
};

int main()
{
    int choice;
    Employee emp;
    do
    {
        cout << endl;
        cout << "\t\t-----------------------------------" << endl;
        cout << "\t\t>> EMPLOYEE MANAGEMENT SYSTEM :- <<" << endl;
        cout << "\t\t-----------------------------------" << endl;
        cout << "\t\t 1. Add Employee" << endl;
        cout << "\t\t 2. Mark Attendance" << endl;
        cout << "\t\t 3. Calculate Salary" << endl;
        cout << "\t\t 4. Apply Increment" << endl;
        cout << "\t\t 5. Grant Bonus" << endl;
        cout << "\t\t 6. Display Employees" << endl;
        cout << "\t\t 7. Exit" << endl;
        cout << "\t\t...................................." << endl;
        cout << "\t\t>> Choice Options:[1/2/3/4/5/6/7] <<" << endl;
        cout << "\t\t...................................." << endl;
        cout << "\n Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            emp.addEmployee();
            break;
        case 2:
            emp.markAttendance(5);
            break;
        case 3:
            emp.calculateSalary();
            break;
        case 4:
            emp.applyIncrement(10);
            break;
        case 5:
            emp.grantBonus(2000);
            break;
        case 6:
            emp.displayEmployee();
            break;
        case 7:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid choice! Try again.";
        }
    } while (choice != 7);

    return 0;
}