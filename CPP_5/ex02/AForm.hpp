/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:16:46 by blandineber       #+#    #+#             */
/*   Updated: 2024/03/13 15:44:10 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeSign;
		const int _gradeExec;
	public:
		AForm(void);
		AForm(std::string name, int gradeSign, int gradeExec);
		AForm(const AForm& Aform);
		AForm& operator=(const AForm& Aform);
		virtual ~AForm(void);

		const std::string getName(void) const;
		bool getSignature(void) const;
		int getGradeSign(void) const;
		int getGradeExec(void) const;

		void beSigned(Bureaucrat& b);
		void setSignature(bool sign);

		virtual void execute(Bureaucrat const & executor) const = 0;

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

std::ostream& operator<<(std::ostream& os, const AForm& Aform);

#endif
