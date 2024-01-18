//Maximum sum of sub-array using divide and conquer technique.

#include <stdio.h>
#include <limits.h>

// Function to find the maximum of three numbers
int max(int a, int b, int c) {
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else
        return c;
}

// Function to find the maximum sum crossing the middle element
int maxCrossingSum(int arr[], int low, int mid, int high) {
    // Initialize sum and left_sum to a minimum value
    int sum = 0;
    int left_sum = INT_MIN;

    // Find the maximum sum of the left subarray
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    // Reset sum to 0 and initialize right_sum to a minimum value
    sum = 0;
    int right_sum = INT_MIN;

    // Find the maximum sum of the right subarray
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    // Return the sum of the maximum subarray crossing the middle element
    return max(left_sum + right_sum, left_sum, right_sum);
}

// Function to find the maximum sum of a subarray using divide and conquer
int maxSubarraySum(int arr[], int low, int high) {
    // Base case: Only one element in the array
    if (low == high)
        return arr[low];

    // Divide the array into two halves
    int mid = (low + high) / 2;

    // Recursively find the maximum sum in the left, right, and crossing subarrays
    int left_sum = maxSubarraySum(arr, low, mid);
    int right_sum = maxSubarraySum(arr, mid + 1, high);
    int crossing_sum = maxCrossingSum(arr, low, mid, high);

    // Return the maximum of the three sums
    return max(left_sum, right_sum, crossing_sum);
}

// Main function
int main() {
    int arr[] = { 10, -20, 30, 40, -50, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int max_sum = maxSubarraySum(arr, 0, n - 1);
    printf("Maximum sum of a subarray: %d\n", max_sum);

    return 0;
}
