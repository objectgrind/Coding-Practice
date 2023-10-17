/*
1/75
You are given an array of positive numbers from 1 to n, such that all numbers from 1 to n are present except one number x. 
You have to find x. The input array is not sorted.

##########
#Approach
##########


A straightforward approach is to search for every integer between 1 and n in the input array, 
stopping the search as soon as a missing number is found.
However, a more efficient solution exists. 

Here's a linear (O(n)) approach utilizing the arithmetic series sum formula:

Compute the sum (sum_of_elements) of all numbers in the array with a linear scan, O(n).
Calculate the sum (expected_sum) of the first n numbers using the arithmetic series sum formula.
Determine the missing number by finding the difference between expected_sum and sum_of_elements.
This algorithm optimizes the process by avoiding unnecessary searches and leverages mathematical properties for a more efficient solution.

*/

#include <iostream>
#include <vector>

int findMissingNumber(const std::vector<int>& nums, int n) {
    // Step 1: Find the sum of elements in the array
    int sum_of_elements = 0;
    for (int num : nums) {
        sum_of_elements += num;
    }

    // Step 2: Find the sum of first n numbers using the arithmetic series sum formula
    int expected_sum = (n * (n + 1)) / 2;

    // Step 3: Determine the missing number
    int missing_number = expected_sum - sum_of_elements;

    return missing_number;
}

int main() {
    // Example usage
    std::vector<int> input_array = {1, 2, 4, 6, 3, 7, 8};
    int n = 8; // Assuming the array should contain numbers from 1 to 8

    int result = findMissingNumber(input_array, n);

    std::cout << "The missing number is: " << result << std::endl;

    return 0;
}

/*

output 
The missing number is: 5

Runtime Complexity: Linear O(n)
*/