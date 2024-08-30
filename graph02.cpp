#include<bits/stdc++.h>
using namespace std;
class BFS{
	public:
		vector<int> bfs(int v, vector<int> adj[]){
			vector<int> traversal;
			int visit[v] = {0};
			visit[0] = 1;
			queue<int> q;
			q.push(0);
			while(!q.empty()){
				int node = q.front();
				q.pop();
				traversal.push_back(node);
				for(auto it : adj[node]){
					if(!visit[it]){
						visit[it] = 1;
						q.push(it);
					}
				}
			}			
			return traversal;
		}
};
int main() {
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;
    vector<int> adj[v];
    int e;
    cout << "Enter the number of edges: ";
    cin >> e;

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    BFS bfsObj;
    vector<int> traversal = bfsObj.bfs(v, adj);
    cout << "BFS traversal of the graph: ";
    for (int i : traversal) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
