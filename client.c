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

static void	hdl(int sig)
{
	
}

int	main(int argc, char **argv)
{
	if (argc != 3 || ft_strlen(argv[2]) == 0)
		return (1);
	action(ft_atoi(argv[1]), argv[2]);
	pause();
}
