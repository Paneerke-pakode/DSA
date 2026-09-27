// Given two sorted arrays nums1 and nums2 of size m and n respectively, 
// return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

#include <limits.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    if (nums1Size > nums2Size){
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int m = nums1Size;
    int n = nums2Size;

    int high = m;
    int low = 0;

    while (low <= high){
        int cutA = (low + high)/2;
        int cutB = (m+n+1)/2 - cutA;

        int Aleft = (cutA == 0) ? INT_MIN : nums1[cutA - 1];
        int Aright = (cutA == m) ? INT_MAX : nums1[cutA];

        int Bleft = (cutB == 0) ? INT_MIN : nums2[cutB - 1];
        int Bright = (cutB == n) ? INT_MAX : nums2[cutB];

        if (Aleft <= Bright && Bleft <= Aright){
            //odd total length
            if((m+n)%2==1){
                return (double)(Aleft>Bleft) ? Aleft : Bleft;
            }

            //even total length
            int leftMax = (Aleft > Bleft) ? Aleft : Bleft;
            int rightMin = (Aright < Bright) ? Aright : Bright;
            return (leftMax + rightMin)/2.0;
        }

        //move partition left
        else if (Aleft > Bright){
            high = cutA - 1;
        } 
        //move partition right
        else {
            low = cutA + 1;
        }
    }
    return 0.0; //will never reach here
}
