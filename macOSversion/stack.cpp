#include <stdio.h>
#include "stack.h"
#include "list.h"

void createStack_Elgacor(Stack &S) {
    S.top = -1;
}

void pop_Elgacor(Stack &S, action &P) {
    if (S.top != -1) {
        P = S.info[S.top];
        S.top--;
    }
}

void push_Elgacor(Stack &S, action P) {
    if (S.top != NMAX - 1) {
        S.top++;
        S.info[S.top] = P;
    }
}

void addByCursorWithUndo(list &L, adr_list P, adr_list &cursor, Stack &undoStack) {
    addByCursor(L, P, cursor);
    action A;
    A.type = 'I';
    A.data = P->infoList;
    A.position = 0;
    push_Elgacor(undoStack, A);
}

void delByCursorWithUndo(list &L, adr_list &P, adr_list &cursor, Stack &undoStack) {
    delByCursor(L, P, cursor);
    if (P != nullptr) {
        action A;
        A.type = 'D';
        A.data = P->infoList;
        A.position = 0;
        push_Elgacor(undoStack, A);
    }
}

void undo_Elgacor(Stack &undoStack, Stack &redoStack, list &L, adr_list &cursor) {
    if (undoStack.top != -1) {
        action A;
        pop_Elgacor(undoStack, A);
        push_Elgacor(redoStack, A);
        
        if (A.type == 'I') {
            adr_list temp;
            delByCursor(L, temp, cursor);
            
        } else if (A.type == 'D') {
            adr_list P = createElmList_Elgacor(A.data);
            addByCursor(L, P, cursor);
        }
    }
}

void redo_Elgacor(Stack &redoStack, Stack &undoStack, list &L, adr_list &cursor) {
    if (redoStack.top != -1) {
        action A;
        pop_Elgacor(redoStack, A);
        push_Elgacor(undoStack, A);
        
        if (A.type == 'I') {
            adr_list P = createElmList_Elgacor(A.data);
            addByCursor(L, P, cursor);
            
        } else if (A.type == 'D') {
            adr_list temp;
            delByCursor(L, temp, cursor);
        }
    }
}
