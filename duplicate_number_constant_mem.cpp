/*
 * Given a list of numbers, where every number
 * shows up twice except for one number, find that one number.
 *
 * Do this using O(1) (constant) memory.
 */

#include <stdio.h>
#include <vector>

int single_number(std::vector<int> &ints) {
    for(int i = 0; i < ints.size(); i++) {
        bool repeated = false;
        /* Check every number against every other number.
         * Not very CPU efficient, but very memory efficient! */
        for(int j = 0; j < ints.size(); j++) {
            if(ints[i] == ints[j] && i != j) {
                repeated = true;
                break;
            }
        }

        if(repeated == false) return ints[i];
    }
    return -1;
}

int main()
{
    auto data = std::vector<int>{4, 3, 2, 4, 1, 3, 2};
    printf("result: %i\n", single_number(data));
    return 0;
}
