/*
A palindrome is a sequence of characters that reads 
the same backwards and forwards. Given a string, s,
find the longest palindromic substring in s.
*/
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

struct Pair {
	int start;
	int end;
};

// banana
std::string longest_palendrome(std::string input) {
	// scan for pairs
	std::vector<Pair*> letter_pair_locations;
	for(int i = 0; i < input.size(); i++) {
		for(int j = i; j < input.size(); j++) {
			if(input[i] == input[j] && i != j)
				letter_pair_locations.push_back(new Pair{i, j});
		}
	}

	// find the palendromic pairs
	std::vector<Pair*> palendromic_pairs;
	for(Pair* pair : letter_pair_locations) {
		// while chars are the same and start/end aren't equal, step closer
		int start = pair->start;
		int end = pair->end;

		while(input[start] == input[end] && start <= end) {
			// you've got a palendrome
			if(start == end || start + 1 == end) {
				palendromic_pairs.push_back(pair);
				break;
			}
			start += 1;
			end -= 1;
		}
	}
	if(palendromic_pairs.size() == 0) return std::string("");

	// find the furthest palendromic pair
	Pair* largest_pair = new Pair {-1, -1};
	for(Pair* pair : palendromic_pairs) {
		if(pair->end - pair->start > largest_pair->end - largest_pair->start)
			largest_pair = pair;
	}

	// build the string from pair and return it
	std::string result(input.begin() + largest_pair->start, input.begin() + largest_pair->end + 1);
	return result;
}

int main() {
	printf("%s\n", longest_palendrome("u know ive got that swagga boi").c_str());
	return 0;
}