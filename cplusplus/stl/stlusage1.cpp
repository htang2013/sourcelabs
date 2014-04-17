#include<vector>
#include<iostream>
#include<string>


using namespace std;
vector<int> values;
vector<string> allstr;

int main(void)
{
    values.assign(7,100);
    values.clear();

    vector<int>::iterator it;
    for ( it = values.begin(); it != values.end(); it++)
        cout << *it << endl;


    string s1;
    s1  =  "Hello,World";
    allstr.assign(5,s1);
    vector<string>::iterator its;
    allstr.clear();
    for ( its = allstr.begin(); its != allstr.end(); its++)
        cout << *its << endl;

    
    
    
    return 1;
}
