#include <stdio.h>
#include <stdbool.h>

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
  if (!myLinkedList->head)
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

bool empty(struct LinkedList *myLinkedList)
{
  if (!myLinkedList->head)
    return true;
  return false;
}

int value_at(int index){
  return 0;
}

struct Node head;
struct LinkedList myLinkedList = {&head, &head};
struct Node newOne = {NULL, &head, 2};


int main()
{
  head.next = &newOne;  
  printf("%d Number of nodes in the linked list\n", size(&myLinkedList));
  printf(empty(&myLinkedList) ? "Is empty" : "Not empty");
  return 0;
}
