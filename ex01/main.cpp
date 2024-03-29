/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:56:25 by mneri             #+#    #+#             */
/*   Updated: 2024/01/12 15:18:55 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	// Bureaucrat *employee = new Bureaucrat("employee", 140);
	Bureaucrat *ceo = new Bureaucrat("CEO", 1);
	Form *form = new Form("Private Policy", 20, 20);
	// Form *form2 = new Form(*form);
	Form *form2 = new Form("Public Policy", 150, 150);
	// form2 = form;
	std::cout << *ceo;
	std::cout << *form;
	std::cout << *form2;
	try
	{
		// form->beSigned(*employee);
		// form->beSigned(*ceo);
		// employee->signForm(*form);
		ceo->signForm(*form);
	}
	catch(const Form::GradeTooLowException &e)
	{
		std::cout << "Form could not be signed" << std::endl;
	}
	
}