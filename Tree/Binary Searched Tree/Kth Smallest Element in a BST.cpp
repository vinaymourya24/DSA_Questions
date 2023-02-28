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
public:
     int count=0,ans=0;
   void findAns(TreeNode* root,int k)
   {
       if(root==NULL) return;
       findAns(root->left,k);
       count++;
       if(count==k){
           ans=root->val;
           return;
       } 
       findAns(root->right,k);
   }

public:   
    int kthSmallest(TreeNode* root, int k) {
        findAns(root,k);
        return ans;
    }
};