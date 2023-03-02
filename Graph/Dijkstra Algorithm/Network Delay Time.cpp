class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> Time(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>> adj(n+1);

        for(int i=0; i<times.size(); i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        Time[k]=0;
        Time[0]=0;
        pq.push({0,k});

        while(!pq.empty())
        {
            pair<int,int> p = pq.top();
            pq.pop();
            int t = p.first;
            int node = p.second;

            for(auto it:adj[node])
            {
               int takeTime = t+it.second;
               if(takeTime<Time[it.first])
               {
                   Time[it.first]=takeTime;
                   pq.push({takeTime,it.first});
               }
            }
        }

        if(*max_element(Time.begin(),Time.end())==INT_MAX) return -1;
        return *max_element(Time.begin(),Time.end());
    }
};