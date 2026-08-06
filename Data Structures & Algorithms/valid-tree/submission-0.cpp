class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visit) {

        // Mark current node as visited
        visit[node] = true;

        // Visit all neighbors
        for (int nei : adj[node]) {

            // Ignore the parent node
            if (nei == parent)
                continue;

            // Cycle found
            if (visit[nei])
                return false;

            // DFS on unvisited neighbor
            if (!dfs(nei, node, adj, visit))
                return false;
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        // A tree must have exactly n-1 edges
        if (edges.size() != n - 1)
            return false;

        // Build adjacency list
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visit(n, false);

        // Check for cycle
        if (!dfs(0, -1, adj, visit))
            return false;

        // Check if all nodes are connected
        for (bool v : visit) {
            if (!v)
                return false;
        }

        return true;
    }
};