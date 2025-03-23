class Solution {
public:

const int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
           unordered_map<int, vector<pair<int, int>>> adj;
    for (auto& road : roads) {
        int u = road[0];
        int v = road[1];
        int wt = road[2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});  // Because roads are bidirectional
    }

    // Step 2: Dijkstra's algorithm setup
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0}); // Starting from node 0 with distance 0

    vector<long long> ways(n, 0);   // To count the number of ways
    vector<long long> dist(n, LLONG_MAX);  // To store shortest distance
    dist[0] = 0;
    ways[0] = 1;

    // Step 3: Dijkstra's algorithm to calculate shortest paths
    while (!pq.empty()) {
        auto P = pq.top();
        pq.pop();

        long long dis = P.first;
        int node = P.second;

        // Traverse through all the neighbors
        for (auto& nbr : adj[node]) {
            int nbrNode = nbr.first;
            int weight = nbr.second;

            // If a shorter path is found
            if (dis + weight < dist[nbrNode]) {
                dist[nbrNode] = dis + weight;
                pq.push({dist[nbrNode], nbrNode});
                ways[nbrNode] = ways[node];  // Reset the number of ways to reach this node
            }
            // If another shortest path is found (equal distance)
            else if (dis + weight == dist[nbrNode]) {
                ways[nbrNode] = (ways[nbrNode] + ways[node]) % MOD;  // Add the number of ways
            }
        }
    }

    // Step 4: Return the number of ways to reach the last node
    return ways[n - 1];
        
    }
};