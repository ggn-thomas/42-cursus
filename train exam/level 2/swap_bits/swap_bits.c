/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:20:57 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/30 08:41:01 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	swap_bits(unsigned char octet)
{
	return (octet << 4 | octet >> 4);
}

unsigned char	swap_bits(unsigned char octet)
{
	return(octet << 4 | 4 >> octet);
}