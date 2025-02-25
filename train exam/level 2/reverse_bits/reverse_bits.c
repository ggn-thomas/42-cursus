/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:22:17 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/30 08:40:24 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	r = 0;
	unsigned	byte_len = 8;

	while (byte_len--)
	{
		r = (r << 1) | (octet & 1);
		octet >>= 1;
	}
	return (r);
}
unsigned char	reverse_bits(unsigned char octet)
[
	unsigned char	r = 0;
	unsigned	byte_len = 8;
	
	while (byte_len--)
	{
		r = (r << 1) | (octet & 1);
		octet<<=1;
	}
	return (r);
]