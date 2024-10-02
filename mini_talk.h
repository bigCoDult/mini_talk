#ifndef MINI_TALK_H
# define MINI_TALK_H

// # include "libft.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <signal.h>
# include <sched.h>

typedef struct s_byte
{
	unsigned char	byte;
	int				received_bit;
}	t_byte;

int		validate_str(char *str);
char	*send_string(pid_t server_pid, char *str);
void	combine_bit(int sig);


#endif /* MINI_TALK_H */