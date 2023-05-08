class Solution {
public:
    string minWindow(string s, string t) {
        // required characters
        unordered_map<char, int> t_count;
        for (int i=0; i<t.size(); i++) {
            t_count[t[i]]++;
        }
        int required = t_count.size();

        // get index
        vector<pair<int, char>> filtered_s;
        for (int i=0; i<s.size(); i++) {
            if (t_count.find(s[i]) != t_count.end()) {
                filtered_s.push_back({i, s[i]});
            }
        }

        // find
        int l = 0, r = 0, filtered_s_len = filtered_s.size();
        int formed = 0;
        unordered_map<char, int> window_count;
        vector<int> ans = {INT_MAX, -1, -1};

        while (r < filtered_s_len) {
            char c = filtered_s[r].second;
            window_count[c]++;

            if (window_count[c] == t_count[c]) formed++;

            while (l<=r && formed == required) {
                c = filtered_s[l].second;

                int end = filtered_s[r].first;
                int start = filtered_s[l].first;
                if (end-start+1 < ans[0]) ans = {end-start+1, start, end};

                if (--window_count[c] < t_count[c]) formed--;
                l++;
            }
            r++;
        }

        return ans[0]==INT_MAX ? "" : s.substr(ans[1], ans[0]);
    }
};
