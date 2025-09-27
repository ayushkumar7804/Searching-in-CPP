/* Ayush Yadav
   24070123028
*/
#include <iostream>
using namespace std;

int fibonacciSearch(int arr[], int n, int key) {
    int fib2 = 0;   
    int fib1 = 1;   
    int fib = fib2 + fib1; 

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    int offset = -1;

    while (fib > 1) {
        int i = min(offset + fib2, n - 1);

        if (arr[i] < key) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if (arr[i] > key) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else return i;
    }

    if (fib1 && arr[offset + 1] == key) return offset + 1;

    return -1;
}

int main() {
    int arr[] = {10, 22, 35, 40, 45, 50, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 45;

    int result = fibonacciSearch(arr, n, key);
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}

/* OUTPUT
  Element found at index 4 
*/
