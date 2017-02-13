#ifndef SORTING_H
#define SORTING_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

//selection sort implementation
//scan the array through the i index
//at each step the left element of i are ordered
//the minimum element right to i is selected and inserted in i position
template<typename Item> void selectionSort(Item a[], int l, int r) {

  for (int i = l; i < r; i++) {
    int min = i;
    for(int j = i+1; j <= r; j++) {
      if (a[j] < a[min]) min = j;
    }
    Item t = a[i];
    a[i] = a[min];
    a[min] = t;
  }
}

//insertion sort implementation
//scan the array through the i index
//at each step the left element of i are ordered
//the i element is inserted between its left elements in the right place
template<typename Item> void insertionSort(Item a[], int l, int r) {
  //scan the input array
  for (int i = l+1; i <= r; i++) {
    int j = i;
    Item t = a[i];
    //find the place where to insert the current element
    while (t < a[j-1] && j > l) {
      a[j] = a[j-1];   
      j--;
    }
    a[j] = t;
  }
}

//bubble sort implementation
//scan the array through the i index
//at each step the left element of i are ordered
//back-scan the array through the j index
//at each step the j element is swapped with the j-1 if this is bigger 
//the j element is inserted in order in i position
template<typename Item> void bubbleSort(Item a[], int l, int r) {
  int count = 0;
  for (int i = l; i < r; i++) {
    bool ordered;
    for (int j = r; j > i; j--) {
      ordered  = true;
      if (a[j] < a[j-1]) {
	Item t = a[j];
	a[j] = a[j-1];
	a[j-1] = t;
	ordered = false;
	count++;
      }
    }
    if (ordered) {std::cout << i << std::endl; break;}
  }
  std::cout << count << std::endl;
}

//shell sort implementation
//h-order the array for decreasing h
//scan the array through the i index
//at each step the left element of i are h-ordered
//the i element is inserted between its left elements in the right place
template<typename Item> void shellSort(Item a[], int l, int r) {
  int max = 1;
  //initialize the max increment according to the array size
  while (max <= (r-l)/3) max = 3*max+1;
   std::cout << max << std::endl;
   
  //h-ordering the array for decreasing h
  for (int h = max; h >= 1; h=h/3) {
    std::cout << h << std::endl;
     //h-ordering the array for the current h
    for (int i = h; i <= r; i++) {
      Item t = a[i];
      int j = i;
      //find the place of the current element in the h-ordered array
      while (t < a[j-h] && j>=h) {
	a[j] = a[j-h];
	j-=h;
      }
      a[j] = t;
    }
    //for (int i = 0; i <= r; ++i) std::cout << a[i] << " ";
    //std::cout << std::endl; 
  }
}

//return the index of the pivot in the right place
template<typename Item> int partition(Item a[], int l, int r) {
  Item pivot = a[r];
  int i = l-1;
  int j = r;

  while (i < j) {
    while (a[++i] < pivot);
    while (a[--j] > pivot && j >l ); //if(j==l) break;
    if(i < j) {
      Item tmp = a[i];
      a[i] = a[j];
      a[j] = tmp;
    }
  }
  a[r] = a[i];
  a[i] = pivot;
  return i;
}

//quick sort implementation
template<typename Item> void quicksort(Item a[], int l, int r) {
 
  if (l>=r) return;   //end if size <= 1
  int pivot = partition (a, l, r); //put the pivot in the right place and return its index
  quicksort (a, l, pivot-1);
  quicksort (a, pivot+1, r);
}

#include <stack>

//iterative quicksort implementation
template<typename Item> void quicksortIt (Item a[], int l, int r) {
  std::stack<int> bounds;
  int pivot;
  bool pop = false;

  do{
    //pop l and r
    if(pop) {
      r = bounds.top();
      bounds.pop();
      l = bounds.top();
      bounds.pop();
    }

    pivot = partition (a, l, r);
    pop = true;

    //push the bigger subset first
    if ((pivot-l) > (r-pivot)) {
      //stop if r <= l
      if ((pivot-1) > l) {
	bounds.push (l);
	bounds.push (pivot-1);
      }
      //stop if r <= l
      //set l without push into the stack
      if (r > (pivot+1)) {
	l = pivot+1;
	pop = false;
      }  
    }
    else {
      //stop if r <= l
      if (r > (pivot+1)) {
	bounds.push (pivot+1);
	bounds.push (r);
      }
      //stop if r <= l
      //set r without push into the stack
      if ((pivot-1) > l) {
	r = pivot-1;
	pop = false;
      }
    }
  }while (!bounds.empty());
}

//select the pivot as the median of five and put the pivot in r-3
template<typename Item> void medianOfFive (Item a[], int l, int r) {
  Item aux[] = {a[l], a[(l+r)/4], a[(l+r)/2], a[3*(l+r)/4], a[r]};
}

//quicksort implementation improved with median of five
//and not ordering subset with less than 11 elements
template<typename Item> void quicksortImp (Item a[], int l, int r) {

  //stop recursion if size of a is
  //less than minimum subset size
  static const int minSubset = 11;
  if ((r-l) < maxSubset) return;

  
  
}

//quicksort + insertionsort implementation
template<typename Item> void hybridsort (Item a[], int l, int r) {
  quicksortImp(a, l, r);
  insertionsort(a, l, r);
}

//Reorder objects in data based on the order specified in index
//n is the size of both data and idx
template<typename Item> void inPlaceSorting (Item data[], int idx[], int n) {  
  for (int i = 0; i < n; ++i) {
    //Check if the i-th element is not ordered
    if (idx[i] != i) {
      //Save the i-th element
      Item tmp = data[i];
      int k = i;
      //Put the element that should be the k-th in the right position
      //and update idx accordingly
      while (idx[k] != i) {
	int j = k;
	data[k] = data[idx[k]];
	k = idx[j];
	idx[j] = j;
      }
      //Put the i-th element in the right position
      data[k] = tmp;
      idx[k] = k;
    }
  }
}

//Wrapper to implement sorting by index
template <class Item>
class IndexSorter {
  Item* data;
 public:
  IndexSorter (Item* d):data(d) {}
  bool operator() (const int lhs, const int rhs) { return data[lhs] < data[rhs]; }
};



#endif
