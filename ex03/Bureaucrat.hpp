/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:34:57 by mneri             #+#    #+#             */
/*   Updated: 2024/01/15 16:44:09 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "GradeTooHighException";
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "GradeTooLowException";
				}
		};
		Bureaucrat(std::string name, int grade);
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();
		void	incGrade(int num);
		void	decGrade(int num);
		void setGrade(int num);
		const std::string getName() const;
		int getGrade() const;
		void signForm(AForm &Form);
		void executeForm(AForm const & form);
		Bureaucrat &operator=(const Bureaucrat &other);
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
