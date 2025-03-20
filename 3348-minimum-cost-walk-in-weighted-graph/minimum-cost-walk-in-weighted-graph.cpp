class Solution {
public:

// void Dijkistra(int src, int des, int&val , unordered_map<int, vector<pair<int, int>>>&adj){

//      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
//     pq.push({INT_MAX, src});
//     unordered_map<int, int>minAnd;
//     minAnd[src]=INT_MAX;
//     while(!pq.empty()){
//         auto P=pq.top();
//         pq.pop();
//         int dis=P.first;
//         int node=P.second;
//         // if( node==des){
//         //     val =min(val, dis);
//         //     // return;
//         // }
//         for( auto nbr: adj[node]){
//             auto p = nbr;
//             int nbrnode=p.first;
//             int nbrdis=p.second;
//             //logic for storing the minimum
//             if(minAnd.find(nbrnode)==minAnd.end() || (nbrdis&dis)<minAnd[nbrnode]){
//                 minAnd[nbrnode]=(nbrdis&dis);
//                 pq.push({(nbrdis&dis), nbrnode});
//             }
//         }
//     }

//     val = (minAnd.find(des) != minAnd.end()) ? minAnd[des] : INT_MAX;


// }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        // unordered_map<int, vector<pair<int, int>>>adj;
        //  for( auto e: edges){
        //     int u = e[0];
        //     int v= e[1];
        //     int w= e[2];
        //     adj[u].push_back({v, w});
        //     adj[v].push_back({u,w});
        //  }
        //  vector<int>ans;

        //  for( auto q: query){
        //     int src=q[0];
        //     int des=q[1];
        //     int val=INT_MAX;
        //     Dijkistra(src, des, val , adj);
        //     if( val==INT_MAX){
        //         ans.push_back(-1);
        //     }
        //     else{
        //     ans.push_back(val);
        //     }

        //  }

        //  return ans;
        vector<int> parent(n), min_path_cost(n, -1);
        iota(parent.begin(), parent.end(), 0);

        function<int(int)> find_root = [&](int node) {
            if (parent[node] != node) {
                parent[node] = find_root(parent[node]);
            }
            return parent[node];
        };

        for (auto& edge : edges) {
            int source = edge[0], target = edge[1], weight = edge[2];
            int source_root = find_root(source);
            int target_root = find_root(target);

            min_path_cost[target_root] &= weight;

            if (source_root != target_root) {
                min_path_cost[target_root] &= min_path_cost[source_root];
                parent[source_root] = target_root;
            }
        }

        vector<int> result;
        for (auto& q : query) {
            int start = q[0], end = q[1];
            if (start == end) {
                result.push_back(0);
            } else if (find_root(start) != find_root(end)) {
                result.push_back(-1);
            } else {
                result.push_back(min_path_cost[find_root(start)]);
            }
        }
        return result;
    



    }
};