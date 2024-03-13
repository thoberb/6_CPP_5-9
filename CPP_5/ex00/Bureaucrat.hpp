/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:47:55 by bberthod          #+#    #+#             */
/*   Updated: 2024/03/13 14:03:08 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "color.hpp"

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string _name, int grade);
		Bureaucrat(const Bureaucrat& bureaucrat);
		Bureaucrat& operator=(const Bureaucrat& bureaucrat);
		~Bureaucrat(void);

		const std::string getName(void) const;
		int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

class GradeTooHighException : public std::exception
{
	public:
		const char* what() const throw()
		{
			return BOLD_BLUE "Grade too high" RESET;
		}
};

class GradeTooLowException : public std::exception
{
	public:
		const char* what() const throw()
		{
			return BOLD_BLUE "Grade too low" RESET;
		}
};

#endif
