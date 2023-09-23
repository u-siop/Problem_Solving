#include <iostream>
using namespace std;
#define MAX 10000

int sorted[MAX];

void merge(int *arr, int left, int mid, int right){
    int i,j,k,l;
    i = left;
    j = mid+1;
    k = left;

    while(i<=mid && j<=right){
        if(arr[i] <= arr[j]) sorted[k++] = arr[i++];
        else sorted[k++] = arr[j++];
    }

    if(i > mid){
        for(l=j; l<=right; l++){
            sorted[k++] = arr[l];
        }
    }
    else{
        for(l=i; l<=mid; l++){
            sorted[k++] = arr[l];
        }
    }

    for(l = left; l<=right; l++){
        arr[l] = sorted[l];
    }
}

void merge_sort(int* arr, int left, int right){
    int mid;

    if(left < right){
        mid = (left + right)/2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }

}

int partition(int *arr, int left, int right){
    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = arr[left];

    do {
        do {
            low++;
        }while (low<=right && arr[low]<pivot);

        do {
        high--;
        }while (high>=left && arr[high]>pivot);
        if(low<high){
            temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }
    }while (low<high);

    temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;

    return high;
}

void quick_sort(int *arr, int left, int right){
    if(left < right){
        int q = partition(arr, left, right);

        quick_sort(arr, left, q-1);
        quick_sort(arr, q+1, right);
    }
}

int main(){
    int arr[MAX];
    for(int i=0; i<MAX; i++){
        cin >> arr[i];
    }
    merge_sort(arr, 0, MAX-1);
    quick_sort(arr, 0, MAX-1);
}