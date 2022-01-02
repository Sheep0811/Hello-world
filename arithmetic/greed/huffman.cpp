//优先队列Huffman算法
#include <bits/stdc++.h>
const int INF = 1e7;

using namespace std;

// 定义存储Huffman节点的结构体
struct HNode
{
    int id;        // 当前节点id(新加)
    double weight; // 权值
    int parent;    // 父节点id
    int lchild;    // 左孩子id
    int rchild;    // 右孩子id
    char sign;     // 该节点标识
    HNode() {id=0;weight=0;parent=-1;lchild=-1;rchild=-1;sign=0;}
    HNode(int _id, double _weight, int _lchild, int _rchild) : id(_id), weight(_weight), lchild(_lchild), rchild(_rchild) {}
    // 自定义比较规则
    bool operator>(const HNode &node) const
    {
        return this->weight > node.weight;
    }
};
        
vector<HNode> tree;

// 定义存储Huffman编码的结构体
struct HCode
{
    char sign;      // 当前的字符标识
    string codeStr; // 存储编码的字符串
};

// 构造Huffman树
vector<HNode> HuffmanTree(int n)
{
    // 建立优先队列存储树的根节点的集合
    priority_queue<HNode, vector<HNode>, greater<HNode>> q;
    for (int i = 0; i < n; i++)
    {
        //将所有节点（可看成时只有一个根节点的树）加入优先队列，按权值大小进行排序
        q.push(tree[i]);
    }

    int diff = 0; // diff表示新加入节点的个数
    while (q.size() > 1)
    {
        HNode node1 = q.top();
        q.pop();
        HNode node2 = q.top();
        q.pop();
        // 将新树的根节点加入到优先队列中
        q.push(HNode(n + diff, node1.weight + node2.weight, node1.id, node2.id));
        // 更新tree
        tree[node1.id].parent = n + diff;
        tree[node2.id].parent = n + diff;
        tree[n + diff].weight = node1.weight + node2.weight;
        tree[n + diff].lchild = node1.id;
        tree[n + diff].rchild = node2.id;

        diff += 1;
        //cout << tree[node1.id].sign << " and " << tree[node2.id].sign << " " << endl;
    }
    return tree;
}

// Huffman编码(从树自底向上得到每个叶节点的Huffman编码)
vector<HCode> HuffmanCode(vector<HNode> &tree, int n)
{
    // 定义存储各个字符编码的HCode数组
    vector<HCode> codes;
    int cur, p; // 当前节点的id和当前节点的父id
    for (int i = 0; i < n; i++)
    {
        HCode hc;
        hc.sign = tree[i].sign;
        // 初始化cur和p
        cur = i;
        p = tree[cur].parent;
        while (p != -1)
        {
            // 判断当前节点属于左孩子还是右孩子
            if (tree[p].lchild == cur)
            {
                hc.codeStr.insert(hc.codeStr.begin(), '0');
            }
            else
                hc.codeStr.insert(hc.codeStr.begin(), '1');
            // 更新cur和p
            cur = p;
            p = tree[cur].parent;
        }
        codes.push_back(hc);
    }
    return codes;
}

// 打印各个字符的Huffman编码
void PrintHuffmanCode(vector<HCode> &codes)
{
    cout << endl;
    for (const auto &a : codes)
    {
        cout << a.sign << " 的Huffman编码为: " << a.codeStr << endl;
    }
}

int main()
{
    int n=0;
    int x;
    cout << "请选择输入方式：\n1.从文件huffman.txt中输入\n2.手动输入\n";
    cin >> x;
    if (x == 1)
    {
        ifstream input("huffman.txt");
        map<char,int> map;
        // 初始化
        char c;
        string str;
        while((c=input.get())!= EOF)
	    {
            str+=c;
            map[c]++;
            if(map[c]==1)n++;
        }
        input.close();
        cout<<"进行编码的字符串为:"<<str<<endl;
        for (int i = 0; i < 2 * n - 1; i++)
        {
            HNode tmp;
            tmp.id = i;
            tmp.weight = 0;
            tmp.parent = -1;
            tmp.lchild = -1;
            tmp.rchild = -1;
            tree.push_back(tmp);
        }
        int i=0;
        for (auto tmp : map)
        {
            cout<<"字符："<<tmp.first<<"的权值为："<<tmp.second<<endl;
            tree[i].sign=tmp.first;
            tree[i].weight=tmp.second;
            i++;
        }
    }
    else if (x == 2)
    {
        cout << "请输入要编码的字符的个数:" << endl;
        cin >> n;
        // 定义Huffman结点，n个字符需要构造哈夫曼树2 * n - 1
        // 初始化
        for (int i = 0; i < 2 * n - 1; i++)
        {
            HNode tmp;
            tmp.id = i;
            tmp.weight = 0;
            tmp.parent = -1;
            tmp.lchild = -1;
            tmp.rchild = -1;
            tree.push_back(tmp);
        }
        cout << "请分别输入" << n << "个字符及其权值(以空格隔开):" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> tree[i].sign >> tree[i].weight;
        }
    }
    else
    {
        cout << "输入错误，退出程序！" << endl;
        system("pause");
        return 0;
    }
    vector<HNode> tree = HuffmanTree(n);
    vector<HCode> codes = HuffmanCode(tree, n);
    PrintHuffmanCode(codes);
    system("pause");
    return 0;
}