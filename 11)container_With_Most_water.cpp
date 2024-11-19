#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:

    int maxArea(vector<int>& height)
    {
        if (height.size() < 2) return 0;

        int* front = &height[0];
        int* back = &height[height.size() - 1];
        int max = 0;

        while (front < back)
        {
            int count = ((*front < *back) ? *front : *back) * (back - front);
            if (count > max) max = count;

            if (*front > *back)
            {
                back--;
            }

            else
            {
                front++;
            }
        }

        return max;
    }
};

int main()
{
    vector<int>height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    Solution solution;

    cout << "the max area is:" << solution.maxArea(height) << endl;

    return 0;
}