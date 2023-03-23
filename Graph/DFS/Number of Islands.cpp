class Solution {
private:
    void dfs(int i,int j,vector<vector<char>> &grid,vector<vector<int>> &visited)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visited[i][j]==1 || grid[i][j]=='0') return;

        visited[i][j]=1;
        dfs(i+1,j,grid,visited);
        dfs(i-1,j,grid,visited);
        dfs(i,j+1,grid,visited);
        dfs(i,j-1,grid,visited);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
vector<vector<int>> visited(grid.size(),vector<int> (grid[0].size(),0));
       int ans=0;
      for(int i=0; i<grid.size(); i++)
      {
          for(int j=0; j<grid[0].size(); j++)
          {
              if(!visited[i][j] && grid[i][j]=='1')
              {
                  ans++;
                  dfs(i,j,grid,visited);
              }
          }
      }

      return ans;
    }
};