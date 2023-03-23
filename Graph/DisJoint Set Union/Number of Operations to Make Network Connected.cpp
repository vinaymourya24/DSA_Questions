class DisJointSet{
   public:
    vector<int> rank,size,parent;
    DisJointSet(int n)
    {
       rank.resize(n+1,0);
       size.resize(n+1,0);
       parent.resize(n+1,0);
       for(int i=0; i<=n; i++)
       {
           parent[i]=i;
           size[i]=1;
       }
    }

    int findParent(int node)
    {
       if(node==parent[node]) return node;
       else
       {
           return parent[node] = findParent(parent[node]);
       }
    }

    void mergeByRank(int u,int v)
    {
       int ult_u = findParent(u);
       int ult_v = findParent(v);
       if(ult_u==ult_v) return;
       else if(rank[ult_u]<rank[ult_v])
       {
           parent[ult_u]=ult_v;
       }
       else if(rank[ult_v]<rank[ult_u])
       {
           parent[ult_v]=ult_u;
       }
       else
       {
           parent[ult_v]=ult_u;
           rank[ult_u]++;
       }
    }

    void mergeBySize(int u,int v)
    {
       int ult_u = findParent(u);
       int ult_v = findParent(v);
       if(ult_u==ult_v) return;
       else if(rank[ult_u]<rank[ult_v])
       {
           parent[ult_u]=ult_v;
           size[ult_v]+=size[ult_u];
       }
       else 
       {
           parent[ult_v]=ult_u;
           size[ult_u]+=size[ult_v];
       }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisJointSet ds(n);
        int extra=0;
        for(int i=0; i<connections.size(); i++)
        {   
            if(ds.findParent(connections[i][0])==ds.findParent(connections[i][1])) extra++;
            else
            {
                ds.mergeBySize(connections[i][0],connections[i][1]);
            }
        }

        int requiredCables=0;

        for(int i=0; i<n; i++)
        {
            if(ds.parent[i]==i) requiredCables++;
        }

        if(extra>=(requiredCables-1)) return requiredCables-1;
        return -1;
    }
};