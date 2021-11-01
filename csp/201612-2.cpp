#include<iostream>
#include<bits/stdc++.h>
using namespace std;

float t; // 税后所得 

int main()
{
    
	cin>>t;
	float s;
	if(t<=3500){
    
		s = t; 
	}
	else if(t>3500 && t<=4955){
    
		s = (t-3500)/0.97+3500;
	}
	else if(t>4955 && t<=7655){
    
		s = (t-4955)/0.9+5000;
	}
	else if(t>7655 && t<=11255){
    
		s = (t-7655)/0.8+8000;
	}
	else if(t>11255 && t<=30755){
    
		s = (t-11255)/0.75+12500;
	}
	else if(t>30755 && t<=44755){
    
		s = (t-30755)/0.7+38500;
	}
	else if(t>44755 && t<=61005){
    
		s = (t-44755)/0.65+58500;
	}
	else if(t>61005){
    
		s = (t-61005)/0.55+83500;
	}
	//int res = (int)s;
cout<<fixed<<setprecision(0)<<s<<endl;
//printf("%3.0lf",s);
system("pause");
	return 0;
}