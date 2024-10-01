
/*
You can have one global variable per program
(one for the client and one for the server),
but you will have to justify their use.

signal()
sigaction()

sigemptyset()
sigaddset()

getpid()

kill()

pause
sleep
usleep
eixt

*/
#include "mini_talk.h"

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("%d",write(2, "Error\n: improper argc\n", 23));
		return (1);
	}
	if (validate_str(argv[2]))
		return (1);
	send_string((pid_t)ft_atoi(argv[1]), argv[2]);
	return (0);
}

int validate_str(char *str)
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

void	send_string(pid_t server_pid, char *str)
{
	int	i;
	i = 0;
	int *bit;
	bit = ft_atob(str);
	send_bit(server_pid, bit);
	return ;
}

int	*ft_atob(char *str)
{
	int	i;
	int	k;
	int	*bit;

	i = 0;
	k = 0;
	if (str == NULL)
		return (NULL);
	bit = (int *)ft_calloc(ft_strlen(str) * 8, sizeof(int));
	if (bit == NULL)
		return (NULL);
	memset(bit, -1, ft_strlen(str) * 8);
	char *tmp_str;
	memmove(tmp_str, str, ft_strlen(str));
	while (tmp_str[i] != '\0')
	{
		while ((k + 1) % 8 != 0)
		{
			if ((tmp_str[i] & 1) == 1)
				bit[k] = 1;
			else if ((tmp_str[i] & 1) == 0)
				bit[k] = 0;
			k++;
			tmp_str[i] = tmp_str[i] >> 1;
		}
		i++;
	}
	return (bit);
}

int send_bit(pid_t server_pid, int *bit)
{
	int	i;

	if (bit == NULL)
		return (0);
	i = 0;
	while (bit[i] != -1)
	{
		if (bit[i] == 1)
			kill(server_pid, SIGUSR1);
		else if (bit[i] == 0)
			kill(server_pid, SIGUSR2);
		else
			return (-1);
		usleep(50);
		i++;
	}
	return (i);
}