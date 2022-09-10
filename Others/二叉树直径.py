class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        global max_path
        max_path = 0

        def dfs(root):
            global max_path
            if root == None:
                return 0
            l = dfs(root.left)
            r = dfs(root.right)
            max_path = max(max_path, l + r + 1)
            return max(l, r) + 1

        dfs(root)
        return max_path - 1

# tree = [TreeNode(0), TreeNode(1), TreeNode(2), TreeNode(3), TreeNode(4), TreeNode(5)]
# tree[1].left = tree[2]
# tree[1].right = tree[3]
# tree[2].left = tree[4]
# tree[2].right = tree[5]
# print('result ' + str(Solution().diameterOfBinaryTree(tree[1])))
