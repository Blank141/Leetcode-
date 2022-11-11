#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)return false;
        long re = 0;
        int temp = x;
        while (temp)
        {
            re = re * 10 + temp % 10;
            temp /= 10;
        }
        if (re == x)return true;
        else return false;
    }
};