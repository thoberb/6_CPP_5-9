/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:30:11 by blandineber       #+#    #+#             */
/*   Updated: 2024/03/26 19:38:45 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main()
{
	// Test avec un tableau d'entiers
	Array<int> intArray(5);
	for (unsigned int i = 0; i < intArray.size(); ++i) {
		intArray[i] = i * i;
		std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
	}

	// Test avec un tableau de chaînes
	Array<std::string> strArray(3);
	strArray[0] = "Hello";
	strArray[1] = "World";
	strArray[2] = "!";
	for (unsigned int i = 0; i < strArray.size(); ++i) {
		std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;
	}

	// Test d'accès hors limite
	try {
		std::cout << intArray[5] << std::endl;
	} catch (const std::out_of_range &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}

