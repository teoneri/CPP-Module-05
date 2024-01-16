/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:32:00 by mneri             #+#    #+#             */
/*   Updated: 2024/01/15 16:35:27 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>
class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm(std::string target);
        RobotomyRequestForm (const RobotomyRequestForm &other);
		virtual void execute(Bureaucrat const & executor) const;
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

};