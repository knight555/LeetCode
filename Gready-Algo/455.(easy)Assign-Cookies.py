# https://leetcode-cn.com/problems/assign-cookies/
class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        gs = sorted(list(g));
        gln = len(g)
        ss = sorted(list(s));
        sln = len(s)
        if gln == 0 or sln == 0:
            return 0
        g_index = s_index = 0
        cnt = 0
        while 0 <= g_index < gln and 0 <= s_index < sln:
            if ss[s_index] >= gs[g_index]:
                cnt += 1
                s_index += 1
                g_index += 1
            else:
                s_index += 1
        return cnt


t1, t2 = [1, 2], [1, 2, 3]
print(Solution().findContentChildren(t1, t2))
