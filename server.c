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

void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

//static void    hdl(int sig)
//{
//
//}
int	main(void)
{
	struct sigaction	a;

	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	a.sa_handler = hdl;
	sigaction(SIGUSR1, &a, NULL);
	sigaction(SIGUSR2, &a, NULL);
	pause();
}
