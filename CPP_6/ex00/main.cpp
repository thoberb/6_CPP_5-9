/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:11:32 by blandineber       #+#    #+#             */
/*   Updated: 2024/03/26 17:02:40 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	//ScalarConverter scalarConverter;  NE DOIT PAS ETRE INSTANCIE

	if (ac != 2)
	{
		std::cerr << "Usage: ./convert literal" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
	return (0);
}
