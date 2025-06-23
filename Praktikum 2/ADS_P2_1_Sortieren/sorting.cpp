#include "sorting.h"



namespace sorting {

	//************
	// QuickSort *
	//************      

    int medianOfThree(std::vector<int>& arr, int low, int mid, int high) {
        if (arr[low] > arr[mid])
            std::swap(arr[low], arr[mid]);
        if (arr[low] > arr[high])
            std::swap(arr[low], arr[high]);
        if (arr[mid] > arr[high])
            std::swap(arr[mid], arr[high]);
        return mid;
    }

    int partition(std::vector<int>& arr, int low, int high) {
        int mid = low + (high - low) / 2;
        int pivotIndex = medianOfThree(arr, low, mid, high);
        int pivot = arr[pivotIndex];
        
        // Place the pivot at the end to avoid it being moved during partitioning
        std::swap(arr[pivotIndex], arr[high]);

        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

	void QuickSort(vector<int>& arr, int left, int right)
	{
		if (left < right) {
            int pivot = partition(arr, left, right);
            QuickSort(arr, left, pivot - 1);
            QuickSort(arr, pivot + 1, right);
        }
	}


	//************
    // MergeSort *
    //************
    void merge(std::vector<int>& a, std::vector<int>& b, int low, int pivot, int high) {
        int j = pivot + 1;
        int i = low;
        int k = low;

        while (i <= pivot && j <= high) {
            if (a[i] <= a[j]) {
                b[k++] = a[i++];
            } else {
                b[k++] = a[j++];
            }
        }

        while (i <= pivot) {
            b[k++] = a[i++];
        }

        while (j <= high) {
            b[k++] = a[j++];
        }

        for (i = low; i <= high; ++i) {
            a[i] = b[i];
        }
    }

    void MergeSort(std::vector<int>& a, std::vector<int>& b, int low, int high) {
        if (low < high) {
            int pivot = (low + high) / 2;
            MergeSort(a, b, low, pivot);
            MergeSort(a, b, pivot + 1, high);
            merge(a, b, low, pivot, high);
        }
    }

    //************
    // Natural MergeSort *
    //************
    void natMerge(std::vector<int>& a, std::vector<int>& b, int left, int middle, int right) {
        int j = middle + 1;
		int i = left;
        int k = left;

		while (i <= middle && j <= right) {
			if (a[i] <= a[j]) {
				b[k++] = a[i++];
			} else {
				b[k++] = a[j++];
			}
		}

		while (i <= middle) {
			b[k++] = a[i++];
		}

		while (j <= right) {
			b[k++] = a[j++];
		}

		for (i = left; i <= right; ++i) {
			a[i] = b[i];
		}
	}

	void natMergeSort(std::vector<int>& a, std::vector<int>& b) {
		int n = a.size();
		bool sorted;

		while (true) {
			sorted = true;
			int left = 0;

			while (left < n - 1) {
				int middle = left;

                //finding runs
				while (middle < n - 1 && a[middle] <= a[middle + 1]) {
					middle++;
				}
                
                //runs completed
				if (middle == n - 1) {
					break;
				}

				int right = middle + 1;
				while (right < n - 1 && a[right] <= a[right + 1]) {
					right++;
				}

				natMerge(a, b, left, middle, right);
				sorted = false;
				left = right + 1;
			}

			if (sorted) {
				break;
			}
		}
	}

    //************
    // Heapsort  *
    //************
    void heapify(std::vector<int>& a, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && a[left] > a[largest])
            largest = left;
        if (right < n && a[right] > a[largest])
            largest = right;
        if (largest != i) {
            std::swap(a[i], a[largest]);
            heapify(a, n, largest);
        }
    }

    void HeapSort(std::vector<int>& a, int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(a, n, i);
        for (int j = n - 1; j >= 0; j--) {
            std::swap(a[0], a[j]);
            heapify(a, j, 0);
        }
    }

    //************
    // Shellsort *
    //************
    // Hier soll Hibbard implementiert werden
    void ShellSort_2n(std::vector<int>& a, int n) {
        std::vector<int> gaps;
        int h = 1;
        while (h < n) {
            gaps.push_back(h);
            h = 2 * h + 1;
        }

        for (int gapIndex = gaps.size() - 1; gapIndex >= 0; --gapIndex) {
            int gap = gaps[gapIndex];
            for (int i = gap; i < n; i++) {
                int tmp = a[i];
                int j = i;
                while (j >= gap && a[j - gap] > tmp) {
                    a[j] = a[j - gap];
                    j -= gap;
                }
                a[j] = tmp;
            }
        }
    }

    void ShellSort_3n(std::vector<int>& a, int n) {
        std::vector<int> gaps;
        int h = 1;
        while (h < n) {
            gaps.push_back(h);
            h = 3 * h + 1;
        }

        for (int gapIndex = gaps.size() - 1; gapIndex >= 0; --gapIndex) {
            int gap = gaps[gapIndex];
            for (int i = gap; i < n; i++) {
                int tmp = a[i];
                int j = i;
                while (j >= gap && a[j - gap] > tmp) {
                    a[j] = a[j - gap];
                    j -= gap;
                }
                a[j] = tmp;
            }
        }
    }

    void randomizeVector(std::vector<int>& array, int n) {
        array.resize(n);
        for (unsigned int i = 0; i < array.size(); i++) {
            array[i] = rand() % 1000000;
        }
    }

    void insertionSort(std::vector<int>& arr, int left, int right) {
        for (int i = left + 1; i <= right; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= left && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    void hybridSort(std::vector<int>& arr, int n0) { //n0 = 10-20
        if (arr.size() <= n0) {
            // insertion sort for teilfolge <= n0
            insertionSort(arr, 0, arr.size() - 1);
        } else {
            // quicksort for teilfolge > n0
            QuickSort(arr, 0, arr.size() - 1);
        }
    }
}

    