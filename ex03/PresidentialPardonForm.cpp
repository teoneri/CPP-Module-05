/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:37:41 by mneri             #+#    #+#             */
/*   Updated: 2024/01/15 16:46:51 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm (const PresidentialPardonForm &other) : AForm(other), _target(other._target)
{
}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if(executor.getGrade() <= this->getExeGrade() && this->getSign() == true)
	{
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	else
		throw AForm::GradeTooLowException();
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this == &other)
		return *this;
	return *this;
}
