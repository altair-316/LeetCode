#include<bits/stdc++.h>
using namespace std;


class Solution {

private:
    int ansL=INT_MAX;

private:
    bool compS(string s1, string  s2){
        if(s1.size()!=s2.size())
            return(0);
        int z=0;
        for(int i=0;i<s1.size() && z<3;i++)
            if(s1[i]!=s2[i])
                z+=1;
        if(z==1)
            return(1);
        return(0);

    }

private:
    void findE(string sWord,string eWord,map<string,vector<string>> &sTree,int &len, set<string> &visited){
        if(sWord==eWord){
            ansL=min(ansL,len);
            return;
        }
        visited.insert(sWord);
        for(auto i:sTree[sWord] ){
            if(visited.find(i)==visited.end()){
                len+=1;
                findE(i,eWord,sTree,len, visited);
                len-=1;
                visited.erase(i);
            }
        }
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        //int len=INT_MAX;
        int len=0;
        set<string> visited;
        map<string,vector<string>> sTree;
        vector<string> temp;
        if(beginWord!=wordList[0])
            sTree.insert(pair<string,vector<string>>(beginWord,temp));

        for(auto i:wordList){
            sTree.insert(pair<string,vector<string>>(i,temp));
        }

        for(auto j:sTree){
            for(auto i:wordList){
                if( compS(j.first,i) )
                    sTree[j.first].push_back(i);
            }
        }

        findE(beginWord,endWord,sTree,len, visited);

/*
        for(auto j:sTree){
            cout<<"\n"<<j.first<<"-->";
            for(auto k:j.second){
                cout<<k<<",";
            }
        }
*/
        if(ansL==INT_MAX)
            return(0);
        return(ansL+1);
    }
};



int main(){

    Solution x;
    
    string beginWord, endWord;
    vector<string> wordList;
    // wordList = [,"dot","dog","lot","log","cog"]
    string temp="";

    cin>>beginWord>>endWord>>temp;

    while(temp!=""){
    //while(temp!="====="){
        wordList.push_back(temp);
        temp="";
        cin>>temp;
    }
    
    int ans=x.ladderLength(beginWord,endWord,wordList);
    cout<<"\n\n"<<ans;


    return(0);
}