/*
7/75

Given a sorted array of integers, return the low and high index of the given key. 
You must return -1 if the indexes are not found. 
The array length can be in the millions with many duplicates.
##########
#Approach
##########

Searching for the low and high indices in a sorted array efficiently is crucial,
especially when dealing with large arrays.
A modified binary search can significantly improve the performance of this task.
 Instead of linearly scanning the array, we can utilize binary search twice,
 once for finding the low index and once for finding the high index.

Let's delve into the algorithm for finding the low index:

Start with the entire array, setting the low index to 0 and the high index to the size of the array minus 1.

Calculate the mid index as (low + high) / 2.

If the element at the mid index is less than the key, update the low index to mid + 1. This move directs the search towards the start of the range.

If the element at the mid index is greater than or equal to the key, update the high index to mid - 1. The low index remains unchanged.

Repeat steps 2-4 until low is greater than high.

At this point, the low index is pointing to the first occurrence of the key. If the element at the low index does not match the key, return -1.

To find the high index, a similar approach is taken with slight modifications:

Start with the entire array, setting the low index to 0 and the high index to the size of the array minus 1.

Calculate the mid index as (low + high) / 2.

If the element at the mid index is less than or equal to the key, update the low index to mid + 1.

If the element at the mid index is greater than the key, update the high index to mid - 1. This time, the low index remains unchanged.

Repeat steps 2-4 until low is greater than high.

By employing this binary search approach for both low and high indices, we optimize the search process. This algorithm efficiently narrows down the range of possible indices, making it suitable for large arrays where linear scanning would be impractical. The key to its effectiveness lies in exploiting the sorted nature of the array, allowing for a more targeted and rapid search for the desired indices.
*/



#include <iostream>
#include <vector>

int findLowIndex(const std::vector<int>& nums, int key) {
    int low = 0;
    int high = nums.size() - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] < key) {
            low = mid + 1;
        } else if (nums[mid] >= key) {
            result = mid;
            high = mid - 1;
        }
    }

    // Check if the element at the low index matches the key
    if (result != -1 && nums[result] != key) {
        return -1;
    }

    return result;
}

int findHighIndex(const std::vector<int>& nums, int key) {
    int low = 0;
    int high = nums.size() - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] <= key) {
            low = mid + 1;
            result = mid;
        } else {
            high = mid - 1;
        }
    }

    // Check if the element at the high index matches the key
    if (result != -1 && nums[result] != key) {
        return -1;
    }

    return result;
}

int main() {
    // Example usage
    std::vector<int> sortedArray = {1, 2, 2, 2, 3, 4, 4, 5, 6};
    int key = 4;

    int lowIndex = findLowIndex(sortedArray, key);
    int highIndex = findHighIndex(sortedArray, key);

    std::cout << "Low Index of " << key << ": " << lowIndex << std::endl;
    std::cout << "High Index of " << key << ": " << highIndex << std::endl;

    return 0;
}


/*

output :
Low Index of 4: 5
High Index of 4: 6

Runtime Complexity: Linear O(log(n))
*/