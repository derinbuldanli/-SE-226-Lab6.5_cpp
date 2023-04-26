#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <cstring>
#include <cmath>

void find_common_elements(int list1[], int list1_size, int list2[], int list2_size, int result[], int& result_size) {
    std::set<int> set1(list1, list1 + list1_size);
    std::set<int> set2(list2, list2 + list2_size);
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), result);
    result_size = std::distance(result, std::find(result, result + std::min(set1.size(), set2.size()), 0));
}

bool is_palindrome(const char* str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

void find_palindromes(const char* str_list[], int str_list_size, const char* result[], int& result_size) {
    int count = 0;
    for (int i = 0; i < str_list_size; i++) {
        if (is_palindrome(str_list[i])) {
            result[count++] = str_list[i];
        }
    }
    result_size = count;
}


void sieve_of_eratosthenes(int num_list[], int num_list_size, int result[], int& result_size) {
    bool* is_prime = new bool[num_list[num_list_size - 1] + 1];
    std::fill_n(is_prime, num_list[num_list_size - 1] + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= sqrt(num_list[num_list_size - 1]); i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= num_list[num_list_size - 1]; j += i) {
                is_prime[j] = false;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < num_list_size; i++) {
        if (is_prime[num_list[i]]) {
            result[count++] = num_list[i];
        }
    }
    result_size = count;
    delete[] is_prime;
}
bool is_anagram(const char* word, const char* str) {
    if (strlen(word) != strlen(str)) {
        return false;
    }
    int freq[26] = { 0 };
    for (size_t i = 0; i < strlen(word); i++) {
        freq[tolower(word[i]) - 'a']++;
        freq[tolower(str[i]) - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            return false;
        }