/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:18:01 by blandineber       #+#    #+#             */
/*   Updated: 2024/03/19 17:33:00 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << BOLD_CYAN  "Default constructor called for Intern" RESET << std::endl;
}

Intern::Intern(const Intern& intern)
{
	std::cout << BOLD_CYAN "Copy constructor called for Intern" RESET << std::endl;
	(void)intern;
}

Intern& Intern::operator=(const Intern& intern)
{
	std::cout << BOLD_CYAN "Copy assignment operator called for Intern" RESET << std::endl;
	(void)intern;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << BOLD_CYAN "Destructor called for Intern" RESET << std::endl;
}

enum FormType
{
	ROBOTOMY,
	SHRUBBERY,
	PARDON,
	UNKNOWN
};

FormType getFormType(const std::string& formName)
{
	if (formName == "robotomy request") return ROBOTOMY;
	if (formName == "shrubbery creation") return SHRUBBERY;
	if (formName == "presidential pardon") return PARDON;
	return UNKNOWN;
}

AForm* Intern::makeForm(std::string formName, const std::string target)
{
	FormType type = getFormType(formName);

	switch (type)
	{
		case ROBOTOMY:
			std::cout << CYAN "Intern creates RobotomyRequestForm" << std::endl;
			return new RobotomyRequestForm(target);
		case SHRUBBERY:
			std::cout << CYAN "Intern creates ShrubberyCreationForm" << std::endl;
			return new ShrubberyCreationForm(target);
		case PARDON:
			std::cout << CYAN "Intern creates PresidentialPardonForm" << std::endl;
			return new PresidentialPardonForm(target);
		default:
			std::cout << CYAN "Intern does not know this form" << std::endl;
			return NULL;
	}
}

