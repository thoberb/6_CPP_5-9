/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:48:54 by bberthod          #+#    #+#             */
/*   Updated: 2024/03/13 14:05:23 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150)
{
	std::cout << BOLD_BLUE "Default constructor called for Bureaucrat" RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << BOLD_BLUE "Constructor called for Bureaucrat " << _name << RESET << std::endl;
	if(_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) : _name(bureaucrat._name)
{
	std::cout << BOLD_BLUE "Copy constructor called for Bureaucrat " << _name << RESET << std::endl;
	_grade = bureaucrat.getGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
	std::cout << BOLD_BLUE "Copy assignment operator called for Bureaucrat " << _name << RESET << std::endl;
	if (this != &bureaucrat)
	{
		this->_grade = bureaucrat.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << BOLD_BLUE "Destructor called for Bureaucrat" RESET << std::endl;
}

const std::string Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return(_grade);
}

void Bureaucrat::incrementGrade(void)
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade -= 1;
	std::cout << BLUE "The Bureaucrat's grade has been incremented by 1" RESET << std::endl;
}

void Bureaucrat::decrementGrade(void)
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade += 1;
	std::cout << BLUE "The Bureaucrat's grade has been decremented by 1" RESET << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << BLUE << b.getName() << ", bureaucrat grade " << b.getGrade() << RESET;
	return os;
}

