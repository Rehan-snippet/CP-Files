#include <bits/stdc++.h>
using namespace std;

struct FordFulkerson {
    struct Edge {
        int to;         // destination node
        long long cap;  // remaining capacity
    };

    int n;                       // number of nodes (0-indexed: 0 to n-1)
    vector<Edge> edges;          // all edges; edge i and its reverse are i and i^1
    vector<vector<int>> adj;     // adj[u] = list of edge ids going out of u
    vector<bool> visited;        // visited array for DFS

    FordFulkerson(int n) : n(n), adj(n), visited(n) {}

    // Add edge u -> v with capacity cap
    // If directed = false, the reverse edge also gets capacity cap
    void addEdge(int u, int v, long long cap, bool directed = true) {
        adj[u].push_back(edges.size());
        edges.push_back({v, cap});              // forward edge
        adj[v].push_back(edges.size());
        edges.push_back({u, directed ? 0 : cap}); // reverse edge (residual)
    }

    // DFS: try to push 'flow' from u to t along any path with remaining capacity
    // Returns the amount of flow actually pushed (0 if no path found)
    long long dfs(int u, int t, long long flow) {
        if (u == t) return flow;       // reached sink, return bottleneck
        visited[u] = true;

        for (int id : adj[u]) {
            int v = edges[id].to;
            // go only to unvisited nodes via edges with remaining capacity
            if (!visited[v] && edges[id].cap > 0) {
                long long pushed = dfs(v, t, min(flow, edges[id].cap));
                if (pushed > 0) {
                    edges[id].cap -= pushed;      // use up forward capacity
                    edges[id ^ 1].cap += pushed;  // add residual capacity backward
                    return pushed;
                }
            }
        }
        return 0;  // no augmenting path from u
    }

    // Compute max flow from s to t
    long long maxFlow(int s, int t) {
        long long flow = 0;
        while (true) {
            fill(visited.begin(), visited.end(), false);  // reset for each DFS
            long long pushed = dfs(s, t, LLONG_MAX);
            if (pushed == 0) break;   // no more augmenting paths
            flow += pushed;
        }
        return flow;
    }
};

int main() {
    int n, m,k;
    cin >> m>>n>>k;
    FordFulkerson ff(n+m+2);
    
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;           // 0-indexed nodes
        ff.addEdge(u, v+m, 1);
    }
    for(int i=0; i<m; i++){
        ff.addEdge(0, i+1, 1);
    }
    for(int i=0; i<n; i++){
        ff.addEdge(i+m+1, n+m+1, 1);
    }
    long long ans= ff.maxFlow(0, n+m+1);
    
    for(int i=0; i<m; i++){
        FordFulkerson f2=ff;
        f2.addEdge(0, i+1, 2);
        ans= max(ans, f2.maxFlow(0, n+m+1));
    }
    

    cout << ans << "\n";   // source = 0, sink = n-1
}