#include<stdio.h>
#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
    //将字符串转换为字符数组
    char* str = (char*)s.c_str();
    int len = s.length();
    if (len == 0)return "";
    if (len == 1)return s;
    int max = 1,i = 0,j = 0;
    int start = 0,center = 1;

    while(center<2*len-1){
        i = (center%2==0)?(center-2)/2:(center-1)/2;
        j = (center%2==0)?(center+2)/2:(center+1)/2;

        while(i>=0 && j<len){
            if(str[i] == str[j]){
                if((j-i+1)>max){
                    max = j-i+1;
                    start = i;
                }
                i--;
                j++;
            }else{
                break;
            }
        }
        center++;
    }
    return s.substr(start,max);
    }
    void test(){
        string s = "cbbd";
        string max = longestPalindrome(s);
        printf("%s",max.c_str());
    }
};

int main(int argc, char *argv[])
{
	Solution s;
    s.test();
	return 0;
}