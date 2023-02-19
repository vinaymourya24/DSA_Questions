class Solution {
private:
     int parent = -1;
private:
    void solve(TreeNode* root,int &ans)
    {
       if(root==NULL) return;
       solve(root->left,ans);
       if(parent!=-1)
       {
           ans = min(ans,abs(parent - root->val));
       }
       parent = root->val;
       
       solve(root->right,ans);
    }

public:
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        solve(root,ans);
        return ans;
    }
};