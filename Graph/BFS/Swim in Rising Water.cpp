class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
     priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
     greater<pair<int,pair<int,int>>>> pq;
     pq.push({grid[0][0],{0,0}});
     vector<vector<int>> visited(grid.size(),vector<int> (grid[0].size(),1e9));
     visited[0][0]=1;
     
     while(!pq.empty())
     {
         int element = pq.top().first;
         int i = pq.top().second.first;
         int j = pq.top().second.second;
         pq.pop();
         if(i==grid.size()-1 && j==grid[0].size()-1) return max(element,grid[i][j]);

         if(i-1>=0 && visited[i-1][j]!=1)
         {
             visited[i-1][j]=1;
             pq.push({max(element,grid[i-1][j]),{i-1,j}});
         }
         if(i+1<grid.size() && visited[i+1][j]!=1)
         {
             visited[i+1][j]=1;
             pq.push({max(element,grid[i+1][j]),{i+1,j}});
         }
         if(j-1>=0 && visited[i][j-1]!=1)
         {
             visited[i][j-1]=1;
             pq.push({max(element,grid[i][j-1]),{i,j-1}});
         }
         if(j+1<grid[0].size() && visited[i][j+1]!=1)
         {
             visited[i][j+1]=1;
             pq.push({max(element,grid[i][j+1]),{i,j+1}});
         }
     }

     return -1;
   }
};