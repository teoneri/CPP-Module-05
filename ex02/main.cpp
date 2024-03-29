/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:20:40 by mneri             #+#    #+#             */
/*   Updated: 2024/01/15 17:04:23 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *ceo = new Bureaucrat("Ceo", 10);
	// ShrubberyCreationForm *SRform = new ShrubberyCreationForm("home");
	// RobotomyRequestForm *RRform = new RobotomyRequestForm("car");
	PresidentialPardonForm *PPform = new PresidentialPardonForm("Joe Shmoe");
	cout << *PPform;
	try
	{
		PPform->beSigned(*ceo);
		// PPform->execute(*ceo);
		ceo->executeForm(*PPform);
	}
	catch(AForm::GradeTooLowException &e)
	{
		std::cout << "could not execute" << std::endl;
	}
}