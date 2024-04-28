#include<iostream>

using namespace std;


int arr[100];

void Max_heapify(int A[], int n, int i) {
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
        Max_heapify(A, n, largest);
    }
}

void heapsort(int arr[],int n)
{
    for(int i=n/2;i>=0;i--)
    {
        Max_heapify(arr,n,i);
    }

    for(int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        Max_heapify(arr, i, 0);
    }
}
int main()
{
    int inp, i =0;
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
    // cout<<i<<" i"<<endl;
    for(int j=(i-1)/2;j>=0;j--)
    {
        Max_heapify(arr, i, j);
    }


    cout<<"Max Heap: ";
    for(int j=0;j<i;j++)
    {
        cout<< arr[j]<<" ";
    }

    cout<<endl;

    heapsort(arr, i);

    cout<<"Sorted: ";
    for(int j=i-1;j>=0;j--)
    {
        cout<< arr[j]<<" ";
    }
    return 0;
}