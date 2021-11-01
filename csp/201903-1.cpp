#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int nums[n]={0};
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    sort(nums,nums+n);
    if(n%2==0){
         if((nums[n/2]+nums[n/2-1])%2==0)
        cout<<nums[n-1]<<" "<<(nums[n/2]+nums[n/2-1])/2<<" "<<nums[0]<<endl;
        else
        {
        cout<<nums[n-1]<<" "<<(nums[n/2]+nums[n/2-1])/2<<".5"<<" "<<nums[0]<<endl;    
        }
    }
    else{
        cout<<nums[n-1]<<" "<<nums[(n-1)/2]<<" "<<nums[0]<<endl;
    }
    system("pause");
    return 0;
}