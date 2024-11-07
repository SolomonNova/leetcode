int lengthOfLongestSubstring(char* s)
{
	int len = strlen(s);

	if (len < 2) return len;

	int low = 0;
	int high = 1;
	int maxlen = 1;
	
	while (high<len)
	{
		for (int i = low;i < high;i++)
		{
			if (s[i] == s[high])
			{
				low = i + 1;
			}
		}

		int CURRET_LEN = high - low + 1;

		if (CURRET_LEN > maxlen)
		{
			maxlen = CURRET_LEN;
		}

		high++;
	}

	return maxlen;
}