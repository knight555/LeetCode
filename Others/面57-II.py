# https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/
# 题目描述：输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
# 序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
#
# 输入：target = 9
# 输出：[[2,3,4],[4,5]]
#
# 输入：target = 15
# 输出：[[1,2,3,4,5],[4,5,6],[7,8]]
class Solution(object):
    # Method1：发现规律，两种情况下可拆分成连续序列，
    # 一是整除奇数m，可分成m个序列；二是除以偶数n且小数部分是0.5
    # 时间复杂度O(n*(n**0.5))
    def findContinuousSequence(self, target):
        """
        :type target: int
        :rtype: List[List[int]]
        """
        if target <= 2:
            return []
        res = []
        for i in range(target / 2, 1, -1):
            mod = target % i
            divi = target // i
            if i % 2 == 1 and mod == 0 and (divi - i / 2) > 0:
                res.append([j for j in range(divi - i / 2, divi + i / 2 + 1)])
            if i % 2 == 0 and mod == (i / 2) and (divi - i / 2 + 1) > 0:
                res.append([j for j in range(divi - i / 2 + 1, divi + i / 2 + 1)])
        return res

    # Method2：滑动窗口
    def findContinuousSequence2(self, target):
        res = []
        left = 1
        right = 2
        while left < right:
            sums = 0.5 * (left + right) * (right - left + 1)
            if sums == target:
                res.append([j for j in range(left, right + 1)])
                left += 1
            elif sums > target:
                left += 1
            else:
                right += 1
        return res


Solution().findContinuousSequence2(15)