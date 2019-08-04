/*
Given a string containing just the characters 
'(', ')', '{', '}', '[' and ']', 
determine if the input string is valid. 
An input string is valid if:
- Open brackets are closed by the same type of brackets.
- Open brackets are closed in the correct order.
- Note that an empty string is also considered valid.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

// Not a fan of this, but not sure how to 
// make this nicer for the time being.
std::map<char, char> 
closed_to_open_bracket_map = {
  {')', '('},  
  {'}', '{'},
  {']', '['}
};
    
bool balanced(std::string string_to_check) {
    std::vector<char> stack;
    for(char c : string_to_check) {
        // check against ( { [, if so, push onto stack
        if(c == '(' || c == '[' || c == '{') {
               stack.push_back(c);
        }
        if(c == ')' || c == ']' || c == '}') {
            if(stack.size() == 0 || stack.back() != closed_to_open_bracket_map.at(c))
                return false;
            stack.pop_back();
        }
    }
    if(stack.size() != 0) return false;
    return true;
}

int main() {
  printf("%s\n", balanced("({}[](([{}])))") ? "Balanced!" : "Not balanced.");
}
