#include "testSorting.h"
#include "sorting.h"
#include "record.h"
#include <iostream>
#include <algorithm>  //sort
#include <cstdlib>

const int size = 5;

void sortRecord (int len) {
  Record* r = new Record[len];
  //for (int i = 0; i < len; ++i) std::cin >> r[i];
  for (int i = 0; i < len; ++i) std::cout << r[i] << std::endl;
  shellSort(r, 0, len-1);
  for (int i = 0; i < len; ++i) std::cout << r[i] << std::endl;
  delete[] r;
}

void sortRecordByIndex (int len) {
  Record* r  = new Record[len];
  int* idx = new int[len];

  for (int i = 0; i < len; ++i) idx[i] = i;
  for (int i = 0; i < len; ++i) std::cout << r[i] << std::endl;
  std::sort(idx, idx+len, IndexSorter<Record>(r));
  for (int i = 0; i < len; ++i) std::cout << idx[i];
  delete[] r;
  delete[] idx;
}

void inPlaceSorting (Item data[], int idx[], int n) {
   
}

//test sorting algorithms with random integers
//measure running time
void testSorting (void) { 
  int test[size]; 
  srand(time(0));
  for (int i = 0; i < size; ++i) test[i] = rand() % 10000;
  for (int i = 0; i < size; ++i) std::cout << test[i] << " ";
  std::cout << std::endl; 
  std::clock_t start = std::clock();
  shellSort(test, 0, size-1);
  std::clock_t end = std::clock() - start;
  std::cout << "Time elapsed: "<< ((static_cast<double>(end-start)/CLOCKS_PER_SEC)/1000) << " ms" << std::endl; 
  for (int i = 0; i < size; ++i) std::cout << test[i] << " ";
  std::cout << std::endl; 
}

//test sorting algorithms in corners case
void testSortingCorners (void) {

  int test[size];
  
  //already ordered
  for (int i = 0; i < size; ++i) test[i] = i;
  for (int i = 0; i < size; ++i) std::cout << test[i] << " ";
  std::cout << std::endl; 
  bubbleSort(test, 0, size-1);
  for (int i = 0; i < size; ++i) std::cout << test[i] << " ";
  std::cout << std::endl; 

  //inversely ordered
  for (int i = 0; i < size; ++i) test[i] = size-i;
  for (int i = 0; i < size; ++i) std::cout << test[i] << " ";
  std::cout << std::endl; 
  bubbleSort(test, 0, size-1);
  for (int i = 0; i < size; ++i) std::cout << test[i] << " ";
  std::cout << std::endl; 

  //same keys
  for (int i = 0; i < size; ++i) test[i] = 10;
  for (int i = 0; i < size; ++i) std::cout << test[i] << " ";
  std::cout << std::endl; 
  bubbleSort(test, 0, size-1);
  for (int i = 0; i < size; ++i) std::cout << test[i] << " ";
  std::cout << std::endl; 
  
  //two keys
  for (int i = 0; i < size; ++i) test[i] = rand() % 2;
  for (int i = 0; i < size; ++i) std::cout << test[i] << " ";
  std::cout << std::endl;
  bubbleSort(test, 0, size-1);
  for (int i = 0; i < size; ++i) std::cout << test[i] << " ";
  std::cout << std::endl; 

  //one element array
  int testOne[1] = {10};
  bubbleSort(testOne, 0, 1);
  for (int i = 0; i < size; ++i) std::cout << test[i] << " ";
  std::cout << std::endl;

}
