#include <unistd.h>
#include <signal.h>

static void	received_signal(int sig)
{
	if (sig == SIGUSR2)
		write(1, "Signal Received\n", 16);
}

static void	err_client(void)
{
	write(1, "$---------------------------------$\n", 36);
	write(1, "~> ./client <PID> <STRING to send>\n", 35);
	write(1, "$---------------------------------$\n", 36);

}

static int	my_atoi(const char *s, char sign, int res, char mod)
{
	if (((9 <= *s && *s <= 13) || *s == 32) && !mod)
		return (my_atoi(s + 1, 0, 0, 0));
	if (*s == 43 && !mod)
		return (my_atoi(s + 1, 0, 0, 1));
	if (*s == 45 && !mod)
		return (my_atoi(s + 1, 1, 0, 1));
	if ('0' <= *s && *s <= '9')
		return (my_atoi(s + 1, sign, (res * 10) + (*s & 15), 1));
	if (sign)
		res = 1 + ~res;
	return (res);
}

static void	signal_sender(int pid, char c)
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

	if (ac == 3)
	{
		pid = my_atoi(av[1], 1, 0, 0);
		if (!pid)
			return (err_client(), 1);
		signal(SIGUSR2, received_signal);
		while (*av[2])
			signal_sender(pid, *av[2]++);
		signal_sender(pid, '\0');
	}
	else
		return (err_client(), 1);
	return (0);
}
