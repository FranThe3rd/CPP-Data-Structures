#include <algorithm>
#include <string>
#include <iostream>
/* Basically this is just a memory refresher, and stuff that I should know
 * by heart, but C++ syntax is so autistic so sometimes I forget to do basic shit.
 * So these are just easy and common questions I should be able to do easily without
 * any issue.
 */



/*1. Reverse String*/

std::string reverseString(std::string s) {
    std::string result;
    for (int i = s.length()-1; i >= 0; i--) {
        result.push_back(s[i]);
    }
    return result;
}

/*2. Remove The Letter E and A From Word */

std::string removeEA(std::string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'e' || s[i] == 'a') {
            s.erase(i,1);
            i--;
        }
    }
    return s;
}








int main() {
    // 1. Reverse String
    std::string word = "cheeseburger";
    std::string reversedWord = reverseString(word);
    std::cout << "Original: " << word << '\n';
    std::cout << "Reversed String: "  << reversedWord << '\n';
    std::cout << '\n';
    // 2. Remove The Letter E and A From Word
    std::string word2 = "Skibidi toilet rizz, I am going to eat ur booty cheeks";
    std::cout << "Original: " << word2 << '\n';
    std::string removedLetterWord = removeEA(word2);
    std::cout << "Remove letter e and a: " << removedLetterWord << '\n';

}