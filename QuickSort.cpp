void swap(int* arr, int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

int find_pivot(int *arr, int st, int end)
{
	int x = arr[end];
	int i = st-1;

	for(int j = st; j < end; j++)
	{
		if(arr[j] <= x )
		{
			i++;
			swap(arr,i,j);
		}
	}
	swap(arr,i+1,end);
	return i+1;

}

void quick_sort(int* arr, int st, int end)
{
	if(st < end)
	{
		int p = find_pivot(arr,st,end);
		quick_sort(arr,st,p-1);
		quick_sort(arr,p+1,end);
	}
}
