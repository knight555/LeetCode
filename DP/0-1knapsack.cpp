#include <iostream>
#include <vector>
using namespace std;

//使用二维数组保存
int knapsack(int N, int W, const vector<int> &values, const vector<int> &weights){
	int k, c; // k for item, c for capacity
	vector<vector<int>> dp(N+1, vector<int>(W+1,0));
	for(k=1;k<=N;k++)
		for(c=1;c<=W;c++){
			if(weights[k] > c){
				dp[k][c] = dp[k-1][c];	//第k个物品的重量大于现在背包的剩余容量，不能拿
			}
			else {	//第k个物品的重量小于现在背包的剩余容量，对于第k个物品：
				int v1 = dp[k-1][c];	//不拿，还是只看前k-1个物品
				int v2 = dp[k-1][c-weights[k]] + values[k];	//拿
				dp[k][c] = v1>v2?v1:v2;
			}
		}
	return dp[N][W];
}

//优化后使用一维的滚动数组
int knapsack_optimized(int N, int W, const vector<int> &values, const vector<int> &weights){
	int k, c; // k for item, c for capacity
	vector<int> dp(W+1, 0);
	for(k=1;k<=N;k++){
		for(c=W;c>=weights[k];c--){
				int v1 = dp[c];
				int v2 = dp[c-weights[k]] + values[k];
				dp[c] = v1>v2?v1:v2;
			}
		}
	return dp[W];
}



int main(){
	int N,W; // N for numbers of items, W for weight limit
	cin >> W >> N;
	vector<int> values(N+1,0);
	vector<int> weights(N+1,0);
	for(int j=1;j<=N;j++){
		cin >> weights[j];
		cin >> values[j];
	}
	int ans = knapsack_optimized(N, W ,values, weights);
	cout << ans << endl;
	return 0;
}