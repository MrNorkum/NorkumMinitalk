#include <unistd.h>
#include <signal.h>
#include <stdbool.h>

static void	my_putnbr(int n)
{
	if (n > 9)
		my_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

static void	start_server(void)
{
	write(1, "$------------$\n", 15);
	write(1, "PID ~> ", 8);
	my_putnbr(getpid());
	write(1, "\n$------------$\n", 16);
	write(1, "\n~> ", 4);
}

static void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	i = 0;
	static unsigned char	c = 0;

	(void)context;
	c = (c << 1) | !!(sig == SIGUSR1);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		kill(info->si_pid, SIGUSR2 * !c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	x;

	x.sa_flags = SA_SIGINFO;
	x.sa_sigaction = &signal_handler;
	start_server();
	sigaction(SIGUSR1, &x, NULL);
	sigaction(SIGUSR2, &x, NULL);
	while (true)
		pause();
}
