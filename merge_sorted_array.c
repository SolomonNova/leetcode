void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    if(nums1Size==0||n==0&&m!=0)
    {
        return ;
    }

    if (m==0&&(n!=0))
    {
        for(int i=0;i<n;i++)
        {
            nums1[i]=nums2[i];
        }

        return ;
    }

    int i=m-1;
    int j=n-1;
    int k=(m+n)-1;

    while(i>=0&&j>=0)
    {
        int x=(nums1[i]>nums2[j])?nums1[i]:nums2[j];
        nums1[k]=x;

        if(x==nums1[i])
        {
            i--;
        }

        else
        {
            j--;
        }

        k--;

        if(i<0)
        {
            while(j>=0)
            {
                nums1[k]=nums2[j];
                j--;
                k--;
            }

            return ;
        }

        if(j<0)
        {
            while(i>=0)
            {
                nums1[k]=nums1[i];
                i--;
                k--;
            }

            return ;
        }

    }
}
    
