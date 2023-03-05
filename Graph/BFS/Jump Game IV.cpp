class Solution {
public:
    int minJumps(vector<int>& arr) {
        vector<int> stepsArray(arr.size(),INT_MAX);
        stepsArray[0]=0;
        int steps=0;
        queue<int> q;
        q.push(0);
        unordered_map<int,vector<int>> mp;
        for(int i=0; i<arr.size(); i++)
        {
            mp[arr[i]].push_back(i);
        }
 
        while(!q.empty())
        {
            int size = q.size();
     
            while(size--)
            {
                int i = q.front();
                q.pop();

                if(i==arr.size()-1) return steps;

                if(i-1>=0 && stepsArray[i-1]>steps)
                {
                  stepsArray[i-1]=steps;
                  q.push(i-1);
                }

                if(i+1<arr.size() && stepsArray[i+1]>steps)
                {
                    stepsArray[i+1]=steps;
                    q.push(i+1);
                }
 
                vector<int> &nextjumps = mp[arr[i]];

                for(auto it:nextjumps)
                {
                  if(stepsArray[it]>steps)
                  {
                      stepsArray[it]=steps;
                      q.push(it);
                  }
                }  

                nextjumps.clear();
            }
            steps++;
        }

        return steps;
    }
};