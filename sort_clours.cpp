#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    void sortColors(vector<int>& nums)
    {
        if (nums.size() < 2) return;
  
        int red = 0, white = 0, blue = 0;

        for (int i = 0;i < nums.size();i++)
        {
            if (nums[i] == 0) red++;
            else if (nums[i] == 1) white++;
            else if (nums[i] == 2) blue++;
        }

        for (int j = 0;j<nums.size();j++)
        {
            if (red)
            {
                nums[j] = 0;
                red--;
            }

            else if (white)
            {
                nums[j] = 1;
                white--;
            }

            else if (blue)
            {
                nums[j] = 2;
                blue--;
            }

            
        }
        return;
    }
};

int main()
{
    vector<int>arr = { 1,2,0,0,2,1,1,0 };

    Solution solution;

    solution.sortColors(arr);

    for (int i = 0;i < arr.size();i++)
    {
        cout << "the " << i << " element of the array is:" << arr[i] << endl;
    }

    return 0;
}