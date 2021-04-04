#include<bits/stdc++.h>
using namespace std;

class Solution{

    public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans1;
        map<int,int> freqs;
        multimap<int,int,greater<int>> freqs1;
        for(int i=0;i<nums.size();i++){
            if(freqs.find(nums[i])==freqs.end())
                freqs[nums[i]]=1;
            else
                freqs[nums[i]]=freqs[nums[i]]+1;
        }

        for(auto i:freqs){
            cout<<i.first<<","<<i.second<<"\t";
            freqs1.insert( pair<int,int>(i.second,i.first)      );
        }

        cout<<"\n\n";
        for(auto i:freqs1){
            cout<<i.first<<","<<i.second<<"\t";
        }

        int p=0;
        for(auto i=freqs1.begin(); p<k ;i++){
            ans1.push_back(   i->second   );
            ++p;
        }
        
        for(auto i:ans1)
            cout<<i<<"\t";
        return(ans1);
    }
};


int main(){

    vector<int> nums,ans;
    nums.push_back(1);
//    nums.push_back(1);
//    nums.push_back(1);
//    nums.push_back(1);
//    nums.push_back(1);
    nums.push_back(2);
//    nums.push_back(2);
//    nums.push_back(2);
//    nums.push_back(3);
//    nums.push_back(3);
    
    
    int k=2;

    Solution kFreq;

    ans=kFreq.topKFrequent(nums,k);


    return(0);
}