class Solution {
public:
    void DFS(vector<vector<char>>& grid, int i, int j, int ROW, int COL) {
        if (i < 0 || j < 0 || i >= ROW || j >= COL || grid[i][j] != '1') {
            return;
        }

        grid[i][j] = '0';

        DFS(grid, i + 1, j, ROW, COL);
        DFS(grid, i - 1, j, ROW, COL);
        DFS(grid, i, j + 1, ROW, COL);
        DFS(grid, i, j - 1, ROW, COL);
    }

    int numIslands(vector<vector<char>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();
        int count = 0;

        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    DFS(grid, i, j, ROW, COL);
                }
            }
        }
        return count;
    }
};
