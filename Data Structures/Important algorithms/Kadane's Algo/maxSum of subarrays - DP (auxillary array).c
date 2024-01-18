//max sum of sub-array using dynamic programming
//using an auxiliary array

#include<stdio.h>

// Function to find the maximum sum of a subarray using dynamic programming
int maxSubarraySum(int arr[], int n) {
    int max_sum = arr[0];  // Initialize the maximum sum with the first element of the array
    int current_sum = arr[0];  // Initialize the current sum with the first element of the array

    for (int i = 1; i < n; i++) {
        // Calculate the current sum by either adding the current element to the previous subarray
        // or starting a new subarray from the current element
        current_sum = (arr[i] > current_sum + arr[i]) ? arr[i] : current_sum + arr[i];

        // Update the maximum sum if the current sum is greater
        if (current_sum > max_sum)
            max_sum = current_sum;
    }

    return max_sum;
}

// Main function
int main() {
    int arr[] = { 10, -20, 30, 40, -50, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int max_sum = maxSubarraySum(arr, n);
    printf("Maximum sum of a subarray: %d\n", max_sum);

    return 0;
}
