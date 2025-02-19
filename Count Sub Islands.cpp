#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int n, m;
        bool vis[506][506];
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool flag;
        bool valid(int x, int y)
        {
            return !(x < 0 || x >= n || y < 0 || y >= m);
        }
        void dfs(int sr, int sc, vector<vector<int>>& grid1, vector<vector<int>> &grid2)
        {
            vis[sr][sc] = true;
            if(grid1[sr][sc] == 0)
                flag = false;
            for(int i = 0; i < 4; i++)
            {
                int si = sr + dir[i].first;
                int sj = sc + dir[i].second;
                if(valid(si, sj) && !vis[si][sj] && grid2[si][sj] == 1)
                {
                    dfs(si, sj, grid1, grid2);
                }
            }
        }
        int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
            n = grid1.size();
            m = grid1[0].size();
            memset(vis, false, sizeof(vis));
    
            int cnt = 0;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(!vis[i][j] && grid2[i][j] == 1)
                    {
                        flag = true;
                        dfs(i, j, grid1, grid2);
                        if(flag)
                            cnt++;
                    }
                }
            }
            return cnt;
        }
    };