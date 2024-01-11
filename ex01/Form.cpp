/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:49:05 by teo               #+#    #+#             */
/*   Updated: 2024/01/11 18:01:40 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("N/A"),  _sign(false), _sign_grade(150), _exe_grade(150)
{
}

Form::Form(std::string name, int sign_grade, int exe_grade) : _name(name),_sign(false),  _sign_grade(sign_grade), _exe_grade(exe_grade)
{
	if(this->_sign_grade < 1 || this->_exe_grade < 1)
		throw Form::GradeTooHighException();
	if(this->_sign_grade > 150 || this->_exe_grade > 150)
		throw Form::GradeTooLowException();
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
		this->_sign = true;
	}
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << ", form name " << "sign status: " << form.getSign() << ", sign grade: " << 
		form.getSigGrade() << ", exe grade: " << form.getExeGrade() << std::endl;
	return out;
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};