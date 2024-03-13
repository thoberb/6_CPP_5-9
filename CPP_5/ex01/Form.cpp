/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:30:10 by blandineber       #+#    #+#             */
/*   Updated: 2024/03/13 15:39:51 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("default"), _signed(false), _gradeSign(60), _gradeExec(60)
{
	std::cout << BOLD_GREEN "Default constructor called for Form" RESET << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExec) :  _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	std::cout << BOLD_GREEN "Constructor called for Form " << _name << RESET << std::endl;
	if (_gradeSign < 1 || _gradeExec < 1)
		throw GradeTooHighException();
	else if (_gradeSign > 150 || _gradeExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& form) : _name(form._name), _signed(form._signed), _gradeSign(form._gradeSign), _gradeExec(form._gradeExec)
{
	std::cout << BOLD_GREEN "Copy constructor called for Form " << _name << RESET << std::endl;
}

Form& Form::operator=(const Form& form)
{
	std::cout << BOLD_GREEN "Copy assignment operator called for Form " << _name << RESET << std::endl;
	if (this != &form)
	{
		this->_signed = form._signed;
	}
	return (*this);
}

Form::~Form(void)
{
	std::cout << BOLD_GREEN "Destructor called for form " << _name << RESET << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << GREEN "The form " << form.getName() << " has a required grade of " << form.getGradeSign() << " to sign it and a required grade of " << form.getGradeExec() << " to execute it. The form has been signed : " << form.getSignature() << RESET;
	return os;
}

const std::string Form::getName(void) const
{
	return (_name);
}

bool Form::getSignature(void) const
{
	return(_signed);
}

int Form::getGradeSign(void) const
{
	return(_gradeSign);
}

int Form::getGradeExec(void) const
{
	return(_gradeExec);
}

void Form::setSignature(bool sign)
{
	_signed = sign;
}

void Form::beSigned(Bureaucrat& b)
{
	if (_signed == false)
	{
		if (b.getGrade() <= _gradeSign)
		{
			_signed = true;
			std::cout << GREEN "Bureaucrat " << b.getName() << " has signed the form" RESET << std::endl;
		}
		else
			throw GradeTooLowException();
	}
	else
		std::cout << GREEN "The form is allready signed" RESET << std::endl;
}
