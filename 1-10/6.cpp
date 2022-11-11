#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)return s;
        char* str = (char*)s.c_str();
        int len = s.length();
        int t = 2 * numRows - 2;
        //长度为len的空字符串
        vector<string> re(numRows);
        for (int i = 0; i < len; i++)
        {
            int index = i % t;
            if (index < numRows)
            {
                re[index] += str[i];
            }
            else
            {
                re[t - index] += str[i];
            }
        }
        for (int i = 1; i < numRows; i++) {     // 将每行接起来就是结果
            re[0] += re[i];
        }
        return re[0];
    }
    void test(){
        string s = "PAYPALISHIRING";
        string re = convert(s,3);
        printf("%s",re);
    }
};

int main()
{
    Solution s;
    s.test();
    return 0;
}