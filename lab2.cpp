using namespace std;
#include <iostream>
#include <string>
#include <cmath>

class Student
{
private:
    string name, surname;
    int mathPoints, languagePoints, informationPoints, age;
    double gpa;

    void recalcGPA()
    {
        gpa = static_cast<double>(mathPoints + languagePoints + informationPoints) / 3;
    }

public:
    Student() : name("Unknown"), surname("Unknown")
    {
        mathPoints = 0;
        languagePoints = 0;
        informationPoints = 0;
        age = 0;
    }

    Student(string a_name, string a_surname) : name(a_name), surname(a_surname)
    {
        mathPoints = 0;
        languagePoints = 0;
        informationPoints = 0;
        age = 0;
    }
    // setters for name and surname
    void setName(string a_name)
    {
        if (!a_name.empty())
        {
            name = a_name;
        }
    }

    void setSurname(string a_surname)
    {
        if (!a_surname.empty())
        {
            surname = a_surname;
        }
    }

    void setMathPoints(int m_points)
    {
        if ((m_points <= 5) && (m_points > 0))
        {
            if (m_points != mathPoints)
            {
                mathPoints = m_points;
                recalcGPA();
            }
            else
                mathPoints = m_points;
        }
    }

    void setLanguagePoints(int l_points)
    {
        if ((l_points <= 5) && (l_points > 0))
        {
            if (l_points != languagePoints)
            {
                languagePoints = l_points;
                recalcGPA();
            }
            else
                languagePoints = l_points;
        }
    }

    void setInformationPoints(int i_points)
    {
        if ((i_points <= 5) && (i_points > 0))
        {
            if (i_points != informationPoints)
            {
                informationPoints = i_points;
                recalcGPA();
            }
            else
                informationPoints = i_points;
        }
    }
    // My age filtration
    void setAge(int a_age)
    {
        if ((a_age >= 16) && (a_age <= 100))
        {
            age = a_age;
        }
    }

    // const getters
    string getName() const
    {
        return name;
    }

    string getSurname() const
    {
        return surname;
    }

    int getAge() const
    {
        return age;
    }

    double getGPA(bool a_round = false) const
    {
        return a_round ? round(gpa) : gpa;
    }

    // printinfo
};

void printInfo(const Student &s)
{

    cout << "Name is " << s.getName() << endl;
    cout << "Surname is " << s.getSurname() << endl;
    cout << "Age is " << s.getAge() << " y.o." << endl;
    cout << "Average not rounded point for math, language and information is " << s.getGPA(false) << endl;
    cout << "Average rounded point for math, language and information is " << s.getGPA(true) << endl;
}

int main()
{

    // empty object
    Student s_1;

    // non empty object

    Student s_2("Name2", "Surname2");

    s_2.setAge(20);
    s_2.setInformationPoints(4);
    s_2.setLanguagePoints(3);
    s_2.setMathPoints(4);
    printInfo(s_2);

    s_2.setAge(0);
    s_2.setInformationPoints(10);
    s_2.setLanguagePoints(0);
    s_2.setMathPoints(3);
    printInfo(s_2);

    s_1.setAge(110);
    s_1.setInformationPoints(-110);
    s_1.setLanguagePoints(110);
    s_1.setMathPoints(110);
    printInfo(s_1);

    return 0;
}