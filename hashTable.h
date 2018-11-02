#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>

class hashNode{
    public:
        int key;
        string word;
        int heap_location;

        hashNode(int key, string word){
            this->key = key;
            this->word = word;
        }
        void setHeapLocation(int index){
            this->heap_location = index;
        }
        int getHeapLocation(){
            return heap_location;
        }
        void setKey(int k){this->key = k;}
        void setWord(string s){this->word = s;}
        string getWord(){return word;}
};

class hashTable{
    static const int TABLE_SIZE = 15;

    public:
        hashTable();
        //if get(word) returns -1, inserts the word in the table using linear probing
        int insert(string word);
        //void updateWord(string old, string s);
        int get(string word);
        void printTable();
        int hash(string word);

        //getters
        int getSize(){return size;}

    private:
        int capacity;
        hashNode** table;
        int size;
};

#endif