#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    void test(){
        string s = "aaa";
        string p = "a*a";
        bool re = isMatch(s,p);
        printf("%d",re);
    }
    
    bool isMatch(string s, string p) {
        int len1 = s.size();
        int len2 = p.size();

        bool dp[len1+1][len2+1];
        memset(dp,0,(len1+1)*(len2+1));
        dp[0][0] = true;
        
        for (int i = 0; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] |= dp[i][j - 2];
                    if ( i != 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') ) {
                        dp[i][j] |= dp[i - 1][j];
                    }
                }
                else {
                    if ( i != 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.') ) {
                        dp[i][j] |= dp[i - 1][j - 1];
                    }
                }
            }
        }
        return dp[len1][len2];
    }

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/regular-expression-matching/solutions/295977/zheng-ze-biao-da-shi-pi-pei-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
};

int main()
{
    Solution s;
    s.test();
    return 0;
}