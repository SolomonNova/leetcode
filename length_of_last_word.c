int lengthOfLastWord(char* s)
{   
   
    int count=0;

    for(int i=strlen(s)-1;i>=0;i--)
    {
        if(s[i]!=' ')
        {
            count++;
            
            if(i-1>=0&&s[i-1]==' ')
            {
                return count;
            }

            if(i-1<0)
            {
                return count;
            }

           
        }
    }

    return 0;
}
    
