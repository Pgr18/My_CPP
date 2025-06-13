
using namespace std;
#include <iostream>
#include <string>


class Animal
{
private:
    string name, nickname;
    int staminaPoints, distance;
    friend void printInfo(const Animal &a)
    {
        cout << "Info" << endl
             << a.name << endl
             << a.nickname << endl
             << a.staminaPoints << endl
             << a.distance << endl;
    }

public:
    Animal(string a_name, string a_nickname, int a_stamina, int a_distance) : name(a_name), nickname(a_nickname)
    {
        if (a_stamina >= 0)
        {
            staminaPoints = a_stamina;
        }
        else
        {
            staminaPoints = 0;
        }
        if (a_distance >= 0)
        {
            distance = a_distance;
        }
        else
        {
            distance = 0;
        }
    }

    Animal() : name("Unknown"), nickname("Unknown")
    {
        staminaPoints = 0;
        distance = 0;
    }

    ~Animal()
    {
        cout << "Distance is " << distance << endl;
    }

    void eat()
    {
        staminaPoints += 3;
        cout << "Name: " << name << endl
             << "Available stamina: " << staminaPoints << " points" << endl;
        while (staminaPoints > 5)
        {
            run();
            cout << "Run" << endl
                 << "Available stamina: " << staminaPoints << " points" << endl;
        }
    }

    void run()
    {
        if (staminaPoints >= 2)
        {
            staminaPoints -= 2;
            distance += 30;
        }
    }
};

int main()
{
    // Проверка конструкторов
    Animal test_a;
    Animal test_b("Test", "Test", 5, 10);
    Animal test_c("Test1", "Test1", -5, 10);
    Animal test_d("Test2", "Test2", -5, -10);
    Animal test_e("Test3", "Test3", 5, -10);
    // Проверка printInfo
    printInfo(test_a);
    printInfo(test_b);
    printInfo(test_c);
    printInfo(test_d);
    printInfo(test_e);
    // Проверка eat
    //test_b.eat();
    for (int i = 0; i<3; i++)
    {
    test_a.eat();
    }
    printInfo(test_a);
    printInfo(test_b);

    return 0;
}