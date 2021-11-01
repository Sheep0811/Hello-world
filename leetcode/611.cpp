int cmp(const void *a ,const void *b)
{
    return (*(int*)a-*(int*)b);
}
int triangleNumber(int* nums, int numsSize){
if (nums==NULL || numsSize<3)
return 0;
int left,right,three,count=0;
qsort(nums,numsSize,sizeof(nums[0]),cmp);
for(int i=numsSize-1;i>=2;i--)
{
    left=0;
    right=i-1;
    three=nums[i];
    while(left<right)
    {
        int sums=nums[left]+nums[right];
        if(three<sums)
        {
            count+=right-left;
            right--;
        }
        else
        {
            left++;
        }
        
    }
}
return count;
}

