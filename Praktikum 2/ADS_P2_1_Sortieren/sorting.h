#ifndef _SORTING_H_
#define _SORTING_H_

#include <vector>
#include <iostream>
#include <string>

using namespace std;

namespace sorting {
  
  //************
  // QuickSort *
  //************
  void QuickSort(vector<int> &arr, int left, int right);

  //************
  // MergeSort *
  //************
  void Merge(vector<int> &a, vector<int> &b,int low, int pivot, int high);
  void MergeSort(vector<int> &a, vector<int> &b, int low, int high);

  //************************
  // Natuerliche Mergesort *
  //************************
  void natMerge(vector<int>& a, vector<int>& b, int low, int pivot, int high);
  void natMergeSort(vector<int> &a, vector<int> &b);

  //************
  // Heapsort  *
  //************
  void HeapSort(vector<int> &a, int n);

  //************
  // Shellsort *
  //************
  void ShellSort_2n(vector<int> &a, int n);
  void ShellSort_3n(vector<int>& a, int n);


  //*******************
  // Helper functions *
  //*******************
  void randomizeVector(vector<int> &array, int n);
  
  int medianOfThree(std::vector<int>& arr, int low, int mid, int high);
  int partition(vector<int>& arr, int low, int high);

  void merge(std::vector<int>& a, std::vector<int>& b, int low, int pivot, int high);
  void natMerge(std::vector<int>& a, std::vector<int>& b, int left, int middle, int right);
  
  void heapify(std::vector<int>& a, int n, int i);

  void insertionSort(std::vector<int>& arr, int left, int right);
  void hybridSort(std::vector<int>& arr, int n0);
 }
#endif 
