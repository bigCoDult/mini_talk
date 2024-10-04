/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:46:47 by sanbaek           #+#    #+#             */
/*   Updated: 2024/10/04 12:56:36 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include "libft.h"
# include <unistd.h>
# include <signal.h>

typedef struct s_byte
{
	char	byte;
	int		received_bit;
}	t_byte;

int		validate_pid(char *str);
int		cmp_itoa_atoi(char *str);
char	*send_string(pid_t server_pid, char *str);
void	combine_bit(int sig);

#endif /* MINI_TALK_H */