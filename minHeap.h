#ifndef MINHEAP_H
#define MINHEAP_H

#include <string>
#include "hashTable.h"

using namespace std;

struct entry{
    int frequency;
    string word;
};

class minHeap{
    public:
        minHeap();
        void minHeapify(int i);
        int parent(int i){return (i-1)/2;}
        int left(int i){return (2*i);}
        int right(int i){return (2*i + 1);}
        void insert();
        void swap(int *x, int *y);
        void increaseF(int i);
        bool isFull(){return heap_size == capacity;}
        string replaceMin(string s);
    private:
        entry *harr;
        int capacity;
        int heap_size;
};
#endif