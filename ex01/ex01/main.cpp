#include <stdio.h>
#pragma warning(disable : 4996)

int strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int main()
{
	int j = 0;
	int res = 0;
	char x[] = "0000000111100000011000000111100110000110000111100111100111111001100111";

	for (int i = 0; i < strlen(x); i++)
	{
		res *= 2;
		if (x[i] == '1')
			res += 1;
		j++;
		if (j == 7)
		{ 
			j = 0;
			printf("%d ", res);
			res = 0;
		}
	}
	
	if (res != 0)
		printf("%d", res);
}