/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:20:40 by mneri             #+#    #+#             */
/*   Updated: 2024/01/16 14:26:11 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Intern *joe = new Intern();
	AForm *form;
	
	form = joe->makeForm("shrubberycreationform", "Joe shmoe");
	
	Bureaucrat *ceo = new Bureaucrat("Ceo", 1);
	if(form != NULL)
	{
		std::cout << *form << std::endl;
		try
		{
			form->beSigned(*ceo);
			// std::cout << *form << std::endl;
			ceo->executeForm(*form);
		}
		catch(AForm::GradeTooLowException &e)
		{
			std::cout << "could not execute" << std::endl;
		}
	}

}