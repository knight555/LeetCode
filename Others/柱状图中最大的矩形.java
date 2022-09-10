// https://leetcode.cn/problems/largest-rectangle-in-histogram/submissions/
// 单调栈

class Solution {
    public int largestRectangleArea(int[] heights) {
        int[] newHeights = new int[heights.length+2];
        System.arraycopy(heights, 0, newHeights, 1, heights.length);
        newHeights[0] = 0;
        newHeights[newHeights.length-1] = 0;
        Stack<Integer> stk = new Stack<>();
        int maxArea = 0;
        for(int pos=0;pos < newHeights.length;){
            while(!stk.empty() && newHeights[stk.peek()] > newHeights[pos]){
                int h = newHeights[stk.pop()];
                int left_idx = stk.peek();
                int S = h * (pos - left_idx - 1);
                maxArea = Math.max(S, maxArea);
            }
            stk.push(pos++);
        }
        return maxArea;
    }
}