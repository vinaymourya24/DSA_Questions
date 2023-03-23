/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* ChalBhaiBST(int low, int high, vector<int> &nums)
     {    
          if(low > high)
             return NULL;
          int mid = (low+high)/2;
          TreeNode* root = new TreeNode(nums[mid]);

          root->left = ChalBhaiBST(low, mid-1, nums);
          root->right = ChalBhaiBST(mid+1, high,  nums);
        
        return root;
     }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int low=0,high=nums.size()-1;

        return ChalBhaiBST(low, high, nums);
    }
};