#include <stdio.h>
#pragma warning (disable : 4996)

int strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int main()
{
	char x[] = "01D06079861D79F99F";
	char str[512];
	int index = 0;
	int size = 0;
	int res = 0;

	for (int i = 0; i < strlen(x); i++)
	{
		if (x[i] >= '0' && x[i] <= '9')
			res = x[i] - '0';
		else if (x[i] >= 'A' && x[i] <= 'F')
			res = x[i] - 'A' + 10;
		for (int j = 3; j >= 0; j--)
		{
			if (res & (1 << j))
				str[index++] = '1';
			else
				str[index++] = '0';
		}
	}
	str[index] = 0;
	res = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		res *= 2;
		if (str[i] == '1')
			res += 1;
		size++;
		if (size == 7)
		{
			size = 0;
			printf("%d ", res);
			res = 0;
		}
	}
	if (res != 0)
		printf("%d", res);
}