#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)return s;
        int len = s.length();
        string re = "";
        int t = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < len; j+=t)
            {
                if (j + i < len)
                {
                    re+=s[j + i];
                }
                if (j + t - i < len && i != 0 && i != numRows - 1)
                {
                    re+=s[j + t - i];
                }
            } 
        }
        return re;
    }
    void test(){
        string s = "PAYPALISHIRING";
        string re = convert(s,4);
        printf("%s",re);
    }
};

int main()
{
    Solution s;
    s.test();
    return 0;
}