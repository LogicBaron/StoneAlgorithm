class Solution {
public:
    int calculateTime(string keyboard, string word) {
        vector<int> c2i('z'-'a'+1, 0);

        for (int i=0; i<keyboard.size(); i++) {
            c2i[keyboard[i]-'a'] = i;
        }

        int rst = c2i[word[0]-'a'];

        for (int i=1; i<word.size(); i++) {
            rst += abs(c2i[word[i]-'a'] - c2i[word[i-1]-'a']);
        }

        return rst;
    }
};
