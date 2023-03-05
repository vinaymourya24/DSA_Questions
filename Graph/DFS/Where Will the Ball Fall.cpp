class Solution {
private:
    int throwBall(int i,int j,vector<vector<int>> &grid)
    {
       if(i<0 || j>=grid[0].size()) return -1;
       else if(i>=grid.size()) return j;
       else if(grid[i][j]==-1 && j==0) return -1;
       else if(grid[i][j]==1 && j==grid[0].size()-1) return -1;
       else if(grid[i][j]==-1 && grid[i][j-1]==1) return -1;
       else if(grid[i][j]==1 && grid[i][j+1]==-1) return -1;

       int path=-1;
       if(grid[i][j]==1)
       {
         path=throwBall(i+1,j+1,grid);
         if(path!=-1) return path;
       }
       else if(grid[i][j]==-1)
       {
          path=throwBall(i+1,j-1,grid);
          if(path!=-1) return path;
       }
       
       return -1;
    }

public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size(),0);

        for(int i=0; i<grid[0].size(); i++)
        {
           ans[i]=throwBall(0,i,grid);
        }

        return ans;
    }
};