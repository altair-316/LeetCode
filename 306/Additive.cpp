#include<bits/stdc++.h>
using namespace std;

class Solution{

public:
    bool checkAdd(string s1, string s2,string s3){
        int sums=stoi(s1)+stoi(s2);
        int sums1=stoi(  s3.substr(0,(to_string(sums)).length())  );
        if(sums==sums1){
            if ( checkAdd(s2,to_string(sums1),s3.substr(  to_string(sums1).length()   ))   )
                return(1);
        }
        
            

        
        
        


        return(0);
    }

public:
    bool isAdditiveNumber(string num) {
        vector<int> nums;

        for(auto i:num)
            nums.push_back( i-'0' );

        if(nums.size()<3)
            return(0);

        string temp=num.substr(num.length());
        if(temp.empty())
            cout<<"hello";

        int s1=nums[0], s2=nums[1];

        checkAdd(num.substr(0,1),num.substr(1,1),num.substr(2));

        return(0);
        
    }

    
};


int main(){

    string number;

    cin>>number;

    Solution addNum;

    addNum.isAdditiveNumber(number);


    return(0);
}