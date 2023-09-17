#include "minitalk.h"

static inline void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int	i = 0;
	static char	c = 0;

	(void)context;
	c = (c << 1) | (sig == SIGUSR1);
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		kill(info->si_pid, SIGUSR2 * (!c));
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &signal_handler;
	ft_printf("%s%d\n", START, getpid());
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
}
