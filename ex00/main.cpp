/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teo <teo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:56:25 by mneri             #+#    #+#             */
/*   Updated: 2024/01/09 13:46:55 by teo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat John = Bureaucrat("John", 150);
	std::cout << John;
	John.decGrade(1);
	std::cout << John;
	John.incGrade(151);
	std::cout << John;
	John.decGrade(50);
	std::cout << John;



}