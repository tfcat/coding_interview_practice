#include <stdio.h>
#include <vector>
#include <unordered_set>

/*
Asked by Uber:
Given a list of numbers, find if there exists a
pythagorean triplet in that list. A pythagorean 
triplet is 3 variables a, b, c where a^2 + b^2 = c^2
*/

// To save repeating a squaring function, square
// all values held in the array. Remove duplicates
// by putting them in a set. Checking if a set contains
// a value has O(1) time.
// Function as a whole has O((n²+n)/2)
// (better than n², worse than linear.)
bool pythag_triplet_exists(std::vector<int> data) {
  std::unordered_set<int> results;
  for (int value : data) results.insert(value*value);

  for (int val1 : results)
    for (int val2 : results)
      if(results.count(val1 + val2) > 0) return true;

  return false;
}

int main(int argc, char const *argv[]) {
  std::vector<int> data {3, 5, 12, 5, 13};
  printf("triplet exists: %s\n",
    (pythag_triplet_exists(data))?"true":"false");
  return 0;
}