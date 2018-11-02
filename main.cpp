//#include "minHeap.h"
#include "topk.h"
#include <iostream>
#include <stdlib>
#include <fstream>
#include <string>

using namespace std;

int main(){
    topk t = new topk();
    ifstream file("article.txt");
    stringstream buffer;

    buffer << file.rdbuf();
    string s = buffer.str();
    to_lower(s);

    string word;
    stringstream ss(s);
    while(ss >> word){
        topk.insert(word);
    }
    int arg;

    do{
    cout<<"Choose the functions...\n";
    cout<<"1) Print Heap\n";
    cout<<"2) Print Hash Table\n";
    cout<<"3) Insert\n";
    cin>>arg;


    switch(arg){
        case 1:
            topk->heap->print();
            break;
        case 2:
            topk->table->print();
            break;
        case 3:
            string t;
            cout<<"Enter a word to insert: ";
            cin>>t;
            topk.insert(s);
            break;
    }
    }while(arg != 4);    


    return 0;
}