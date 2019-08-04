/* Given a sorted array, A, with possibly duplicated elements, 
find the indices of the first and last occurrences of a target 
element, x. Return -1 if the target is not found. */

#include <iostream>
#include <string>
#include <vector>

struct Range {
  int start = -1;
  int end = -1;
};

Range find_target_range(std::vector<int> array, int target) {
    Range result;
    bool tracking = false;
    for(unsigned int i = 0; i < array.size(); i++) {
        if(!tracking && array[i] == target) {
            result.start = i;
            tracking = true;   
        }
        if((tracking && array[i] != target) || i == array.size() -1) {
            result.end = i - 1;
            tracking = false;   
        }
    }
    return result;
}

int main() {
  std::vector<int> A { 1,3,3,5,7,8,9,9,9,15 };
  Range result = find_target_range(A, 9);
  printf("%i %i", result.start, result.end);
}
