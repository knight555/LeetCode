/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode trimBST(TreeNode root, int low, int high) {
        return dfs(root, low, high);
    }

    public TreeNode dfs(TreeNode root, int low, int high){
        if(root == null){
            return null;
        }
        TreeNode new_root = new TreeNode(root.val);
        TreeNode left = null;
        TreeNode right = null;
        if(root.val <= high && root.val >= low){
            new_root.left = dfs(root.left, low, high);
            new_root.right = dfs(root.right, low, high);
            return new_root;
        }
        else if(root.val > high){
            return dfs(root.left, low, high);
        }
        else{
            return dfs(root.right, low, high);
        }
    }

}