#include "minitalk.h"

static inline int	my_atoi(const char *str, int sign, int res, int mod)
{
	if (((9 <= *str && *str <= 13) || *str == 32) && mod == 0)
		return (my_atoi(str + 1, 1, 0, 0));
	if (*str == 43 && mod == 0)
		return (my_atoi(str + 1, 1, 0, 1));
	if (*str == 45 && mod == 0)
		return (my_atoi(str + 1, -1, 0, 1));
	if ('0' <= *str && *str <= '9')
		return (my_atoi(str + 1, sign, res * 10 + *str - 48, 1));
	return (res * sign);
}

static inline void	signal_sender(int pid, char c)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c << i & 128)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
	}
}

int	main(int ac, char **av)
{
	int	pid;

	pid = my_atoi(av[1], 1, 0, 0);
	if (ac == 3)
		while (*av[2])
			signal_sender(pid, *av[2]++);
	else
		return (ft_printf("%s", ERROR), 1);
	return (0);
}
