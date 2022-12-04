#include <stdio.h>
#include <stdlib.h>

int getElementByIndex(int index);             // done
void addElementInIndex(int index, int value); // done
void removeElementByIndex(int index);         // done
void push(int value);                         // done
int *resize(int newCapacity);                 // done
void capacity(void);                          // done
void removeFromArray(int value);              // done
void isEmpty(void);                           // done
int pop(void);                                // done
int find(int value);                          // done
void prepend(int value);                      // done
int *dynamicArray;
int length = 0;
int size;
int lastIndex = 0; // not implemented

int main()
{
  int n = 5;
  size = n;
  dynamicArray = malloc(n * sizeof(int));
  push(10);
  push(9);
  push(8);
  push(7);
  push(6);
  prepend(1);

  for (int i = 0; i < size; ++i)
  {
    printf("%d\n", dynamicArray[i]);
  }

  free(dynamicArray);
  return 0;
}

void prepend(int value)
{
  if (!(length < size))
  {
    resize(size * 2);
  }
  int valueToReplace = dynamicArray[1];
  int aux = 0;
  dynamicArray[1] = dynamicArray[0];
  for (int i = 2; i < size; ++i)
  {
    aux = dynamicArray[i];
    dynamicArray[i] = valueToReplace;
    valueToReplace = aux;
  }
  dynamicArray[0] = value;
}

void removeFromArray(int value)
{
  for (int i = 0; i < size; ++i)
    if (dynamicArray[i] == value)
      dynamicArray[i] = 0;
}

int find(int value)
{
  for (int i = 0; i < size; ++i)
  {
    if (dynamicArray[i] == value)
    {
      printf("Value %d found in the position: %d of the array\n", value, i + 1);
      return i;
    }
  }
  printf("Couldn't find the value in the array\n");
  return -1;
}

void push(int value)
{ // FIX me
  if (length < size)
  {
    dynamicArray[length] = value; // this is bad because the last element is not in the index of the length, because you can delete an element before etc.
    ++length;
    printf("pushed: %d\n", value);
    return;
  }
  resize(size * 2);
  dynamicArray[length] = value;
  ++length;
  printf("pushed: %d\n", value);
}

int *resize(int newCapacity)
{
  int oldSize = size;
  int *newArray = malloc(newCapacity * sizeof(int));
  size = newCapacity;
  int j = 0;
  for (int i = 0; i < oldSize; ++i)
    if (dynamicArray[i] != 0)
    {
      newArray[j] = dynamicArray[i];
      ++j;
    }
  for (int i = j; i < size; ++i)
    newArray[i] = 0;
  free(dynamicArray);
  dynamicArray = newArray;
  return newArray;
}

// FIXME, it breaks if you add a 0 to the array
int pop(void)
{
  if (length > 0)
  {
    int element = 0;
    for (int i = size - 1; i >= 0; --i)
      if (dynamicArray[i] != 0)
      {
        element = dynamicArray[length - 1];
        dynamicArray[i] = 0;
        printf("Removed: %d\n", element);
        length -= 1;
        break;
      }
    if (length <= (size / 4))
      resize(size / 2);
    return element;
  }
  printf("No elements in array\n");
  return 0;
}

int getElementByIndex(int index)
{
  if (index > 0 && index <= length)
  {
    printf("Retorned value: %d\n", dynamicArray[index - 1]);
    return dynamicArray[index];
  }
  printf("Index without value!\n");
  return 0;
}

void removeElementByIndex(int index)
{
  if (index > 0 && index <= size)
  {
    printf("Element removed: %d\n", dynamicArray[index - 1]);
    for (int i = index - 1; i < size - 1; ++i)
    {
      dynamicArray[i] = dynamicArray[i + 1];
    }
    return;
  }
  printf("Index out of bounds\n");
}

void capacity(void)
{
  printf("%d capacity left\n", size - length);
}

void isEmpty(void)
{
  if (length > 0)
  {
    printf("Array not empty\n");
    return;
  }
  printf("Array is empty\n");
}

void addElementInIndex(int index, int value)
{
  if (length == size)
    resize(size * 2);
  if (index > 0 && index <= size)
  {
    int valueToReplace = dynamicArray[index - 1];
    dynamicArray[index - 1] = value;

    for (int i = index; i < size; ++i)
    {
      int aux = dynamicArray[i];
      dynamicArray[i] = valueToReplace;
      valueToReplace = aux;
    }
    printf("Added %d in index %d\n", value, index);
    ++length;
    return;
  }
  printf("Index out of bounds\n");
}
