/*BFS visits all neighbors of a node before going deeper.
    0
   / \
  1   2
     / \
    3   4
Starting from 0, BFS traversal: 0 1 2 3 4 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function for BFS
void BFS(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        // Visit all unvisited neighbors
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int V = 5;  // Number of vertices
    vector<vector<int>> adj(V);  // Adjacency list

    // Add edges (undirected)
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[2].push_back(4);
    adj[4].push_back(2);

    // Visited array
    vector<bool> visited(V, false);

    cout << "BFS traversal starting from node 0: ";
    BFS(0, adj, visited);

    return 0;
}

/*BFS traversal starting from node 0: 0 1 2 3 4

✅ How BFS Works (Step-by-step):

    Start at node 0

    Visit its neighbors: 1, 2

    From 1, no new neighbors

    From 2, visit 3 and 4

    All nodes visited, traversal ends

    | Feature      | DFS                  | BFS                   |
| ------------ | -------------------- | --------------------- |
| Uses         | Stack (or Recursion) | Queue                 |
| Goes         | Deep first           | Level by level        |
| Suitable for | Backtracking, paths  | Shortest path, levels |
| Memory use   | Can be high          | Controlled by level   |

ok
*/

