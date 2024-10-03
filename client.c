/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguengo <hguengo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:24:37 by hguengo           #+#    #+#             */
/*   Updated: 2024/10/03 12:38:33 by hguengo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi2(char *str)
{
	long	nb;
	int		len;
	int		i;

	len = 0;
	while (str && str[len])
		len++;
	i = 0;
	nb = 0;
	while (i < len)
		nb = (nb * 10) + (str[i++] - 48);
	return (nb);
}

void	ft_enviar_sinal(int pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (c & 0b10000000)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(10);
		c <<= 1;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		write(1, "Erro nos argumentos", 19);
	else
	{
		pid = ft_atoi2(argv[1]);
		while (argv[2] && *argv[2])
			ft_enviar_sinal(pid, *argv[2]++);
		ft_enviar_sinal(pid, '\n');
		ft_printf("enviado com sucesso.");
	}
	return (0);
}
