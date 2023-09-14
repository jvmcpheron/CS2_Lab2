#include <iostream>
#include <stdlib.h>
using namespace std;

class LLData {
private:
    int data;
    LLData *next;
    LLData() {}
public:
    LLData(int d, LLData *nxt) {
        data = d;
        next = nxt;
    }
    int getData() { return data; }
    LLData* getNext() { return next; }
    void setData(int d) { data = d; }
    void setNext(LLData* nxt) { next = nxt; }
};
class LinkedList {
private:
    LLData* first;
public:
    LinkedList() { first = NULL; }
    LLData *getFirst() { return first; }
    void setFirst(LLData *fst) { first = fst; }
    bool isEmpty() { return (first == NULL); }
    void addItem(int d) {
        first = new LLData(d,first);
    }
    void showList() {
        LLData *curr = getFirst();
        while (curr != NULL) {
            cout << curr->getData() << " -> ";
            curr = curr->getNext();
        }
        cout << endl;
    }
    void addItemAtEnd(int d) {
        if (first == NULL) {
            first = new LLData(d,first);
        }
        else {
            LLData* curr = first;
            while (curr->getNext() != NULL) {
                curr = curr->getNext();
            }
            curr->setNext(new LLData(d,curr->getNext()));
        }
    }


};

int RandInRange(int low, int high) {
    return (low + rand()%(high - low + 1));
}

// *** Code To Complete ***

LLData *findBiggest(LLData *curr) {
// findBiggest should return a pointer to the node with the biggest integer value in the list starting at curr
// So if curr points to 5 -> 3 -> 2 -> 5 -> 4 -> 5 -> 3 -> 1 the function should return a pointer to one of the
// nodes that has a 5 in it


//IDEA: call function until end of linked list, storing pointer if value is bigger than value at current stored pointer
//if end of linked list, return pointer
}

LLData *deleteAndCount(LLData *curr, int numToDelete, int& totalDeleted) {
// deleteAndCount should return a list consisting only of the parts of the list starting at curr that does not
// include nodes with data valued numToDelete, in addition, totalDeleted should be set to how many times that
// that value was deleted
// So if curr points to 5 -> 3 -> 2 -> 5 -> 4 -> 5 -> 3 -> 1 and numToDelete is 5 it should return the list
//   3 -> 2 -> 4 -> 3 -> 1
// and totalDeleted would be 3
//

//IDEA: call function until end of linked list, storing each data into new linked list unless numToDelete
// if it is num to delete, then add to totalDeleted value.
//if next is empty return, else call function again
}

// *** Code To Complete ***

LinkedList sortList(LinkedList curr) {
    LinkedList newList;
    while (!curr.isEmpty()) {
        LLData* biggest = findBiggest(curr.getFirst());
        int numToDelete = biggest->getData();
        cout << "Number to delete is " << numToDelete << endl;
        int totalDeleted = 0;
        curr.setFirst(deleteAndCount(curr.getFirst(),numToDelete,totalDeleted));
        for (int i = 0; i < totalDeleted; i++) {
            newList.addItem(numToDelete);
        }
    }
    return newList;
}

int main() {
    srand(time(0));
    LinkedList myList;
    for (int i = 0; i < 500; i++) {
        myList.addItem(RandInRange(1,100));
    }
    myList.showList();
    LinkedList newList = sortList(myList);
    newList.showList();
    return 0;
}
