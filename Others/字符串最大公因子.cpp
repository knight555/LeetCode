class Solution {
public:
    // to check if s1 is the substring of s2
    int isValid(string s1,string s2){
        int len1 = (int)s1.length(),len2 = (int)s2.length();
        if(len2 % len1)
            return 0;
        int lenx = len2 / len1;
        string temp = "";
        for(int i=0;i<lenx;i++)
            temp += s1;
        return temp == s2;
    }
//    int gcd(int a,int b){
//        if(a<b)
//            return gcd(b,a);
//        if(a%b==0)
//            return b;
//        else
//            return gcd(b,a%b);
//    }
    string gcdOfStrings(string str1, string str2) {
        int l1 = (int)str1.length(), l2 = (int)str2.length();
        string T = str1.substr(0,__gcd(l1,l2)); // __gcd为c++自带的求最大公约数的函数
        if(isValid(T,str1) && isValid(T,str2))
            return T;
        return "";
    }
};
