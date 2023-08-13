#include "minitalk.h"
#include <signal.h>

static inline void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	i;
	static char	c;

	(void)context;
	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else if (sig == SIGUSR2)
		c = (c << 1);
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
        	kill(info->si_pid, SIGUSR2);
		i = 0;
		c = 0;
	}
}


int	main(int argc, char **argv)
{
	struct sigaction	act;

    	act.sa_flags = SA_SIGINFO;
    	act.sa_sigaction = &signal_handler;
    	ft_printf("SERVER : Server Started\nPID -> %d\n", getpid());
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
}
