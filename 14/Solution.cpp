#include<iostream>
#include<stdio.h>
#include<vector>
#include<bits/stdc++.h>

using namespace std;


struct tNode{
    map<char,tNode *> node;
    bool isEnd;
};

tNode *newNode(){
    tNode *n = new tNode;
    n->isEnd=false;
    return(n);
}

bool comp(string &s1,string &s2){
    return(s1.size()<=s2.size());
}

class trie{

public:
    tNode *head,*temp,*temp1;

public:
    trie(){
        head=NULL;
    }

public:
    void addSToTrie(string s){
        temp=head;
        for(auto i:s){
            temp=head;
            addToTrie(i);
        }
    }

public:
    void addToTrie(char c){
        if(head==NULL){
            head=newNode();
            head->node[c]=newNode();
            return;
        }
        else {


        }


        }

    }


};

class Solution{


public:
    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin(),strs.end(),comp);
        trie t;
        
        for(vector<string>::iterator it=strs.begin();it!=strs.end();it++){
            t.addSToTrie(*it);
        }

        return("HELLO!!");

        
    }

};

int main(){

    Solution LCS;
    
    vector<string> strs;
    strs.push_back("abcdefg");
    strs.push_back("abcdef");
    strs.push_back("abcde");
    strs.push_back("abcd");
    strs.push_back("abc");
    strs.push_back("ab");

    LCS.longestCommonPrefix(strs);

    return(0);
}