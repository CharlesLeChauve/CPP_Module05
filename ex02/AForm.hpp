#pragma once
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class AForm
{
protected:
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
	AForm(const std::string &name, int signGrade, int execGrade);
	~AForm();
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

