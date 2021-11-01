class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(),s.end());
        reverse(s.begin(),s.end()-n);
        reverse(s.end()-n,s.end());
        return s;
    //    s+=s.substr(0,n);
    //    s.erase(0,n);
    //    return s;
    }
};