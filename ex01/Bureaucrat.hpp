#pragma once
#include <iostream>
#include <stdexcept>

class Form;

class Bureaucrat
{
private:
	const	std::string name;
	int		grade;
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
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &other);

	const std::string &getName() const;
	int getGrade() const;

	void	signForm(Form& Form);

	void	raiseGrade();
	void	lowerGrade();
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bc);
