#include <bits/stdc++.h>
using namespace std;

/*
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/  

class Solution
{

private:
    int ans=0;
public:
    //void bfs(vector<vector<char>> &grid,set<pair<int,int>> &visited,int i,int j)
    void bfs(vector<vector<char>> &grid,vector<vector<bool>>  &vA,int i,int j)
    {
        pair<int,int> temp=pair<int,int>(i,j);
        //if(i>=0  &&  j>=0  && i<grid.size()  &&  j<grid[0].size() && grid[i][j]=='1'  && visited.find(temp)==visited.end() )
        if(i>=0  &&  j>=0  && i<grid.size()  &&  j<grid[0].size() && grid[i][j]=='1'  && vA[i][j]==0 )
        {
            //visited.insert(temp);
            //bfs(grid,visited,i,j+1);
            //bfs(grid,visited,i+1,j);
            //bfs(grid,visited,i,j-1);
            //bfs(grid,visited,i-1,j);
            vA[i][j]=1;
            bfs(grid,vA,i,j+1);
            bfs(grid,vA,i+1,j);
            bfs(grid,vA,i,j-1);
            bfs(grid,vA,i-1,j);
        }    
        else
            return;

    }


public:
    int numIslands(vector<vector<char>> &grid)
    {
        int i = 0, j = 0;
        //set<pair<int,int>> visited;
        vector<vector<bool>>  vA;
        vector<bool> temp;

        for (j = 0; j < grid[0].size(); j++)
            temp.push_back(0);
        for (i = 0; i < grid.size(); i++)
            vA.push_back(temp);

            


        for (i = 0; i < grid.size(); i++)
        {
            for (j = 0; j < grid[i].size(); j++)
            {
                pair<int,int> temp=pair<int,int>(i,j);
                //if(grid[i][j]=='1'  &&  visited.find(temp)==visited.end())
                if(grid[i][j]=='1'  &&  vA[i][j]==0  )
                {
                    cout<<"\n"<<i<<","<<j;
                    //bfs(grid,visited,i,j);
                    bfs(grid,vA,i,j);
                    ans+=1;
                }
            }
        }

    return(ans);
    }
    
};

int main()
{   
    vector<vector<char>> grid;
    vector<char> gridi(5);

    gridi[0]='1';
    gridi[1]='1';
    gridi[2]='0';
    gridi[3]='0';
    gridi[4]='0'; 
    grid.push_back(gridi);

    gridi[0]='1';
    gridi[1]='1';
    gridi[2]='0';
    gridi[3]='0';
    gridi[4]='0'; 
    grid.push_back(gridi);

    gridi[0]='0';
    gridi[1]='0';
    gridi[2]='1';
    gridi[3]='0';
    gridi[4]='0'; 
    grid.push_back(gridi);

    gridi[0]='0';
    gridi[1]='0';
    gridi[2]='0';
    gridi[3]='1';
    gridi[4]='1'; 
    grid.push_back(gridi);

    Solution x;
    int a=x.numIslands(grid);

    cout<<"\n\n"<<a;

    return (0);
}