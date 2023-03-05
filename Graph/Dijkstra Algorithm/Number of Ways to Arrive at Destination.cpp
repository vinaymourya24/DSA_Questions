class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long,long>> adj[n];
        for(auto it :roads)
        {
          adj[it[0]].push_back({it[1],it[2]});
          adj[it[1]].push_back({it[0],it[2]});
        }        
    priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>> pq;
        pq.push({0,0});
        vector<long long> dis(n,LONG_MAX),ways(n,0);
        ways[0]=1;
        dis[0]=0;
        long long MOD = (long long)1e9+7;
        while(!pq.empty())
        {
           long long d = pq.top().first;
           long long node = pq.top().second;
           pq.pop();
           for(auto v:adj[node])
           {
               long long takedis = v.second;
               long long toNode = v.first;
               if((d+takedis)<dis[toNode])
               {
                  dis[toNode]=(d+takedis);
                   ways[toNode]=ways[node];
                  pq.push({d+takedis,toNode});
               }
               else if((d+takedis)==dis[toNode])
               {
                  ways[toNode]=(ways[toNode]+ways[node])%MOD;
               }
           }
        }

        return (ways[n-1]%MOD);
    }
};