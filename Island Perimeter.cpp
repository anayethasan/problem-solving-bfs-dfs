#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int cnt;
        vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        bool vis[105][105];
        int n, m;
    
        bool valid(int x, int y)
        {
            if(x < 0 || x >= n || y < 0 || y >= m)
                return false;
            else
                return true;    
        }
    
        void dfs(int sc, int sr, vector<vector<int>>& grid)
        {
            vis[sc][sr] = true;
            for(int i = 0; i < 4; i++)
            {
                int ci = sc + dir[i].first;
                int cj = sr + dir[i].second;
                if(valid(ci, cj) == false)
                    cnt++;
                else if(valid(ci, cj) == true && grid[ci][cj] == 0) 
                    cnt++;
                else if(valid(ci, cj) == true && !vis[ci][cj] && grid[ci][cj] == 1)
                    dfs(ci, cj, grid);       
            }
        }
    
        int islandPerimeter(vector<vector<int>>& grid) {
            cnt = 0;
            n = grid.size();
            m = grid[0].size();
            memset(vis, false, sizeof(vis));
    
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(!vis[i][j] && grid[i][j] == 1)
                    {
                        dfs(i, j, grid);
                    }
                }
            }
            return cnt;
        }
    };