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
   bool isEqual(TreeNode* root1,TreeNode* root2)
   {
      if(root1==NULL && root2==NULL) return true;
      else if(root1==NULL || root2==NULL) return false;
      else if(root1->val!=root2->val) return false;
      
      if(isEqual(root1->left,root2->right)==0)
      {
          return false;
      }
      if(isEqual(root1->right,root2->left)==0)
      {
          return false;
      }

      return true;
   }

public:
    bool isSymmetric(TreeNode* root) {
        return isEqual(root->left,root->right);
    }
};