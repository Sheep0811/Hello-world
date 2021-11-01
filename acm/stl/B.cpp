#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a=0;
    int count=0;
    int k=0;
    int n;
    cin>>n;
    vector<int>vec;
	for(int i=0;i<n;i++)
	{
        cin>>a;
        vec.push_back(a);
    }
    for(int i=0;i<n;i++)
    {
       //k=0;
        for(int j=i+1;j<n;j++)
        {
            k=0;
            if (vec[j]>k && vec[i]>vec[j])
            {
                count++;
                k=vec[j];
            }
            else if(vec[i]<vec[j])
            break;
        }
    }
    cout<<count<<endl;
    system("pause");
    return 0;
}