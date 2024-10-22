int removeElement(int* nums, int numsSize, int val) 
{
    if(nums==0)
    {
        return 0;
    }

    int not_val=0;

    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]!=val)
        {
            nums[not_val]=nums[i];
            not_val++;
        }
    }

    return not_val;
}    