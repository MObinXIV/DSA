#include<bits/stdc++.h>
using namespace std;
/**
 * @brief
 * WE use Dfs to Traverse in all directions 
 * we follow up the base cases to break else we traverse 
 */
void dfs(vector<vector<int>>& image, int sr, int sc,int newColor,int rows,int cols,int source)
    {
        if(sr<0 || sr>=rows || sc<0 || sc>=cols)
            return;
        else if(image[sr][sc]!=source)
            return; // not equqlity case
        
        image[sr][sc] = newColor; //assign value
       
        //recurse for the 4 directions 
        dfs(image,sr-1,sc,newColor,rows,cols,source);   //TOP
        dfs(image,sr+1,sc,newColor,rows,cols,source);   //DOWN
        dfs(image,sr,sc-1,newColor,rows,cols,source);   //LEFT
        dfs(image,sr,sc+1,newColor,rows,cols,source);   //RIGHT
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if(newColor==image[sr][sc])
            return image;//here we can't change anything 
        int rows = image.size();
        int cols = image[0].size();
        int source = image[sr][sc]; 
        dfs(image,sr,sc,newColor,rows,cols,source);
        return image;
    }


    //BFS solution 

    int validCoord(int x, int y, int n, int m)
{
 
    if (x < 0 || y < 0) {
        return 0;
    }
    if (x >= n || y >= m) {
        return 0;
    }
    return 1;
}
 void bfs(int n, int m, int data[][8],int x, int y, int color)
 {
     // Visiting array
  int vis[101][101];
   
  // Initializing all as zero
  memset(vis, 0, sizeof(vis));
  // Creating queue for bfs
  queue<pair<int, int> > obj;
   
  // Pushing pair of {x, y}
  obj.push({ x, y });
   
  // Marking {x, y} as visited
  vis[x][y] = 1;
  while(!obj.empty())
  {
      int x = obj.front().first;
      int y= obj.front().second;

      //take the current source 
      int preColor=data[x][y];

      //assign the current position with new value 
      data[x][y]=color;

      //take it out 

      obj.pop();
      if (validCoord(x - 1, y, n, m)
        && vis[x - 1][y] == 0
        && data[x - 1][y] == preColor)
    {
      obj.push({ x - 1, y });
      vis[x - 1][y] = 1;
    }
     
    // For Right side Pixel or Cell
    if (validCoord(x, y + 1, n, m)
        && vis[x][y + 1] == 0
        && data[x][y + 1] == preColor)
    {
      obj.push({ x, y + 1 });
      vis[x][y + 1] = 1;
    }
     
    // For Left side Pixel or Cell
    if (validCoord(x, y - 1, n, m)
        && vis[x][y - 1] == 0
        && data[x][y - 1] == preColor)
    {
      obj.push({ x, y - 1 });
      vis[x][y - 1] = 1;
    }

  }

 }
