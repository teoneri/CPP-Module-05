/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:48:57 by teo               #+#    #+#             */
/*   Updated: 2024/01/11 17:16:30 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
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
		Form();
        Form(std::string name, int sign_grade, int exe_grade);
        Form(const Form &other);
        ~Form();
        int getSigGrade() const;
        bool getSign() const;
        int getExeGrade() const;
        std::string getName() const;
		void beSigned(Bureaucrat &bureau);
		Form &operator=(const Form &other);
};
std::ostream &operator<<(std::ostream &out, const Form &form);
