#include<bits/stdc++.h>

using namespace std;
bool isValid (int i , int j , int n , int m , vector<vector<int>>&grid,vector<vector<int>>&vis)
{
    if (vis[i][j]||grid[i][j])//in case we have already visited or has the vallue one we have here a false case 
    return false ;
    return true;

}

bool dfs (int i , int j , int n,int m  , vector<vector<int>>&grid,vector<vector<int>>&vis)
{
    if(!isValid(i,j,n,m,grid,vis))return true;//We are good till we move forward zeros or meet one
    if(i==0 || i==n-1 || j == m-1 || j ==0)return false;//not good if we get here we out of rounding with any ones

    //visit 
    vis[i][j]=1;
    bool up= dfs(i-1,j,n,m,grid,vis);
    bool down = dfs(i+1,j,n,m,grid,vis);
    bool right = dfs(i,j+1,n,m,grid,vis);
    bool left = dfs(i,j-1,n,m,grid,vis);

    return up&left&right&down;//In case of any one not occured we get false at the end
    
    
}

int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int  m  =grid[0].size();
        int c =0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0 ;i<n;i++)
        {
            for(int j = 0 ; j<m;j++)
            {
                if(!vis[i][j]&& grid[i][j]==0)
                if(dfs(i,j,n,m,grid,vis))c++;
            }
        }
        return c;
    }