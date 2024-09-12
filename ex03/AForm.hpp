#pragma once
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string	name;
	bool				approved;
	const int			signGrade;
	const int			execGrade;
public:
	class FormNotSignedException : public std::exception
	{
		public:
		const char* what() const throw();
	};
	void	beSigned(const Bureaucrat& bc);
	bool getApproved() const;
	int getSignGrade() const;
	int getExecGrade() const;
	const std::string& getName() const;
	void execute(Bureaucrat const & executor) const;

	virtual void exec_action() const = 0;

	AForm(const std::string &name, int signGrade, int execGrade);
	virtual ~AForm();
	AForm(const AForm& other);  // Constructeur de copie
	AForm& operator=(const AForm& other);  // Surcharge de l'opérateur d'assignation
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

