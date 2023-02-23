class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
         vector<pair<int,int>> mini_capital;
         for(int i=0; i<capital.size(); i++)
         {
             mini_capital.push_back({capital[i],profits[i]});
         }

         sort(mini_capital.begin(),mini_capital.end());
         priority_queue<int> max_profit;
        //  for(auto v:mini_capital)
        //  {
        //      cout<<v.first<<" "<<v.second<<endl;
        //  }
        int index=0;
        while(k--)
        {
          while(index<capital.size() && mini_capital[index].first<=w)
          {
              max_profit.push(mini_capital[index].second);
              index++;
          }
          if(max_profit.empty()) break;
          w+=max_profit.top();
          max_profit.pop();
        }
        return w;
    }
};