/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:01:20 by blandineber       #+#    #+#             */
/*   Updated: 2024/03/19 16:41:30 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("presidentialform", 25, 5)
{
	std::cout << BOLD_RED "Default constructor called for PresidentialPardonForm" RESET << std::endl;
	_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("presidentialform", 25, 5)
{
	std::cout << BOLD_RED "Constructor called for PresidentialPardonForm " << _name << RESET << std::endl;
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& PresidentialPardonForm) : AForm("presidentialform", 25, 5)
{
	std::cout << BOLD_RED "Copy constructor called for PresidentialPardonForm " << _name << RESET << std::endl;
	_target = PresidentialPardonForm._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& PresidentialPardonForm)
{
	std::cout << BOLD_RED "Copy assignment operator called for PresidentialPardonForm " << _name << RESET << std::endl;
	if (this != &PresidentialPardonForm)
	{
		this->_target = PresidentialPardonForm._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << BOLD_RED "Destructor called for PresidentialPardonForm " << _name << RESET << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (!getSignature())
	{
		std::cout << RED << "The form has not been signed." << std::endl;
		return ;
	}
	else if (executor.getGrade() > getGradeExec())
		throw AForm::GradeTooLowException();
	std::cout << RED << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
