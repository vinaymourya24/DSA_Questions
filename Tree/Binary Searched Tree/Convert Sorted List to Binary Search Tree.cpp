/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* makeBalancedTree(int s,int e,vector<int> &arr)
    {
         if(s>e) return NULL;
         int mid = s + (e - s)/2;
         TreeNode* root = new TreeNode(arr[mid]);
         root->left=makeBalancedTree(s,mid-1,arr);
         root->right=makeBalancedTree(mid+1,e,arr);
         return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *temp=head;
        vector<int> arr;
        while(temp!=NULL)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }  

        return makeBalancedTree(0,arr.size()-1,arr); 
    }
};