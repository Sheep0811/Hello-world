#include <bits/stdc++.h>
using namespace std;

int longest(string a, string b, vector<vector<int>> &dp, vector<vector<int>> &m); //最长公共子序列个数

void lcs(int i, int j, string a, string &ans, vector<vector<int>> m); //最长公共子序列

int main()
{
    string a, b;
    int x;
    cout<<"请选择输入方式：\n1.从文件LCS.txt中输入\n2.手动输入\n";
    cin>>x;
    if(x==1)
    {
        ifstream input;
        input.open("LCS.txt",ios::in);                                            
        if (!input)
	    {
		    cout << "文件不存在" << endl;
		    cout << "退出程序" << endl;
            system("pause");
		    return 0;
        }
        input>>a>>b;
        cout<<"第一个子序列为："<<a<<endl;
        cout<<"第二个子序列为："<<b;        
        input.close();
    }
    else if(x==2)
    {
        cout << "请输入第一个序列：" << endl;
        cin >> a;
        cout << "请输入第二个序列：" << endl;
        cin >> b;   
    }
    else
    {
        cout<<"输入错误";
        system("pause");
        return 0;
    }
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
    vector<vector<int>> m(a.size() + 1, vector<int>(b.size() + 1, 0)); //0为左下，1为左，-1为下
    int length = longest(a, b, dp, m);
    cout << "\n公共子序列长度为：" << length << endl;
    string ans;
    lcs(a.size(), b.size(), a, ans, m);
    cout << "\n最长公共子序列为：" << ans << endl;
    system("pause");
    return 0;
}

int longest(string a, string b, vector<vector<int>> &dp, vector<vector<int>> &m)
{
    int la = a.size();
    int lb = b.size();
    //memset(dp,0,sizeof(dp));
    for (int i = 1; i <= la; ++i)
    {
        for (int k = 1; k <= lb; ++k)
        {
            if (a[i - 1] == b[k - 1])
            {
                dp[i][k] = dp[i - 1][k - 1] + 1;
                m[i][k] = 0;
            }
            else
            {
                dp[i][k] = max(dp[i - 1][k], dp[i][k - 1]);
                m[i][k] = dp[i - 1][k] >= dp[i][k - 1] ? -1 : 1;
            }
        }
    }
    return dp[la][lb];
}
void lcs(int i, int j, string a, string &ans, vector<vector<int>> m)
{
    if (i == 0 || j == 0)
        return;
    if (m[i][j] == 0)
    {
        lcs(i - 1, j - 1, a, ans, m);
        ans += a[i - 1];
    }
    else if (m[i][j] == -1)
        lcs(i - 1, j, a, ans, m);
    else
        lcs(i, j - 1, a, ans, m);
}

