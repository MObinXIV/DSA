
/*
 * @file NumberofIslands.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-09
 * 
 * @copyright Copyright (c) 2022
 * Lands whcih are connected only in case  of 4 directions
 */

#include<bits/stdc++.h>

using namespace std;
void dfs (vector<vector<char>> &matrix,int x,int y,int r,int c)
{
     if(x<0 || x>=r || y<0 || y>=c || matrix[x][y]!='1')  //Boundary case for matrix
            return;
        
        
        matrix[x][y] = '2';//Mark current cell as visited
        
        //Make recursive call in all 4 adjacent directions
        dfs(matrix,x+1,y,r,c);  //DOWN
        dfs(matrix,x,y+1,r,c);  //RIGHT
        dfs(matrix,x-1,y,r,c);  //TOP
        dfs(matrix,x,y-1,r,c);  //LEFT
}

int numIslands(vector<vector<char>>& grid)
{
    int rows = grid.size();
        if(rows==0)     //Empty grid boundary case
            return 0;
        int cols = grid[0].size();
        
        //Iterate for all cells of the array
        int no_of_islands = 0;

        //Itereate through matrix and assign dfs for all 1's and in case of 1 only (not visited we will go trhough it ) and incerease int count by 1
         for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(grid[i][j]=='1')//get the unvisted grids to count
                {
                    dfs(grid,i,j,rows,cols);
                    no_of_islands += 1;
                }
            }
        }
        return no_of_islands;
}