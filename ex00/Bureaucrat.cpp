/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:34:55 by mneri             #+#    #+#             */
/*   Updated: 2024/01/11 16:54:54 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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


std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return out;
}
