#include<vector>
#include<string>
#include<iostream>
#include<list>

using namespace std;

int main(void)
{
    list <string> v;
    v.push_back("The number is 10");
    v.push_back("The number is 20");
    v.push_back("The number is 30");

    list<string>::reverse_iterator ri;

    for (ri = v.rbegin(); ri != v.rend(); ri++)
    {
        cout << *ri << endl; 
    }
    
    list<string>::iterator it;
    for ( it = v.begin(); it !=v.end(); it++)
    {
       cout << *it << endl;
    }
    
    return 0;
}
