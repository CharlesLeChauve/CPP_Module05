#include "RobotomyRequestForm.hpp"
#include <cstdlib>  // Pour rand() et srand()
#include <ctime> 

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
    : AForm("Robotomy Request", 72, 45), target(target) 
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) 
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::exec_action() const {
    srand(time(NULL));
    bool success = rand() % 2;
    std::cout << "\033[1m*Make some Drilling Noise*\033[0m" << std::endl;
    if (success)
        std::cout << "Congratulations, " << target << " has been succesfully Robotomized !" << std::endl;
    else
        std::cout << "Oopsie, " << target << "'s brain looks like Marmelade now..." << std::endl;
}