#include <stdio.h>
#include <string.h>

void binary_to_char(char *binary)
{
    int i;
    int len;
	int value = 0;
    int j;

	len = strlen(binary);
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

int main(void)
{
    binary_to_char("010000010100001001000011010001000100010101000110010000010100011101000111010101011001010110010101110000011011110110111101110101");
    return 0;
}
