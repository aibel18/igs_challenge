#ifndef MERGE_LIST_H
#define MERGE_LIST_H

#define NULL 0

struct ListNode {
	int data;
	struct ListNode* next;
};

typedef struct ListNode ListNode;

ListNode* createList(int array[], int size);

void deleteList(ListNode* list);

void printList(ListNode* list);

ListNode* mergeTwoList(ListNode* list1, ListNode* list2);

ListNode* mergeKLists(ListNode** listas, int listasSize);

#endif
