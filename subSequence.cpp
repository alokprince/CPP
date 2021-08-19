#include <bits/stdc++.h>
using namespace std;

void subSequence(string s, string ans,int k)
{
    vector<int> arr;
    if (s.length() == 0)
    {
        if(ans.size() >= k){
        cout << ans << endl;
        }
        return;
    }
    char ch = s[0];
    string remainingString = s.substr(1);

    subSequence(remainingString, ans + ch,k);
    subSequence(remainingString, ans,k);
}

int main()
{
    subSequence("ABCDE", "",0);
    cout << endl;
}