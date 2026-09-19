class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;

        int rows = matrix.size();
        int cols = matrix[0].size();

        int row = 0;
        int col = cols - 1;  // Start at top-right

        while (row < rows && col >= 0) {
            int current = matrix[row][col];

            if (current == target) {
                return true;
            }
            else if (current > target) {
                // Current is too large → move left
                col--;
            }
            else {
                // Current is too small → move down
                row++;
            }
        }

        return false;
    }
};
