#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_convert_bin_to_char(char c)
{
	char	str;
	int		j;
	int		len;
	char	c;

	j = 0;
	c = 0;
	while (j < 8)
	{
		c = (c << 1) | (str - '0');
		j++;
	}
	printf("%c", c);
	printf("\n");
	return (0);
}

int main(void)
{
	
}