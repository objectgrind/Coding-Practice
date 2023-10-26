/*
11/75

Place a set of integers into N arrays such that the sum of the medians of all the arrays is maximized.##########
#Approach
##########

To maximize the sum of the medians, you want to distribute the integers in a way that concentrates the larger values in the middle of each array. 
One approach could be to sort the integers and then distribute them in a zigzag pattern among the N arrays.
This way, each array will have a relatively large median.
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximizeMedianSum(vector<int>& nums, int N) {
    sort(nums.begin(), nums.end());

    int sum = 0;
    int start = 0;
    int end = nums.size() - 1;

    while (start <= end) {
        for (int i = 0; i < N; ++i) {
            if (start <= end) {
                sum += nums[end];
                --end;
            }
        }

        for (int i = 0; i < N - 2; ++i) {
            if (start <= end) {
                ++start;
            }
        }
    }

    return sum;
}

int main() {
    // Example usage
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int N = 3;  // Number of arrays

    int result = maximizeMedianSum(nums, N);

    cout << "Maximized sum of medians: " << result << endl;

    return 0;
}




/*

output :
Maximized sum of medians: 52


Runtime Complexity: Linear O(nlogn)
*/