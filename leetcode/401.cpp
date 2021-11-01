/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** readBinaryWatch(int turnedOn, int* returnSize)
{
char **ans=malloc(1000*sizeof(char*));
*returnSize=0;
for (int i=0;i<12;i++)
{
    for(int j=0;j<60;j++)
    {
        if(__builtin_popcount(i) + __builtin_popcount(j) == turnedOn)
        {
            ans[*returnSize]=malloc(sizeof(char)*6);
            sprintf(ans[(*returnSize)++],"%d:%02d",i,j);
        }

    }
}
return ans;
}
