/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:49:05 by teo               #+#    #+#             */
/*   Updated: 2024/01/16 14:34:27 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("N/A"),  _sign(false), _sign_grade(150), _exe_grade(150)
{
}

Form::Form(std::string name, int sign_grade, int exe_grade) : _name(name),_sign(false),  _sign_grade(sign_grade), _exe_grade(exe_grade)
{
	try
	{
		if(this->_sign_grade < 1 || this->_exe_grade < 1)
			throw Form::GradeTooHighException();
		if(this->_sign_grade > 150 || this->_exe_grade > 150)
			throw Form::GradeTooLowException();
	}
	catch(const Form::GradeTooLowException &e)
	{
		std::cout << "Grade too low" << std::endl;
	}
	catch(const Form::GradeTooHighException &e)
	{
		std::cout << "Grade too high" << std::endl;
	}
}

Form::Form(const Form &other) : _name(other.getName()), _sign_grade(other.getSigGrade()), _exe_grade(other.getSigGrade())
{
	*this = other;
}

Form::~Form()
{
}

int Form::getSigGrade() const
{
	return _sign_grade;
}

int Form::getExeGrade() const
{
    return _exe_grade;
}

bool Form::getSign() const
{
    return _sign;
}

std::string Form::getName() const
{
    return _name;
}

Form &Form::operator=(const Form &other)
{
	if (this == &other)
		return *this;
	return *this;
}

void Form::beSigned(Bureaucrat &bureau)
{
	if(this->_sign_grade >= bureau.getGrade())
	{
		std::cout << this->getName() << " has been signed by " << bureau.getName() << std::endl;
		this->_sign = true;
	}
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out <<  "form name: " << form.getName()  << " sign status: " << form.getSign() << ", sign grade: " << 
		form.getSigGrade() << ", exe grade: " << form.getExeGrade() << std::endl;
	return out;
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low exception thrown");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high exception thrown");
};

void	Form::setSign(bool var)
{
	this->_sign = var;
}