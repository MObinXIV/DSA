/*#include<bits/stdc++.h>

using namespace std;
void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0 ; i< n ; i++)
        {
            for (int j  = 0 ; j<m ; j++)
            {
                if(matrix [i][j]==0) 
                {
                    int ind = i-1;

                    while(ind>=0)//Set the top raw 
                    {
                        if(matrix[ind][j]!=0) // we check The !0 values to change them which not affect the remaining values 
                        matrix[ind][j]=-1;
                        ind --;
                    }
                    ind = i+1;
                    while (ind<n )
                    {
                        if(matrix[ind][j]!=0) // we check The !0 values to change them which not affect the remaining values 
                        matrix[ind][j]=-1;
                        ind ++;
                    }
                    ind = j - 1;
        while (ind >= 0) {
          if (matrix[i][ind] != 0) {
            matrix[i][ind] = -1;

          }
          ind--;
        }
        ind = j + 1;
        while (ind < m) {
          if (matrix[i][ind] != 0) {
            matrix[i][ind] = -1;

          }
          ind++;
        }
                }

            }
        }
        for (int i=0 ; i<n ; i++)
    for (int j = 0 ; j<m;j++) if (matrix[i][j]<=0)matrix[i][j]=0;
    }
    
int main()

{
 vector < vector < int >> arr;
  arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  setZeroes(arr);
  cout << "The Final Matrix is " << endl;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
}*/

/*#include<bits/stdc++.h>

using namespace std;
void setZeroes(vector < vector < int >> & matrix)
{
    int rows = matrix.size(), cols = matrix[0].size();
    vector<int> dummy1(rows,-1) , dummy2(cols,-1);
    for (int i = 0; i<rows;i++)
    {
        for (int j=0;j<cols;j++)
        {
            if (matrix[i][j]==0)
            {
                dummy1[i]=0;
                dummy2[j]=0;
            }
        }
    }
    for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (dummy1[i] == 0 || dummy2[j]==0) {
        matrix[i][j] = 0;
      }
    }
  }
}
int main()

{
    vector < vector < int >> arr;
  arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  setZeroes(arr);
  cout<<"The Final Matrix is "<<endl;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
    
}*/


#include<bits/stdc++.h>

using namespace std;
 void setZeroes(vector < vector < int >> & matrix)
 {
     //The tricky here when we use the first row and 1st colmun as our 2d guy we don't take the 1st col guy till we get back to not affect it's neighbors in 1st row when we back 

     int col0=1;// we intially set 1st col as true;
     int rows = matrix.size(), cols = matrix[0].size();
     for (int i =0 ; i < rows ; i++)
     {
         if (matrix[i][0]==0) col0=0;//We do it to not set the 0's col to not affect the backing steps 
         for(int j =1 ; j < cols;j++)
         {
             if (matrix[i][j]==0)
             {
                 matrix [i][0]=0;
                 matrix [0][j]=0;
             }
         }
        
     }
     for (int i= rows-1; i>=0;i--)
     {
         for (int j = cols-1 ; j>=1;j--)
         {
             if (matrix[i][0]==0 || matrix [0][j]==0) matrix[i][j]=0;
         }
         if(col0==0)matrix[i][0]=0;

     }

 }
 int main()
 {
 vector < vector < int >> arr;
  arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  setZeroes(arr);
  cout<<"The Final Matrix is "<<endl;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
 }