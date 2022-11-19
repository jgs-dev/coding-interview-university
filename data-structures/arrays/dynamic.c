#include <stdio.h>
#include <stdlib.h>

int getElementByIndex(int index); // done
void addElementInIndex(int index, int value);
void removeElementByIndex(int index); // done
int pop(void); // done
void push(int value); // done
int * twoTimesSizeArray(void); // done
void capacity(void); //done
void isEmpty(void);
int* dynamicArray;
int length = 0;
int size;


int main(){
  int n = 5;
  size = n;
  dynamicArray = (int*) malloc(n * sizeof(int));
  push(10);
  addElementInIndex(2,1);
  push(9);
  push(8);
  push(7);
  push(6);
  // push(5);
  // push(4);
  

  
  for(int i = 0; i < size; ++i){
    printf("%d\n", dynamicArray[i]);
  }
  free(dynamicArray);
  return 0;
}

void push(int value){
  if(length < size){
    dynamicArray[length] = value;
    ++length;
  printf("pushed: %d||value in array: %d||size: %d\n", value, dynamicArray[length-1], size);
    return;
  }
  dynamicArray = twoTimesSizeArray();
  dynamicArray[length] = value;
  ++length;
  printf("pushed: %d||value in array: %d||size: %d\n", value, dynamicArray[length-1], size);
}

int * twoTimesSizeArray(void){
  int oldSize = size;
  int newSize = oldSize * 2;
  size = newSize;
  int* newArray = (int*) malloc(newSize * sizeof(int));
  for(int i = 0; i < oldSize; ++i) {
    newArray[i] = dynamicArray[i];
  }
  free(dynamicArray);
  return newArray;
}

int pop(void){
  if(length > 0){
    int element = dynamicArray[length - 1];
    dynamicArray[length - 1] = 0;
    printf("Removed: %d\n", element);
    length -= 1;
    return element;
  }
  printf("No elements in array\n");
  return 0;
}

int getElementByIndex(int index){
  if(index > 0 && index <= length){
    printf("Retorned value: %d\n", dynamicArray[index - 1]);
    return dynamicArray[index];
  }
  printf("Index without value!\n");
  return 0;
}

void removeElementByIndex(int index){
  if(index > 0 && index <= size){
    printf("Element removed: %d\n", dynamicArray[index - 1]);
    for(int i = index - 1; i < size - 1; ++i){
      dynamicArray[i] = dynamicArray[i+1];
    }
    return;
  }
  printf("Index out of bounds\n");
}

void capacity(void){
  printf("%d capacity left\n", size - length);
}

void isEmpty(void){
  if(length > 0){
    printf("Array not empty\n");
    return;
  }
  printf("Array is empty\n");
}

void addElementInIndex(int index, int value){
  if(length == size) dynamicArray = twoTimesSizeArray();
  if(index > 0 && index <= size){
    int valueToReplace = dynamicArray[index-1];
    dynamicArray[index-1] = value;
    
    for(int i = index; i < size; ++i){
      int aux = dynamicArray[i];
      dynamicArray[i] = valueToReplace;
      valueToReplace = aux;
      // for(int j = 0; j<size; ++j){
      //   printf("%d ", dynamicArray[j]);
      // }
      // printf("\n");
    }
    ++length;
    return;
  }
  printf("Index out of bounds\n");
}
