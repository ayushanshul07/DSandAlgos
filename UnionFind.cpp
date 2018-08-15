class UnionFind
{
	int *rank, *parent; 
public:
	UnionFind(int v)
	{
		rank = new int[v];
		parent = new int[v];
		for(int i = 0; i < v; i++)
		{
			parent[i] = i;
			rank[i] = 0;
		}
	}
	
	int findSet(int i)
	{
		return ((parent[i] == i)?i:(parent[i] = findSet(parent[i])));
	}

	bool isSameSet(int i, int j)
	{
		return (findSet(i) == findSet(j));
	}

	void setUnion(int i, int j)
	{
		if(isSameSet(i,j)) return;

		int x = findSet(i), y = findSet(j);
		if(rank[x] > rank[y])
			parent[y] = x;
		else if(rank[x] < rank[y])
			parent[x] = y;
		else
		{
			parent[x] = y;
			rank[y]++;
		}
	}
	
};