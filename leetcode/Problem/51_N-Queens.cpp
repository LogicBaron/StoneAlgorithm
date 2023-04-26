class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        if (n==1) return {{"Q"}};
        vector<vector<int>> queens;
        vector<vector<vector<int>>> queens_ans;
        vector<vector<string>> ans;

        for (int i=0; i<n; i++) {
            backtrack(queens_ans, queens, n, 0, i);
        }

        for (vector<vector<int>> cur: queens_ans) {
            vector<string> v(n, string(n, '.'));
            for (vector<int> queen: cur) {
                v[queen[0]][queen[1]] = 'Q';
            }
            ans.push_back(v);
        }

        return ans;
    }

    void backtrack(vector<vector<vector<int>>>& queens_ans, vector<vector<int>>& queens, int n, int row, int col) {
        queens.push_back({row, col});

        for (int i=0; i<n; i++) {
            int flag = false;
            for (vector<int> queen: queens) {
                if (i == queen[1] || row+1+i == queen[0]+queen[1] || row+1-i == queen[0]-queen[1]) {
                    flag=true;
                    break;
                }
            }
            if (flag) continue;
            if (row == n-2) {
                queens.push_back({row+1, i});
                queens_ans.push_back(queens);
                queens.pop_back();
            }
            else {
                backtrack(queens_ans, queens, n, row+1, i);
            }
        }

        queens.pop_back();
    }
};
