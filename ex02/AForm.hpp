/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:48:57 by teo               #+#    #+#             */
/*   Updated: 2024/01/12 17:29:56 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _sign;
        const int _sign_grade;
        const int _exe_grade;
    public:
    	class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();

		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		AForm();
        AForm(std::string name, int sign_grade, int exe_grade);
        AForm(const AForm &other);
        ~AForm();
        int getSigGrade() const;
        bool getSign() const;
        int getExeGrade() const;
        std::string getName() const;
		void beSigned(Bureaucrat &bureau);
		virtual void execute(Bureaucrat const & executor) const = 0;
		void	setSign(bool var);
		AForm &operator=(const AForm &other);
};
std::ostream &operator<<(std::ostream &out, const AForm &form);
