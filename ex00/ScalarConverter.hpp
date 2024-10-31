/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:43:53 by anarama           #+#    #+#             */
/*   Updated: 2024/10/31 10:46:34 by anarama          ###   ########.fr       */
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
		static void convert( const std::string& str );
		
		class IncorrectFormatException: public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif // SCALARCONVERTER_HPP