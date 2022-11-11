#include <stdio.h>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //将字符串转换为字符数组
        char* str = (char*)s.c_str();
        //定义一个数组，用来存储每个字符出现的次数
        int count[256] = {0};
        int len = s.length();
        int max = 0,i = 0,j = 0;    
        while(i<len){
            //如果当前字符出现的次数为0，那么就将其出现的次数加1
            if(count[str[i]] == 0){
                count[str[i]]=1;
                i++;
            }
            //如果当前字符出现的次数不为0，那么就将其出现的次数减1
            else{
                for (int k = j; k < i; k++)
                {
                    count[str[k]] = 0;
                    if (str[k] == str[i])
                    {
                        j = k + 1;
                        break;
                    }
                }
            }
            //如果当前的最大长度小于当前的长度，那么就将当前的长度赋值给最大长度
            if(max < i-j){
                max = i-j;
            }
        }
        return max;
    }
    void test(){
        string s = "abcabcbb";
        int max = lengthOfLongestSubstring(s);
        printf("%d",max);
    }
};

int main()
{
    Solution s;
    s.test();
    return 0;
}