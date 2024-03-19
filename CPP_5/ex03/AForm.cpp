/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:30:10 by blandineber       #+#    #+#             */
/*   Updated: 2024/03/19 13:33:35 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("default"), _signed(false), _gradeSign(60), _gradeExec(60)
{
	std::cout << BOLD_GREEN "Default constructor called for AForm" RESET << std::endl;
}

AForm::AForm(std::string name, int gradeSign, int gradeExec) :  _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	std::cout << BOLD_GREEN "Constructor called for AForm " << _name << RESET << std::endl;
	if (_gradeSign < 1 || _gradeExec < 1)
		throw GradeTooHighException();
	else if (_gradeSign > 150 || _gradeExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& Aform) : _name(Aform._name), _signed(Aform._signed), _gradeSign(Aform._gradeSign), _gradeExec(Aform._gradeExec)
{
	std::cout << BOLD_GREEN "Copy constructor called for AForm " << _name << RESET << std::endl;
}

AForm& AForm::operator=(const AForm& Aform)
{
	std::cout << BOLD_GREEN "Copy assignment operator called for AForm " << _name << RESET << std::endl;
	if (this != &Aform)
	{
		this->_signed = Aform._signed;
	}
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << BOLD_GREEN "Destructor called for Aform " << _name << RESET << std::endl;
}

std::ostream& operator<<(std::ostream& os, const AForm& Aform)
{
	os << GREEN "The Aform " << Aform.getName() << " has a required grade of " << Aform.getGradeSign() << " to sign it and a required grade of " << Aform.getGradeExec() << " to execute it. The Aform has been signed : " << Aform.getSignature() << RESET;
	return os;
}

const std::string AForm::getName(void) const
{
	return (_name);
}

bool AForm::getSignature(void) const
{
	return(_signed);
}

int AForm::getGradeSign(void) const
{
	return(_gradeSign);
}

int AForm::getGradeExec(void) const
{
	return(_gradeExec);
}

void AForm::setSignature(bool sign)
{
	_signed = sign;
}

void AForm::beSigned(Bureaucrat& b)
{
	if (_signed == false)
	{
		if (b.getGrade() <= _gradeSign)
		{
			_signed = true;
			std::cout << GREEN "Bureaucrat " << b.getName() << " has signed the Aform" RESET << std::endl;
		}
		else
			throw GradeTooLowException();
	}
	else
		std::cout << GREEN "The Aform is allready signed" RESET << std::endl;
}
