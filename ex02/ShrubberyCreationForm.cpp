/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:46:47 by mneri             #+#    #+#             */
/*   Updated: 2024/01/12 17:47:44 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm (const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if(executor.getGrade() <= this->getExeGrade() && this->getSign() == true)
	{
		ofstream f0;
		f0.open((this->_target + "_shrubbery").c_str(), ios::app);
		if(f0.is_open())
		{
			f0 << "             # #### ####\n";
			f0 << "           ### \\/#|### |/####\n";
			f0 << "          ##\\/#/ \\||/##/_/##/_#\n";
			f0 << "        ###  \\/###|/ \\/ # ###\n";
			f0 << "      ##_\\_#\\_\\## | #/###_/_####\n";
			f0 << "     ## #### # \\ #| /  #### ##/##\n";
			f0 << "      __#_--###`  |{,###---###-~\n";
			f0 << "                \\ }{\n";
			f0 << "                 }}{\n";
			f0 << "                 }}{\n";
			f0 << "                 }}{\n";
			f0 << "                 }}{\n";
		}
	}
	else
		throw AForm::GradeTooLowException();
}


ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return *this;
	return *this;
}
