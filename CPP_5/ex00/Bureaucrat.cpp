/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:48:54 by bberthod          #+#    #+#             */
/*   Updated: 2024/03/05 21:17:42 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Bureaucrat(void);
// Bureaucrat(std::string _name, int grade);
// Bureaucrat(const Bureaucrat& bureaucrat);
// ~Bureaucrat(void);

// const std::string getName(void) const;
// int getGrade(void) const;

Bureaucrat::Bureaucrat(void) : _name(0), _grade(0)
{
	std::cout << "Default constructor called for Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Constructor called for Bureaucrat " << _name << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat)
{
	std::cout << "Copy constructor called for Bureaucrat " << _name << std::endl;
	_grade = bureaucrat.getGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
	std::cout << "Copy assignment operator called for Bureaucrat " << _name << std::endl;
	if (this != &bureaucrat)
	{
		this->_grade = bureaucrat.getGrade();
	}
	return (*this);
}

