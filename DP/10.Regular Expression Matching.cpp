class Solution {
public:
	//https://leetcode-cn.com/problems/regular-expression-matching/solution/zheng-ze-biao-da-shi-pi-pei-by-leetcode-solution/
	//官方题解的状态转移方程，在出现*时即使s中与p中*前的字符相同（或匹配）也有可能最终并不是对应的
	//如s = "a", p = "aa*" 当i=1,j=3时，是f[i][j-2]起作用
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> f(m+1,vector<bool>(n+1,0));
        f[0][0] = 1;
        for(int i=0;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i == 0){
                    if(p[j-1] == '*')
                        f[i][j] = f[i][j-2];
                }
                else if(charMatch(s[i-1],p[j-1])){
                    f[i][j] = f[i-1][j-1];
                }
                else if(p[j-1] == '*'){
                    if(!charMatch(s[i-1],p[j-2]))
                        f[i][j] = f[i][j-2];
                    else{
                        f[i][j] = (f[i-1][j] + f[i][j-2]);
                    }
                }
            }
        }
        return f[m][n];
    }

    bool charMatch(char s_ch,char p_ch){
        if(p_ch =='.' || s_ch == p_ch)
            return 1;
        return 0;
    }
};