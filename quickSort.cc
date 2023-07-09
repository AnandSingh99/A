#include<iostream>
using namespace std;

int partition(int arr[],int s,int e){
    int k=0;
    int pivot = arr[s];
    
    for(int i=s+1;i<=e;i++){
        if(pivot>arr[i]){
            k++;
        }
    }
    //place pivot at right position
    int pivotIndex = s + k;
    swap(arr[pivotIndex],arr[s]);

    //left right check kare ki sab pivot chota h ya nhi left me
    int i = s;
    int j = e;

    while(i < pivotIndex && j > pivotIndex){
        while(arr[i]<pivot){
            i++;
        }

        while(arr[j]>pivot){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
}

void quicksort(int arr[],int s,int e){
    //base case
    if(s>=e)
    return;

    int p = partition(arr,s,e);

    //left part sort karle 
    quicksort(arr,s,p-1);

    //right part sort karle
    quicksort(arr,p+1,e);
    
}

int main()
{
    int arr[1000];
    int n;
    
    cout<<"Enter the length of array :- ";
    cin>>n;
    cout<<endl;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }


    quicksort(arr,0,n-1);

    cout<<"The sorted array is :- ";

     for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;

}
