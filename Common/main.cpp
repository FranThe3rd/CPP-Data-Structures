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


/* 2. Count Words
Example:
"hello world again" -> 3
*/
int countWords(std::string s) {
    int count = 0;
    bool inWord = false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ' && !inWord) {
            count ++;
            inWord = true;
        }
        else if (s[i] == ' ') {
            inWord = false;
        }
    }
    return count;
}


/* 3. Longest Word
Example:
"I love programming" -> "programming"
*/
std::string longestWord(std::string s) {
    std::string word;
    std::string longest;

    for (int i = 0; i < s.length(); i++) {
        if (i < s.length() && s[i] != ' ') {
            word.push_back(s[i]);
        }
        else {
            if (word.length() > longest.length()) {
                longest = word;
            }
            word.clear();
        }
    }
    return longest;

}


/* 4. Shortest Word
Example:
"I love programming" -> "I"
*/
std::string shortestWord(std::string s) {

    std::string word;
    std::string shortest;

    for (int i = 0; i < s.length(); i++) {
        if (i < s.length() && s[i] != ' ') {
            word.push_back(s[i]);
        }
        else {
            if (word.length() < shortest.length()) {
                shortest = word;
            }
            word.clear();
        }
    }
    return shortest;
}


/* 5. Remove Consecutive Duplicate Characters
Example:
"aaabbccdaa" -> "abcda"
*/
std::string removeConsecutiveDuplicates(std::string s) {

}


/* 6. Compress String
Example:
"aaabbcccc" -> "a3b2c4"
*/
std::string compressString(std::string s) {

}


/* 7. Expand Compressed String
Example:
"a3b2c4" -> "aaabbcccc"

Assume counts are single digits.
*/
std::string expandString(std::string s) {

}


/* 8. Check Anagram
Example:
"listen", "silent" -> true
"hello", "world" -> false
*/
bool isAnagram(std::string a, std::string b) {

}


/* 9. First Non-Repeating Character
Example:
"swiss" -> 'w'

Return '\0' if none exists.
*/
char firstUniqueCharacter(std::string s) {

}


/* 10. First Repeating Character
Example:
"abcdefca" -> 'c'
*/
char firstRepeatingCharacter(std::string s) {

}


/* 11. Character With Highest Frequency
Example:
"mississippi" -> 'i'

Assume there is one clear answer.
*/
char mostFrequentCharacter(std::string s) {

}


/* 12. Character With Lowest Frequency
Example:
"aabbcddd" -> 'c'
*/
char leastFrequentCharacter(std::string s) {

}


/* 13. Remove Duplicate Words
Example:
"cat dog cat bird dog" -> "cat dog bird"
*/
std::string removeDuplicateWords(std::string s) {

}


/* 14. Reverse Word Order
Example:
"I love C++" -> "C++ love I"
*/
std::string reverseWordOrder(std::string s) {

}


/* 15. Capitalize Every Word
Example:
"hello world again" -> "Hello World Again"
*/
std::string capitalizeWords(std::string s) {

}


/* 16. Find Longest Repeated Character Streak
Example:
"aaabbccccdd" -> 4
*/
int longestStreak(std::string s) {

}


/* 17. Return Character With Longest Streak
Example:
"aaabbccccdd" -> 'c'
*/
char longestStreakCharacter(std::string s) {

}


/* 18. Count Substring Occurrences
Example:
countSubstring("abababa", "aba") -> 3

Overlapping matches count.
*/
int countSubstring(std::string s, std::string target) {

}


/* 19. Remove All Occurrences of a Substring
Example:
removeSubstring("catdogcatdog", "cat")
-> "dogdog"
*/
std::string removeSubstring(std::string s, std::string target) {

}


/* 20. Replace All Occurrences of a Word
Example:
replaceWord("I like cats and cats", "cats", "dogs")
-> "I like dogs and dogs"
*/
std::string replaceWord(
    std::string s,
    std::string oldWord,
    std::string newWord
) {

}


/* 21. Check Rotation
Example:
"waterbottle", "erbottlewat" -> true

Hint:
Think about:
a + a
*/
bool isRotation(std::string a, std::string b) {

}


/* 22. Move All Digits to the End
Example:
"a1b2c3" -> "abc123"
*/
std::string moveDigitsToEnd(std::string s) {

}


/* 23. Separate Letters and Numbers
Example:
"ab12cd34" -> "abcd1234"
*/
std::string separateLettersNumbers(std::string s) {

}


/* 24. Remove Characters From Another String
Example:
removeCharacters("hello world", "lo")
-> "he wrd"
*/
std::string removeCharacters(
    std::string s,
    std::string remove
) {

}


/* 25. Find Longest Palindromic Word
Example:
"hello racecar level dog"
-> "racecar"
*/
std::string longestPalindromeWord(std::string s) {

}


/* 26. Check If Two Strings Differ By One Character
Example:
"cat", "bat" -> true
"cat", "dog" -> false
"cat", "cats" -> false
*/
bool differsByOne(std::string a, std::string b) {

}


/* 27. Find Common Characters
Return each common character only once.

Example:
"hello", "world" -> "lo"
*/
std::string commonCharacters(
    std::string a,
    std::string b
) {

}


/* 28. Find Longest Common Prefix
Example:
"flower", "flow" -> "flow"
"computer", "compact" -> "com"
*/
std::string commonPrefix(
    std::string a,
    std::string b
) {

}


/* 29. Valid Parentheses
Example:
"(()())" -> true
"(()" -> false
")(" -> false

Only '(' and ')' are included.
*/
bool validParentheses(std::string s) {

}


/* 30. Basic Run-Length Decoder
Example:
"3a2b4c" -> "aaabbcccc"

Unlike #7, the number comes BEFORE
the character.

BONUS:
Make it support numbers larger than 9.

"12a" -> "aaaaaaaaaaaa"
*/
std::string decodeString(std::string s) {

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
    std::cout << '\n';
    // 3. Count how many words in a string
    std::string sentence1 = "Hello my name is barry allen and I am the fastest man alive";
    std::cout << "Sentence: " << sentence1 << '\n';
    int countingWordResult = countWords(sentence1);
    std::cout << "How many words: " << countingWordResult << '\n';
    std::cout << '\n';

    // 4. Return the longest word
    std::string sentence2 = "Cheeseburger AMERICA, I AM BARRY ALLEN Francisco Figueroa";
    std::cout << "Sentence: " << sentence2 << '\n';
    std::string longestWordResult = longestWord(sentence2);
    std::cout << "Longest Word: " << longestWordResult<< '\n';
    std::cout << '\n';

    // 5. Return the shortest word
    std::cout << "Sentence: " << sentence2 << '\n';
    std::string shortestWordResult = shortestWord(sentence2);
    std::cout << "Shortest Word: " << shortestWordResult<< '\n';
    std::cout << '\n';





}