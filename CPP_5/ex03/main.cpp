/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:47:42 by bberthod          #+#    #+#             */
/*   Updated: 2024/03/19 17:36:07 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try {
		Intern	someRandomIntern;
		AForm*	rrf;
		Bureaucrat Charles("Charles", 30);

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		rrf->beSigned(Charles);
		rrf->execute(Charles);
	}
	catch (std::exception & e) {
		std::cerr << "Exception caught : " << e.what() << std::endl;
	}
}


