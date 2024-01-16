/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:49:05 by teo               #+#    #+#             */
/*   Updated: 2024/01/15 17:44:24 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("N/A"),  _sign(false), _sign_grade(150), _exe_grade(150)
{
}

AForm::AForm(std::string name, int sign_grade, int exe_grade) : _name(name),_sign(false),  _sign_grade(sign_grade), _exe_grade(exe_grade)
{
	try
	{
		if(this->_sign_grade < 1 || this->_exe_grade < 1)
			throw AForm::GradeTooHighException();
		if(this->_sign_grade > 150 || this->_exe_grade > 150)
			throw AForm::GradeTooLowException();
	}
	catch(const AForm::GradeTooLowException &e)
	{
		std::cout << "Grade too low" << std::endl;
	}
	catch(const AForm::GradeTooHighException &e)
	{
		std::cout << "Grade too high" << std::endl;
	}
}

AForm::AForm(const AForm &other) : _name(other.getName()), _sign_grade(other.getSigGrade()), _exe_grade(other.getSigGrade())
{
	*this = other;
}

AForm::~AForm()
{
}

int AForm::getSigGrade() const
{
	return _sign_grade;
}

int AForm::getExeGrade() const
{
    return _exe_grade;
}

bool AForm::getSign() const
{
    return _sign;
}

std::string AForm::getName() const
{
    return _name;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this == &other)
		return *this;
	return *this;
}

void AForm::beSigned(Bureaucrat &bureau)
{
	if(this->_sign_grade >= bureau.getGrade())
	{
		std::cout << this->getName() << " has been signed by " << bureau.getName() << std::endl;
		this->_sign = true;
	}
	else
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out <<  "form name: " << form.getName()  << "sign status: " << form.getSign() << ", sign grade: " << 
		form.getSigGrade() << ", exe grade: " << form.getExeGrade() << std::endl;
	return out;
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low exception thrown");
};

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high exception thrown");
};

void	AForm::setSign(bool var)
{
	this->_sign = var;
}