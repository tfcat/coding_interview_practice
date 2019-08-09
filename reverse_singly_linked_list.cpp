#include <stdio.h>
/**
 * Given a singly-linked list, 
 * reverse the list. This can be done iteratively or recursively. 
 * Can you get both solutions?
 */
struct Node {
    int data;
    struct Node *next = nullptr;
};

void add_to_list(Node* current_node, int value) {
	while(current_node->next != nullptr)
		current_node = current_node->next;
	Node* new_node = new Node {value, nullptr};
	current_node->next = new_node;
}

void print_list(Node* current_node) {
	// print head node data
	printf("%i ", current_node->data);
	while(current_node->next != nullptr){
		current_node = current_node->next;
		printf("%i ", current_node->data);
	}
	printf("\n");
}

/**
 * I've never reversed a linked list before,
 * this is me working stuff out manually.
 * -------------------------
 * head = 0x1
 * 0x1      0x2      0x3      0x4
 * [a, 0x2] [b, 0x3] [c, 0x4] [d, nul]
 *
 * head = 0x4
 * 0x1      0x2      0x3      0x4
 * [a, nul] [b, 0x1] [c, 0x2] [d, 0x3]
 *	
 * stored_prev:  0x4
 * current_node: nul
 * stored_next:  nul
 * head = 0x1
 * 0x1        0x2        0x3        0x4
 * [  8, nul] [  4, 0x1] [-14, 0x2] [ 53, 0x3]
 */

Node* reverse_list_iteratively(Node* head_node) {
	Node* current_node = head_node;

	// setup
	Node* stored_prev = current_node;
	current_node = current_node->next;
	
	while(current_node != nullptr) {
		Node* stored_next = current_node->next;
		current_node->next = stored_prev;

		stored_prev = current_node;
		current_node = stored_next;
	}

	head_node->next = nullptr;
	return stored_prev;
}

/**
 * base case:
 * if node.next is null, return node 
 * (this case is true if node is the last node in the list)
 * walks through list backwards
 * -> make current's neighbor point to current.
 * -> make current point to null
 * -> go 1 step up the stack
 * -> current is now previous node
 * 
 *  0x1      0x2      0x3      0x4
 *	[a, 0x2] [b, 0x3] [c, 0x4] [d, nul]
 *
 * stack:
 * [ current: 0x1 current.next: 0x2 ]
 *   [ current: 0x2 current.next: 0x3 ]
 *     [ current: 0x3 current.next: 0x4 ]
 *       [ current: 0x4 current.next: nul] -> 0x4
 *     [set (0x3.next)[0x4].next to 0x3, set 0x3.next to nul] -> 0x4
 *   [head_set (0x2.next)[0x3].next to 0x2, set 0x2.next to nul] -> 0x4
 * [set (0x1.next)[0x2].next to 0x1, set 0x1.next to nul] -> 0x4
 */
Node* reverse_list_recursively(Node* current) {
    if(current->next == nullptr) return current;

    Node* new_head = reverse_list_recursively(current->next);
    current->next->next = current;
    current->next = nullptr;

    return new_head;
}

int main(int argc, char const *argv[]) {
	// setup linked list
	Node* list_head = new Node{8};
	add_to_list(list_head, 4);
	add_to_list(list_head, -14);
	add_to_list(list_head, 53);
	add_to_list(list_head, 47);
	add_to_list(list_head, 28);
	add_to_list(list_head, -324);
	add_to_list(list_head, 7);

	printf("List:\n");
	print_list(list_head);

	// reverse the list iteratively
	list_head = reverse_list_iteratively(list_head);
	printf("Reversed list:\n");
	print_list(list_head);

	// reverse the list recursively
	list_head = reverse_list_recursively(list_head);
	printf("Re-reversed list:\n");
	print_list(list_head);

	return 0;
}
