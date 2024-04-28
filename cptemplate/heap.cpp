#include<iostream>

using namespace std;


int arr[100], i=0;

void Min_heapify(int A[], int n, int i);
void heapsort(int arr[],int n) ;
int Heap_Minimum(int heap[]);
int Heap_extract_min(int heap[]);
void Heap_decrease_key(int p, int k, int heap[]);
void Heap_increase_key(int p, int k, int heap[]);
void Min_heap_insert(int value, int heap[]);
void printheap();


void Min_heapify(int A[], int n, int i) {
    int largest = i;
    int l = 2 * i+1;
    int r = 2 * i + 2;


    if (l < n && A[l] > A[largest]) {
        largest = l;
    }
    if (r < n && A[r] > A[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(A[largest], A[i]);
        Min_heapify(A, n, largest);
    }
}

void heapsort(int arr[],int n)
{
    for(int i=n/2;i>=0;i--)
    {
        Min_heapify(arr,n,i);
    }

    for(int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        Min_heapify(arr, i, 0);
    }
}

int Heap_Minimum(int heap[])
{

    return heap[0];

}

int Heap_extract_min(int heap[])
{
    swap(heap[i-1], heap[0]);
    int temp = heap[i-1];
    i -= 1;

    heapsort(arr, i);
    printheap();

    return temp;

}


void Heap_decrease_key(int p, int k, int heap[])
{
    heap[p-1] -= k;

    heapsort(arr, i);
    printheap();

    return;
}

void Heap_increase_key(int p, int k, int heap[])
{
    heap[p-1] += k;

    heapsort(arr, i);
    printheap();
    return;
}

void Min_heap_insert(int value, int heap[])
{
    heap[i] = value;
    i++;

    heapsort(arr, i);
    printheap();
}


void printheap()
{
    for(int j=0;j<i;j++)
    {
        cout<< arr[j]<<" ";
    }
    cout<<endl;
}

void func_id(int n)
{
    switch (n)
    {
    case 1:
        cout<<Heap_Minimum(arr)<<endl;
        printheap();

        break;
    
    case 2:
        cout<<Heap_extract_min(arr)<<endl;
        printheap();
        break;
    
    case 3:

        int value;
        cin>>value;
        Min_heap_insert(value, arr);
        printheap();
        break;
    
    case 4:
        int p,k;
        cin>>p>>k;
        Heap_decrease_key(p ,k, arr);
        printheap();
        break;
    case 5:
        cin>>p>>k;
        Heap_increase_key(p ,k, arr);
        printheap();
        break;
    
    default:
        cout<<"invalid"<<endl;
    }
    
}

int main()
{
    int inp;
    while(1)
    {
        cin>>inp;
        if(inp == -1)
        {
            break;
        }else
        {
            arr[i] = inp;
            i++;
        }
    }

    heapsort(arr, i);

    cout<<"Min Heap: ";
    for(int j=0;j<i;j++)
    {
        cout<< arr[j]<<" ";
    }
    cout<<endl;
    while(1)
    {
        cin>>inp;
        if(inp == -1)
        {
            break;
        }else
        {
            func_id(inp);
        }
    }
    return 0;
}