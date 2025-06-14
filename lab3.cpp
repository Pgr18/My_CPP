#include <vector>
#include <iostream>
#include <string>

#include <typeinfo>


class Employee
{
protected:
    std::string name;
    bool isWorking;
    int salary;

public:
    virtual void startWork() {};
    virtual void stopWork() {};
    virtual void printStatus() {};

    int getSalary()
    {
        return salary;
    }
    virtual ~Employee() {};
};

class Team
{
private:
    std::vector<Employee *> employees;

public:
    void addEmployee(Employee *emp)
    {
        employees.emplace_back(emp);
    }

    void startWork()
    {
        for (size_t i= 0; i < employees.size(); ++i)
        {
            employees[i]->startWork();
        }

    }

    void stopWork()
    {
        for (size_t i= 0; i < employees.size(); ++i)
        {
            employees[i]->stopWork();
        }
    }

    void printStatus()
    {
        for (size_t i= 0; i < employees.size(); ++i)
        {
            employees[i]->printStatus();
        }
    }

    const std::vector<Employee *> &getEmployees()
    {
        return employees;
    }
    
};

class Director : public Employee
{
public:
    Director() {};
    Director(std::string a_name, bool a_isWorking, int a_salary)
    {
        name = a_name;
        isWorking = a_isWorking;
        salary = a_salary;
    };

    void startWork() override
    {
        isWorking = true;
        std::cout << typeid(*this).name() << " " << name << " " << "start work" << std::endl;
    }

    void stopWork() override
    {
        isWorking = false;
        std::cout << typeid(*this).name() << " " << name << " " << "stop work" << std::endl;
    }

    void printStatus() override
    {
        std::cout << typeid(*this).name() << " " << name << " " << (isWorking ? "is working" : "isn't working") << std::endl;
    }
    ~Director() {};
};

class Manager : public Employee
{
public:
    Manager() {};
    Manager(std::string a_name, bool a_isWorking, int a_salary)
    {
        name = a_name;
        isWorking = a_isWorking;
        salary = a_salary;
    };

    void startWork() override
    {
        isWorking = true;
        std::cout << typeid(*this).name() << " " << name << " " << "start work" << std::endl;
    }

    void stopWork() override
    {
        isWorking = false;
        std::cout << typeid(*this).name() << " " << name << " " << "stop work" << std::endl;
    }

    void printStatus() override
    {
        std::cout << typeid(*this).name() << " " << name << " " << (isWorking ? "is working" : "isn't working") << std::endl;
    }
    ~Manager() {};
};

class Cleaner : public Employee
{
public:
    Cleaner() {};
    Cleaner(std::string a_name, bool a_isWorking, int a_salary)
    {
        name = a_name;
        isWorking = a_isWorking;
        salary = a_salary;
    };
    void startWork() override
    {
        isWorking = true;
        std::cout << typeid(*this).name() << " " << name << " " << "start work" << std::endl;
    }

    void stopWork() override
    {
        isWorking = false;
        std::cout << typeid(*this).name() << " " << name << " " << "stop work" << std::endl;
    }

    void printStatus() override
    {
        std::cout << typeid(*this).name() << " " << name << " " << (isWorking ? "is working" : "isn't working") << std::endl;
    }
    ~Cleaner() {};
};

int main()
{

    Director dir1("Director",false,500);
    Manager mang1("Manager",true,200);
    Cleaner clean1("Cleaner",true, 100);
    Team team1;

    team1.addEmployee(&dir1);
    team1.addEmployee(&mang1);
    team1.addEmployee(&clean1);

    team1.stopWork();
    team1.printStatus();
    dir1.startWork();
    team1.printStatus();
    mang1.startWork();
    team1.printStatus();
    clean1.startWork();
    team1.printStatus();

    std::cout << "Sum salary is " << (dir1.getSalary() + mang1.getSalary() + clean1.getSalary()) << std::endl;



    return 0;
}