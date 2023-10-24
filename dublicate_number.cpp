/*
10/75

How do you find all duplicate numbers in an array if it contains multiple duplicates?
##########
#Approach
##########

Use two nested loops to compare each element with every other element in the array.
If a duplicate is found, print it and break out of the inner loop to avoid duplicate printing.
*/


#include <iostream>

int main() {
    const int size = 10; // Change this to the size of your array
    int arr[size] = {2, 4, 6, 8, 2, 9, 6, 8, 1, 3}; // Your array

    std::cout << "Duplicate numbers: ";

    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] == arr[j]) {
                std::cout << arr[i] << " ";
                break; // To avoid printing the same duplicate multiple times
            }
        }
    }

    return 0;
}



/*

output :
Duplicate numbers: 2 6 8 

Runtime Complexity: Linear O(n^2)
*/