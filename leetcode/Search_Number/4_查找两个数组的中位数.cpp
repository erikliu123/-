
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int ret_number(vector<int>& nums1, vector<int>& nums2, int index)
    {
        int n=nums1.size(), m=nums2.size();
        int start1 = 0, start2 = 0;
        int eliminate = 0;
        int dst = (index-1)/2;
        while(eliminate < index)
        {
            int mid1 = start1, mid2 = start2;
            dst = (index- eliminate -1)/2;
            if(start1 + dst >= nums1.size())
            {
                mid1 = nums1.size()-1;
            }
            else mid1 = start1 + dst;

            if(start2 + dst >= nums2.size())
            {
                mid2 = nums2.size()-1;
            }
            else mid2 = start2 + dst;

            if(start2>=m)
            {
                return nums1[start1 + index - eliminate];
            }
            if(start1>=n)
            {
                return nums2[start2 + index - eliminate];
            }
            // if(eliminate == (index-1)){

            // }
            if(nums1[mid1] > nums2[mid2])
            {
                //排除num2[start2] ~ num2[mid2 - 1]
                int x=(mid2 - start2);
                if(x==0) x=1;
                eliminate += x;
                start2 += x;
            }
            else{
                //排除num1[start1] ~ num1[mid1 - 1]
                int x=(mid1 - start1);
                 if(x==0) x=1;
                eliminate += x;
                start1 += x;

            }
            
        }
        if(start2>=m)
        {
            return nums1[start1];
        }
        if(start1>=n)
        {
            return nums2[start2];
        }
        return min(nums1[start1], nums2[start2]);

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int pos = (total-1)/2; 
        int num1 = ret_number(nums1, nums2, pos);
        int num2 = 0;
        if(total == 0)
            return 0.0;
        if((total&0x1) == 0)
        {
            num2 = ret_number(nums1, nums2, pos+1);
            return 1.0*(num1+num2)/2;
        }
        return num1;

    }
};