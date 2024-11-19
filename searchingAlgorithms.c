// linear search; checks each element of list sequentially 

int linearSearch(int arr[], int n, int x) {
  for (int i = 0; i < n; i++) {
    if(arr[i] == x) {
      return i;
    }
  }
return -1;
}

// binary search; more efficient algorithm that works on sorted arrays
// repeatedly divides search interval in half 

int binarySearch(int arr[], int low, int high, int x) {
  if (high >= low) {
    int mid = low + (high - low) / 2; 
    if (arr[mid] == x)
      return mid;
    if (arr[mid] > x)
      return binarySearch(arr, low, mid - 1, x);
    return binarySeach(arr, mid + 1, high, x); 
  }
return -1; 
}


// interpolation search; improved binary search. estimates position of target
// element based on the values of the endpoints 

int interpolationSearch(int arr[], int lo, int hi, int x) {
  if (lo <= hi && x >= arr[lo] && x <= arr[high]) {
      int pow = lo + ((double)(hi - lo) / (arr[hi] - arr[lo]))

      if (arr[pos] == x)
        return pos;
      if (arr[pos] < x)
        return interpolationSearch(arr, pos + 1, hi, x);
      if (arr[pos] > x)
        return interpolationSearch(arr, lo, pos - 1, x); 
  }
return -1; 
}


// jumpSearch; skips elemnts in blocks, works better than liner for big arrays
int jumpSearch(int arr[], int x, int n)
{
  int step = sqrt(n);
  int prev = 0;
  while(arr[min(step, n)-1] < x) {
    prev = step;
    step += sqrt(n);
    if(prev >= n)
      return -1;
  }

  while (arr[prev] < x) {
    prev++;
    if(prev == min(step, n))
      return -1;
  }
  if(arr[prev] == x)
    return prev; 

return -1; 
}


    
