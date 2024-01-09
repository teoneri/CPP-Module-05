/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teo <teo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:48:57 by teo               #+#    #+#             */
/*   Updated: 2024/01/09 14:34:52 by teo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
        Form(std::string name, int sign_grade, int exe_grade);
        Form(const Form &other);
        ~Form();
        int getSigGrade() const;
        bool getSign() const;
        int getExeGrade() const;
        std::string getName() const;
		Form &operator=(const Form &other);

};