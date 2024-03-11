// Tianze Ren, tr2bx, ListItr.cpp, 09/04/2022
#include "List.h"
using namespace std;

ListItr:: ListItr(){
    current = NULL;
}

ListItr:: ListItr(ListNode* theNode){
    current = theNode;
}

bool ListItr:: isPastEnd() const{
    if (current->next == NULL){
        return true;
    }
    else{
        return false;
    }
}

bool ListItr:: isPastBeginning() const{
    if (current -> previous == NULL){
        return true;
    }
    else{
        return false;
    }
}

void ListItr:: moveForward(){
    if (isPastEnd() == false){
        current = current->next;
    }
}

void ListItr:: moveBackward(){
    if (isPastBeginning() == false){
        current = current-> previous;
    }
}

int ListItr:: retrieve() const{
    return current-> value;
}


