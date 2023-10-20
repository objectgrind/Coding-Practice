/*
6/75

Search for a given number in a sorted array, with unique elements, that has been rotated by some arbitrary number.
Return -1 if the number does not exist. 
Assume that the array does not contain duplicates.
##########
#Approach
##########

The approach presented involves a binary search with specific adjustments.
Upon closer inspection of the example array, it becomes evident that, in any given scenario, 
at least one half of the array is consistently sorted. Leveraging this characteristic proves advantageous.
If the target number 'n' is within the sorted half, the problem transforms into a conventional binary search. 
Alternatively, if 'n' lies in the unsorted half, the sorted half is discarded, and the search continues in the unsorted portion. 
This strategy results in a runtime complexity of O(log(n)), offering an efficient solution.
*/

#include <iostream>
#include <vector>

int searchInRotatedArray(const std::vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            return mid; // Target found
        }

        // Check which half is sorted
        if (nums[low] <= nums[mid]) {
            // Left half is sorted

            // Check if target is in the left sorted half
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            // Right half is sorted

            // Check if target is in the right sorted half
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1; // Target not found
}

int main() {
    // Example usage
    std::vector<int> rotatedArray = {4, 5, 6, 7, 8, 9, 1, 2, 3};
    int target = 6;

    int result = searchInRotatedArray(rotatedArray, target);

    if (result != -1) {
        std::cout << "Target " << target << " found at index " << result << std::endl;
    } else {
        std::cout << "Target " << target << " not found in the array." << std::endl;
    }

    return 0;
}

/*

output :
Target 6 found at index 2

Runtime Complexity: Linear O(log(n))
*/