/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:54:09 by mneri             #+#    #+#             */
/*   Updated: 2024/01/16 14:15:44 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{}

Intern::~Intern()
{}

Intern::Intern(const Intern &other)
{
	*this = other;
}

AForm* Intern::makeForm(std::string formName, std::string formTarg)
{
	std::string names[3] ={
		"presidentialpardonform",
		"robotomyrequestform",
		"shrubberycreationform",
	};
	AForm *Forms[3] ={
		new PresidentialPardonForm(formTarg),
		new RobotomyRequestForm(formTarg),
		new ShrubberyCreationForm(formTarg),
	};
	for(int i = 0; i < 3; i++)
	{
		if(formName == names[i])
			return Forms[i];
	}
	cout << "Invalid form" << std::endl;
	return NULL;
}
