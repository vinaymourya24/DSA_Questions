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
     TreeNode* chalBhaiKar(vector<int> &inorder,int il,int ir,vector<int> &postorder,int pl,int pr,map<int,int> &mp)
     {
        if(il>ir || pl>pr) return NULL;

        TreeNode* root = new TreeNode(postorder[pr]);
         
        int inRoot = mp[postorder[pr]];
        int numLeft = inRoot - il;

    root->left = chalBhaiKar(inorder,il,inRoot-1,postorder,pl,pl+numLeft-1,mp);

    root->right = chalBhaiKar(inorder,inRoot+1,ir,postorder,pl+numLeft,pr-1,mp);

        return root;
     }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return NULL;
        map<int,int> mp;

        for(int i=0; i<inorder.size(); i++)
        {
            mp[inorder[i]]=i;
        }

 return chalBhaiKar(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
    }
};