class Solution {
public:
    void DFS(int row, int col, vector<vector<int>>& image, int newColor, int color, int dr[], int dc[]) {
        image[row][col] = newColor;

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nc >= 0 && nr < image.size() && nc < image[0].size()
                && image[nr][nc] == color) {
                DFS(nr, nc, image, newColor, color, dr, dc);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];

        // If the new color is the same as the original, no need to do anything
        if (inicolor == color) return image;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        DFS(sr, sc, image, color, inicolor, dr, dc);
        return image;
    }
};
