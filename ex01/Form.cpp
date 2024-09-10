#include "Form.hpp"

void	Form::beSigned(const Bureaucrat& bc)
{
	if (bc.getGrade() <= this->signGrade)
		this->approved = true;
	else
		throw(Bureaucrat::GradeTooLowException());
}

Form::Form(const std::string &name, int signGrade, int execGrade) : name(name), signGrade(signGrade), execGrade(execGrade), approved(false)
{
}

const std::string& Form::getName() const
{
	return (this->name);
}

Form::~Form()
{
}

bool Form::getApproved() const { return approved; }
int Form::getSignGrade() const { return signGrade; }
int Form::getExecGrade() const { return execGrade; }

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName() << " requires grade " << form.getSignGrade() 
       << " to sign, grade " << form.getExecGrade() << " to execute, and is currently "
       << (form.getApproved() ? "signed." : "not signed.");
    return os;
}