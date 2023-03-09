class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n,vector<int> (n,INT_MAX));
        for(auto it:edges)
        {
            distance[it[0]][it[1]]=it[2];
            distance[it[1]][it[0]]=it[2];   
        }
       for(int i=0; i<n; i++) distance[i][i]=0;
        for(int via=0; via<n; via++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                   if(distance[i][via]==INT_MAX || distance[via][j]==INT_MAX) continue;
                  distance[i][j]=min(distance[i][j],distance[i][via]+distance[via][j]);
                }
            }
        }

        int countOfCity=n,cityNumber=-1;

        for(int i=0; i<n; i++)
        {
            int count=0;
            for(int j=0; j<n; j++)
            {
               if(distance[i][j]<=distanceThreshold) count++;
            }
            if(count<=countOfCity){
                countOfCity=count;
                cityNumber=i;
            }
        }
        return cityNumber;
    }
};