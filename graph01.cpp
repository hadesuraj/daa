#include<bits/stdc++.h>
using namespace std;
/* Adjacency Matrix Representation Of Undirected Graphs y*/
/*int main(){
	int n, m; // n -> node & m -> edge
	cin >> n >> m;
	int adj[n+1][m+1]; // because of '1' based indexing
	for(int i = 0;i<=m;i++)
	{
		int u,v;
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	return 0;
}*/

/* Adjacency List Representation Of Undirected Graphs */

int main(){
	int n , m;
	cin >> n >> m;
	vector<int> adj[n+1]; // '0' based indexing
	for (int i = 0; i<=m; i++){	
		int u,v;
		// u ---> v
		cin >> u >> v;
		adj[u].push_back(v);
		//adj[v].push_back(u);
	}
	//space for directed G: O(E)
	return 0;
}
