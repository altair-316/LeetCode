#include<bits/stdc++.h>
using namespace std;

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(),intervals.end(),[](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];} );

        for(auto i:intervals){
            cout<<i[0]<<","<<i[1]<<"\t";
        }

        int st=intervals[0][0];
        int en=intervals[0][1];
        vector<int> temp(2);
        for(int i=1;i<intervals.size();i++){
            if(  intervals[i][0] <= en  )
            {
                if(intervals[i][1]>en)
                    en=intervals[i][1];
            }
            else
            {
                temp[0]=st;
                temp[1]=en;
                ans.push_back(temp);
                st=intervals[i][0];
                en=intervals[i][1];
            }
        }
        temp[0]=st;
        temp[1]=en;
        ans.push_back(temp);

        cout<<"\n-----------\n";
        for(auto i:ans){
            cout<<i[0]<<","<<i[1]<<"\t";
        }

        return(ans);
        
    }
};

int main(){

    Solution x;
    vector<vector<int>> intervals;
    vector<int> temp(2);
    temp[0]=1;
    temp[1]=4;
    intervals.push_back(temp);
    temp[0]=2;
    temp[1]=3;
    intervals.push_back(temp);
//    temp[0]=15;
//    temp[1]=18;
//    intervals.push_back(temp);
//    temp[0]=8;
//    temp[1]=10;
//    intervals.push_back(temp);
    /*
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
*/
    x.merge(intervals);



    return(0);
}