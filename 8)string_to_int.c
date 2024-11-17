#include<stdbool.h>
#include<string.h>
#include<stdio.h>
#include<limits.h>

int myAtoi(char* s)
{
	int len = strlen(s);

	if (len == 0 || (len == 1 && !(s[0] - '0' < 10 && s[0] - '0' >= 0)))return 0;
	if (len == 1 && (s[0] - '0' >= 0 && s[0] - '0' < 10))return s[0] - '0';

	long long num = 0;
	int i = 0;
	bool isnegative = false;

	while (s[i] == ' ') { i++; }

	if (s[i] == '+' || s[i] == '-')
	{
		isnegative = (s[i] == '-');
		i++;
	}

	if (!(s[i] >= '0' && s[i] <= '9')) { return 0; }

	for (;i < len;i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			num = num * 10 + (s[i] - '0');
			if (!isnegative && num > INT_MAX) { return INT_MAX; }
			if (isnegative && -num < INT_MIN) { return INT_MIN; }
		}
		else break;
	}

	return isnegative ? -num : num;
}


