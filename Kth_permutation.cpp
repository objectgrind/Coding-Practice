/*
5/75

Given a set of ‘n’ elements, find their Kth permutation. Consider the following set of elements:

##########
#Approach
##########
Here is an algorithm that we will follow:

1. If the input vector is empty, return the result vector.

2. Calculate the block size as (n-1)! (where 'n' is the size of the vector).

3. Determine the block in which element k will lie and select the first element of that block (can be obtained by (k-1)/block_size).

4. Append the selected element to the result vector and remove it from the original input vector.

5. Update k by subtracting the contribution of the selected element: k = k - selected * block_size.

6. Repeat steps 3-5 until the input vector is empty.

This algorithm is designed to handle certain operations on a vector based on block calculations. 
It does so by iteratively selecting elements from the original vector and appending them to a result vector while adjusting the value of k in the process.

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// Function to find the Kth permutation
std::vector<int> findKthPermutation(int n, int k) {
    std::vector<int> result;
    std::vector<int> elements(n);

    // Initialize the elements vector with values 1 to n
    std::iota(elements.begin(), elements.end(), 1);

    // Calculate the block size
    int blockSize = 1;
    for (int i = 2; i <= n - 1; ++i) {
        blockSize *= i;
    }

    k--; // Adjust k to be 0-based

    // Iterate through the elements
    while (!elements.empty()) {
        // Determine the block in which element k will lie
        int selectedBlock = k / blockSize;
        
        // Select the first element of the block
        int selectedElement = elements[selectedBlock];

        // Append selected element to the result vector
        result.push_back(selectedElement);

        // Remove the selected element from the original vector
        elements.erase(elements.begin() + selectedBlock);

        // Update k by subtracting the contribution of the selected element
        k = k % blockSize;

        // Update the block size for the next iteration
        if (!elements.empty()) {
            blockSize /= elements.size();
        }
    }

    return result;
}

int main() {
    int n, k;

    // Input the size of the set and the desired Kth permutation
    std::cout << "Enter the size of the set (n): ";
    std::cin >> n;

    std::cout << "Enter the value of K for the Kth permutation: ";
    std::cin >> k;

    // Find and print the Kth permutation
    std::vector<int> kthPermutation = findKthPermutation(n, k);

    std::cout << "Kth Permutation: ";
    for (int element : kthPermutation) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}



/*

output :
Enter the size of the set (n): 9
Enter the value of K for the Kth permutation: 10
Kth Permutation: 1 2 3 4 5 7 8 9 6 

Runtime Complexity: Linear O(n)
*/