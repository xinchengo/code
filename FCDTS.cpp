// Fear cuts deeper than swords.

#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> wordlist = {"Fear", "cuts", "deeper", "than", "swords."};
int main()
{
    for(auto &cur : wordlist)
    {
        cout << cur;
        cout << ' ';
    }
    cout << endl;
    return 0;
}