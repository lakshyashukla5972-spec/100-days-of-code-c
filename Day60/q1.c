//Q110: Write a program to take an integer array arr and an integer k as inputs. The task is to find the maximum element in each subarray of size k moving from left to right. Print the maximum elements for each window separated by spaces as output.

/*
Sample Test Cases:
Input 1:
arr[1, 2, 3, 1, 4, 5, 2, 3, 6] = , k = 3
Output 1:
3 3 4 5 5 5 6

Input 2:
arr[5, 1, 3, 4, 2] = , k = 1
Output 2:
5 1 3 4 2

*/
#include <stdio.h>
#include <stdlib.h>

// A structure for deque
typedef struct {
    int *data;   // stores indices of array elements
    int front;
    int rear;
    int size;
} Deque;

// Initialize deque
Deque* createDeque(int size) {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->data = (int*)malloc(size * sizeof(int));
    dq->front = 0;
    dq->rear = -1;
    dq->size = 0;
    return dq;
}

// Check if deque is empty
int isEmpty(Deque* dq) {
    return dq->size == 0;
}

// Push element to rear
void pushRear(Deque* dq, int value, int capacity) {
    dq->rear = (dq->rear + 1) % capacity;
    dq->data[dq->rear] = value;
    dq->size++;
}

// Pop element from rear
void popRear(Deque* dq, int capacity) {
    dq->rear = (dq->rear - 1 + capacity) % capacity;
    dq->size--;
}

// Pop element from front
void popFront(Deque* dq, int capacity) {
    dq->front = (dq->front + 1) % capacity;
    dq->size--;
}

// Get front element
int getFront(Deque* dq) {
    return dq->data[dq->front];
}

// Main function to print max of each subarray of size k
void slidingWindowMax(int arr[], int n, int k) {
    if (k <= 0 || k > n) {
        printf("Invalid window size.\n");
        return;
    }

    Deque* dq = createDeque(n);

    // Process first k elements
    for (int i = 0; i < k; i++) {
        while (!isEmpty(dq) && arr[dq->data[dq->rear]] <= arr[i])
            popRear(dq, n);
        pushRear(dq, i, n);
    }

    // Process rest of the elements
    for (int i = k; i < n; i++) {
        printf("%d ", arr[getFront(dq)]);

        // Remove elements out of this window
        while (!isEmpty(dq) && getFront(dq) <= i - k)
            popFront(dq, n);

        // Remove smaller elements
        while (!isEmpty(dq) && arr[dq->data[dq->rear]] <= arr[i])
            popRear(dq, n);

        pushRear(dq, i, n);
    }

    // Print max of last window
    printf("%d\n", arr[getFront(dq)]);

    free(dq->data);
    free(dq);
}

int main() {
    int n, k;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    printf("Enter window size k: ");
    if (scanf("%d", &k) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    slidingWindowMax(arr, n, k);
    return 0;
}
