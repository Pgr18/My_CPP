#include <iostream>
#include <regex>
#include <string>

class MathAction
{
public:
    virtual int exec(int a1, int a2) {};
    virtual ~MathAction() {};
};

class SumAction : public MathAction
{
public:
    int exec(int a1, int a2) override
    {
        return a1 + a2;
    }
};

class SubAction : public MathAction
{
public:
    int exec(int a1, int a2) override
    {
        return a1 - a2;
    }
};

class MultAction : public MathAction
{
public:
    int exec(int a1, int a2) override
    {
        return a1 * a2;
    }
};

class DivAction : public MathAction
{
public:
    int exec(int a1, int a2) override
    {
        return static_cast<int>(a1 / a2);
    }
};

class Calculator
{
private:
    SumAction sum;
    SubAction sub;
    DivAction div;
    MultAction mult;

public:
    enum MathOperation
    {
        Add = '+',
        Subtract = '-',
        Multiply = '*',
        Divide = '/'
    };
    Calculator() {};
    ~Calculator() {};
    int calc(MathOperation opr, int a1, int a2)
    {
        switch (opr)
        {
        case MathOperation::Add:
            return sum.exec(a1, a2);
            break;
        case MathOperation::Subtract:
            return sub.exec(a1, a2);
            break;
        case MathOperation::Multiply:
            return mult.exec(a1, a2);
            break;
        case MathOperation::Divide:
            return div.exec(a1, a2);
            break;
        }
    }
};

bool isValidFormat(std::string &input)
{
    std::regex pattern(R"(\d\s*[-+*/]\s*\d)");
    return std::regex_match(input, pattern);
}

bool parseComplexExpression(const std::string &input, double &num1, char &op, double &num2)
{
    std::istringstream iss(input);
    iss >> num1 >> op >> num2;
    if (iss.fail())
    {
        return false;
    }
    return true;
}

int main()
{

    Calculator calc;
    std::string expr;
    std::cout << "Enter expression in format /digit/ /operation/ /digit/" << std::endl;
    std::getline(std::cin, expr);
    try
    {
        double num1, num2;
        char op;

        remove_if(expr.begin(), expr.end(), isspace);
        while (!parseComplexExpression(expr, num1, op, num2))
        {
            std::cout << "Wrong expression" << std::endl;
            std::cout << "Enter expression in format /digit/ /operation/ /digit/" << std::endl;
            std::getline(std::cin, expr);
            remove_if(expr.begin(), expr.end(), isspace);
        }

        int res = calc.calc(static_cast<Calculator::MathOperation>(op), num1, num2);

        std::cout << "Result is " << res << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}