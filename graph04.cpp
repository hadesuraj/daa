#include<bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int>::max();
int minKey(vector<int>& key, vector<bool>& mstSet) {
    int min = INF, min_index;
    for (int v = 0; v < key.size(); v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(vector<int>& parent, vector<vector<int>>& graph) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < parent.size(); i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << "\n";
}
void primMST(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> parent(V);
    vector<int> key(V, INF);
    vector<bool> mstSet(V, false);
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, graph);
}
int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }
    primMST(graph);
    return 0;
}

