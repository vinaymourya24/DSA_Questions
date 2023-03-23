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
    void chalBhaiKar(TreeNode* root,int &ans,int parent)
    {
      if(root==NULL) return;
      if(root->left==NULL && root->right==NULL) 
      {
         ans += parent*10+root->val;
         return;
      }
       
      chalBhaiKar(root->left,ans,parent*10+root->val);

      chalBhaiKar(root->right,ans,parent*10+root->val);
    }

public:
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return root->val;
        
        int ans=0;
       chalBhaiKar(root,ans,0);
       return ans;
    }
};