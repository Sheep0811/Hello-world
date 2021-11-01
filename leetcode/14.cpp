char * longestCommonPrefix(char ** strs, int strsSize){
if(strsSize==0){
    return " ";
}
int flag=0;
for(int i=0;i<strlen(strs[0]);i++){
    for(int j=1;j<strsSize;j++){
        if(strs[j][i]!=strs[0][i]){
            flag=1;
            strs[0][i]='\0';
            break;
        }
    }
    if (flag==1)return strs[0];
}
return strs[0];
}