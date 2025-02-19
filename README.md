# problem-solving-bfs-dfs
🌍 Mastering Graph and Grid Problems in C++ 🚀

💡 This week, I tackled several interesting graph and grid traversal problems using DFS (Depth First Search) in C++. Each problem required a unique approach to explore and manipulate grid-based structures effectively.

🔥 Problems Solved:
1️⃣ Island Perimeter 🏝️

Given a grid with land (1) and water (0), determine the perimeter of the single island.
✅ Used DFS to count the edges that touch water.
🏆 Key takeaway: Handling boundary conditions properly is crucial!
cpp
Copy
Edit
class Solution {
public:
    int cnt;
    vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    bool vis[105][105];
    int n, m;

    bool valid(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    void dfs(int sc, int sr, vector<vector<int>>& grid) {
        vis[sc][sr] = true;
        for (int i = 0; i < 4; i++) {
            int ci = sc + dir[i].first;
            int cj = sr + dir[i].second;
            if (!valid(ci, cj) || grid[ci][cj] == 0) cnt++;
            else if (!vis[ci][cj] && grid[ci][cj] == 1) dfs(ci, cj, grid);
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        cnt = 0;
        n = grid.size(), m = grid[0].size();
        memset(vis, false, sizeof(vis));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!vis[i][j] && grid[i][j] == 1) dfs(i, j, grid);

        return cnt;
    }
};
2️⃣ Find if Path Exists in a Graph 🔄

Given an undirected graph, determine if there’s a valid path between two nodes.
✅ Used DFS traversal to mark visited nodes.
🔍 Key takeaway: Graph traversal techniques like DFS and BFS are powerful!
cpp
Copy
Edit
class Solution {
public:
    vector<int> adj_list[200005];
    bool vis[200005];

    void dfs(int src) {
        vis[src] = true;
        for (int child : adj_list[src])
            if (!vis[child]) dfs(child);
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for (auto edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        memset(vis, false, sizeof(vis));
        dfs(source);
        return vis[destination];
    }
};
3️⃣ Max Area of Island 📏

Find the largest island's area in a binary grid.
✅ Used DFS to count the number of connected land cells.
🔥 Key takeaway: Keep track of visited nodes to prevent redundant checks.
cpp
Copy
Edit
class Solution {
public:
    int n, m;
    bool vis[55][55];
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool valid(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    int cnt;
    void dfs(int sr, int sc, vector<vector<int>>& grid) {
        vis[sr][sc] = true;
        cnt++;
        for (auto d : dir) {
            int si = sr + d.first, sj = sc + d.second;
            if (valid(si, sj) && !vis[si][sj] && grid[si][sj] == 1) dfs(si, sj, grid);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        memset(vis, false, sizeof(vis));
        int max_cnt = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!vis[i][j] && grid[i][j] == 1) {
                    cnt = 0;
                    dfs(i, j, grid);
                    max_cnt = max(max_cnt, cnt);
                }

        return max_cnt;
    }
};
Summary
These problems involve finding islands in a 2D grid using DFS. In Count Sub Islands, we check if an island in grid2 is completely contained within grid1. In Number of Closed Islands, we count the islands of 0s that are completely surrounded by 1s.

Approach
1️⃣ Count Sub Islands (Problem 1905)
Step 1: Iterate through grid2 and use DFS to find islands.
Step 2: For each island, check if all its cells are also land (1) in grid1.
Step 3: If an island exists fully in grid1, count it as a sub-island.

Algorithm
Count Sub Islands
Loop through grid2.
If a cell is 1 and not visited, start DFS.
During DFS, check if any cell is 0 in grid1, marking flag = false.
If flag remains true, count this as a sub-island.

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
2️⃣ Number of Closed Islands (Problem 1254)
Step 1: Perform DFS from the land (0) cells.
Step 2: If an island touches the boundary, mark it as not closed.
Step 3: Count only fully enclosed islands.

Algorithm
Closed Islands
Loop through grid, performing DFS from 0s.
If DFS reaches a boundary, mark flag = false.
If flag remains true, count it as a closed island.

 class Solution {
public:
    int n,m;
    bool vis[105][105];
    bool flag;
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool valid(int x, int y)
    {
        return !(x < 0 || x >= n || y < 0 || y >= m);
    }

    void dfs(int sr, int sc, vector<vector<int>>& grid)
    {
        vis[sr][sc] = true;
        
        for(int i = 0; i < 4; i++)
        {
            int si = sr + dir[i].first;
            int sj = sc + dir[i]. second;
            if(!valid(si, sj))
                flag = false;
            if(valid(si, sj) && !vis[si][sj] && grid[si][sj] == 0)
            {
                dfs(si, sj, grid);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(vis, false, sizeof(vis));

        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vis[i][j] && grid[i][j] == 0)
                {
                    flag = true;
                    dfs(i, j, grid);
                    if(flag)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};

🎯 What I Learned:
✔ DFS is a powerful technique for exploring grids and graphs.
✔ Edge cases matter! Handling boundaries in a grid-based problem is crucial.
✔ Efficiency matters: Reducing redundant calculations significantly improves performance.

📌 Next Goal: Explore BFS-based approaches for similar problems.