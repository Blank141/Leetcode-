#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        // abc ab*c

        int len1 = s.length();
        int len2 = p.length(); 

        int i = 0, j = 0;
        while (i < len1 && j < len2)
        {
            if (s[i] == p[j] || p[j] == '.')
            {
                i++;
                j++;
            }
            else if (p[j] == '*')
            {
                if (j > 0 && (s[i] == p[j - 1] || p[j - 1] == '.'))
                {
                    i++;
                }
                else if (j < (len2-1) && (s[i] == p[j + 1] || p[j + 1] == '.'))
                {
                    j++;
                }
                else
                {
                    return false;
                }
            }
            else if (p[j+1]=='*')
            {
                j++;
            }
            else
            {
                return false;
            }
        }
        if(i==len1){    //s已经匹配完 abbb ab*bb
            while (j < len2)
            {
                if (p[j] == s[i-1])
                {
                    j++;
                }
                else if (p[j] == '*')
                {
                    j++;
                }
                else
                {
                    return false;
                }
            }
        }else if(j==len2){  //p已经匹配完
            return false;
        }
        return true;
    }
    void test(){
        string s = "aaa";
        string p = "a*a";
        bool re = isMatch(s,p);
        printf("%d",re);
    }
};

int main()
{
    Solution s;
    s.test();
    return 0;
}