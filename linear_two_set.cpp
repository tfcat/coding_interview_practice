/*
You are given a list of numbers, and a target number k. 
Return whether or not there are two numbers in the list that add up to k.

Example:
Given [4, 7, 1 , -3, 2] and k = 5, 
return true since 4 + 1 = 5.

Try to do this in only one pass of the list (linear time).
*/

#include <stdio.h>
#include <unordered_set>

bool twosum(int list[], size_t size, int k) {
	std::unordered_set<int> check_set;
	for (int i = 0; i < size; ++i)
	{
		// if in check set
		if(check_set.count(k - list[i]) != 0)
			return true;
		else
			check_set.insert(list[i]);
	}
	return false;
}

int main(int argc, char const *argv[]) {
	printf("hello world\n");
	int array1[] = {4,7,1,-3,2};
	printf("test 1 (1): %i\n", twosum(array1, 5, 5));
	printf("test 2 (0): %i\n", twosum(array1, 5, 12));
	printf("test 3 (1): %i\n", twosum(array1, 5, -2));
	return 0;
}
