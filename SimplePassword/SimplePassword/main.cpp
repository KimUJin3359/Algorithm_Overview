#include <stdio.h>
#pragma warning(disable:4996)

int strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int judge_string(char *str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '1')
			return (1);
	}
	return (0);
}

//to binary
int* atob(char *str, int *ans)
{
	int *num;
	int res = 0;
	int size = 0;
	int flag = 0;
	int index = 0;

	num = new int[8];
	for (int i = 0; i < strlen(str) - 55; i++)
	{
		res = 0;
		for (int j = 0; j < 56; j++)
		{
			res *= 2;
			if (str[i + j] == '1')
				res += 1;
			size++;
			if (size == 7)
			{
				size = 0;
				if (ans[res] != -1)
				{
					num[index++] = ans[res];
					flag = 1;
				}
				if (!flag)
				{
					index = 0;
					break;
				}
				res = 0;
			}
		}
		res = 0;
		for (int j = 0; j < 8; j++)
		{
			if (j % 2 == 0)
				res += (num[j] * 3);
			else
				res += num[j];
		}
		if (res % 10 == 0 && index == 8)
			return (num);
		index = 0;
	}
	return (NULL);
}

int main()
{
	int rep;
	int test_c = 1;
	int row, col;
	int *temp;
	char arr[50][100] = { 0, };
	int ans[128];

	for (int i = 0; i < 128; i++)
		ans[i] = -1;
	ans[13] = 0;	ans[25] = 1;	ans[19] = 2;	ans[61] = 3;	ans[35] = 4;	ans[49] = 5;
	ans[47] = 6;	ans[59] = 7;	ans[55] = 8;	ans[11] = 9;
	scanf("%d", &rep);
	while (test_c <= rep)
	{
		int i = 0;
		for (i = 0; i < 50; i++)
		{
			for (int j = 0; j < 100; j++)
				arr[i][j] = 0;
		}
		scanf("%d %d\n", &row, &col);
		for (i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				scanf(" %c ", &arr[i][j]);
		}
		for (i = 0; i < row; i++)
		{
			if (judge_string(arr[i]))
				break;
		}
		if (!(temp = atob(arr[i], ans)))
			printf("#%d 0\n", test_c);
		else
		{
			int res = 0;
			for (int i = 0; i < 8; i++)
				res += temp[i];
			delete temp;
			printf("#%d %d\n", test_c, res);
		}
		test_c++;
	}
}