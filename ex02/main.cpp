/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:20:40 by mneri             #+#    #+#             */
/*   Updated: 2024/01/12 17:48:51 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *ceo = new Bureaucrat("Ceo", 150);
	ShrubberyCreationForm *SRform = new ShrubberyCreationForm("home");
	
	try
	{
		SRform->beSigned(*ceo);
		SRform->execute(*ceo);
	}
	catch(AForm::GradeTooLowException &e)
	{
		std::cout << "could not execute" << std::endl;
	}
}