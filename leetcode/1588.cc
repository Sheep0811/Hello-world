int sumOddLengthSubarrays(int* arr, int arrSize){
int i,j,q,sum=0;
for(i=1;i<=arrSize;i+=2){
    for(j=0;j<arrSize-i;j++){
        for(q=0;q<i;q++){
            sum+=arr[j+q];
        }
    }
}
return sum;
}