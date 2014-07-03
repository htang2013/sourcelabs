#include<iostream>

using namespace std;

bool isPalindrome(char *begin, char *end)
{
     while(begin < end)
     {
         if (*begin++ != *end--)
            
            return false;
     }
     
     return true;
}


int main(void)
{
    const char *Txt = "was it eliot's toilet u  saw?";
    char PurTxt[100];
    char *ptr = PurTxt;
    while(*Txt){
       if( (*Txt >'a' && *Txt <'z') || (*Txt > 'A' && *Txt <'Z'))
           *ptr ++= *Txt;
        Txt ++;
    }
    *ptr = '\0';
    cout << PurTxt << endl; 

    if( isPalindrome(PurTxt, ptr-1) == true)
    {
            cout << "Is palindrome" << endl;
            return 0;
    } else {
            cout << "no palindrome" << endl;
    }
    

    return 0; 
}
