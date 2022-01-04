/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:55:36 by rezzahra          #+#    #+#             */
/*   Updated: 2022/01/04 16:03:30 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	n;

	if (nb < 0)
	{
		ft_putchar('-');
		n = -nb;
	}
	else
		n = nb;
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
}

void print(int sig)
{
    static int c;
    static int i;

    if (sig == SIGUSR2)
        c += (1 << (7 - i));
    i++;
    if (i == 8)
    {
        write(1, &c, 1);
        i = 0;
        c = 0;
    }
}

int main()
{
    int pid;
    
    pid = getpid();
    if(pid <= 0)
        return (0);
    ft_putnbr(pid);
    write(1, "\n", 1);
    signal(SIGUSR2,print);
    signal(SIGUSR1,print);
    usleep(50);
    while(1)
        pause();
}