#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define INF 1e6

vector<vector<int> > G(100);

void BFS(vector<vector<int> > &G, int s)
{
	vector<int> d(100,INF);
	queue<int> q;
	q.push(s);
	d[s] = 0;

	while(!q.empty())
	{
		int p = q.front(); q.pop();
		for(auto to : G[p])
		{
			if(d[to] == INF)
			{
				q.push(to);
				d[to] = d[p]+1;
			}
		}
	}
}


int main()
{
	return 0;
}