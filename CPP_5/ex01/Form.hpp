/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:16:46 by blandineber       #+#    #+#             */
/*   Updated: 2024/03/13 15:38:28 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeSign;
		const int _gradeExec;
	public:
		Form(void);
		Form(std::string name, int gradeSign, int gradeExec);
		Form(const Form& form);
		Form& operator=(const Form& form);
		~Form(void);

		const std::string getName(void) const;
		bool getSignature(void) const;
		int getGradeSign(void) const;
		int getGradeExec(void) const;

		void beSigned(Bureaucrat& b);
		void setSignature(bool sign);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return GREEN "Grade too high" RESET;
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return GREEN "Grade too low" RESET;
				}
		};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
