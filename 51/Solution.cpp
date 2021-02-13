#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
        int cq=0;
        vector<vector<string>> finalA;
        vector<string> ans;
        
        add_row(ans,0,n,cq,finalA);
        
        return(finalA);
        
    }
    
public:
    void add_row(vector<string> &ans,int r,int n,int cq,vector<vector<string>> &finalA){
        
        if(cq==n){
            finalA.push_back(ans);
            return;
        }
        
        string row;
        for(int i=0;i<n;i++)
            row.push_back('.');
        
        for(int i=0;i<n;i++){
            row[i]='Q';
            if(validR(row,r,i,ans,n)){
                ans.push_back(row);
                ++cq;
                add_row(ans,r+1,n,cq,finalA);
                ans.pop_back();
                --cq;
            }
            row[i]='.';            
        }
        
        
    }
    
    
public:
    bool validR(string cRow,int cr,int cc,vector<string> &ans,int n){
        if(cr==0)
            return(1);
        
        int rnum=cr,cnum=cc;
        
        rnum=cr-1;
        while(rnum>=0){
            if(ans[rnum][cnum]=='Q')
                return(0);
            --rnum;
        }
        
        rnum=cr-1;
        cnum=cc+1;
        while(rnum>=0 and cnum<=n){
            if(ans[rnum][cnum]=='Q')
                return(0);
            --rnum;
            ++cnum;
        }
        
        rnum=cr-1;
        cnum=cc-1;
        while(rnum>=0 and cnum>=0){
            if(ans[rnum][cnum]=='Q')
                return(0);
            --rnum;
            --cnum;
        }
        
        return(1);
        
    }
};

int main(){
    Solution Nqueens;
    vector<vector<string>> nQueens_ans;
    nQueens_ans=Nqueens.solveNQueens(4);

    for(auto i:nQueens_ans){
        for(auto j:i)
            cout<<j<<"\t";
        cout<<endl;        
    }
    return(0);
}