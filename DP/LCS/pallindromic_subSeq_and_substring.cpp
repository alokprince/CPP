#include<bits/stdc++.h>
using namespace std;

string print_pallindrome_seq(string x,string y,int n,int m){
    int t[n+1][m+1];
    for(int i = 0 ; i < n+1 ; i++){
        for(int j = 0 ; j < m+1; j++){
            if(i == 0 || j == 0)
            t[i][j] = 0;
        }
    }

    for(int i = 1; i < n +1 ; i++){
        for(int j = 1 ; j < m + 1 ; j++){
            if(x[i-1] == y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i][j-1],t[i-1][j]);
            }
        }
    }

    int i = n+1, j = m+1;
    string ans;
    while(i > 0 , j > 0){
        if(x[i - 1] == y[j-1]){
            ans.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i][j-1] > t[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    ans.pop_back();
    return ans;
}
int print_pallindrome_subString(string x,string y,int n,int m){
    int t[n+1][m+1];
    for(int i = 0 ; i < n+1 ; i++){
        for(int j = 0 ; j < m+1; j++){
            if(i == 0 || j == 0)
            t[i][j] = 0;
        }
    }
    int result = 0;
    for(int i = 1; i < n +1 ; i++){
        for(int j = 1 ; j < m + 1 ; j++){
            if(x[i-1] == y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
                result = max(result,t[i][j]);
            }
            else{
                t[i][j] = 0;
            }
        }
    }

    // int i = n+1, j = m+1;
    // string ans;
    // while(i > 0 , j > 0){
    //     if(x[i - 1] == y[j-1]){
    //         ans.push_back(x[i-1]);
    //         i--;
    //         j--;
    //     }
    //     else{
    //         if(t[i][j-1] > t[i-1][j]){
    //             j--;
    //         }
    //         else{
    //             i--;
    //         }
    //     }
    // }
    // reverse(ans.begin(),ans.end());
    // ans.pop_back();
    return result;
}
int main(){
    string x = "agbcba";
    string y = x;
    reverse(y.begin(),y.end());
    int n = x.size();
    int m = y.size();
    cout<<"pallindromic sequence is ->  "<<print_pallindrome_seq(x,y,n,m)<<endl;
    cout<<"size of pallindrome ->  "<<print_pallindrome_seq(x,y,n,m).size()<<endl;
     cout<<"pallindromic sub string is ->  "<<print_pallindrome_subString(x,y,n,m)<<endl;
    //cout<<"size of sub string pallindrome ->  "<<print_pallindrome_subString(x,y,n,m).size()<<endl;
}