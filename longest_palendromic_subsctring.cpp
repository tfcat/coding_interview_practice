/*
A palindrome is a sequence of characters that reads 
the same backwards and forwards. Given a string, s,
find the longest palindromic substring in s. */
// stats:
// googles: 0
// compiles: 3
// errors:
// missing semicolons (no linter ;-;)
// used input.start() instead of input.begin()
// used . instead of -> on one occasion

#include <stdio.h>
#include <string>
#include <vector>
#include <map>

std::string longest_palendrome(std::string input) {
	// scan for pairs
	std::vector<std::pair<size_t, size_t>> letter_pair_locations;
	for(size_t i = 0; i < input.size(); i++) {
		for(size_t j = i; j < input.size(); j++) {
			if(input[i] == input[j] && i != j)
				letter_pair_locations.emplace_back(i, j);
		}
	}

	// find the palendromic pairs
	std::vector<std::pair<size_t, size_t>*> palendromic_pairs;
	for(auto &pair : letter_pair_locations) {
		// while chars are the same and start/end aren't equal, step closer
		size_t start = pair.first;
		size_t end = pair.second;

		while(input[start] == input[end] && start <= end) {
			// you've got a palendrome
			if(start == end || start + 1 == end) {
				palendromic_pairs.push_back(&pair);
				break;
			}
			start += 1;
			end -= 1;
		}
	}
	if(palendromic_pairs.size() == 0) return std::string("");

	// find the furthest palendromic pair
	std::pair<size_t, size_t> *largest_pair = palendromic_pairs.back();
	for(auto* pair : palendromic_pairs) {
		if(pair->second - pair->first > largest_pair->second - largest_pair->first)
			largest_pair = pair;
	}

	// build the string from pair and return it
	std::string result(input.begin() + largest_pair->first, input.begin() + largest_pair->second + 1);
	return result;
}

int main() {
	printf("%s\n", longest_palendrome("million").c_str());
	return 0;
}
