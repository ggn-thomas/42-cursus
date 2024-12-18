/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 22:23:38 by thgaugai          #+#    #+#             */
/*   Updated: 2024/07/31 14:18:49 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void compare(s_stock_max carre, s_stock_max max)
{
    if (carre.size > max.size)
    {
        max.size = carre.size;
        max.x = carre.x;
        max.y = carre.y;
    }
}
void    check_map(int length, char **tab)
{
    int x ;
    int y ;
    s_stock_max max ; // variable qui stocke les coordonnes ainsi que la taille du plus grande carre trouve
    s_stock_max carre ; // variable qui stocke les coordonnes ainsi que la taille d'un carre qu'on va verifier

    (void)length;
    y = 1;
    x = 0;
    max.size = 0;
    max.x = 0;
    max.y = 0;
    while (tab[y]) // on parcourt toutes les colonnes
    {   
        x = 0;
        while (tab[y][x] != '\n') // on parcourt toutes les lignes de chaque colonnes
        {   
            carre.x = x; // le carre prend par defaut les coordonnes d'ou on se trouve
            carre.y = y;
            carre.size = 1;
            while (tab[y + 1][x + 1] != 'o' && tab[y + 1][x + 1] != '\n') // on check les diagonales
            {
                if (check_line(carre, tab)) // on check les lignes 
                {
                    carre.size++; // si les lignes sont bonnes on incremente la taille du carre 
                }
                compare(carre, max); // on compare la taille du carre actuel avec le plus grand 
                x++; //on continue d'incremente tant que les diagonales et les lignes sont bonnes
                y++;
            }
            x = carre.size; // si les diagonales ne sont pas bonne on decale de la largeur du carre precedent 
        }
        y = carre.size ;
    }
    fill_square(max,tab);
}

int    check_line(s_stock_max carre, char **tab)
{
        int x ;
        int y ;

        y = carre.size + carre.x ;
        x = carre.size + carre.y ;
        while(tab[y][x] != tab[carre.y][x])
        {
            if (tab[y][x] != 'o')
                y--;
            else
                return (0);
        }
        while(tab[y][x] != tab[y][carre.x])
        {
            if (tab[x][y] != 'o')
                x--;
            else 
                return (0);
        }    
        return (1);
}

void fill_square(s_stock_max max, char **tab)
{
    while (tab[max.y][max.x] != tab[max.y + max.size][max.x])
    {
        while (tab[max.y][max.x] != tab[max.y][max.x + max.size])
        {
            tab[max.y][max.x] = 'x';
            max.x++;
        }
        max.y++;
    }
    aff_tab(tab); 
}


void	aff_tab(char **tab)
{
	int	i ;
	int	j ;
	
	i = 0;
	j = 0;
	while (tab[i])
	{	
		j = 0;
		while (tab[i][j] != '\n')
		{
			write(1, &tab[i][j], 1);
			j++;
		}
		i++;
	}
}
