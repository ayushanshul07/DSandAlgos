#define MAX_SIZE 1e3
#define LOG_SIZE 10 // 2^10 >= 1000

// preprocessing time O(nlogn) and query O(1)
class SparseTable{
	int spT[MAX_SIZE][LOG_SIZE], a[MAX_SIZE];
public:
	SparseTable(int arr[], int n)
	{	
		for(int i = 0; i < n; i++)
		{
			a[i] = arr[i];
			spT[i][0] = i;
		}

		for(int j = 1; (1<<j) <= n; j++)
		{
			for(int i = 0; i + (1<<j) - 1 < n; i++)
			{
				if(a[spT[i][j-1]] <= a[spT[i+(1<<(j-1))][j-1]])
					spT[i][j] = spT[i][j-1];
				else 
					spT[i][j] = spT[i+(1<<(j-1))][j-1];
			}
		}
	}

	int query(int l, int r)
	{
		int k = log((double)(l-r+1))/log(2.0);
		if(a[spT[l][k]] <= a[spT[r-(1<<k)+1][k]])
			return spT[l][k];
		else return spT[r-(1<<k)+1][k];
	}

};

