#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        // Création de bureaucrates avec différents grades
        Bureaucrat highRank("Alice", 1);   // Grade élevé
        Bureaucrat midRank("Bob", 75);     // Grade moyen
        Bureaucrat lowRank("Charlie", 150); // Grade bas

        // Création de formulaires avec des niveaux requis pour signer et exécuter
        Form contract("Contract", 50, 25);
        Form report("Report", 100, 80);

        // Test 1 : Bureaucrat with high rank signs a form (success case)
        std::cout << contract << std::endl;
        highRank.signForm(contract);   // Alice devrait pouvoir signer car son grade est 1
        std::cout << contract << std::endl;

        // Test 2 : Bureaucrat with mid rank signs a form (failure case)
        std::cout << report << std::endl;
        midRank.signForm(report);      // Bob devrait pouvoir signer ce formulaire
        std::cout << report << std::endl;

        // Test 3 : Bureaucrat with low rank tries to sign a form (failure case)
        lowRank.signForm(contract);    // Charlie ne devrait pas pouvoir signer le formulaire "Contract"
        std::cout << contract << std::endl;

        // Test 4 : Invalid form creation (exception case)
        Form invalidForm("InvalidForm", 0, 160); // Devrait générer une exception
    } 
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

