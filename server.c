#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	ft_convert_bin_to_char(char c)
{
	char	str;
	int		j;
	int		len;

	j = 0;
	c = 0;
	while (j < 8)
	{
		c = (c << 1) | (str - '0');
		j++;
	}
	printf("%c", c);
	printf("\n");
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n < 10)
	{
		ft_putchar_fd((n + 48), fd);
		return ;
	}
	ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

void sigusr1_handler(int sig) {
	if (sig == SIGUSR1)
		printf("%d\n", 0);
	if (sig == SIGUSR2)
		printf("%d\n", 1);
}

int main(int argc, char** argv) {
	write(1, "PID : ", 6);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR2, sigusr1_handler);
		signal(SIGUSR1, sigusr1_handler);
	}
    // code principal de votre programme
    return 0;
}
