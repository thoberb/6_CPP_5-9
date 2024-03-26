/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:19:06 by blandineber       #+#    #+#             */
/*   Updated: 2024/03/26 18:20:58 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << BOLD_RED "Default constructor called for ScalarConverter" RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& scalarConverter)
{
	std::cout << BOLD_RED "Copy constructor called for ScalarConverter" RESET << std::endl;
	(void)scalarConverter;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& scalarConverter)
{
	std::cout << BOLD_RED "Copy assignment operator called for ScalarConverter" RESET << std::endl;
	(void)scalarConverter;
	return (*this);
}


ScalarConverter::~ScalarConverter(void)
{
	std::cout << BOLD_RED "Destructor called for ScalarConverter" RESET << std::endl;
}


void ScalarConverter::convert(const std::string& input)
{
	char* end;
	errno = 0;

	// INPUT EST UN CHAR
	if (input.length() == 1 && !isdigit(input[0]))
	{
		char c = input[0];
		if (std::isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
		return;
	}


	// SINON Conversion en double pour tout le monde
	double dValue = std::strtod(input.c_str(), &end);

	if (errno != ERANGE)
	{
		// Gestion des cas spéciaux inf et nan
		if (input == "-inff" || input == "+inff" || input == "-inf"
			|| input == "+inf" || input == "nanf" || input == "nan")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			if (input == "nanf" || input == "nan")
			{
				std::cout << "float: nanf" << std::endl;
				std::cout << "double: nan" << std::endl;
			}
			else if (input == "+inf" || input == "+inff")
			{
				std::cout << "float: +inff" << std::endl;
				std::cout << "double: +inf" << std::endl;
			}
			else
			{
				std::cout << "float: -inff" << std::endl;
				std::cout << "double: -inf" << std::endl;
			}
			return;
		}


		// Conversion et affichage en char
		if (dValue >= 0 && dValue <= 127 && std::floor(dValue) == dValue)
		{
			char cValue = static_cast<char>(dValue);
			if (std::isprint(cValue))
				std::cout << "char: '" << cValue << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;


		// Conversion et affichage en int
		long lValue = strtol(input.c_str(), &end, 10);
		if (end != input.c_str() && *end == '\0' &&
			lValue >= std::numeric_limits<int>::min() && lValue <= std::numeric_limits<int>::max())
			std::cout << "int: " << static_cast<int>(lValue) << std::endl;
		else
		{
			// Vérifie si la partie non entière de la conversion double est nulle
			double dValueCheck = strtod(input.c_str(), nullptr);
			if (dValueCheck == static_cast<double>(static_cast<int>(dValueCheck)))
				std::cout << "int: " << static_cast<int>(dValueCheck) << std::endl;
			else
				std::cout << "int: impossible" << std::endl;
		}

		// Conversion et affichage en float
		float fValue = std::strtof(input.c_str(), &end);
		if ((*end == '\0' || *end == 'f'))
			std::cout << "float: " << std::fixed << std::setprecision(1) << fValue << "f" << std::endl;
		else
			std::cout << "float: impossible" << std::endl;


		// Affichage en double
		std::cout << "double: " << std::fixed << std::setprecision(1) << dValue << std::endl;
	}

	// Gestion des cas d'erreur errno == ERANGE
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}


// NOTES :

// errno != ERANGE est utilisé pour vérifier si la conversion a réussi sans erreur de dépassement de capacité.

// std::floor(dValue) == dValue est utilisé pour vérifier si la valeur est un entier. std::floor arrondi
// la valeur à l'entier le plus proche.
