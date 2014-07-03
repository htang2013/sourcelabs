#include<iostream>
#include<string.h>

using namespace std;

void reverse(char *begin, char *end)
{
     char temp;

     while(begin < end)
     {
         temp = *begin;
         *begin ++ = *end;
         *end -- = temp;
     }
}

void reverseWords( char *s)
{
      char *begin = s;
      char *end = s;
      while(*end) end ++;
      reverse(begin, end-1);

      end = s;
    
      while(*end)
      {
           if( *end == ' ')
           {
              reverse(begin, end-1);
              begin = end +1;
           }
           end ++;
      } 

      reverse(begin, end -1);
}



const char *Txt = "Hello World I love you ";

char Buffer[100];

int main(void)
{
     strcpy(Buffer,Txt);
     reverseWords(Buffer);
     cout << Buffer << endl;
     return 0;
}
