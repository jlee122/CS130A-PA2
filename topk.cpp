#include "topk.h"
#include <string>

using namespace std;

topk::topk(){
    table = new hashTable();
    heap = new minHeap();
}

void topk::insert(string s){
    if(table.get(s) == NULL){
        if(heap.isFull()){
            string old = heap.replaceMin(s);
            int hashVal = table->hash(s);
            hashNode newNode = new hashNode(hashVal, word);
            newNode->setHeapLocation(1);
            table->get(old) = newNode;
            //table->update_string(old, s);
        }else{
            heap->insert(s);
            table->insert(s);
            update();
        }
    }else{
        hashNode h = table->get(s);
        int i = h->heap_location;
        heap->increaseF(i);
        update();
    }
}

void topk::update(){
    for(int i = 1; i < heap->getSize(); i++){
        string w = heap[i]->word;
        table->get(w)->setHeapLocation(i);
    }
}
