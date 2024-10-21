bool isPalindrome(int x)
{
    if(x<0)
    {
        return false;
    }



        char arr[256];
        sprintf(arr,"%d",x);

        int j;

        for(int i=0;i<strlen(arr);i++)
        {
            if(arr[i]=='\0')
            {
                 j=i;
                 return 0;
            }
        }

     if(x!=0)
     {for(int i=0;i<j;i++)
        {
            if(arr[i]!=arr[j-1-i])
               {
                   return false;
               }

        }
     }
        else
        {
            return true;
        }

}


