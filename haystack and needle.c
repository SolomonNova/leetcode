int strStr(char* haystack, char* needle)
{  
    int index=0;

    for(int i=0;i<strlen(haystack);i++)
    {       
            int count=1;
            if(haystack[i]==needle[0])
            {  
                index=i;
                
                for(int j=1;j<strlen(needle)&&(i+j<strlen(haystack));j++)
                {
                    if(haystack[i+j]==needle[j])
                    {
                        count++;
                        
                    }
                }

                if(count==strlen(needle))
                        {
                            return index;
                        }
            }    
    }

   
    
        return -1;
    
}    
