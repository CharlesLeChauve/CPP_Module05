#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
    : AForm("ShrubberyCreation", 145, 137), target(target) 
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) 
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::exec_action() const {
    std::ofstream file;
    file.open(target + "_shrubbery");
    if (file.is_open()) {
        file << "        ccee88oo" << std::endl;
        file << "  C8O8O8Q8PoOb o8oo" << std::endl;
        file << " dOB69QO8PdUOpugoO9bD" << std::endl;
        file << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
        file << "    6OuU  /p u gcoUodpP" << std::endl;
        file << "      \\\\\\//  /douU" << std::endl;
        file << "        \\\\\\////" << std::endl;
        file << "         |||/\\" << std::endl;
        file << "         |||\\/" << std::endl;
        file << "         |||||" << std::endl;
        file << "   .....//||||\\...." << std::endl;
        file.close();
    } else {
        std::cerr << "Error: Could not open file." << std::endl;
    }
}