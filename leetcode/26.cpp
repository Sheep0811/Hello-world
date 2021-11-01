int removeDuplicates(int* nums, int numsSize){
int j=0;
for (int i=0 ; i<numsSize-1 ; i++)
{
    if (nums[i]==nums[i+1])
    { j++; }
     nums[i+1-j]=nums[i+1];
    
}
numsSize-=j;
return numsSize;
}
