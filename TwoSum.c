/*
You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize=2;
    int* returnarr = (int*)malloc(*returnSize * sizeof(int));
    
    for (int i=0;i<numsSize;i++){
        for(int j=0;j<numsSize,i!=j;j++){
            if (nums[i]+nums[j]==target){
                returnarr[0]=i;
                returnarr[1]=j;
                return returnarr;
            }
        }
    }
    return NULL;
}
