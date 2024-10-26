/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int carry = 1;
    int sum = 0;

    for (int i = digitsSize - 1; i >= 0; i--)
    {
        sum = digits[i] + carry;
        digits[i] = sum % 10;
        carry = sum / 10;

        if (carry == 0) 
        {
            *returnSize = digitsSize;
            int* result = (int*)malloc(digitsSize * sizeof(int));
            for (int j = 0; j < digitsSize; j++)
            {
                result[j] = digits[j];
            }
            return result;
        }
    }

    *returnSize = digitsSize + 1;
    int* result = (int*)malloc(*returnSize * sizeof(int));
    result[0] = 1;
    for (int i = 1; i < *returnSize; i++)
    {
        result[i] = 0;
    }

    return result;
}
