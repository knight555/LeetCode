class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        ln = len(coins)
        d = [-1] * (amount + 1)  # !!!!
        d[0] = 0

        def min1(a, b):
            if a >= 0 and b >= 0:
                return min(a, b)
            if a == -2:
                return b
            if b == -2:
                return a

        def dp(value):
            if d[value] != -1:
                return d[value]
            d[value] = amount + 1
            for ik in range(ln):
                if value >= coins[ik]:
                    d[value] = min(d[value], dp(value - coins[ik]) + 1)
            return d[value]

        dp(amount)
        return d[-1] if d[-1]!=amount+1 else -1