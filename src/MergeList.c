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

ListNode* mergeTwoList(ListNode* list1, ListNode* list2) {
	ListNode* result = NULL;

	// base cases
	if (list1 == NULL)
		return (list2);
	else if (list2 == NULL)
		return (list1);

	// pick either list1 or list2
	if (list1->data <= list2->data) {
		result = list1;
		result->next = mergeTwoList(list1->next, list2);
	} else {
		result = list2;
		result->next = mergeTwoList(list1, list2->next);
	}
	return result;
}

ListNode* mergeKLists(ListNode** lists, int listsSize) {

	ListNode* list1 = lists[0];

	for (int i = 1; i < listsSize; i++) {

		mergeTwoList(list1, lists[i]);
	}

	return list1;
}

int main() {

	int a1[] = {1, 3, 8};
	int a2[] = {1, 3, 6};
	int a3[] = {8, 9};

	ListNode* lists[3];

	lists[0] = createList(a1, sizeof(a1) / sizeof(int));
	lists[1] = createList(a2, sizeof(a2) / sizeof(int));
	lists[2] = createList(a3, sizeof(a3) / sizeof(int));

	ListNode* rpta = mergeKLists(lists, 3);

	printList(rpta);

	deleteList(rpta);

	return 0;
}