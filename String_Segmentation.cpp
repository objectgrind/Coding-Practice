/*
3/75
You are given a dictionary of words and a large input string.
 You have to find out whether the input string can be completely segmented into the words of a given dictionary. 
 The following two examples elaborate on the problem further.


##########
#Approach
##########

 To address this issue, one can tackle the problem by dividing the extensive string at each conceivable position and verifying whether the string can be entirely segmented into words present in the dictionary.
  The algorithm can be outlined in the following steps:

Let 'n' be the length of the input string.

For 'i' from 0 to n - 1:

Extract the substring 'first_word' from the input string, ranging from index [0, i].
Extract the substring 'second_word' from the input string, ranging from index [i + 1, n - 1].
If 'first_word' exists in the dictionary:
If 'second_word' is in the dictionary or has a zero length, return true.
Recursively call this method with 'second_word' as input and return true if it can be segmented.
However, this algorithm may compute the same substring multiple times, even if it does not exist in the dictionary. To address this redundancy, memoization can be employed. 
By remembering which substrings have already been solved, one can optimize both time and memory complexities.

To implement memoization, store the 'second_word' in a new set during each iteration. This approach significantly reduces both time and memory complexities
*/

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

bool wordBreakHelper(const std::string& s, const std::unordered_set<std::string>& wordDict, std::unordered_map<std::string, bool>& memo) {
    if (s.empty()) {
        return true;
    }

    if (memo.find(s) != memo.end()) {
        return memo[s];
    }

    for (int i = 1; i <= s.length(); ++i) {
        std::string firstWord = s.substr(0, i);
        std::string secondWord = s.substr(i);

        if (wordDict.count(firstWord) > 0 && (wordDict.count(secondWord) > 0 || secondWord.empty())) {
            if (wordBreakHelper(secondWord, wordDict, memo)) {
                memo[s] = true;
                return true;
            }
        }
    }

    memo[s] = false;
    return false;
}

bool wordBreak(const std::string& s, const std::unordered_set<std::string>& wordDict) {
    std::unordered_map<std::string, bool> memo;
    return wordBreakHelper(s, wordDict, memo);
}

int main() {
    std::unordered_set<std::string> wordDict = {"apple", "pen"};

    std::string input1 = "applepenapple";
    std::cout << (wordBreak(input1, wordDict) ? "True" : "False") << std::endl;

    std::string input2 = "catsandog";
    std::cout << (wordBreak(input2, wordDict) ? "True" : "False") << std::endl;

    return 0;
}

/*
complexity -O(n*n)

Output
False
False
*/