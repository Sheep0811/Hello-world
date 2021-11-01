char pair(char a)
{
    if(a==')') return'(';
    if(a=='}')return '{';
    if(a==']')return '[';
    return '0';
}

bool isValid(char * s)
{
int n=strlen(s);
int top=-1;
if(n%2==1)return false;
char sym[n+1];
for(int i=0;i<n;i++)
{
    char c=s[i];
    if(pair(c)=='0')
    {
        top++;
        sym[top]=c;   
    }
    else
    {
        if(top==-1)return false;
        if(sym[top]!=pair(c))return false;
        top--;
    }
}
if(top==-1)return true;
else return false;
}
