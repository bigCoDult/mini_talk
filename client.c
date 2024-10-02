/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:25:36 by sanbaek           #+#    #+#             */
/*   Updated: 2024/10/02 13:43:16 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(2, "Error\n: improper argc\n", 23);
		return (1);
	}
	if (!validate_str(argv[2]))
		return (1);
	send_string((pid_t)ft_atoi(argv[1]), argv[2]);
	return (0);
}

int	validate_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(2, "Error\n: null string\n", 21);
		return (0);
	}
	while (str[i] != '\0')
	{
		if (ft_isprint(str[i]) == 0)
		{
			write(2, "Error\n: non-printable character\n", 33);
			return (0);
		}
		i++;
	}
	return (1);
}

char	*send_string(pid_t server_pid, char *str)
{
	int	i;
	int	bit_up;

	i = 0;
	while (str[i] != '\0')
	{
		bit_up = 7;
		while (bit_up >= 0)
		{
			if ((str[i] & (1 << bit_up)) != 0)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(400);
			bit_up--;
		}
		i++;
	}
	return (str);
}
