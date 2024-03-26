/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:16:19 by blandineber       #+#    #+#             */
/*   Updated: 2024/03/26 19:27:35 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

// Fonction pour afficher un élément
template <typename T>
void printElement(T &element)
{
	std::cout << element << std::endl;
}

// Fonction pour incrémenter un élément
void increment(int &n)
{
	n++;
}

int main()
{
	// Tableau d'entiers
	int arrInt[] = {1, 2, 3, 4, 5};
	int lengthInt = sizeof(arrInt) / sizeof(*arrInt);

	std::cout << "Array of ints before increment:" << std::endl;
	iter(arrInt, lengthInt, printElement);

	iter(arrInt, lengthInt, increment);

	std::cout << "Array of ints after increment:" << std::endl;
	iter(arrInt, lengthInt, printElement);

	// Tableau de chaînes de caractères
	std::string arrStr[] = {"hello", "world", "this", "is", "C++"};
	int lengthStr = sizeof(arrStr) / sizeof(*arrStr);

	std::cout << "Array of strings:" << std::endl;
	iter(arrStr, lengthStr, printElement);

	return 0;
}

