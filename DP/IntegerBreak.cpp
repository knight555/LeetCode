https://leetcode-cn.com/problems/integer-break/
class Solution {
public:
    vector<int> product; //	product[i]表示数字i拆分后能形成的最大乘积
    int integerBreak(int n) {
        product.assign(59,0);
        product[1] = 0;
        product[2] = 1;
        for(int i=3;i<=n;i++){
            product[i] = i-1;
            for(int delta = 1;delta <= i / 2 ;delta++){
                product[i] = max(product[i],Regg(i-delta)*Regg(delta));
				//对于数字i有以下两种情况
				//1. i拆分成i和i-j，且i-j不再继续拆分，product[i] = j*(i-j)
				//2. i拆分成i和i-j，且i-j继续拆分,product[i] = j*product[i-j]
				//如果保证j从小到大拆分，可以写成下面这种
				//product[i] = max(product[i],max(j*(i-j),j*product[i-j]);
            }
        }
        return product[n];
    }
    int Regg(int c){
        return c>product[c]?c:product[c];
    }
};