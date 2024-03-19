/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:47:42 by bberthod          #+#    #+#             */
/*   Updated: 2024/03/19 17:06:19 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	srand(static_cast<unsigned int>(time(NULL)));
	try {
		Bureaucrat alice("Alice", 6);
		PresidentialPardonForm form("TARGET");

		alice.incrementGrade();
		std::cout << alice << std::endl;

		form.beSigned(alice);
		std::cout << form << std::endl;

		form.execute(alice);

	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat charles("Charles", 40);
		RobotomyRequestForm form("TARGET");

		form.beSigned(charles);
		std::cout << form << std::endl;

		form.execute(charles);
		form.execute(charles);

		charles.executeForm(form);
		charles.executeForm(form);


	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat Jean("Jean", 130);
		ShrubberyCreationForm form("TARGET");

		form.beSigned(Jean);
		std::cout << form << std::endl;

		form.execute(Jean);

	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}


