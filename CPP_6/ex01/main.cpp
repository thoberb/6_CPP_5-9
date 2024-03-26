/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:35:39 by blandineber       #+#    #+#             */
/*   Updated: 2024/03/26 18:39:40 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	//Serializer serializer; ne doit pas compiler

	Data originalData;

	std::cout << "Adresse de originalData: " << &originalData << std::endl;

	uintptr_t rawData = Serializer::serialize(&originalData);
	std::cout << "Donnée sérialisée: " << rawData << std::endl;

	Data* deserializedData = Serializer::deserialize(rawData);
	std::cout << "Adresse après désérialisation: " << deserializedData << std::endl;

	if (&originalData == deserializedData)
		std::cout << "La désérialisation a réussi. Les adresses sont identiques." << std::endl;
	else
		std::cout << "Erreur de désérialisation. Les adresses diffèrent." << std::endl;

	return 0;
}
