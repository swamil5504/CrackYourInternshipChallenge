class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // Directions for 8 neighbors
        vector<vector<int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        
        int m = board.size();
        int n = board[0].size();
        
        // Temporary board to store the next state
        vector<vector<int>> next_state(m, vector<int>(n, 0));

        // Process each cell to compute the next state
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live_neighbors = 0;
                
                // Count live neighbors
                for (const auto& dir : directions) {
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] == 1) {
                        live_neighbors++;
                    }
                }
                
                // Apply the rules of the Game of Life
                if (board[i][j] == 1) {
                    if (live_neighbors == 2 || live_neighbors == 3) {
                        next_state[i][j] = 1;
                    } else {
                        next_state[i][j] = 0;
                    }
                } else {
                    if (live_neighbors == 3) {
                        next_state[i][j] = 1;
                    }
                }
            }
        }

        // Copy the next state to the original board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = next_state[i][j];
            }
        }
    }
};
