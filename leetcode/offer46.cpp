class Solution {
public:
    int translateNum(int num) {
        string tmp = to_string(num);
        int count = tmp.size();
        int a = 0, b = 1, c = 1;
        for (int i = 1; i < count; ++i)
        {
            if(tmp[i-1]=='1' ||(tmp[i-1]=='2'&& tmp[i]-'0'>=0 && tmp[i]-'0'<=5))
            {
                c = a + b;
                a = b;
                b = c;
            }
            else
            {
                a = c;
            }
        }
        return c;
    }
};