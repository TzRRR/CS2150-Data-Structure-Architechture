// Tianze Ren, tr2bx,09/04/2022, List.cpp
#include <iostream>
#include "ListNode.h"
#include "ListItr.h"
using namespace std;

List::List(){
    head = new ListNode();
    tail = new ListNode();
    head->next = tail;
    tail->previous = head;
    count = 0;
}

// Copy constructor
// Called when the code looks something like List list2 = list1;
// (In other words, it is called when you are trying to construct a **new** list from an existing one)
List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;
// Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve()); iter.moveForward();
        
    }
}
// Copy assignment operator // Called when the code looks something like list2 =list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source) {
    if (this == &source) {
// The two are the same list; no need to do anything return *this;
        
    } else {
// Clear out anything this list contained
// before copying over the items from the other list makeEmpty();
// Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

List:: ~List(){
    delete head;
    delete tail;
}
    
bool List:: isEmpty() const{
    if (head->next == tail || tail-> previous == head){
        return true;
    }
    else{
        return false;
    }
}
    
void List:: makeEmpty(){
  ListItr empty = first();
  ListNode* current = new ListNode();
  current = head-> next;
  while (current-> next != NULL){
      current = current-> next;
      delete current-> previous;

    }
    head-> next = tail;
    tail-> previous = head;
}

ListItr List:: first(){
    ListItr* f = new ListItr(head-> next);
    ListItr fc = *f;
    delete f;
    return fc;
    
}

ListItr List:: last(){
    ListItr* l = new ListItr(tail-> previous);
    ListItr lc = *l;
    delete l;
    return lc;
}

void List::insertAfter(int x, ListItr position){
    ListNode* n = new ListNode();
    n-> value = x;
    position.current-> next-> previous = n;
    n-> next = position.current-> next;
    position.current-> next = n;
    n-> previous = position.current;
    count++;
    delete n;
}

void List::insertBefore(int x, ListItr position){
    ListNode* n = new ListNode();
    n-> value = x;
    position.current-> previous-> next = n;
    n-> previous = position.current-> previous;
    position.current-> previous = n;
    n-> next = position.current;
    count++;
    delete n;
}

void List:: insertAtTail(int x){
    ListNode* n = new ListNode();
    n-> value = x;
    n-> next = tail;
    n-> previous = tail-> previous;
    tail-> previous = n;
    tail-> previous-> previous-> next = n;
    count++;
    delete n;
}

ListItr List::find(int x){
    ListItr temp = first();
    while (!temp.isPastEnd()){
        if (temp.current-> value == x){
            return temp;
        }
        temp.moveForward();
    }
    return tail;
    
}

void List::remove(int x){
    ListNode* temp = find(x).current;
    temp-> previous-> next = temp-> next;
    temp-> next-> previous = temp-> previous;
    delete temp;
    count--;
    
}

int List::size() const{
  return count;
}

void printList(List& source, bool forward){
    ListItr printf = ListItr(source.first());
    ListItr printb = ListItr(source.last());
    string outputf = "";
    string outputb = "";
    if (forward == true){
        while (printf.isPastEnd() == false){
            outputf = outputf + to_string(printf.retrieve()) + " ";
            // to_string method learned from stackoverflow
            printf.moveForward();
        }
        cout << outputf << endl;
    }
    else{
      while (printb.isPastBeginning() == false){
	outputb = outputb + to_string(printb.retrieve()) + " ";
	printb.moveBackward();
    }
      cout << outputb << endl;
}
}




