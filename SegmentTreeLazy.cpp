#define MAX_SIZE 1e5
#define INT_MIN -1e5

class SegmentTreeLazy{
	int a[MAX_SIZE], t[MAX_SIZE], l[MAX_SIZE];
public:

	SegmentTreeLazy(int arr[], int n)
	{
		for(int i = 0; i < n; i++)
		{
			a[i] = arr[i];
		}

		for(int i = 0; i < 4*n; i++)
		{
			l[i] = 0;
		}

		build(1,0,n-1);
	}

	int max(int a, int b)
	{
		return (a>=b)?a:b;
	}

	void build(int root, int l, int r)
	{
		if(l > r)
			return;
		if(l == r)
		{
			t[root] = a[l];
			return;
		}
		int mid = l + (r-l)/2;
		build(2*root, l, mid);
		build(2*root+1, mid+1, r);

		t[root] = max(t[2*root],t[2*root+1]);
	}

	void shift(int root, int l, int r)
	{
		if(l[root] != 0)
		{
			t[root] = max(t[root],l[root]);
			if(l != r)
			{
				l[2*root] = max(l[2*root],l[root]);
				l[2*root+1] = max(l[2*root+1],l[root]);
			}
			l[root] = 0;
		}
	}

	void update(int root, int l, int r, int i, int j, int val)
	{
		shift(root,l,r);
		
		if(l > r || l > j || r < i )
			return;
		if(l >= i && r <= j)
		{
			t[root] = max(t[root],val);
			if(l != r)
			{
				l[2*root] = max(l[2*root],val);
				l[2*root+1] = max(l[2*root+1],val);
			}
			return;
		}

		int mid = l + (r-l)/2;
		update(2*root,l, mid, i, j, val);
		update(2*root+1,mid+1,r,i,j,val);
		t[root] = max(t[2*root],t[2*root+1]);
	}

	int query(int root, int l, int r, int i, int j)
	{
		if(l > r || l > j || r < i)
			return INT_MIN;

		shift(root,l,r);

		if(l >= i && r <= j)
		{
			return t[root];
		}

		int mid = l + (r-l)/2;
		int l = query(2*root,l,mid,i,j);
		int r = query(2*root+1,mid+1,r,i,j);
		return max(l,r);
	}

};
