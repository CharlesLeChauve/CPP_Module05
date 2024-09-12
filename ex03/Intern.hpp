#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &other);
	~Intern();
	Intern &operator=(const Intern &other);

	AForm* makeForm(std::string name, std::string target);
};

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	if (&other != this) {}
	return (*this);
}

Intern::~Intern()
{
}

AForm* createShrubberyCreationForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* createRobotomyRequestForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* createPresidentialPardonForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string ids[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};
	AForm *(*creators[3])(const std::string&) = {
		createPresidentialPardonForm,
		createRobotomyRequestForm,
		createShrubberyCreationForm
	};

	for (int i = 0; i < 3; i++) {
		if (ids[i] == name) {
			std::cout << "Intern creates " << name << std::endl;
			return (creators[i](target));
		}
	}
	std::cout << "Asked form does not exist yet, don't expect too much from an intern" << std::endl;
	return (NULL);
}
