#include "minHeap.h"

using namespace std;

minHeap::minHeap(){
    heap_size = 0;
    capacity = 16;
    harr = new entry[capacity];
}

void minHeap::minHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l < heap_size && harr[l]->frequency < harr[i]->frequency)
        smallest = l;
    if(r < heap_size && harr[r]->frequency < harr[smallest]->frequency)
        smallest = r;
    if(smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        minHeapify(smallest);
    }
}

void minHeap::insert(){
    if(heap_size == capacity){
        return;
    }
    heap_size++;
    int i = heap_size -1;
    harr[i]->frequency = 1;

    while(i != 0 && harr[parent(i)]->frequency > harr[i]->frequency){
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

void minHeap::swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void minHeap::increaseF(int i){
    harr[i]->frequency++;
    int temp = harr[i];
    minHeapify(i);
}

string minHeap::replaceMin(string s){
    string temp = harr[1]->word;
    harr[1]->word = s;
    return temp;
}
