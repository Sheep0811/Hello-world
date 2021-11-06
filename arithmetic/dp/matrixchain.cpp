#include <bits/stdc++.h>
using namespace std;
#define N 100
static void traceback(int s[][N], int i, int j); //寻找最优子结构

static void matrixChain(int p[], int m[][N], int s[][N], int n); //m存最优值，s存断开位置。

void printParenthesis(int s[][N] , int i, int j);//输出表达式

int main()
{
    cout<<"请输入矩阵个数： ";
    int n;
    cin>>n;
    cout<<"请输入矩阵(忽略两个矩阵间相同的值，共"<<(n+1)<<"个数）:";
    int p[n+1];
    for(int i=0;i<=n;++i)
    {
        cin>>p[i];
    }
    int m[n+1][N];
    int s[n+1][N];
    matrixChain(p, m, s, n);
    for (int i = 1; i <= n; i++)
    {
        for(int k=1;k<i;++k)
        {
            printf("      ");
        }
        for (int j = i; j <= n; j++)
        {
            printf("%5d ",m[i][j]);
        }
        cout << endl;
    }
    cout<<"\n最少乘法次数为"<<m[1][n];
    cout<<"\n表达式为：";
    printParenthesis(s,1,n);
    cout<<endl;
    traceback(s, 1, n);
    system("pause");
    return 0;
}

static void traceback(int s[][N], int i, int j)
{
    if (i == j)
        return;
    traceback(s, i, s[i][j]);
    traceback(s, s[i][j] + 1, j);
    cout << "将 A" <<"["<< i << "," << s[i][j] <<"]"<< "与 A" <<"["<<(s[i][j] + 1) << "," << j << "]"<<"相乘"<<endl;
}

static void matrixChain(int p[], int m[][N], int s[][N], int n) //m存最优值，s存断开位置。
{
    for (int i = 1; i <= n; i++)
        m[i][i] = 0;
    for (int r = 2; r <= n; r++) //r子问题个数
        for (int i = 1; i <= n - r + 1; i++)
        {
            int j = i + r - 1;
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j]; //m[i][i]=0,从i处分开
            s[i][j] = i;
            for (int k = i + 1; k < j; k++)
            {
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]; //k为可分开的位置，遍历得到最小值
                if (t < m[i][j])
                {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
}

void printParenthesis(int s[][N] , int i, int j)
{
    if (i == j)
        printf("A[%d]",i);
    else
    {
        printf("(");
        printParenthesis(s, i, s[i][j]);
        printParenthesis(s, s[i][j] + 1, j);
        printf(")");
    }
}
