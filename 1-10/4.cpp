#include<stdio.h>
#include<vector>

using namespace std;
// [1,4,5] [2,3,6,7]
// [1,2,4,5][2,3,4,6,6,7,8,9,10]
// [3][1,2]

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int i = 0,j = 0;
        if(m == 0){
            if(n%2 == 0){
                return (nums2[n/2-1]+nums2[n/2])/2.0;
            }else{
                return nums2[n/2];
            }
        }else if(n == 0){
            if(m%2 == 0){
                return (nums1[m/2-1]+nums1[m/2])/2.0;
            }else{
                return nums1[m/2];
            }
        }

        for (int k = 0;k < (m+n)/2-1;k++)
        {
            //若为偶数则为右侧的数
            //nums1的中位数 num1s[m/2]
            i = m/2;
            //nums2的中位数 nums2[n/2]
            j = n/2;

            //若nums1的中位数小于nums2的中位数
            if (nums1[i] < nums2[j])
            {
                //num1s[m/2]左侧的数都不可能是中位数
                //num2s[n/2]右侧的数都不可能是中位数
                if(m%2 == 0){
                    nums1.erase(nums1.begin(),nums1.begin()+i-1);
                }else{
                    nums1.erase(nums1.begin(),nums1.begin()+i);
                }
                if(n%2 == 0){
                    nums2.erase(nums2.begin()+j,nums2.end());
                }else{
                    nums2.erase(nums2.begin()+j+1,nums2.end());
                }
                m = nums1.size();
                n = nums2.size();
            }else if(nums1[i] > nums2[j]){
                //num1s[m/2]右侧的数都不可能是中位数
                //num2s[n/2]左侧的数都不可能是中位数
                if(m%2 == 0){
                    nums1.erase(nums1.begin()+i,nums1.end());
                }else{
                    nums1.erase(nums1.begin()+i+1,nums1.end());
                }
                if(n%2 == 0){
                    nums2.erase(nums2.begin(),nums2.begin()+j-1);
                }else{
                    nums2.erase(nums2.begin(),nums2.begin()+j);
                }
                m = nums1.size();
                n = nums2.size();
            }else{
                return nums1[i];
            }
        }
        if((m+n)%2 == 0){
            return (nums1[0]+nums2[0])/2.0;
        }else{
            if (nums1[0] > nums2[0])
            {
                return nums1[0];
            }else{
                return nums2[0];
            }
            
        }
    }
};