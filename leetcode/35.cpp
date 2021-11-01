int searchInsert(int* nums, int numsSize, int target){
int l=0,r=numsSize-1;
if(nums[r] < target) return r + 1;
while(l<r)
{
    int mid=(l+r)/2;
    if(nums[mid]>=target)
    {
        r=mid;
    }
    else l=mid+1;
}
return l;
}