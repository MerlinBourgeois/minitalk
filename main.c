#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "Hello, World!";
	int		i;
	int		j;

	i = 0;
	while (i < strlen(str))
	{
		j = 7;
		while (j >= 0)
		{
			printf("%d", (str[i] >> j) & 1);
			j--;
		}
		printf(" ");
		i++;
	}
	printf("\n");
	return (0);
}