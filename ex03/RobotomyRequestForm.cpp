/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:32:36 by mneri             #+#    #+#             */
/*   Updated: 2024/01/15 16:35:11 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm (const RobotomyRequestForm &other) : AForm(other), _target(other._target)
{
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if(executor.getGrade() > this->getExeGrade() || this->getSign() == false)
	{
		throw AForm::GradeTooLowException();
	}
	else
	{
		std::cout << "*drilling noise*" << std::endl;
		srand(time(NULL));
		if (rand() % 2 == 0)		
		{
			std::cout << this->_target << " has been robotomized" << std::endl;
		}
		else
			std::cout << this->_target << " has failed to robotomize" << std::endl;
	}
}


RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this == &other)
		return *this;
	return *this;
}
