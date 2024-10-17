/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:06:17 by anarama           #+#    #+#             */
/*   Updated: 2024/10/17 15:58:27 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

class Data {
	private:
		
	public:
		Data( void );
		Data( const Data& other );
		Data& operator=( const Data& other );
		~Data( void );
};

#endif // DATA_HPP