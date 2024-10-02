/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:46:04 by sanbaek           #+#    #+#             */
/*   Updated: 2024/10/02 13:46:18 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

/*
The server must be started first.
After its launch, it has to print its PID
Declaration and an initialisation cannot be on the same line,
except for global variables (when allowed),
static variables, and constants.
*/

t_byte	g_byte;

int	main(void)
{
	pid_t	process_id;

	process_id = getpid();
	ft_printf("%d\n", process_id);
	signal(SIGUSR1, combine_bit);
	signal(SIGUSR2, combine_bit);
	while (1)
		pause();
	return (0);
}

void	combine_bit(int sig)
{
	if (sig == SIGUSR1)
	{
		g_byte.byte <<= 1;
		g_byte.byte |= 1;
	}
	else if (sig == SIGUSR2)
	{
		g_byte.byte <<= 1;
	}
	g_byte.received_bit++;
	if (g_byte.received_bit == 8)
	{
		ft_printf("%c", g_byte.byte);
		g_byte.received_bit = 0;
		g_byte.byte = 0;
	}
	return ;
}
