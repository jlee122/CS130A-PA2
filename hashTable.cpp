#include "hashTable.h"
#include <string>
#include <iostream>

using namespace std;

const int TABLE_SIZE = 15;

hashTable::hashTable(){
    capacity = TABLE_SIZE;
    size = 0;
    table = new hashNode*[capacity];

    for(int i = 0; i < capacity; i++){
        table[i] = NULL;
    }
}

void hashTable::insert(string word){
    int key = hash(word);
    hashNode temp = new hashNode(key, word);
    int hashIndex = key;
    while(table[hashIndex] != NULL){
        hashIndex++;
        hashIndex %= capacity;
    }
    //temp->setKey(hashIndex);
    table[hashIndex] = temp;
}

// void hashTable::updateWord(string old, string s){
//     this->search(old)->setWord(s);
// }

hashNode hashTable::get(string word){
    int hashIndex = hash(word);
    int counter = 0;
    while(table[hashIndex] != NULL){
        counter++;
        if(counter > capacity){
            return NULL;
        }
        if(table[hashIndex]->getWord() == word){
            return table[hashIndex];
        }
        hashIndex++;
        hashIndex %= capacity;
    }
    return NULL;
}

void hashTable::printTable(){
    for(int i = 0; i < capacity; i++){
        if(table[i] != NULL){
            cout<<"Key = " <<i;
            cout<<"  Word = " <<table[i]->getWord();
            cout<<"  Index in MinHeap = "<<table[i]->getHeapLocation()<<endl;
        }
    }
}

int hashTable::hash(string word){
    int hashVal = 0;
    for(char ch : word){
        hashVal = 37*hashVal+ch;
    }
    return hashVal % TABLE_SIZE;
}