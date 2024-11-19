#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j   
 + 1] = temp;
            }
        }
    }
}


// selection sort; finds min value in unsorted portion of array and 
// swaps it with the first unsorted element 

void selectionSort(int arr[], int n){
int i, j, min_idx;
for(i = 0; i < n - 1; i++)
{
min_idx = i;
for(j = i + 1; j < n; j++)
{
if(arr[j] < arr[min_idx])
  min_idx = j;
int temp = arr[min_idx]; 
arr[min_idx] = arr[i];
arr[i] = temp; 
}
}
}




// insertion sort; builds final sorted array one at a time 
void insertionSort(int arr[], int n){
  int i, key, j;
for(i = 1; i < n; i++)
{
key = arr[i];
j = i - 1; 
while(j >= 0 && arr[j] > key) {
arr[j + 1] = arr[j];
j = j-1; 
}
arr[j+1] = key;
}
}

// merge sort; divides array into two halves, sorts each recursively, merges
// two sorted halves 
void merge(int arr[], int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right = mid; 
// create temp arrays
int L[n1], R[n2];

// copy data to temp arrays
for(int i = 0; i < n1; i++)
  L[i] = arr[left + i];
for(int j = 0; j < n2; j++)
  R[j] = arr[mid + 1 + j];

// merge temporary arrays back into arr
int i = 0; j = 0; k = left; 
while(i < n1 && j < n2)
{
if(L[i] <= R[j])
{
arr[k] = L[i];
i++;
}
else
{
arr[k] = R[j];
j++;
}
k++;
}

// copy remaining elements of L[] if there are any
while (i < n1)
{
arr[k] = L[i];
i++;
k++;
}
while(j < n2)
{
arr[k] = R[j];
j++;
k++;
}
}

void mergeSort(int arr[], int left, int right)
{
  if(left < right) {
  int mid = left + (right - left) / 2;

  mergeSort(arr, left, mid);
  mergeSort(arr, mid + 1, right); 

  merge(arr, left, mid, right); 
  }
}


// quicksort; picks an element as a pivot and partitions array around pivot
int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = (low - 1); 
  for(int j = low; j < high; j++) {
    if(arr[j] <= pivot) {
      i++;
      int temp = arr[i];
      arr[i] = arr[i];
      arr[j] = temp;
    }
  }
int temp = arr[i + 1];
arr[i + 1] = arr[high];
arr[high] = temp;

return(i + 1);
}

void quickSort(int arr[], int low, int high)
{
  if(low < high){
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi-1);
    quickSort(arr, pi + 1, high);
  }
}
