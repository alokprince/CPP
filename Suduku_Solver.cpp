#include<bits/stdc++.h>
using namespace std;

void helper(
    int r,
    int c, 
    map<pair<int,int>,map<int,int>> &mp,
    vector<vector<char>> &a,
    vector<map<int,int>> row,
    vector<map<int,int>> col){

        if(r == 9){
            for (auto it : a)
            {
                for(auto i : it){
                    cout<< i << " ";
                }
                cout<<endl;
            }
            cout<<endl;
            return;
        }

        if(c == 9){
            helper(r+1,0,mp,a,row,col);
            return;
        }

        if(a[r][c] != '0'){
            helper(r,c+1,mp,a,row,col);
            return;
        }

        for (int i = 1; i <= 9; i++)
        {
            int rw = r/3,cl = c/3;
            if(!mp[{rw,cl}][i] and !row[r][i] and !col[c][i] ){
                mp[{rw,cl}][i] = true;
                row[r][i] = true ;
                col[c][i] = true ;
                a[r][c] = i + '0';
                helper(r,c+1,mp,a,row,col);
                mp[{rw,cl}][i] = 0;
                row[r][i] = 0;
                col[c][i] = 0 ;
                a[r][c] = '0';

            }
            
        }
        

    }
void Suduko_Solver(vector<vector<char>> &a){
    map<pair<int,int>,map<int,int>> mp;
    vector<map<int,int>> row(9);
    vector<map<int,int>> col(9);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
           if(a[i][j] != '0'){
               mp[{i/3,j/3}][a[i][j]-'0'] = 1;
               row[i][a[i][j]-'0'] = 1;
               col[j][a[i][j]-'0'] = 1;
           }
        }
        
    }
    
    helper(0,0,mp,a,row,col);
}

int main(){
vector<vector<char>> a = {  {'3', '0', '6', '5', '0', '8', '4', '0', '0'}, 
                            {'5', '2', '0', '0', '0', '0', '0', '0', '0'}, 
                            {'0', '8', '7', '0', '0', '0', '0', '3', '1'}, 
                            {'0', '0', '3', '0', '1', '0', '0', '8', '0'}, 
                            {'9', '0', '0', '8', '6', '3', '0', '0', '5'}, 
                            {'0', '5', '0', '0', '9', '0', '6', '0', '0'}, 
                            {'1', '3', '0', '0', '0', '0', '2', '5', '0'}, 
                            {'0', '0', '0', '0', '0', '0', '0', '7', '4'}, 
                            {'0', '0', '5', '2', '0', '6', '3', '0', '0'}  };
    Suduko_Solver(a);

}