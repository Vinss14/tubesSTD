#ifndef stack_h
#define stack_h

#include "list.h"

//  ADT Stack
const int NMAX = 1000;
struct action {
    char type;    // 'I' untuk Insert, 'D' untuk Delete
    char data;    // Karakter yang dimasukkan/dihapus
    int position; // Posisi kursor saat aksi terjadi
};
struct Stack {
    action info[NMAX];
    int top;
};

//  Stack primitive
void createStack_Elgacor(Stack &S);
void pop_Elgacor(Stack &S, infotype &P);
void push_Elgacor(Stack &S, infotype P);

void addByCursorWithUndo(list &L, adr_list P, adr_list &cursor, Stack &undoStack);
void delByCursorWithUndo(list &L, adr_list &P, adr_list &cursor, Stack &undoStack);
void undo_Elgacor(Stack &undoStack, Stack &redoStack, list &L, adr_list &cursor);
void redo_Elgacor(Stack &redoStack, Stack &undoStack, list &L, adr_list &cursor);

#endif /* stack_h */
