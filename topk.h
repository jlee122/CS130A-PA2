#ifndef TOPK_H
#define TOPK_H

#include "hashTable.h"
#include "minHeap.h"
#include <string>

using namespace std;

class topk{
    public:
        topk();
        void insert(string s);
        void update();

    private:
        hashTable table;
        minHeap heap;
};
#endif