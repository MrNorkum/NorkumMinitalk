#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdarg.h>
# include <unistd.h>

# define DEC "0123456789"
# define HEXLOW "0123456789abcdef"
# define HEXUP "0123456789ABCDEF"
# define START "SERVER : Server Started\nPID -> "
# define ERROR "CLIENT : FORMAT Error! -> ./client <PID> <STRING to send>"

typedef struct s_printf
{
	va_list		args;
	char		f;
	int			len;
}		t_printf;

int	ft_printf(const char *str, ...);

#endif

