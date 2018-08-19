#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX_VERT 100
const int INF = 1e5;
using ii = pair<int,int>;

vector<vector<ii> > G(MAX_VERT); // (vertex,edge-weight)

void dijkstra(vector<vector<ii> > &G, int s)
{

	priority_queue<ii, vector<ii>, greater<ii> > pq; //(dist, vertex)
	vector<int> dist(MAX_VERT,INF);
	pq.push(ii(0,s));
	dist[s] = 0;
	while(!pq.empty())
	{
		ii tmp = pq.top(); pq.pop();
		int d = tmp.first, p = tmp.second;
		if(d > dist[p]) continue; 
		for(auto to : G[p])
		{
			if(dist[p] + to.second < dist[to.first])
			{
				pq.push(ii(dist[p] + to.second, to.first));
				dist[to.first] = dist[p] + to.second;
			}
		}
	}
}


int main()
{
	return 0;
}