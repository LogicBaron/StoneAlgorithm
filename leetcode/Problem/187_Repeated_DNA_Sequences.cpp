class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size()<=10) return {};

        unordered_map<char, int> c2i {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        unordered_map<int, int> mp;
        vector<string> rst;

        // initial value
        int tmp = 0;
        for (int i=0; i<10; i++) {
            tmp += c2i[s[i]]*pow(4, 9-i);
        }
        mp[tmp]++;

        int k = pow(4, 9);
        for (int i=10; i<s.size(); i++) {
            tmp -= c2i[s[i-10]]*k;
            tmp *= 4;
            tmp += c2i[s[i]];
            mp[tmp]++;
            if (mp[tmp] == 2) {
                rst.push_back(s.substr(i-9, 10));
            }
        }

        return rst;
    }
};
