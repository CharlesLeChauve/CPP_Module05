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

const char* AForm::FormNotSignedException::what() const throw() {
	return "This Form isn't Approved yet!";
}

const std::string& AForm::getName() const
{
	return (this->name);
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!this->getApproved())
        throw FormNotSignedException();
    else if (executor.getGrade() > this->getExecGrade())
        throw Bureaucrat::GradeTooLowException();
    else {
        this->exec_action();
    }
}

AForm::~AForm()
{
}

AForm::AForm(const AForm& other)
    : name(other.name), approved(other.approved), signGrade(other.signGrade), execGrade(other.execGrade)
{
    // Initialisation des membres constants à partir de l'objet source
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other) {
        // Les membres const ne peuvent pas être réassignés, on copie seulement les membres modifiables
        this->approved = other.approved;
    }
    return *this;
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