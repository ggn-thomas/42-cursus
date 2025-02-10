/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:07:08 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/29 22:03:38 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

int main (int ac , char **av)
{
	int i = 0;
	int j;

	if (ac >= 2)
	{

			while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))//je skip les espaces au début
			{
				i++;
			}
			j = i; // sera mon point de départ pour le premier mot
			while (av[1][i])
			{
				while (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t')) //je cherche le deuxième mot
				{
					i++;
				}
				while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t')) //je skip les espaces entre le premier et le deuxième mot
				{
					i++;
				}
				while (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t') && (av[1][i -1] == ' ' || av[1][i - 1] == '\t'))// si jamais avant le deuxième mot j'ai un espace je commence à l'écrire
				{
					while (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t')) //je l'écris jusqu'à rencontrer un espace
					{
						write (1, &av[1][i], 1);
						i++;
					}
					write (1, " ", 1); //je write un espace pour séparer es z
					i++;
				}
			}
			while (av[1][j] && (av[1][j] != ' ' && av[1][j] != '\t'))
			{
				write (1, &av[1][j], 1);
				j++;
			}
	}
	write (1, "\n", 1);
}