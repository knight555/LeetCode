class Solution(object):
    # 求有向无环图的最短路径方法，超出时间限制了，但方法值得学习
    def maxEnvelopes(self, envelopes):
        """
        :type envelopes: List[List[int]]
        :rtype: int
        """
        ln = len(envelopes)
        Graph = [[0 for i in range(ln)] for j in range(ln)]
        d = [0] * ln

        def isValid(e1, e2):
            if e1[0] < e2[0] and e1[1] < e2[1]:
                return True
            return False

        def initG(G, envel):
            for i in range(ln):
                for j in range(ln):
                    if isValid(envel[i], envel[j]):
                        G[i][j] = 1

        def dp(G, d, index):
            if d[index] > 0:
                return d[index]
            d[index] = 1
            for j in range(ln):
                if G[index][j] == 1:
                    d[index] = max(d[index], dp(G, d, j) + 1)
            return d[index]

        initG(Graph, envelopes)
        for kk in range(len(Graph)):
            print(Graph[kk])
        ans = 0
        dp(Graph,d,0)
        return ans


e = [[5, 4], [6, 4], [6, 7], [2, 3]]
print(Solution().maxEnvelopes(e))
