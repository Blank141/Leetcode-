#include <stdio.h>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //将字符串转换为字符数组
        char* str = (char*)s.c_str();
        int len = s.length();
        int max = 0,i = 0,j = 0;    
        while(i<len){
            j = i+1;
            while(j<len){
                if(str[i] == str[j]){
                    break;
                }
                j++;
            }
            if(j-i>max){
                max = j-i;
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