/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:02:18 by blandineber       #+#    #+#             */
/*   Updated: 2024/03/19 16:42:27 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << BOLD_YELLOW "Default constructor called for ShrubberyCreationForm" RESET << std::endl;
	_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << BOLD_YELLOW "Constructor called for ShrubberyCreationForm " << _name << RESET << std::endl;
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ShrubberyCreationForm) : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << BOLD_YELLOW "Copy constructor called for ShrubberyCreationForm " << _name << RESET << std::endl;
	_target = ShrubberyCreationForm._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ShrubberyCreationForm)
{
	std::cout << BOLD_YELLOW "Copy assignment operator called for ShrubberyCreationForm " << _name << RESET << std::endl;
	if (this != &ShrubberyCreationForm)
	{
		this->_target = ShrubberyCreationForm._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << BOLD_YELLOW "Destructor called for ShrubberyCreationForm " << _name << RESET << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (!getSignature())
	{
		std::cout << YELLOW << "The form has not been signed." << std::endl;
		return ;
	}
	else if (executor.getGrade() > getGradeExec())
		throw AForm::GradeTooLowException();
	std::ofstream file;
	file.open(_target + "_shrubbery");
	file << "      /\\      " << std::endl;
	file << "     /\\*\\     " << std::endl;
	file << "    /\\O\\*\\    " << std::endl;
	file << "   /*/\\/\\/\\   " << std::endl;
	file << "  /\\O\\/\\*\\/\\  " << std::endl;
	file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << std::endl;
	file.close();
}
