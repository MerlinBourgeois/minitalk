#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_convert_bin(char *str, int pid)
{
	int		res;
	int		i;
	int		j;

	i = 0;
	while (i < ft_strlen(str))
	{
		j = 7;
		while (j >= 0)
		{
			res = (str[i] >> j) & 1;
			{
				if (res == 0)
				{
					kill(pid, SIGUSR1);
					usleep(300);
				}
				if (res == 1)
				{
					kill(pid, SIGUSR2);
					usleep(300);
				}
			}
			j--;
		}
		i++;
	}
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
	c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long int	result;

	sign = 1;
	result = 0;
	while (ft_is_whitespace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while ((*str != '\0') && ft_isdigit(*str))
	{
		if ((result > 922337203685477580 || (result == 922337203685477580
					&& (*str - '0') > 7)) && sign == 1)
			return (-1);
		else if ((result > 922337203685477580 || (result == 922337203685477580
					&& (*str - '0') > 8)) && sign == -1)
			return (0);
		result = (result * 10) + (*str - '0');
		str++;
	}
	return ((int)(result * sign));
}

int main(int argc, char** argv) {
	int result;
	int pid;
	
	if (argc != 3)
	{
		write(1, ("Le client prends deux arguments.\n"), ft_strlen("Le client prends deux arguments.\n"));
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	ft_convert_bin(argv[2], pid);
    return 0;
}