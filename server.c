#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int bit_i;
bit_i = 0;

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

void binary_to_char(char *binary)
{
    int i;
    int len;
	int value = 0;
    int j;

	len = ft_strlen(binary);
    for (i = 0; i < len; i += 8)
    {
    	value = 0;
        for (j = 0; j < 8; j++)
        {
            value += (binary[i + j] - '0') << (7 - j);
        }
        printf("%c", value);
    }
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

void sigusr1_handler(int sig)
{
	char bits[8];
	if (sig == SIGUSR1)
	{
		printf("%d", 0);
		bits[bit_i] = '0';
		bit_i++;
	}
	if (sig == SIGUSR2)
	{
		printf("%d", 1);
		bits[bit_i] = '1';
		bit_i++;
	}
	if (bit_i == 7)
	{
		binary_to_char(bits);
		bit_i = 0;
	}
}

int main(int argc, char** argv)
{
	write(1, "PID : ", 6);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR2, sigusr1_handler);
		signal(SIGUSR1, sigusr1_handler);
	}
    return 0;
}
