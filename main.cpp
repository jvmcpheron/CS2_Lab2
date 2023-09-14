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
// deleteAndCount should return a list consisting only of the parts of the list starting at curr that does not
// include nodes with data valued numToDelete, in addition, totalDeleted should be set to how many times that
// that value was deleted
// So if curr points to 5 -> 3 -> 2 -> 5 -> 4 -> 5 -> 3 -> 1 and numToDelete is 5 it should return the list
//   3 -> 2 -> 4 -> 3 -> 1
// and totalDeleted would be 3
//

//if null pointer
    if (curr == nullptr) {

        return nullptr;
    }

    //recurssively calling function
    LLData* nextBiggest = findBiggest(curr->getNext());

    //conditional checking if data is bigger than the biggest item so far
    //only starts running after last pointer is found
    if (nextBiggest == nullptr || curr->getData() > nextBiggest->getData()) {
        return curr;

    } else {

        return nextBiggest;

    }
}

LLData *deleteAndCount(LLData *curr, int numToDelete, int& totalDeleted) {
// findBiggest should return a pointer to the node with the biggest integer value in the list starting at curr
// So if curr points to 5 -> 3 -> 2 -> 5 -> 4 -> 5 -> 3 -> 1 the function should return a pointer to one of the
// nodes that has a 5 in it
    
    //checks if pointer is null, if at the end of the list pointer is null so it will return
    if (curr == nullptr) {
        return nullptr;
    }

    //recurssively calls function with next pointer
    LLData* next = deleteAndCount(curr->getNext(), numToDelete, totalDeleted);


    //as recursion returns values, this conditional checks if value should be deleted and updates based on that
    if (curr->getData() == numToDelete) {

        totalDeleted++;

        return next;

    } else {

        curr->setNext(next);

        return curr;
    }
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
    for (int i = 0; i < 50; i++) {
        myList.addItem(RandInRange(1,100));
    }
    myList.showList();

    //code to test functions

    LLData* biggest = findBiggest(myList.getFirst());

    int numToDelete = 51;
    int numOfDeletes = 0;

    myList.setFirst(deleteAndCount(myList.getFirst(), numToDelete, numOfDeletes));
    cout << "List after deleting " << numToDelete << ": ";
    myList.showList();
    cout << "Total deletes: " << numOfDeletes << endl;

    cout << "The biggest number is: " << biggest->getData() <<endl;



    return 0;
}
