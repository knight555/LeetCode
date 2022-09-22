//https://www.nowcoder.com/questionTerminal/f97e99347cc24f6c8a7136766cfdc9bb
import java.util.*;


public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int d = sc.nextInt();
        int a1 = getNums(n,k);
        int a2 = getNums(n,d-1);
        System.out.println((a1-a2 + MOD)%MOD);
    }

    public static final int MOD = 998244353;

	//总和为n, 物品为【1，y】的完全背包总数，PS: MOD是为了满足题目要求
	//每一个数字都可以由它前面的数字加一个数得到，所以前面的dp数组都加都加
    public static int getNums(int n, int y){
        int[] dp = new int[n+1];
        dp[0] = 1;
        for(int i = 1;i <= n;i++){
            for(int j = 1 ;j <= Math.min(i,y);j++){
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
        return dp[n];
    }
    
}