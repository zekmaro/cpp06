/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:43:53 by anarama           #+#    #+#             */
/*   Updated: 2024/10/17 17:40:38 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <exception>
# include <string>

class ScalarConverter {
	private:
		ScalarConverter( void );
		ScalarConverter( const ScalarConverter& other );
		ScalarConverter& operator=( const ScalarConverter& other );
		~ScalarConverter( void );

	public:
		static void convert( std::string str );
	
		class EmptyStringException: public std::exception {
			public:
				const char* what() const throw();
		};

		class MultipleCharsException: public std::exception {
			public:
				const char* what() const throw();
		};
		
};

#endif // SCALARCONVERTER_HPP