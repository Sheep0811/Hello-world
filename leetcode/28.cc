int strStr(char * haystack, char * needle){
if(needle=" " || strlen(needle)>strlen(haystack))
return 0;
int i,j,q,flag=0;
for(i=0;i<strlen(haystack);i++)
{
    if (strlen(haystack) - i < strlen(needle)) {
            return -1;
        }
    q=i;
    for(j=0;j<strlen(needle);j++)
    {
        if(haystack[q]!=needle[j]){
            break;
        }
        q++;
    }
    if(q==i+strlen(needle))
    return i;
}
return 0;
}