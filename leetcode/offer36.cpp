/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution
{
public:
    vector<Node *> q;
    Node *treeToDoublyList(Node *root)
    {
        if (root == nullptr)
            return nullptr;
        in(root);
        int n = q.size();
        for (int i = 0; i < n; ++i)
        {
             if(i==0)
            {
                q[i]->left=q[len-1];
                if(i+1<len)
                    q[i]->right=q[i+1];
                else
                    q[i]->right=q[i];
            }
            else if(i==len-1)
            {
                q[i]->right=q[0];
                if(i-1>=0)
                    q[i]->left=q[i-1];
                else
                    q[i]->left=q[i];
            }
            else
            {
                q[i]->left=q[i-1];
                q[i]->right=q[i+1];
            }
          //  q[i]->left = q[(i - 1 + n) % n];
          //  q[i]->right = q[(i + 1) % n];
        }
        return q[0];
    }
    void in(Node *root)
    {
        if (root == nullptr)
            return;
        in(root->left);
        q.push_back(root);
        in(root->right);
    }
};