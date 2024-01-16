/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:34:55 by mneri             #+#    #+#             */
/*   Updated: 2024/01/15 16:50:57 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	try 
	{
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
    }
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
		this->setGrade(1);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
		this->setGrade(150);
	}
}

Bureaucrat::Bureaucrat() : _name("N/A"), _grade(150)
{}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName())
{
	*this = other;
}

const std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if(this != &other)
	{
		this->_grade = other._grade;
		// this->_name = other._name;
	}
	return *this;
}

void Bureaucrat::setGrade(int num)
{
	this->_grade = num;
}

void Bureaucrat::incGrade(int num)
{
	try
	{
		this->_grade -= num;
		if(this->_grade < 1)
            throw Bureaucrat::GradeTooHighException();
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
		this->_grade = 1;
	}
}

void Bureaucrat::decGrade(int num)
{
	try
	{
		this->_grade += num;
		if(this->_grade > 150)
            throw Bureaucrat::GradeTooLowException();
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
		this->_grade = 150;
	}
}


void Bureaucrat::signForm(AForm &form)
{
	if(form.getSigGrade() >= this->getGrade())
	{
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
		form.setSign(true);
	}
	else
	{
		std::cout << this->getName() << " could not sign " << form.getName() << " because of low grade " << std::endl;
		throw AForm::GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return out;
}

void Bureaucrat::executeForm(AForm const & form)
{
	if(this->getGrade() <= form.getExeGrade() && form.getSign() == true)
	{
		std::cout << this->getName() << " executed " << form.getName() << std::endl;;
		form.execute(*this);
	}
	else
	{
		std::cout << this->getName() << " could not execute " << form.getName() << std::endl;;
		throw AForm::GradeTooLowException();
	}
}