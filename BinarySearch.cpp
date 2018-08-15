// find leftmost occurence of a element in sorted array
// caching is also important
int BinarySearch(int a[], int st, int end, int key)
{
	int mid,left = -1;
	while(st <= end)
	{
		mid = st + (end-st)/2;
		if(a[mid] > key) end = mid-1;
		else if(a[mid] < key) st = mid+1;
		else
		{
			left = mid;
			end = mid-1;
		}
	}
	return left;
}