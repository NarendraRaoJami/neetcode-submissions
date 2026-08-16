class CountSquares {
    int cnt[1001][1001]{};

public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        cnt[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int px = point[0];
        int py = point[1];
        
        int ans = 0;

        // Choose the other point on the same horizontal line
        for (int x = 0; x <= 1000; x++) {
            if (x == px || cnt[x][py] == 0)
                continue;

            int side = abs(x - px);

            // Square above
            if (py + side <= 1000) {
                ans += cnt[x][py]
                     * cnt[px][py + side]
                     * cnt[x][py + side];
            }

            // Square below
            if (py - side >= 0) {
                ans += cnt[x][py]
                     * cnt[px][py - side]
                     * cnt[x][py - side];
            }
        }

        return ans;
    }
};