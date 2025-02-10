/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:38:59 by thomas            #+#    #+#             */
/*   Updated: 2025/02/07 14:26:08 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    pipex(char **av)
{
    
}



int main(int ac, char **av)
{
    int fd[2];
    int pid;
    
    pid = 0;
    if (ac != 5)
        return (1);
    if (pipe(fd) == -1)
        return (1);
    pid = fork();
    if (pid == 0)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        execve(commande, nom_du_fichier, NULL);
        
    }
    return (0);
} 

