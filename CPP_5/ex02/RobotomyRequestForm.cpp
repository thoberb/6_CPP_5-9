/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:01:50 by blandineber       #+#    #+#             */
/*   Updated: 2024/03/19 16:52:11 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy request form", 72, 45)
{
	std::cout << BOLD_MAGENTA "Default constructor called for RobotomyRequestForm" RESET << std::endl;
	_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy request form", 72, 45)
{
	std::cout << BOLD_MAGENTA "Constructor called for RobotomyRequestForm " << _name << RESET << std::endl;
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& RobotomyRequestForm) : AForm("presidentialform", 72, 45)
{
	std::cout << BOLD_MAGENTA "Copy constructor called for RobotomyRequestForm " << _name << RESET << std::endl;
	_target = RobotomyRequestForm._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& RobotomyRequestForm)
{
	std::cout << BOLD_MAGENTA "Copy assignment operator called for RobotomyRequestForm " << _name << RESET << std::endl;
	if (this != &RobotomyRequestForm)
	{
		this->_target = RobotomyRequestForm._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << BOLD_MAGENTA "Destructor called for RobotomyRequestForm " << _name << RESET << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (!getSignature())
	{
		std::cout << MAGENTA << "The form has not been signed." << std::endl;
		return ;
	}
	else if (executor.getGrade() > getGradeExec())
		throw AForm::GradeTooLowException();
	std::cout << MAGENTA "Drilling noises" << std::endl;
	if (rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " robotomization failed" << std::endl;
}
