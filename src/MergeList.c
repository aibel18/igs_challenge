#include "MergeList.h"

#include <stdio.h>
#include <stdlib.h>

ListNode* createList(int array[], int size) {

	if (size == 0)
		return NULL;

	ListNode* init = NULL;
	init = malloc(sizeof(ListNode*));
	init->data = array[0];

	ListNode* prev = init;

	for (int i = 1; i < size; i++) {
		prev->next = malloc(sizeof(ListNode*));
		prev->next->data = array[i];

		prev = prev->next;
	}
	return init;
}

void printList(ListNode* list) {
	ListNode* current = list;

	printf("[");
	while (current) {
		printf("%i ", current->data);
		current = current->next;
	}
	printf("]\n");
}

void deleteList(ListNode* list) {
	ListNode* current = list;
	ListNode* deletedNode = NULL;

	while (current) {
		deletedNode = current;
		current = current->next;

		free(deletedNode);
	}
}

struct ListNode* mergeTwoList(struct ListNode* list1, struct ListNode* list2) {
	return 0;
}

int main() {

	int array[] = {1, 1, 3, 3, 6, 8, 8, 9};
	int size = sizeof(array) / sizeof(int);

	ListNode* list = createList(array, size);

	printList(list);

	deleteList(list);

	return 0;
}