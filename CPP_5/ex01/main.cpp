/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:47:42 by bberthod          #+#    #+#             */
/*   Updated: 2024/03/13 15:41:54 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	try {
		// Test constructing Bureaucrats with valid grades
		Bureaucrat alice("Alice", 2);
		Bureaucrat bob("Bob", 140);
		std::cout << alice << std::endl;
		std::cout << bob << std::endl;

		// Test increment and decrement at boundary conditions
		alice.incrementGrade(); // Should be fine
		std::cout << alice << std::endl;
		bob.decrementGrade(); // Should be fine
		std::cout << bob << std::endl;

		// Test increment and decrement beyond boundary conditions
		Bureaucrat charlie("Charlie", 1);
		charlie.incrementGrade(); // Should throw an exception

	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Bureaucrat dave("Dave", 151); // Should throw an exception
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		// Test constructing Forms with valid grades
		Form formA("FormA", 50, 25);
		Bureaucrat elena("Elena", 49);
		formA.beSigned(elena); // Should succeed
		std::cout << formA << std::endl;

		// Test signing a form with insufficient grade
		Bureaucrat fred("Fred", 51);
		formA.beSigned(fred); // Should throw an exception

	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		// Constructing a Form with invalid grades
		Form formB("FormB", 45, 151); // Should throw an exception
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}

