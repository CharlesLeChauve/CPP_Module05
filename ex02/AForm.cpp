#include "AForm.hpp"

void	AForm::beSigned(const Bureaucrat& bc)
{
	if (bc.getGrade() <= this->signGrade)
		this->approved = true;
	else
		throw(Bureaucrat::GradeTooLowException());
}

AForm::AForm(const std::string &name, int signGrade, int execGrade) : name(name), signGrade(signGrade), execGrade(execGrade), approved(false)
{
}

const std::string& AForm::getName() const
{
	return (this->name);
}

AForm::~AForm()
{
}

bool AForm::getApproved() const { return approved; }
int AForm::getSignGrade() const { return signGrade; }
int AForm::getExecGrade() const { return execGrade; }

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "AForm " << form.getName() << " requires grade " << form.getSignGrade() 
       << " to sign, grade " << form.getExecGrade() << " to execute, and is currently "
       << (form.getApproved() ? "signed." : "not signed.");
    return os;
}