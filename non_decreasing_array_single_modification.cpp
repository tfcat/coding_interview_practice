#include <stdio.h>
#include <vector>
/*
You are given an array of integers in an arbitrary order. 
Return whether or not it is possible to make the array
non-decreasing by modifying at most 1 element to any value.

We define an array is non-decreasing 
if array[i] <= array[i + 1] holds 
for every i (1 <= i < n).

Example:

[13, 4, 7] should return true, 
since we can modify 13 to any value 4 or less, 
to make it non-decreasing.

[13, 4, 1] however, should return false, 
since there is no way to modify just one element to make the array non-decreasing.


Challenge: Find a solution that runs in O(n) time.
*/

bool check_nondecreasing(std::vector<int>* data) {
	if(data->size() <= 2) return true;
	bool has_decreased = false;
	for (size_t i = 0; i < data->size() - 1; ++i) {
		if(data->at(i) > data->at(i+1)) {
			if(has_decreased) return false;
			has_decreased = true;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	printf("%i (should be 1)\n", check_nondecreasing(new std::vector<int>{13, 4, 7}));
	printf("%i (should be 0)\n", check_nondecreasing(new std::vector<int>{13, 4, 1}));
	printf("%i (should be 1)\n", check_nondecreasing(new std::vector<int>{1, 5, 7, -3, 58, 510}));
	printf("%i (should be 0)\n", check_nondecreasing(new std::vector<int>{1, 5, 7, -3, 52, 51}));
	return 0;
}