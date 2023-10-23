/*
9/75

Check if strings are rotations of each other or not
Given two strings s1 and s2. The task is to check if s2 is a rotated version of the string s1. 
The characters in the strings are in lowercase.
##########
#Approach
##########
function areRotations that takes two strings as input and checks if one is a rotation of the other.
The main function takes user input for two strings and calls the areRotations function to determine if they are rotations of each other.
*/
#include <iostream>
#include <string>

bool areRotations(std::string s1, std::string s2) {
    // Check if lengths of both strings are the same
    if (s1.length() != s2.length()) {
        return false;
    }

    // Concatenate s1 with itself
    std::string temp = s1 + s1;

    // Check if s2 is a substring of temp
    if (temp.find(s2) != std::string::npos) {
        return true;
    }

    return false;
}

int main() {
    std::string s1, s2;
    std::cout << "Enter the first string: ";
    std::cin >> s1;
    std::cout << "Enter the second string: ";
    std::cin >> s2;

    if (areRotations(s1, s2)) {
        std::cout << s2 << " is a rotation of " << s1 << std::endl;
    } else {
        std::cout << s2 << " is not a rotation of " << s1 << std::endl;
    }

    return 0;
}


/*

output :
Enter the first string: anshuman
Enter the second string: anshuman
anshuman is a rotation of anshuman

Runtime Complexity: Linear O(n)
*/