#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int len = s.length();
        long long re = 0;

        int i = 0;
        while (i < len)
        {
            if (s[i] == ' '){
                i++;
            }else{
                break;
            }
        }
        

        int flag = 1;
            if (s[i] == '-'){
                flag = -1;
                i++;
            }else if (s[i] == '+'){
                flag = 1;
                i++;
            }

        while (i < len)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                if (re > INT_MAX / 10 || (re == INT_MAX / 10 && s[i] - '0' > 7))
                {
                    if (flag == 1)
                    {
                        return INT_MAX;
                    }
                    else
                    {
                        return INT_MIN;
                    }
                }
                re = re * 10 + s[i] - '0';
                i++;
            }
            else
            {
                break;
            }
        }
        return re*flag;
    }
    void test(){
        string s = "21474836460";
        int re = myAtoi(s);
        printf("%d",re);
    }
};

int main()
{
    Solution s;
    s.test();
    return 0;
}