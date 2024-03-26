/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:51:33 by blandineber       #+#    #+#             */
/*   Updated: 2024/03/26 17:16:13 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "ScalarConverter.hpp"
# include "color.hpp"
# include <iostream>
# include <cstdlib>
# include <cerrno>
# include <cmath>
# include <climits>
# include <cfloat>
# include <limits>
# include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& scalarConverter);
		ScalarConverter& operator=(const ScalarConverter& scalarConverter);
		~ScalarConverter(void );

	public:
		static void convert(const std::string& str);
};

#endif
