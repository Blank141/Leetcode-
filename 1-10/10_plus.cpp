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
        if (len1 == 0){
            if (len2 == 0)return true;
            else if (len2 % 2 == 1)return false;
            else{
                for (int i = 1; i < len2; i += 2)
                {
                    if (p[i] != '*')return false;
                }
                return true;
            }
        }else if (len2 == 0)return false;


        int i = len1-1, j = len2-1;
        if (s[i] == p[j] || p[j] == '.')
        {
            return isMatch(s.substr(0, i), p.substr(0, j));
        }
        else if (p[j] == '*'){
            if (s[i] == p[j-1] || p[j-1] == '.')
            {
                return isMatch(s.substr(0, i), p) || isMatch(s, p.substr(0, j-1));
            }else{
                return isMatch(s, p.substr(0, j-1));
            }
        }
        else
        {
            return false;
        }
    }

    void test(){
        string s = "aasdfasdfasdfasdfas";
        string p = "aasdf.*asdf.*asdf.*asdf.*s";
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