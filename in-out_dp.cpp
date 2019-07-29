#include <bits/stdc++.h>

using namespace std;

#define MAX_NODE 100
#define pb push_back

vector<int> G[MAX_NODE];
int in[MAX_NODE];
int out[MAX_NODE];

void dfs1(int u, int par){
	in[u] = 0;

	for(int v: G[u]){
		if(v == par) continue;
		dfs1(v,u);
		in[u] = max(1+in[v],in[u]);
	}
}

void dfs2(int u, int par){
	int mx1(-1),mx2(-1);

	for(int v: G[u]){
		if(v == par) continue;
		if(in[v] >= mx1){
			mx2=mx1;
			mx1=in[v];
		}
		else if(in[v] > mx2){
			mx2 = in[v];
		}
	}

	for(int v: G[u]){
		if(v == par) continue;

		int to_use = mx1;
		if(in[v] == mx1) to_use = mx2;

		out[v] = max(1 + out[u], 2 + to_use);

		dfs2(v,u);
	}

}



int main(){
	int n,x,y;
	cin >> n;

	for(int i = 1; i < n; i++){
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}

	dfs1(1,0);
	dfs2(1,0);

	for(int i = 1; i <= n; i++){
		cout << max(in[i],out[i]) << " ";
	}
	cout << endl;


}
