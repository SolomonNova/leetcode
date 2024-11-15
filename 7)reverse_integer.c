#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

int reverse(int x)
{
	if (x / 10 == 0)
	{
		return x;
	}

	long long num = x;

	bool isnegative = false;
	long int reverse_num = 0;

	if (x < 0)
	{
		num = -num;
		isnegative = true;
	}

	while (num != 0)
	{
		int remainder = num % 10;

		reverse_num = reverse_num * 10 + remainder;

		if (reverse_num > INT_MAX) return 0;

		num /= 10;
	}

	if (isnegative)
	{
		reverse_num = -reverse_num;

		if (reverse_num < INT_MIN) return 0;

		return (int)reverse_num;
	}

	return (int)reverse_num;
}

