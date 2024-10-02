/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:25:36 by sanbaek           #+#    #+#             */
/*   Updated: 2024/10/03 05:11:44 by sanbaek          ###   ########.fr       */
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
	if (!validate_pid(argv[1]))
		return (1);
	send_string((pid_t)ft_atoi(argv[1]), argv[2]);
	return (0);
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

int	validate_pid(char *str)
{
	if (cmp_itoa_atoi(str) == 0)
		return (1);
	else
	{
		write(2, "Error\n: invalid PID\n", 21);
		return (0);
	}
}

int	cmp_itoa_atoi(char *str)
{
	int		num;
	int		cmp_result;
	char	*tmp_str;

	num = ft_atoi(str);
	tmp_str = ft_itoa(num);
	cmp_result = ft_memcmp(str, tmp_str, ft_strlen(str));
	free(tmp_str);
	return (cmp_result);
}
