https://leetcode.cn/problems/trapping-rain-water/submissions/

class Solution {
    // 维护一个递减的单调栈的解法
    public int trap(int[] height) {
        Stack<Integer> stk = new Stack<>();
        int rainSum = 0;
        for(int i=0;i<height.length;){
            while(!stk.empty() && height[stk.peek()] < height[i]){
                int cur = stk.pop();
                if(stk.empty()) {
                    break;
                }
                int left = stk.peek();
                int h = Math.min(height[i], height[left]) - height[cur];
                int S = (i - left -1)*h;
                rainSum += S;
            }
            stk.push(i++);
        }
        return rainSum;
    }
}