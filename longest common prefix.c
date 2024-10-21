char* longestCommonPrefix(char** strs, int strsSize)
{
    char* prefix=strs[0];

    if(strSize==0)
    {
        return "";
    }
    if(strSize==1)
    {
        return prefix;
    }

    for(int i=1;i<strsSize;i++)
    {
        int j=0;

        while(prefix[j]&&strs[i][j]&&(prefix[j]==strs[i][j]))
        {
            j++;
        }
    }

    prefix[j]='\0';

    return prefix;
}

