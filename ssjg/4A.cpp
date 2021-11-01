#include<cstdio>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

struct HTNode
{
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

int counter(string tempstring)//ͳ��Ȩ��
{
    int length=0;//��ͷ��ʼ
    int j= 0;
    for(int i = 0;i<tempstring.length();i++)//���ַ������б�������
	{
        for(j = 0;j<length;j++) //���ַ������Ƿ��½��ж�
		{
            if(HTree[j].value == tempstring[i]) break;
        }
        if(j!=length)
		{
            HTree[j].weight++;//���³��� ԭȨ���Լ�
        }
        else
		{
            length++;//�³��� ��չ�����½ڵ�
            HTree[j].weight++;
            HTree[j].value = tempstring[i];
            HTree[j].ID = length;
        }

    }
    return length;//��������
}

void Sort_1(int la,int ra)//��Ȩ�ش�С��������
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

void Sort_2(int la,int ra)//��ID��������
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

int HTree_Bulid(int length)//����
{
    cout<<"ͳ��Ȩ�أ�"<<endl;
    for(int i=0;i<length;i++)
	{
    cout<<HTree[i].value<<" "<<HTree[i].weight<<endl;
    }
    Sort_1(0,length-1);
    int head,last;
    head = 0;
    last = length;
    while(last-1>head) //�����ڵ㽨��
	{                                              
        HTree[last].weight = HTree[head].weight+HTree[head+1].weight;//���ڵ�Ȩ��Ϊ�ӽڵ�Ȩ��֮��
        HTree[last].ID = last+1;//���ڵ���
        HTree[head].Parent = HTree[head+1].Parent = last+1;//�ӽڵ�ĸ��±�����
        HTree[last].LeftC = HTree[head].ID;//���ڵ��������±�
        HTree[last].RightC = HTree[head+1].ID;
        int i;
        HTNode HTemp = HTree[last];//���½����ڵ��Ȩ������
        for(i=last-1;i>head+2&&HTree[i].weight>HTree[last].weight;i--)//����
		{
            HTree[i+1] = HTree[i];
        }
        HTree[i+1] = HTree[i];
        HTree[i]=HTemp;
        head+=2;
        last++;
    }
    Sort_2(0,last-1);//��ID��������
    cout<<"���νڵ�ֵ��"<<endl;
    for(int i=0;i<last;i++)
	{
        cout<<HTree[i].ID<<" "<<HTree[i].weight<<" "<<HTree[i].Parent<<" "<<HTree[i].LeftC<<" "<<HTree[i].RightC<<endl;
    }
    return last;//�������սڵ�����С
}

void CODE(int length,char TempC[],int node,FILE *HTreeCode)
{
    if(!HTree[node].LeftC) //������Ҷ�ӽڵ㣨��Ҷ�ӽڵ�ĺ���IDΪ0��
	{
        fprintf(HTreeCode,"%c: ",HTree[node].value);//�ַ�ֵд���ļ�
        for(int i = 0;i<length;i++)
		{
            HTree[node].code[i] = TempC[i]; //��ȡ·������
            fprintf(HTreeCode,"%c",HTree[node].code[i]);//д���ļ�
        }
        fprintf(HTreeCode,"\n");
        HTree[node].code[length]='\0';
        cout<<HTree[node].value<<" "<<HTree[node].code<<endl;
        int l=0;
        return ;
    }
    length++;
    TempC[length-1] = '0';//��Ҷ�� ����·��Ϊ0
    CODE(length,TempC,HTree[node].LeftC-1,HTreeCode);
    TempC[length-1] = '1';//����·��Ϊ1
    CODE(length,TempC,HTree[node].RightC-1,HTreeCode);
    return ;
}

int RAR(string temp)//ѹ���ļ�ǰ4�ַ����泤�� �󱣴�ѹ����
{
    int end_ = 0;
    for(int i=0;i<temp.length();i++)
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

char RENode(int *l,int node) //��ÿ��Ҷ�ӽڵ�ƥ��
{
    int k = *l;
    int b = 0;
    while(1){
        if(HTree[node].code[b]==0)//����ȫƥ��ʱ
        {
            *l+=b;//�޸��ѷ��볤��
            return HTree[node].value;//���ط�����
        }
        if(HTree[node].code[b]-'0'!=REZIPCODE[k]-'0') //����ƥ��ʱ����
        {
            return 0;
        }
        k++;
        b++;
    }
    return 0;
}

void RERAR(int end_,char RECODE[],int length_)
// ��ѹ���ļ����ȡ ǰ4λΪ���� ��Ϊ����
{
    FILE *CodeRead = fopen("CodeFile.dat","rb");
    int sum = 0;
    char m;
    for(int i = 0;i<3;i++){//��ȡ����
        m=fgetc(CodeRead);
        if(m==0) break;
        sum*=10;
        sum+=(m-'0');
    }
    fseek(CodeRead,4,0);//��ת
    for(int i=0;i<sum;i++)
	{
        fread(&REZIPCODE[i],sizeof(char),1,CodeRead);
    }
    fclose(CodeRead);
    int k=0;//��ǰ����λ�±�
    int l=0;//��ǰ�����ѷ���λ��
    int r=0;
    while(l<sum){
        for(int i = 0;i<length_;i++) //��Ҷ�ӽڵ��б���Ѱ��
        {
            char key = RENode(&l,i);//��ǰ������
            if(key!=0)//�����Ч
            {
                RECODE[k] = key;
                k++;
                break;
            }
        }
    }
    RECODE[k] = '\0';//���ĩβֵ
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

string TempRead()//�����ļ�
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
    cout<<"��ѡ��ģʽ�� \n1.��File.txt�л�ȡ(Ĭ��)\n2.��������"<<endl;
    int o;
    cin>>o;
    switch (o)
	{
        case 1:temp=TempRead();break;
        case 2:cout<<"�����룺\n";cin>>temp;break;
        default :cout<<"error"<<endl;temp=TempRead();break;
    }
    FILE *code = fopen("CodeFile.dat","wb");
    int length = counter(temp);
    int last = HTree_Bulid(length);
    HTreeWrite(last);
    HTreeRead(&last);
    char TempC[20];
    FILE *HTreeCode = fopen("HufCode.txt","w");
    cout<<"����ֵ��"<<endl;
    CODE(0,TempC,last-1,HTreeCode);
    fclose(HTreeCode);
    int end_ = RAR(temp);
    fprintf(code,"%d",end_);
    fseek(code,4,0);
    cout<<"�ļ�����Ϊ:"<<endl;
    for(int i=0;i<end_;i++)
	{
        cout<<(int)ZIPCODE[i];
        fprintf(code, "%d", ZIPCODE[i]);
    }
    fclose(code);
    cout<<endl;
    char RETemp[2000];
    RERAR(end_,RETemp,length);
    cout<<"��ѹ��Ϊ��"<<endl;
    cout<<RETemp<<endl;
    system("pause");
    return 0;
}

