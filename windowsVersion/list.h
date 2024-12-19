#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
using namespace std;

//  ADT Doubly Linked List
typedef char infotype;
typedef struct elmList *adr_list;
typedef struct list *baris;
struct elmList {
    infotype infoList;
    adr_list nextList;
    adr_list prevList;
};
struct list {
    adr_list firstList;
    adr_list lastList;
    baris prevBaris;
    baris nextBaris;
};

// Doubly Linked List Primitive
void createList_Elgacor(list &L);
adr_list createElmList_Elgacor(infotype data);
void insertFirst_Elgacor(list &L, adr_list P);
void insertLast_Elgacor(list &L, adr_list P);
void insertAfter_Elgacor(list &L, adr_list prec, adr_list P);
void deleteFirst_Elgacor(list &L, adr_list &P);
void deleteLast_Elgacor(list &L, adr_list &P);
void deleteAfter_Elgacor(list &L, adr_list prec, adr_list &P);
void addByCursor(list &L, adr_list P, adr_list &cursor);
void delByCursor(list &L, adr_list &P, adr_list &cursor);
void addBaris(list &currentBaris, list *&newBaris);
void showAllBaris(list &L);
void moveCursorUp(list* &L, adr_list &cursor);
void moveCursorDown(list* &L, adr_list &cursor);
void moveCursorLeft(list &L, adr_list &cursor);
void moveCursorRight(list &L, adr_list &cursor);
void showWithCursor(list &textEditor, list *currentBaris, adr_list cursor);
#endif // LIST_H_INCLUDED
