int countDigitOne(int n){
int count=0;
int r=0;
for(int i=0;n!=0;i++)
{
    int m=n/10;
    if(m*10+1<n) {
        m++;
    }
    else if(m*10+1==n){
        count+=r+1;
    }
    count+=(m*pow(10,i));
    r+=(n%10*pow(10,i));
    n=n/10;
}
return count;
}