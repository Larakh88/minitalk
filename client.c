/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:12:26 by lel-khou          #+#    #+#             */
/*   Updated: 2022/04/01 14:28:16 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

static void	action(int pid, char *str)
{
	int	i;
	char	c;
	int	j;

	i = 0;
	while (str[i] != 0)
	{
		c = str[i];
		j = 7;
		while (j >= 0)
		{
			if ((c << j & 128) == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j--;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || ft_strlen(argv[2]) == 0)
		return (1);
	action(ft_atoi(argv[1]), argv[2]);
}
