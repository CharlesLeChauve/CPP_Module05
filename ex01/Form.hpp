#pragma once
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	name;
	bool				approved;
	const int			signGrade;
	const int			execGrade;
public:
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		const char* what() const throw();
	};
	void	beSigned(const Bureaucrat& bc);
	bool getApproved() const;
	int getSignGrade() const;
	int getExecGrade() const;
	const std::string& getName() const;
	Form(const std::string &name, int signGrade, int execGrade);
	~Form();
};

std::ostream& operator<<(std::ostream& os, const Form& form);

