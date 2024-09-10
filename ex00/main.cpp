#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat john("John", 2);
        std::cout << john << std::endl;
        john.raiseGrade();
        std::cout << "After increment: " << john << std::endl;
        john.raiseGrade(); //Not valid, should throw
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat jane("Jane", 151); //Not valid, should throw
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bob("Bob", 0); //Not valid, should throw
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat alice("Alice", 149);
        std::cout << alice << std::endl;
        alice.lowerGrade();
        std::cout << "After decrement: " << alice << std::endl;
        alice.lowerGrade(); //Not valid, should throw
        std::cout << "After decrement: " << alice << std::endl; //Should still be 150
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
