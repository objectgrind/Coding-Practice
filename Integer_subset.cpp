/*
8/75

We are given a set of integers and we have to find all the possible subsets of this set of integers.
##########
#Approach
##########
To address this issue, we'll explore a particularly elegant and straightforward solution.
Understanding that a set with n elements yields 2^n subsets (e.g., a set of 3 elements results in 8 subsets), let's outline the algorithm:

Let n be the size of the given integer set.
Calculate subsets_count as 2^n.
Iterate from 0 to subsets_count.
Form a subset using the value of 'i' as follows:
The bits in the number 'i' represent the indices of elements to choose from the original set.
If a specific bit is 1, select that corresponding number from the original set and add it to the current subset.
For example, if i = 6 (110 in binary), it means that the 1st and 2nd elements in the original array should be included.
Add the current subset to the list of all subsets.
*/

#include <iostream>
#include <vector>

void generateSubsets(const std::vector<int>& originalSet) {
    int n = originalSet.size();
    int subsetsCount = 1 << n;  // Calculate 2^n

    for (int i = 0; i < subsetsCount; ++i) {
        std::vector<int> currentSubset;

        for (int j = 0; j < n; ++j) {
            // Check if the j-th bit is set in i
            if (i & (1 << j)) {
                // Include corresponding element in the subset
                currentSubset.push_back(originalSet[j]);
            }
        }

        // Display or process the current subset
        std::cout << "Subset " << i + 1 << ": {";
        for (int k = 0; k < currentSubset.size(); ++k) {
            std::cout << currentSubset[k];
            if (k < currentSubset.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "}\n";
    }
}

int main() {
    // Example usage
    std::vector<int> originalSet = {1, 2, 3};
    generateSubsets(originalSet);

    return 0;
}




/*

output :
Subset 1: {}
Subset 2: {1}
Subset 3: {2}
Subset 4: {1, 2}
Subset 5: {3}
Subset 6: {1, 3}
Subset 7: {2, 3}
Subset 8: {1, 2, 3}

Runtime Complexity: Linear O(2^n * n)
*/