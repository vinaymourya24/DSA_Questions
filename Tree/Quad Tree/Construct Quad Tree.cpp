/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* solve(vector<vector<int>> &grid,int rowStart,int rowEnd,int colStart,int colEnd)
    {
        if(rowStart>rowEnd || colStart>colEnd) return NULL;
        bool isLeaf=true;
        int value=grid[rowStart][colStart];

        for(int i=rowStart; i<=rowEnd; i++)
        {
            for(int j=colStart; j<=colEnd; j++)
            {
                if(grid[i][j]!=value)
                {
                    isLeaf=false;
                    break;
                }
            }
            if(isLeaf==false) break;
        }

        if(isLeaf) return new Node(value,true);

        int rowMid = (rowStart + rowEnd)/2;
        int colMid = (colStart + colEnd)/2;

        Node* topleft = solve(grid,rowStart,rowMid,colStart,colMid);
        Node* topright = solve(grid,rowStart,rowMid,colMid+1,colEnd);
        Node* bottomleft = solve(grid,rowMid+1,rowEnd,colStart,colMid);
        Node* bottomright = solve(grid,rowMid+1,rowEnd,colMid+1,colEnd);

        return new Node(false,false,topleft,topright,bottomleft,bottomright);
    }
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid,0,grid.size()-1,0,grid.size()-1);
    }
};