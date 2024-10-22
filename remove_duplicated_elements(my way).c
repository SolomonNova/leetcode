int removeDuplicates(int* nums, int numsSize)
{
    int unique=1;
  
    for(int i=1;i<numsSize;i++)
    {
        if(nums[i]!=nums[i-1])
        {
            unique++;
        }
    }
    for(int k=0;k<numsSize;k++)
    {
        for(int i=1;i<numsSize;i++)
        {
            if(nums[i]==nums[i-1])
            {
                for(int j=i;j<numsSize;j++)
                {
                    nums[j-1]=nums[j];               
                }
            }
        }
    }

    
    return unique;
}
    
