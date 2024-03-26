/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:44:17 by blandineber       #+#    #+#             */
/*   Updated: 2024/03/26 18:54:26 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base * generate(void)
{
	int i = rand() % 3;

	if (i == 0)
	{
		std::cout << "A generated" << std::endl;
		return new A;
	}
	else if (i == 1)
	{
		std::cout << "B generated" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "C generated" << std::endl;
		return new C;
	}
}

void identify(Base * p) //dynamic_cast renvoie nullptr si le cast échoue pour un pointeur
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base & p)
{
	try
	{
		A & a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast & e)
	{
		try
		{
			B & b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch (std::bad_cast & e)
		{
			try
			{
				C & c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch (std::bad_cast & e)
			{
				std::cout << "Unknown" << std::endl;
			}
		}
	}
}

int main()
{
	srand(time(NULL));

	Base * base = generate();

	identify(base); //identifier depuis un pointeur
	identify(*base); //identifier depuis une référence

	delete base;

	return 0;
}

//NOTES :

// Avec les pointeurs, dynamic_cast retourne nullptr si le cast échoue,
// c'est-à-dire, si l'objet pointé n'est pas du type spécifié ou d'un type dérivé
// compatible. Cela fournit une manière simple et directe de vérifier si le cast a
// réussi ou échoué sans utiliser d'exceptions.

// Avec les références, la situation est différente. Si le cast échoue,
// dynamic_cast ne peut pas retourner nullptr car les références ne peuvent
// pas être nulles en C++. À la place, dynamic_cast lève une exception
// de type std::bad_cast pour signaler l'échec du cast.
