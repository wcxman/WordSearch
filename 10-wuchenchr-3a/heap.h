#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class heap
{
private:
    vector<T> heapArray;

    // parents functions
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

public:
    // Get item at n
    T getItem(int n) {
        if (n < 0 || n >= heapArray.size()) {
            throw out_of_range("Heap index out of range");
        }
        return heapArray[n];
    }

    // Max heap functions
    void maxHeapify(int i, int heapSize);
    void buildMaxHeap();
    
    // Heapsort function
    void heapsort();

    // Additional utility functions
    void initializeMaxHeap(const vector<T>& input);
    vector<T> getSortedArray();
};

// Maxheapify implementation
template <typename T>
void heap<T>::maxHeapify(int i, int heapSize) {
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < heapSize && heapArray[l] > heapArray[i]) {
        largest = l;
    }

    if (r < heapSize && heapArray[r] > heapArray[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(heapArray[i], heapArray[largest]);
        maxHeapify(largest, heapSize);
    }
}

// maxheap implementation
template <typename T>
void heap<T>::buildMaxHeap() {
    int heapSize = heapArray.size();
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        maxHeapify(i, heapSize);
    }
}

// Heapsort implementation
template <typename T>
void heap<T>::heapsort() {
    buildMaxHeap();
    int heapSize = heapArray.size();
    
    for (int i = heapSize - 1; i >= 1; i--) {
        swap(heapArray[0], heapArray[i]);
        heapSize--;
        maxHeapify(0, heapSize);
    }
}

// Initialize heap with input array
template <typename T>
void heap<T>::initializeMaxHeap(const vector<T>& input) {
    heapArray = input;
}

// Get sorted array after heapsort
template <typename T>
vector<T> heap<T>::getSortedArray() {
    return heapArray;
}

#endif
