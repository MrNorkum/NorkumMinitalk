#include "minitalk.h"

static inline void	signal_handler(int sig)
{
	static int	i = 0;
	static char	c = 0;

	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else
		c = (c << 1);
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("SERVER : Server Started\nPID -> %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
}
