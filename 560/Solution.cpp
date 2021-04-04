#include<bits/stdc++.h>
using namespace std;

//   -1 -1 1         3 4 5 6 7 7 8

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i=0,j=0,s=0,t=0,op=0,l=0;
        for(i=0;i<nums.size();i++){
            for(j=0; j<nums.size();j++){
                t=i+j;
                if(t>nums.size()-1)
                    continue;
                l=j;
                while(l<=t){
                    s=s+nums[l];
                    ++l;
                }
                if(s==k)
                    op+=1;
                s=0;
            }
        }
        cout<<"\n\n"<<op<<"\n\n";
        return(op);
        
    }
};

int main(){

    Solution subSum;
    vector<int> nums;
    int n=0,t=0,k=0;

    cout<<"\nenter array size\n";
    cin>>n;
    cout<<"\nEnter array\n";
    for(int i=0;i<n;i++){
        cin>>t;
        nums.push_back(t);
    }
    cout<<"\nEnter sum";
    cin>>k;



    subSum.subarraySum(nums,k);



    return(0);
}