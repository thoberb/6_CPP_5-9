/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:17:37 by blandineber       #+#    #+#             */
/*   Updated: 2024/03/19 17:26:05 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm* _createShrubberyCreationForm(std::string target);
		AForm* _createRobotomyRequestForm(std::string target);
		AForm* _createPresidentialPardonForm(std::string target);
	public:
		Intern(void);
		Intern(const Intern& intern);
		Intern& operator=(const Intern& intern);
		~Intern(void);

		AForm* makeForm(std::string form, std::string target);
};

#endif
