#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
private:
    int *arr;
    int maxSize;
    int heapSize;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int lChild(int i) {
        return (2 * i + 1);
    }

    int rChild(int i) {
        return (2 * i + 2);
    }

public:
    MaxHeap(int totalSize) {
        heapSize = 0;
        maxSize = totalSize;
        arr = new int[totalSize];
    }

    int getMax() {
        return arr[0];
    }

    int curSize() {
        return heapSize;
    }

    void insertKey(int x) {
        if(heapSize == maxSize) {
            cout << "\nCannot insert new key\n";
            return;
        }

        heapSize++;
        int i = heapSize - 1;
        arr[i] = x;

        while(i != 0 && arr[parent(i)] < arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void increaseKey(int i, int newVal) {
        arr[i] = newVal;
        while(i != 0 && arr[parent(i)] < arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    int removeMax() {
        if(heapSize <= 0) {
            return INT_MIN;
        }

        if(heapSize == 1) {
            heapSize--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[heapSize - 1];
        heapSize--;
        MaxHeapify(0);

        return root;
    }

    void deleteKey(int i) {
        increaseKey(i, INT_MAX);
        removeMax();
    }

    void MaxHeapify(int i) {
        int l = lChild(i), r = rChild(i);
        int largest = i;
        if(l < heapSize && arr[l] > arr[i]) {
            largest = l;
        }

        if(r < heapSize && arr[r] > arr[largest]) {
            largest = r;
        }

        if(largest != i) {
            swap(arr[i], arr[largest]);
            MaxHeapify(largest);
        }
    }
};

void MaxHeap::MaxHeapify(int i)
{
    int l = lChild(i);
    int r = rChild(i);
    int largest = i;
    if (l < heapSize && arr[l] > arr[i])
        largest = l;
    if (r < heapSize && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        MaxHeapify(largest);
    }
}