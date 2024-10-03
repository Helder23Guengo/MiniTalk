/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguengo <hguengo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:24:27 by hguengo           #+#    #+#             */
/*   Updated: 2024/10/03 12:38:46 by hguengo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr_digito(long nbr)
{
	char	temp;

	if (nbr / 10 > 0)
		ft_putnbr_digito(nbr / 10);
	temp = nbr % 10 + '0';
	write(1, &temp, 1);
}

void	ft_clear(void)
{
	write(STDOUT_FILENO, "\e[1;1H\e[2J", 11);
}

void	manipulador_bits(int sinal)
{
	static unsigned char	ch;
	static int				i;

	ch |= (sinal == SIGUSR1);
	i++;
	if (i == 8)
	{
		if (ch == '\0')
			write(1, "\n", 1);
		else
			write(1, &ch, 1);
		ch = 0;
		i = 0;
	}
	else
		ch <<= 1;
}

int	main(void)
{
	struct sigaction	sigact;

	ft_clear();
	ft_printf("*********************************************\n");
	ft_printf("---------------------------------------------\n");
	ft_printf("||User:hguengo                             ||\n");
	ft_printf("||Camp:42 Luanda                           ||\n");
	ft_printf("||Servidor \033[1;32mOnline\033[0m                \033[1;93mPID:");
	ft_putnbr_digito(getpid());
	ft_printf("\033[0m||\n");
	ft_printf("---------------------------------------------\n");
	ft_printf("\n");
	ft_printf("Esperando mensagens\n");
	ft_printf("_________________________________________\n");
	write(1, "\n", 1);
	while (1)
	{
		sigact.sa_handler = &manipulador_bits;
		sigact.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sigact, 0);
		sigaction(SIGUSR2, &sigact, 0);
	}
	return (0);
}
