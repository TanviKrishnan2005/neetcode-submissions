class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh = 0;
        int time = 0;

        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 1) fresh++;
                if(grid[r][c] == 2) q.push({r,c});
            }
        }

        vector<pair<int,int>> direc = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        while(fresh > 0 && !q.empty()){
            int len = q.size();

            for(int i = 0; i < len; i++){
                auto curr = q.front();
                q.pop();

                int r = curr.first;
                int c = curr.second;

                for(const auto& dir : direc){
                    int rows = r + dir.first;
                    int cols = c + dir.second;

                    if(rows >= 0 && cols >= 0 &&
                       rows < grid.size() &&
                       cols < grid[0].size() &&
                       grid[rows][cols] == 1){

                        grid[rows][cols] = 2;
                        q.push({rows,cols});
                        fresh--;
                    }
                }
            }
            time++;
        }

        return fresh == 0 ? time : -1;
    }
};