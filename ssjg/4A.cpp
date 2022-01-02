#include<cstdio>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

struct HTNode{
    int weight;
    char value;
    int LeftC;
    int RightC;
    int Parent;
    int ID;
    char code[200];
};

HTNode HTree[200];

HTNode REHTree[200];

bool ZIPCODE[1000000];

char REZIPCODE[1000000];

int counter(string tempstring)//统计权重
{
    int length=0;//从头开始
    int j= 0;
    int n=tempstring.size();
    for(int i = 0;i<n;i++)//对字符串进行遍历操作
	{
        for(j = 0;j<length;j++) //对字符进行是否新建判断
		{
            if(HTree[j].value == tempstring[i]) break;
        }
        if(j!=length)
		{
            HTree[j].weight++;//非新出现 原权重自加
        }
        else
		{
            length++;//新出现 扩展生成新节点
            HTree[j].weight++;
            HTree[j].value = tempstring[i];
            HTree[j].ID = length;
        }

    }
    return length;//返回数量
}

void Sort_1(int la,int ra)//按权重从小到大排序
{
    if(la>=ra) return ;
    int r = ra;
    int l = la;
    HTNode T = HTree[l];
    while(l<r)
	{
        while(l<r&&T.weight<HTree[r].weight) r--;
        if(l<r)
		{
            HTree[l] = HTree[r];
            HTree[r]=T;
            l++;
        }
        while (l<r&&T.weight>HTree[l].weight) l++;
        if(l<r)
      	{
            HTree[r] = HTree[l];
            HTree[l]=T;
            r--;
        }
    }
    Sort_1(la,l-1);
    Sort_1(l+1,ra);
    return ;
}

void Sort_2(int la,int ra)//对ID进行排序
{
    if(la>=ra) return ;
    int r = ra;
    int l = la;
    HTNode T = HTree[l];
    while(l<r)
	{
        while(l<r&&T.ID<HTree[r].ID) r--;
        if(l<r) 
		{
            HTree[l] = HTree[r];
            HTree[r]=T;
            l++;
        }
        while (l<r&&T.ID>HTree[l].ID) l++;
        if(l<r)
		{
            HTree[r] = HTree[l];
            HTree[l]=T;
            r--;
        }
    }
    Sort_2(la,l-1);
    Sort_2(l+1,ra);
    return ;
}

int HTree_Bulid(int length)//建树
{
    cout<<"统计权重："<<endl;
    for(int i=0;i<length;i++)
	{
    cout<<HTree[i].value<<" "<<HTree[i].weight<<endl;
    }
    Sort_1(0,length-1);
    int head,last;
    head = 0;
    last = length;
    while(last-1>head) //后树节点建立
	{                                              
        HTree[last].weight = HTree[head].weight+HTree[head+1].weight;//父节点权重为子节点权重之和
        HTree[last].ID = last+1;//父节点编号
        HTree[head].Parent = HTree[head+1].Parent = last+1;//子节点的父下标属性
        HTree[last].LeftC = HTree[head].ID;//父节点左右子下标
        HTree[last].RightC = HTree[head+1].ID;
        int i;
        HTNode HTemp = HTree[last];//将新建立节点队权重排序
        for(i=last-1;i>head+2&&HTree[i].weight>HTree[last].weight;i--)//插入
		{
            HTree[i+1] = HTree[i];
        }
        HTree[i+1] = HTree[i];
        HTree[i]=HTemp;
        head+=2;
        last++;
    }
    Sort_2(0,last-1);//对ID进行排序
    cout<<"树形节点值："<<endl;
    for(int i=0;i<last;i++)
	{
        cout<<HTree[i].ID<<" "<<HTree[i].weight<<" "<<HTree[i].Parent<<" "<<HTree[i].LeftC<<" "<<HTree[i].RightC<<endl;
    }
    return last;//返回最终节点树大小
}

void CODE(int length,char TempC[],int node,FILE *HTreeCode)
{
    if(!HTree[node].LeftC) //当到达叶子节点（仅叶子节点的孩子ID为0）
	{
        fprintf(HTreeCode,"%c: ",HTree[node].value);//字符值写入文件
        for(int i = 0;i<length;i++)
		{
            HTree[node].code[i] = TempC[i]; //获取路径编码
            fprintf(HTreeCode,"%c",HTree[node].code[i]);//写入文件
        }
        fprintf(HTreeCode,"\n");
        HTree[node].code[length]='\0';
        cout<<HTree[node].value<<" "<<HTree[node].code<<endl;
        return ;
    }
    length++;
    TempC[length-1] = '0';//非叶子 左子路径为0
    CODE(length,TempC,HTree[node].LeftC-1,HTreeCode);
    TempC[length-1] = '1';//右子路径为1
    CODE(length,TempC,HTree[node].RightC-1,HTreeCode);
    return ;
}

int RAR(string temp)//压缩文件前4字符保存长度 后保存压缩码
{
    int end_ = 0;
    int n=temp.size();
    for(int i=0;i<n;i++)
	{
        int j=0;
        for(j=0;HTree[j].value!=temp[i];j++);
        int k=0;
        while(HTree[j].code[k]!='\0')
		{
            ZIPCODE[end_++] = HTree[j].code[k++]-'0';
        }
    }
    return end_;
}

char RENode(int *l,int node) //对每个叶子节点匹配
{
    int k = *l;
    int b = 0;
    while(1){
        if(HTree[node].code[b]==0)//当完全匹配时
        {
            *l+=b;//修改已翻译长度
            return HTree[node].value;//返回翻译码
        }
        if(HTree[node].code[b]-'0'!=REZIPCODE[k]-'0') //当不匹配时返回
        {
            return 0;
        }
        k++;
        b++;
    }
    return 0;
}

void RERAR(int end_,char RECODE[],int length_)
// 将压缩文件表读取 前4位为长度 后为编码
{
    FILE *CodeRead = fopen("CodeFile.dat","rb");
    int sum = 0;
    char m;
    for(int i = 0;i<3;i++){//读取长度
        m=fgetc(CodeRead);
        if(m==0) break;
        sum*=10;
        sum+=(m-'0');
    }
    fseek(CodeRead,4,0);//跳转
    for(int i=0;i<sum;i++)
	{
        fread(&REZIPCODE[i],sizeof(char),1,CodeRead);
    }
    fclose(CodeRead);
    int k=0;//当前翻译位下标
    int l=0;//当前编码已翻译位置
    int r=0;
    while(l<sum){
        for(int i = 0;i<length_;i++) //在叶子节点中遍历寻找
        {
            char key = RENode(&l,i);//当前翻译码
            if(key!=0)//如果有效
            {
                RECODE[k] = key;
                k++;
                break;
            }
        }
    }
    RECODE[k] = '\0';//最后末尾值
    return ;
}

void HTreeWrite(int last)
{
    FILE *HTreeW = fopen("HTreeData.dat","wb");
    fprintf(HTreeW,"%d",last);
    fseek(HTreeW,4,0);
    for(int i = 0;i<last;i++){
        fwrite(&HTree[i],sizeof(struct HTNode),1,HTreeW);
    }
    fclose(HTreeW);
    return ;
}

void HTreeRead(int *length){
    FILE *HTreeR  = fopen("HTreeData.dat","rb");
    int sum = 0;
    char k;
    for(int i = 0;i<3;i++){
        k=fgetc(HTreeR);
        if(k==0) break;
        sum*=10;
        sum+=(k-'0');
    }
    fseek(HTreeR,4,0);
    for(int i = 0;i<sum;i++)
	{
        fread(&REHTree[i],sizeof(struct HTNode),1,HTreeR);

    }
    fclose(HTreeR);
    return ;
} 

string TempRead()//读入文件
{
    FILE *TEXTRead = fopen("File.txt","r");
    string Temp;
    int i=0;
    char c;
    while((c = fgetc(TEXTRead)) != EOF)
	{
        Temp.push_back(c);
        i++;
    }
    Temp[i]='\0';
    fclose(TEXTRead);
    cout<<Temp<<endl;
    return Temp;
}


int main()
{
    string temp;
    cout<<"请选择模式： \n1.从File.txt中获取(默认)\n2.自行输入"<<endl;
    int o;
    cin>>o;
    switch (o)
	{
        case 1:temp=TempRead();break;
        case 2:cout<<"请输入：\n";cin>>temp;break;
        default :cout<<"error"<<endl;temp=TempRead();break;
    }
    FILE *code = fopen("CodeFile.dat","wb");
    int length = counter(temp);
    int last = HTree_Bulid(length);
    HTreeWrite(last);
    HTreeRead(&last);
    char TempC[20];
    FILE *HTreeCode = fopen("HufCode.txt","w");
    cout<<"编码值："<<endl;
    CODE(0,TempC,last-1,HTreeCode);
    fclose(HTreeCode);
    int end_ = RAR(temp);
    fprintf(code,"%d",end_);
    fseek(code,4,0);
    cout<<"文件编码为:"<<endl;
    for(int i=0;i<end_;i++)
	{
        cout<<(int)ZIPCODE[i];
        fprintf(code, "%d", ZIPCODE[i]);
    }
    fclose(code);
    cout<<endl;
    char RETemp[2000];
    RERAR(end_,RETemp,length);
    cout<<"解压后为："<<endl;
    cout<<RETemp<<endl;
    system("pause");
    return 0;
}
