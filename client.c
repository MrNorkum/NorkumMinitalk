#include <unistd.h>
#include <signal.h>
#include <stdbool.h>

static void	received_signal(int sig)
{
	if (sig == SIGUSR2)
		write(1, "Signal Received\n", 16);
}

static char	err_client(void)
{
	write(1, "$---------------------------------$\n", 36);
	write(1, "~> ./client <PID> <STRING to send>\n", 35);
	write(1, "$---------------------------------$\n", 36);
	return (1);
}

static pid_t	mr_atoi(const char *s, bool sign, int res, bool mod)
{
	if (((9 <= *s && *s <= 13) || *s == 32) && !mod)
		return (mr_atoi(s + 1, false, 0, false));
	if (*s == 43 && !mod)
		return (mr_atoi(s + 1, false, 0, true));
	if (*s == 45 && !mod)
		return (mr_atoi(s + 1, true, 0, true));
	if ('0' <= *s && *s <= '9')
		return (mr_atoi(s + 1, sign, (res * 10) + (*s & 15), true));
	if (sign)
		return (1 + ~res);
	return (res);
}

static void	signal_sender(pid_t pid, char c)
{
	register int	i;

	i = -1;
	while (++i < 8)
	{
		kill(pid, SIGUSR1 + !(c << i & 128));
		usleep(200);
	}
}

int	main(int argc, char *argv[])
{
	register pid_t	pid;

	if (argc == 3)
	{
		pid = mr_atoi(argv[1], false, 0, false);
		if (pid == -1)
			return (-1);
		signal(SIGUSR2, received_signal);
		while (*argv[2])
			signal_sender(pid, *argv[2]++);
		signal_sender(pid, '\0');
		return (0);
	}
	return (err_client());
}
