/// recursion - function calls itself directly or indirectly

int factorial(int n){
  if (n == 0) {
    return 1; 
  }
  else {
    return n * factorial(n - 1);
  }
}

int fibonacci(int n) {
  if (n <= 1) {
    return n;
  }
  else {
    return fibonacci(n - 1) + fibonacci(n - 2); 
  }
}

void towerofHanoi(int n, char from_rod, char to_rod, char aux_rod) {
  if (n == 1) {
    printf("movde disk 1 from rod %c to rod %c\n", from_rod, to_rod);
    return;
  }
  towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
  printf("move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
  towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

