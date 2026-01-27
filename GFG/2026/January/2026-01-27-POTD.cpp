class Solution {
public:
    int n, m;

    bool solve(int i, int j, vector<vector<char>> &mat, string &word,
               int pnt, vector<vector<bool>> &vis) {

        if (pnt == word.size()) return true;

        if (i < 0 || j < 0 || i >= n || j >= m ||
            vis[i][j] || mat[i][j] != word[pnt])
            return false;

        vis[i][j] = true;

        if (solve(i+1, j, mat, word, pnt+1, vis)) return true;
        if (solve(i-1, j, mat, word, pnt+1, vis)) return true;
        if (solve(i, j+1, mat, word, pnt+1, vis)) return true;
        if (solve(i, j-1, mat, word, pnt+1, vis)) return true;

        vis[i][j] = false;
        return false;
    }

    bool isWordExist(vector<vector<char>> &mat, string &word) {
        n = mat.size();
        m = mat[0].size();

        unordered_map<char,int> cnt;
        for (auto &row : mat)
            for (char c : row) cnt[c]++;

        for (char c : word)
            if (--cnt[c] < 0) return false;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0]) {
                    if (solve(i, j, mat, word, 0, vis))
                        return true;
                }
            }
        }
        return false;
    }
};
