#include <iostream>
using namespace std;


void subSequence(string s,string ans){
if(s.length()==0){
 cout<<ans<<endl;
 return;
}
char ch = s[0];
string remainingString = s.substr(1);


subSequence(remainingString,ans);
subSequence(remainingString,ans + ch);
}



int main(){
subSequence("ABCDEFGHIJKL","");
cout<<endl;
}