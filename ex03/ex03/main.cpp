#include <stdio.h>
#pragma warning (disable:4996)

int strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (-s2[i]);
	else if (!s2)
		return (s1[i]);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int main()
{
	int index = 0;
	char x[] = "0269FAC9A0";
	char password[11][7] = { "001101", "010011", "111011", "110001", "100011", "110111", "001011", "111101", "011001", "101111" };
	int size = strlen(x) * 4;
	char str[256];

	for (int i = 0; i < strlen(x); i++)
	{
		int num;

		if (x[i] >= '0' && x[i] <= '9')
			num = x[i] - '0';
		else if (x[i] >= 'A' && x[i] <= 'F')
			num = x[i] - 'A' + 10;
		for (int j = 3; j >= 0; j--)
		{
			if (num & (1 << j))
				str[index++] = '1';
			else
				str[index++] = '0';
		}
	}
	str[index] = 0;
	index = 0;
	while (str[index])
	{
		for (int i = 0; i < 10; i++)
		{
			int flag = 0;
			for (int j = 0; j < 6; j++)
			{
				if (str[index + j] != password[i][j])
					flag = 1;
			}
			if (!flag)
			{
				index += 5;
				printf("%d", i);
			}
		}
		index++;
	}
}