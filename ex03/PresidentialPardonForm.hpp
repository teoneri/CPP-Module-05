/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:36:35 by mneri             #+#    #+#             */
/*   Updated: 2024/01/15 16:37:10 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm(std::string target);
        PresidentialPardonForm (const PresidentialPardonForm &other);
		virtual void execute(Bureaucrat const & executor) const;
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

};