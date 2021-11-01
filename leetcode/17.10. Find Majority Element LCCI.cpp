int majorityElement(int* nums, int numsSize){
int x=nums[0];int cout=1;
for(int i=1;i<numsSize;i++)
{
    if(nums[i]==x)
    {
        cout++;
        continue;
    }
    if(--cout==0)
    {
        x=nums[i];
        cout=1;
    }
 /*   if(nums[i]!=x)
    {
        cout--;
        if(cout==0)
        {
            x=nums[i];
            cout=1;            
        }
    }
}*/
 cout=0;
for(int i=0;i<numsSize;i++)
{
    if(nums[i]==x)cout++;
}
if(cout>numsSize/2)
{
    return x;
}
return -1;
}
