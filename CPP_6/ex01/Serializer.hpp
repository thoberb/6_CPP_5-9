/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:22:38 by blandineber       #+#    #+#             */
/*   Updated: 2024/03/26 18:34:23 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <cstdint>
# include "color.hpp"
# include "Data.hpp"

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer& serializer);
		Serializer& operator=(const Serializer& serializer);
		~Serializer(void );

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
