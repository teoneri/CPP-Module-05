/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teo <teo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:49:05 by teo               #+#    #+#             */
/*   Updated: 2024/01/09 14:37:09 by teo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int sign_grade, int exe_grade) : _name(name), _sign(false),
    _sign_grade(sign_grade), _exe_grade(exe_grade)
{
    try
    {
        if(this->_sign_grade < 1)
            throw Form::GradeTooHighException();
        if(this->_sign_grade > 150)
            throw Form::GradeTooLowException();
        if(this->_exe_grade < 1)
            throw Form::GradeTooHighException();
        if(this->_exe_grade > 150)
            throw Form::GradeTooLowException();
    }
    catch(GradeTooHighException &e)
    {
        
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