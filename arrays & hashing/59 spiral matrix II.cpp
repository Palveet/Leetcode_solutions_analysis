class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int cnt = 1;
        int startRow = 0;
        int endRow = n - 1;
        int startCol = 0;
        int endCol = n - 1;
        while (cnt <= n * n) {
            for (int col = startCol; col <= endCol; col++) {
                matrix[startRow][col] = cnt++;
            }
            for (int row = startRow + 1; row <= endRow; row++) {
                matrix[row][endCol] = cnt++;
            }
            for (int col = endCol - 1; col >= startCol; col--) {
                if (startRow == endRow) {
                    break;
                }
                matrix[endRow][col] = cnt++;
            }
            for (int row = endRow - 1; row >= startRow + 1; row--) {
                if (startCol == endCol) {
                    break;
                }
                matrix[row][startCol] = cnt++;
            }
            startRow++;
            endRow--;
            startCol++;
            endCol--;
        }
        return matrix;
    }
};

//TC:O(N*N)
//SC:O(N*N)