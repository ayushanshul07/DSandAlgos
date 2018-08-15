// array starting from 0 index.

int left(int i){return 2*i+1;}
int right(int i){return 2*i+2;}
int parent(int i){return (i-1)/2;}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Heapify(int a[], int i, int heapsize)
{
	int maximum = i;
	if(left(i) < heapsize && a[left(i)] > a[i])
		maximum = left(i);

	if(right(i) < heapsize && a[right(i)] > a[maximum])
		maximum = right(i);

	if(maximum == i) return;
	else if(maximum == left(i))
	{
		swap(&a[i],&a[left(i)]);
		Heapify(a,left(i),heapsize);
	}
	else
	{
		swap(&a[i],&a[right(i)]);
		Heapify(a,right(i),heapsize);
	}
}

void BuildHeap(int a[], int len)
{
	for(int i = (len-2)/2; i >= 0; i--)
	{
		Heapify(a,i,len);
	}
}

void HeapSort(int a[], int len)
{
	BuildHeap(a,len);
	int heapsize = len;
	for(int i = len-1; i >= 1; i--)
	{
		swap(&a[0],&a[i]);
		heapsize--;
		Heapify(a,0,heapsize);
	}
}