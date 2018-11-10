#include <stdio.h>
#include <stdlib.h>



int main()
{
    char text[500] = "My name is Ahmed Mohamed Abdo m Ahmed Mohamed";
    char strs[] = "Abdo";
    char strr[] = "elsayed";
    Last(text,strs,strr);
    return 0;
}

void CaseSensitive(char text[100], char strs[20], const char strr[20])
{
   char array[10] = "";
   char textbackup[500] = "";
   char *save;
   int i = 0;
   int j = 0;
   int k = 0;
   int l = 0;
   int m;
   int slen = strlen(strs);
   int tlen = strlen(text);
   int strrlen = strlen(strr);
   int alen;
   char *ptext;
   char *ptextbackup;
   ptext = &text[0];
   for(i = 0; i < tlen; i++)
    {
        for(j = 97; j <= 122; j++)
        {
            if((int)(text[i] == j) )
            {
                textbackup[i] = (int)text[i] - 32; // This section to transform the small letters of text[] to capital letter//
                j= 123;
            }
            else
            {
                textbackup[i] = text[i];
            }
        }
    }
    for(i = 0; i < slen; i++)
    {
        for(j = 97; j <= 122; j++)
        {
            if((int)(strs[i] == j) )
            {
                strs[i] = (int)strs[i] - 32;   // This section to transform the small letters of strs[] to capital letter//
                j= 123;
            }

        }
    }
    j =0;
    i = 0;
    while(textbackup[i] != '\0')
    {
       while((textbackup[i] != ' ')&&(i<=tlen)&&(textbackup[i] != '\0'))
       {
           array[j] = textbackup[i];
           j++;
           i++;
           ptext++;
       }
       j = 0;
       i++;
       ptext++;
       alen = strlen(array);
       if(alen == slen)
       {
          ptext--;
            for(k = 0; k < alen; k++)
           {
               if (array[k] == strs[k])
               {
                   l++;
               }
               else
               {
                   k = alen;
                   l = 0;
               }
           }
           if (l == alen)
           {
               l = 0;
               if (strrlen <= slen)
               {
                   ptext = ptext - slen;
                   for( m = 0; m < slen; m++)
                   {
                       if(m < strrlen)
                       {
                           *ptext = strr[m];
                       }
                       ptext = ptext + 1;
                      *ptext=' ';
                   }
                 ptextbackup = ptext;
                 for(m = 0 ; m < (slen - strrlen); m++)
                 {
                    while(*ptext!='\0')
                    {
                       *ptext = *(ptext + 1);
                       ptext++;
                    }
                   ptextbackup --;
                   ptext = ptextbackup;
               }
               i--;
            }
            else
            {
                ptextbackup = ptext;
                ptext = ptext + (tlen -i + 1);
                save = ptext;
                 for(m = 0 ; m < (strrlen - slen); m++)
                 {
                    while(ptext!= ptextbackup)
                    {
                        *ptext = *(ptext - 1);
                        ptext --;
                    }
                    tlen++;
                    save = save + 1;
                    ptext = save;
                }
                ptext = ptextbackup - slen;
                *ptext=' ';
                for( m = 0; m < strrlen; m++)
                   {
                       *ptext = strr[m];
                       ptext = ptext + 1;
                   }
                   ptext++;

        }
           }

       for (k = 0; k < alen; k++)
       {
           array[k] = '\0';
       }
   }
}
