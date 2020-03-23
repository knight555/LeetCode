https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique/
给定整数数组 A，每次 move 操作将会选择任意 A[i]，并将其递增 1。
返回使 A 中的每个值都是唯一的最少操作次数。

示例 1:
输入：[1,2,2]
输出：1
解释：经过一次 move 操作，数组将变为 [1, 2, 3]

示例 2:
输入：[3,2,1,2,1,7]
输出：6
解释：经过 6 次 move 操作，数组将变为 [3, 4, 1, 2, 5, 7]。
可以看出 5 次或 5 次以下的 move 操作是不能让数组的每个值唯一的。

提示：
0 <= A.length <= 40000
0 <= A[i] < 40000

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int n = (int)A.size();
        if(n<=1)
            return 0;
        sort(A.begin(),A.end());
        int steps = 0;
        int taken = 0;
        for(int i=1;i<n;i++){
            if(A[i]==A[i-1]){
                steps -= A[i];
                taken++;
            }
            else{
                int amount = min(taken,A[i]-A[i-1]-1);
                steps += amount*(amount+1)/2+A[i-1]*amount;
                taken -= amount;
            }
        }
        steps += taken*(taken+1)/2+taken*A[n-1];
        return steps;
    }
};