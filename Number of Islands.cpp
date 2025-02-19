#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int n, m;
        bool vis[350][350];
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool valid(int x, int y)
        {
            return !(x < 0 || x >= n || y < 0 || y >= m);
        }
        void dfs(int sr, int sc, vector<vector<char>>& grid)
        {
            vis[sr][sc] = true;
            for(int i = 0; i < 4; i++)
            {
                int si = sr + dir[i].first;
                int sj = sc + dir[i].second;
                if(valid(si, sj) && !vis[si][sj] && grid[si][sj] == '1')
                    dfs(si, sj, grid);
            }
        }
        int numIslands(vector<vector<char>>& grid) {
            n = grid.size();
            m = grid[0].size();
            memset(vis, false, sizeof(vis));
    
            int cnt = 0;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    if(!vis[i][j] && grid[i][j] == '1')
                    {
                        dfs(i, j, grid);
                        cnt++;
                    }
    
    
            return cnt;        
        }
    };