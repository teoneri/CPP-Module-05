/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:43:09 by mneri             #+#    #+#             */
/*   Updated: 2024/01/12 17:01:57 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <fstream>

using namespace std;
class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm (const ShrubberyCreationForm &other);
		virtual void execute(Bureaucrat const & executor) const;
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

};