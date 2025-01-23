/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:42:09 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/22 12:57:51 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	r;
	unsigned	byte_len = 8;

	while (byte_len--)
	{
		r = (r << 1) | (octet & 1);
		octet >>= 1;
	}
	return (r);

}

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet << 4 | octet >> 4));
}

unsigned char print_bits(unsigned char octet)
{
	int	i = 128;
	while (i)
	{
		(octet & i) ? write(1, "1", 1) : write(1, "0", 1);
		i = i /2;
	}
}



int	main(void)
{
	unsigned char bit = 0;
	unsigned char res = reverse_bits((unsigned char)5);

	int i = 8;
	while (i--)
	{
		bit = (res >> i & 1) + 48;
		printf("%c", bit);
	}
}

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	r;
	int byte_len = 8;

	while (byte_len--)
	{
		r = (r << 1) | (octet & 1);
		octet >>= 1;
	}
	return (r);
}

void	print_bit(unsigned char octet)
{
	int i = 128;

	while (i)
	{
		(octet & i) ? write(1, "1", 1) : write(1, "0", 1);
		i = i / 2;
	}
}

unsigned char	swap_bit(unsigned char octet)
{
	return ((4 << octet | octet >> 4));
}