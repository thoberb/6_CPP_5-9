/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:25:35 by blandineber       #+#    #+#             */
/*   Updated: 2024/03/26 18:34:35 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << BOLD_RED "Default constructor called for Serializer" RESET << std::endl;
}

Serializer::Serializer(const Serializer& serializer)
{
	std::cout << BOLD_RED "Copy constructor called for Serializer" RESET << std::endl;
	(void)serializer;
}

Serializer& Serializer::operator=(const Serializer& serializer)
{
	std::cout << BOLD_RED "Copy assignment operator called for Serializer" RESET << std::endl;
	(void)serializer;
	return (*this);
}

Serializer::~Serializer(void)
{
	std::cout << BOLD_RED "Destructor called for Serializer" RESET << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
