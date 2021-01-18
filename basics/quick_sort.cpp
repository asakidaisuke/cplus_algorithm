#include <bits/stdc++.h> 
#include <vector>
using namespace std;  
  

void swap(vector<int> &arr,int i ,int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(vector<int> &arr, int start ,int end)
{
    int pi = arr[end];
    int i = start;

    for(int j= start; j<end; j++)
    {
        if(arr[j] < pi)
        {
            swap(arr, i, j);
            i++;
        }
    }
    swap(arr, i, end);
    return i;
}

void quickSort(vector<int> &arr, int start, int end)
{
    if(start < end)
    {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot-1);
        quickSort(arr, pivot+1, end);
    }
}

void printArray(vector<int> arr)
{
    for(int i=0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int start=0, end = arr.size()-1;
    quickSort(arr, start, end);
    printArray(arr);
    return 0;
}


