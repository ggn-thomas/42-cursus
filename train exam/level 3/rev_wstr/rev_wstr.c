/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:29:29 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/29 14:56:49 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_last(char *str, int len)
{
	int	i;

	while (len > 0 && (str[len] == ' ' || str[len] == '\t'))
		len--;
	i = 0;
	while (i <= len && str[len - i] != ' ' && str[len - i] != '\t')
		i++;
	write(1, str + len - i + 1, i);
	while (len > 0 && (str[len] == ' ' || str[len] == '\t'))
		len--;
	if (i < len)
		write (1, " ", 1);
	return (len - i);
}

int main (int ac , char **av)
{
	int	len;

	if (ac == 2)
	{
		len = 0;
		while (av[1][len] != '\0')
			len++;
		len--;
		while (len > 0)
			len = print_last(av[1], len);
	}
	write(1, "\n", 1);
	return (0);
}
