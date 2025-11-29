#include<iostream>
#include<vector>
#include<string>

class Solution
{
    public:
        int myAtoi(std::string s)
        {
            if (s.size() < 1) return 0;

            int i = 0;
            bool isNegative = false;
            bool startIndexFound = false;
            int startIndex = 0;
            int endIndex = 0;

            while (s[i] == ' ') i++;

            if (s[i] != '+' && s[i] != '-' && (s[i] < '0' || s[i] > '9')) return 0;

            if (s[i] == '+') i++;

            else if (s[i] == '-')
            {
                isNegative = true;
                i++;
            }

            if (s[i] < '0' || s[i] > '9') return 0;

            while (s[i] == '0') i++;

            if (s[i] < '0' || s[i] > '9') return 0;

            while (s[i] >= '0' && s[i] <= '9')
            {
                if (startIndexFound == false)
                {
                    startIndexFound = true;
                    startIndex = i;
                }

                i++;
            }

            endIndex = i - 1;

            long result = 0;
            long multiplier = 1;

            //std::cout << endIndex << std::endl;
            //std::cout << startIndex << std::endl;

            bool isJumped = false;

            for (int j = startIndex; j <= endIndex; j++)
            {
                if (result > INT_MAX / 10)
                {
                    isJumped = true;
                    break;
                }

                else if (result == INT_MAX / 10)
                {
                    if (s[i] - '0' > INT_MAX % 10) break;
                }

                result = result * 10 + (s[j] - '0');

                //std::cout << result << std::endl;
                //std::cout << j << std::endl;
                //std::cout << result << std::endl;
            }

            if (isJumped)
            {
                if (isNegative) return INT_MIN;
                else return INT_MAX;
            }

            if (isNegative) result = -result;

            if (result > INT_MAX) return INT_MAX;
            if (result < INT_MIN) return INT_MIN;

            return result;
        }
};




int main()
{
    Solution* s = new Solution();
    std::cout << s->myAtoi("20000000000000000000");

    return 0;
}