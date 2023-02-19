class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        int i=0;
        while(!q.empty())
        {
            vector<int> row;
            int size = q.size();

            while(size--)
            {
               TreeNode* temp = q.front();
               if(temp==NULL){
                 q.pop();
                 continue;
               }
               row.push_back(temp->val);
               if(temp->left!=NULL)
               {
                   q.push(temp->left);
               }
               if(temp->right!=NULL)
               {
                   q.push(temp->right);
               }
               q.pop();
            }
            
            if(i&1)
            {
                reverse(row.begin(),row.end());
            }
            
            if(row.empty()==0)
            ans.push_back(row);
            i++;
        }

        return ans;
    }
};