char* addBinary(char* a, char* b)
{
   int lenA=strlen(a);
   int lenB=strlen(b);

   int maxlen = (lenA>lenB)?lenA:lenB;

   char *returns=(char*)malloc(maxlen+2);
   returns[maxlen+1]='\0';

   int i=lenA-1,j=lenB-1,k=maxlen;
   int carry=0;

   while(i>=0||j>=0||carry>0)
   {
      int sum=carry;

      if(i>=0)
      {
         sum+=a[i]-'0';
         i--;
      }

      if(j>=0)
      {
         sum+=b[j]-'0';
         j--;
      }

      returns[k]=sum%2 + '0';
      carry=sum/2;
      k--;
   } 

   return returns; 
}

    
