#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int n, m;
        bool vis[55][55];
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool valid(int x, int y)
        {
            if(x < 0 || x >= n || y < 0 || y >= m)
                return false;
            else
                return true;    
        }
        int cnt;
        void dfs(int sr, int sc, vector<vector<int>>& grid)
        {
            vis[sr][sc] = true;
            cnt++;
            for(int i = 0; i < 4; i++)
            {
                int si = sr + dir[i].first;
                int sj = sc + dir[i].second;
                if(valid(si, sj) && !vis[si][sj] && grid[si][sj] == 1) 
                {
                    dfs(si, sj, grid);
                }
            }
        }
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            n = grid.size();
            m = grid[0].size();
            memset(vis, false, sizeof(vis));
            int max_cnt = 0;
    
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    if(!vis[i][j] && grid[i][j] == 1)
                    {
                        cnt = 0;
                        dfs(i, j, grid);
                        if(max_cnt < cnt)
                            max_cnt = cnt;
                    }
    
            return max_cnt;        
        }
    };