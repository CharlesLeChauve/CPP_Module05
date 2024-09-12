#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        // Création d'un bureaucrate avec un grade élevé
        Bureaucrat highRankBureaucrat("Alice", 1);

        // Création d'un bureaucrate avec un grade moyen
        Bureaucrat midRankBureaucrat("Bob", 50);

        // Création d'un bureaucrate avec un grade faible
        Bureaucrat lowRankBureaucrat("Charlie", 150);

        // Création de formulaires
        ShrubberyCreationForm shrubForm("home");
        RobotomyRequestForm robotForm("Mommy");
        PresidentialPardonForm pardonForm("The User");

        std::cout << "Attempting to sign forms:\n";
        highRankBureaucrat.signForm(shrubForm);
        midRankBureaucrat.signForm(robotForm);
        lowRankBureaucrat.signForm(pardonForm); // Devrait échouer

        std::cout << "\nAttempting to execute forms:\n";
        highRankBureaucrat.executeForm(shrubForm);   // Devrait fonctionner
        highRankBureaucrat.executeForm(robotForm);   // Devrait fonctionner
        midRankBureaucrat.executeForm(pardonForm);   // Devrait échouer car pas signé
        highRankBureaucrat.signForm(pardonForm);
        midRankBureaucrat.executeForm(pardonForm);   // Devrait fonctionner cette fois-ci
        lowRankBureaucrat.executeForm(shrubForm);    // Devrait échouer (grade trop bas)
        
    }
    catch (std::exception &e) {
        //std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

