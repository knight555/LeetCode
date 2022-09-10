# https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/
# 请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的时间复杂度都是O(1)。
# 若队列为空，pop_front 和 max_value 需要返回 -1
#
# 示例 1：
# 输入:
# ["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
# [[],[1],[2],[],[],[]]
# 输出: [null,null,null,2,1,2]
# 示例 2：
# 输入:
# ["MaxQueue","pop_front","max_value"]
# [[],[],[]]
# 输出: [null,-1,-1]

class MaxQueue(object):
    # 与求栈的最大（小）值不同，这个需要双端队列维护队列最大值
    def __init__(self):
        self.queue = []
        self.max_queue = []

    def max_value(self):
        """
        :rtype: int
        """
        if self.max_queue:
            return self.max_queue[0]
        else:
            return -1

    def push_back(self, value):
        """
        :type value: int
        :rtype: None
        """
        self.queue.append(value)
        if self.max_queue:
            while self.max_queue and self.max_queue[-1] < value:
                self.max_queue.pop()
        self.max_queue.append(value)

    def pop_front(self):
        """
        :rtype: int
        """
        if self.queue:
            if self.max_queue and self.max_queue[0] == self.queue[0]:
                self.max_queue.pop(0)
            return self.queue.pop(0)
        else:
            return -1

# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
