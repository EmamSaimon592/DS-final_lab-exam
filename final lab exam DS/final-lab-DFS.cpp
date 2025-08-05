/*DFS is a graph traversal algorithm that starts at a node and
 explores as far as possible along each branch before backtracking.
    0
   / \
  1   2
     / \
    3   4
Starting from 0, DFS traversal: 0 1 2 3 4 */

#include <iostream>
#include <vector>
using namespace std;

// DFS function
void DFS(int node, vector<bool>& visited, vector<vector<int>>& adj) {
    cout << node << " ";
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, visited, adj);
        }
    }
}

int main() {
    int V = 5;  // Number of vertices
    vector<vector<int>> adj(V);  // Adjacency list

    // Add edges
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[2].push_back(3);
    adj[2].push_back(4);

    // Visited array
    vector<bool> visited(V, false);

    cout << "DFS traversal starting from node 0: ";
    DFS(0, visited, adj);

    return 0;
}

/*DFS traversal starting from node 0: 0 1 2 3 4

 How it Works:

    Start at node 0

    Visit node 1 (from 0)

    Backtrack to 0, then visit node 2

    From node 2, visit 3, then 4

    All nodes visited, DFS ends */
