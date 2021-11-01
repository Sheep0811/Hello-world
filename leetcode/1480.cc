/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
if(numsSize==0){
    *returnSize=0;
    return NULL;
}
int *dp=(int*)malloc(sizeof(int)*numsSize);
int i;
dp[0]=nums[0];
for(i=1;i<numsSize;i++){
    dp[i]=dp[i-1]+nums[i];
}
*returnSize=numsSize;
return dp;
}