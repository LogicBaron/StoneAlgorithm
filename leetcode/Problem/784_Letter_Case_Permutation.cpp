class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans = {""};

        for (char c: s) {
            if (isdigit(c)) {
                int n = ans.size();
                for (int i=0; i<n; i++) {
                    ans[i] = ans[i] + c;
                }
            }
            else {
                int n = ans.size();
                for (int i=0; i<n; i++) {
                    ans.push_back(ans[i] + char(tolower(c)));
                    ans[i] = ans[i] + char(toupper(c));
                }
            }
        }
        
        return ans;
    }
};
