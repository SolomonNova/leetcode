char* longestPalindrome(char* s)
{
    int len = strlen(s);
    if (len < 2) return s;

    int low = 0, high = 0;
    int maxLength = 1, start = 0;

    for (int i = 0;i < len;i++)
    {
        low = i - 1;
        high = i + 1;

        while (low >= 0 && high < len && s[low] == s[high])
        {
            if (high - low + 1 > maxLength) {
                start = low;
                maxLength = high - low + 1;
            }
            low--;
            high++;
        }

        low = i;
        high = i + 1;

        while (low >= 0 && high < len && s[low] == s[high])
        {
            if (high - low + 1 > maxLength) {
                start = low;
                maxLength = high - low + 1;
            }
            low--;
            high++;
        }
    }

    char* result = (char*)malloc((maxLength + 1) * sizeof(char));
    strncpy(result, s + start, maxLength);
    result[maxLength] = '\0';

    return result;
}
