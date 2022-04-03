/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:12:19 by lel-khou          #+#    #+#             */
/*   Updated: 2022/04/01 14:28:20 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "libft/libft.h"

static void    hdl(int sig)
{
	static int	i;
	int		j;
	static char	c;

	i++;
	j = 8 - i;
	if (sig == SIGUSR2)
		c = 128 >> j | c;
	if (sig == SIGUSR1)
		c = c | 0;
	if (j == 0)
	{
		ft_putchar_fd(c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, hdl);
	signal(SIGUSR2, hdl);
	while (1)
		pause();
}
