class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int i,j;
        for(i=0,j=0;i<nums1.size()&&j<nums2.size();)
        {
            if(nums1[i]<nums2[j])
            {
                nums.push_back(nums1[i]);
                i++;
            }
            else
            {
                nums.push_back(nums2[j]);
                j++;
            }
        }
        if(i<nums1.size())
        {
            for(int k=i;k<nums1.size();k++)
            {
                nums.push_back(nums1[k]);
            }
        }
        if(j<nums2.size())
        {
            for(int k=j;k<nums2.size();k++)
            {
                nums.push_back(nums2[k]);
            }
        }
        if(nums.size()%2==0)return ((double)nums[nums.size()/2]+(double)nums[nums.size()/2-1])/2;
        else if(nums.size()%2==1)return (double)nums[(nums.size()-1)/2];
        return 0.00000;
    }
};