class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string tmp = "";

        for (int i=0; i<s.size(); i++) {
            if (s[i]==' ') {
                if (tmp.size()>0) {
                    v.push_back(tmp);
                }
                tmp = "";
            }
            else tmp+= s[i];
        }
        if (tmp.size()>0) v.push_back(tmp);

        string ans = "";
        int n = v.size();

        for (int i=n-1; i>0; i--) {
            ans += v[i];
            ans += " ";
        }
        ans += v[0];

        return ans;
    }
};
