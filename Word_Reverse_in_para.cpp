/*
4/75
Reverse the order of words in a given sentence (an array of characters).


##########
#Approach
##########
The steps to solve this problem are simpler than they seem:

Reverse the string.
Traverse the string and reverse each word in place.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

void reverseWords(std::string& sentence) {
    // Step 1: Reverse the entire sentence
    std::reverse(sentence.begin(), sentence.end());

    // Step 2: Reverse each word in place
    std::istringstream iss(sentence);
    std::vector<std::string> words(std::istream_iterator<std::string>{iss},
                                   std::istream_iterator<std::string>());

    for (auto& word : words) {
        std::reverse(word.begin(), word.end());
    }

    // Reconstruct the sentence
    std::ostringstream oss;
    std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(oss, " "));
    sentence = oss.str();
}

int main() {
    // Example usage
    std::string inputSentence = "The steps to solve this problem are simpler than they seem";
    
    // Call the function to reverse the order of words
    reverseWords(inputSentence);

    // Output the result
    std::cout << "Reversed Sentence: " << inputSentence << std::endl;

    return 0;
}

/*
complexity -O(n){Linear}

Output
Reversed Sentence: seem they than simpler are problem this solve to steps The 
*/