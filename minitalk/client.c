/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:55:23 by rezzahra          #+#    #+#             */
/*   Updated: 2022/01/04 18:59:30 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	return (nbr * sign);
}

void    processing(char c, int pid)
{
    int j = 7;
    int b = 0;
    
    while(j >= 0)
    {
        b = ((c >> j) & 1);
        if (b == 1)
            kill(pid,SIGUSR2);
        else
            kill(pid,SIGUSR1);
        usleep(200);
        j--;
    }
}
int main(int ac, char **av)
{
    int pid;
    int i = 0;
   
    if (ac != 3)
        write(1, "Error", 5);
    else
    {
        pid = ft_atoi(av[1]);
        while(av[2][i])
        {   
            processing(av[2][i],pid);
            i++;
        }
    }
}