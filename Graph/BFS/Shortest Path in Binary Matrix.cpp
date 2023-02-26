class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        vector<vector<bool>> visited(grid.size()+1,vector<bool> (grid[0].size()+1,0));
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
       
        vector<int> rmove(8);
        rmove={+1,+1,-1,-1,0,0,-1,+1};
        vector<int> cmove(8);
        cmove={0,+1,0,-1,+1,-1,+1,-1};
        while(!q.empty())
        {
           pair<pair<int,int>,int> temp = q.front();
           q.pop();
           int row = temp.first.first;
           int coloumn = temp.first.second;
           int distance = temp.second;
           if(row==grid.size()-1 && coloumn==grid[0].size()-1)
           {
               return distance;
           }

           for(int i=0; i<8; i++)
           {
               row+=rmove[i];
               coloumn+=cmove[i];
               if(row>=0 && row<grid.size() && coloumn>=0 && coloumn<grid[0].size() && visited[row][coloumn]==0 && grid[row][coloumn]==0)
               {
                   visited[row][coloumn]=1;
                   q.push({{row,coloumn},distance+1});
               }
               row-=rmove[i];
               coloumn-=cmove[i];
           }
        }

        return -1;
    }
};