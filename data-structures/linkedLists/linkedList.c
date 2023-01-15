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

struct LinkedList myLinkedList = {NULL, NULL};

int size();
bool empty();
int value_at(int index);
void push_front(int value);
void print();

int main()
{
  struct Node head = {NULL, NULL, 1};
  myLinkedList.head = &head;
  myLinkedList.tail = &head;
  struct Node newOne = {NULL, &head, 2};
  head.next = &newOne;

  printf("%d Number of nodes in the linked list\n", size());
  printf(empty() ? "Is empty\n" : "Not empty\n");
  printf("%d is the value at index 0\n", value_at(1));
  push_front(5);
  print();

  return 0;
}
int size()
{
  if (!myLinkedList.head)
    return 0;
  struct Node *current = myLinkedList.head;
  int count = 1;
  while (current->next)
  {
    ++count;
    current = current->next;
  }

  return count;
}

bool empty()
{
  if (!myLinkedList.head)
    return true;
  return false;
}

int value_at(int index)
{
  if (0 == index)
    return myLinkedList.head->value;
  int counter = 0;
  struct Node *current = myLinkedList.head;
  while (current->next && counter < index)
  {
    current = current->next;
    ++counter;
  }

  return current->value;
}

void push_front(int value)
{
  struct Node newNode = {myLinkedList.head, NULL, value};
  myLinkedList.head->before = &newNode;
  myLinkedList.head = &newNode;
}

void print()
{
  struct Node *current = myLinkedList.head;
  while (current->next)
  {
    current = current->next;
    printf("Node value: %d\n", current->before->value);
  }
  printf("Node value: %d\n", current->value);
  return;
}
