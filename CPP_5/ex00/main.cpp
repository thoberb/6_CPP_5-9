/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:47:42 by bberthod          #+#    #+#             */
/*   Updated: 2024/03/13 14:13:50 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try{
		Bureaucrat bob("Bob", 3);
		bob.incrementGrade();
	}
	catch (const std::exception& e) {
		std::cerr << BOLD_BLUE "Exception caught: " << e.what() << RESET << std::endl;
	}
	return 0;
}
