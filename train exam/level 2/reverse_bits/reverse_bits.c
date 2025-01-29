/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:22:17 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/29 15:29:21 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	r = 0;
	unsigned	byte_len = 8;

	while (byte_len)
	{
		r = (r << 1) | (octet & 1);
		octet >>= 1;
	}
	return (r);
}