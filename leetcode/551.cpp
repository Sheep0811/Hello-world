bool checkRecord(char * s){
int lenght=strlen(s);
int coutA=0;
int coutL=0;
for(int i=0;i<lenght;i++)
{
    if(s[i]=='A'){
        coutA++;
        if(coutA==2){
            return false;
        }
    }
    if(s[i]=='L'){
        coutL++;
        if(coutL==3)return false;
    }
    else coutL=0;
}
return true;
}