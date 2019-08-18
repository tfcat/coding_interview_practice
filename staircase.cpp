// Asked by LinkedIn:
// You are given a positive integer N which 
// represents the number of steps in a staircase. 
// You can either climb 1 or 2 steps at a time. 
// Write a function that returns the number of unique 
// ways to climb the stairs.

// challenge: solve in linear time.
// unfortunately, this program runs in n² time, i can't
// solve this linearly off the top of my head.

#include <stdio.h>

int factorial(int n) {
	if(n == 1) return 1;
	return n * factorial(n-1);
}

int choose(int n, int r) {
	if(r == 0 or n == 0) return 1;
	// cant lie, had to remind myself what 
	// the equation for "choose" was; C(n,r) = n! / r!(n-r)!
	return factorial(n)/(factorial(r) * factorial(n-r));
}

/* 
Just some quick working out!

6 stairs
2 2 1 1
2 1 2 1
2 1 1 2
1 2 1 2
1 1 2 2
1 2 2 1
6 combinations when there's 2 twos in 4 slots
4c2 = 6

5 stairs
1 1 1 1 1 (5c0 = 1 combinations)
2 1 1 1 (4c1 = 4 combinations)
2 2 1 (3c2 = 3 combinations)
answer = 1 + 4 + 3 = 8

lower bound of length: 5/2 = 2, add 1 if n is odd thus: n/2 + n%2
*/

size_t ways_to_climb_stairs(int number_of_steps) {
	int result = 0;
	int lower_bound = number_of_steps/2 + number_of_steps%2;

	for(int i = number_of_steps; i >= lower_bound; --i)
		result += choose(i, number_of_steps-i);
	
	return result;
}

int main(int argc, char const *argv[])
{
	int n = 5;
	printf("Ways to climb set of %i stairs: %lu\n", n, ways_to_climb_stairs(n));
	return 0;
}