#include <stdio.h>

struct LinkedList
{
  struct Node *head;
  struct Node *tail;
};

struct Node
{
  struct Node *next;
  struct Node *before;
  int value;
};

int size(struct LinkedList *myLinkedList)
{
  if (!myLinkedList)
    return 0;
  struct Node *current = myLinkedList->head;
  int count = 1;
  while (current->next)
  {
    ++count;
    current = current->next;
  }

  return count;
}

int main()
{
  struct Node head;
  struct LinkedList myLinkedList = {&head, &head};
  struct Node newOne = {NULL, &head, 2};
  head.next = &newOne;
  printf("%d Number of nodes in the linked list", size(&myLinkedList));
  return 0;
}
