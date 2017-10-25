// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
int josephus(int n, int c);
int main()
{
	int num, counter;
	scanf_s("%d%d", &num, &counter);
	printf("winner=%d\n", josephus(num, counter));
	return 0;
}
int josephus(int n, int c)
{
	int i, j, winner, *p;
	p = (int*)malloc(n * sizeof(int));
	if (p == NULL)
	{
		printf("allocation failure");
		exit(1);
	}
	for (i = 0; i < n; ++i)
		p[i] = i + 1;
	i = 0;
	while (n > 1)
	{
		i = (i + c - 1) % n;
		printf("%-4d", p[i]);
		for (j = i + 1; j < n; ++j)
			p[j - 1] = p[j];
		n--;
		if (i == n)
			i = 0;
	}
	winner = p[0];
	free(p);
	return winner;
}
