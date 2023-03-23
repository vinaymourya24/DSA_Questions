class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
         unordered_map<int,int> hash;

        for(int i=0; i<arr.size(); i++)
        {
            hash[arr[i]]++;
        }
        vector<int> hash1(1001,0);

        for(auto v:hash)
        {
            hash1[v.second]++;
        }
         
        for(int i=0; i<1001; i++)
        {
           if(hash1[i]>1) return false; 
        }
        return true;
    }
};