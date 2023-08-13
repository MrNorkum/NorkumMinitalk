#include "minitalk.h"
#include <signal.h>

static inline int	ft_atoi(const char *str)
{
	static int	res;

	while ('0' <= *str && *str <= '9')
		res = res * 10 + *str++ - 48;
	return (res);
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
		usleep(500);
	}
}

static inline void	received_signal(int sig)
{
	if (sig == SIGUSR2)
        ft_printf("Signal Received\n");
}

int	main(int ac, char **av)
{
	int	i;
    	int	pid;

	i = -1;
    	pid = ft_atoi(av[1]);
	if (ac == 3)
	{
		while (av[2][++i])
			signal_sender(pid, av[2][i]);
        signal(SIGUSR2, received_signal);
        signal_sender(pid, '\0');
	}
	else
		ft_printf("CLIENT : FORMAT Error!\n");
}