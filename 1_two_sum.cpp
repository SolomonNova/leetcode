#include <cstddef>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
    public:
        vector<int> twoSum(vector<int>& nums, int target)
        {
            unordered_map<int, int> mp;
            
            for (size_t x = 0; x < nums.size(); x++)
            {
                if (mp.find(target - nums[x]) != mp.end())    
                {
                    int value = mp[target - nums[x]];
                    return {(int)x, value};
                }    
                
                mp[nums[x]] = x;
            }
            
            return {};
        }
};
