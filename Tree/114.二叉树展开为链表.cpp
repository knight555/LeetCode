//https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/submissions/
class Solution {
public:
    
    void flatten(TreeNode* root) {
        LeftBranchToRight(root);
    }

    //把一个结点的左子树插到右子树前面
    void LeftBranchToRight(TreeNode* root){
        if(root == nullptr){
            return;
        }
        if(root->left == nullptr){
            LeftBranchToRight(root->right);
        }
        else{
            // if(root->right == nullptr) //经检验，右子树为空的情况不需要单独讨论
            //查找左子树的最右边的结点，用于右子树的拼接
            TreeNode *record_right = root->right;   //保留原root->right
            TreeNode *f = root->left;
            while(f->right != nullptr){
                f = f->right;
            }
            f->right = root->right;
            root->right = root->left;
            root->left = nullptr;
            
            LeftBranchToRight(record_right);
            LeftBranchToRight(root->right); //root->right现在是原来的root->left
        }
    }
    
};