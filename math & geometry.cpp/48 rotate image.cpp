class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (i < j) {
                    int t = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = t;
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

//TC: O(N^2)
//SC: O(1)