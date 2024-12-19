#include "list.h"

void createList_Elgacor(list &L) {
    L.firstList = nullptr;
    L.lastList = nullptr;
    L.nextBaris = nullptr;
    L.prevBaris = nullptr;
}

adr_list createElmList_Elgacor(infotype data) {
    adr_list P = new elmList;
    P->infoList = data;
    P->nextList = nullptr;
    P->prevList = nullptr;
    return P;
}

void insertFirst_Elgacor(list &L, adr_list P) {
    if (L.firstList == nullptr && L.lastList == nullptr) {
        L.firstList = P;
        L.lastList = P;
    } else {
        P->nextList = L.firstList;
        P->nextList->prevList = P;
        L.firstList = P;
    }
}

void insertLast_Elgacor(list &L, adr_list P) {
    if (L.firstList == nullptr && L.lastList == nullptr) {
        L.firstList = P;
        L.lastList = P;
    } else {
        P->prevList = L.lastList;
        P->prevList->nextList = P;
        L.lastList = P;
    }
}

void insertAfter_Elgacor(list &l, adr_list prec, adr_list P) {
    P->nextList = prec->nextList;
    P->prevList = prec;
    prec->nextList = P;
    P->nextList->prevList = P;
}

void deleteFirst_Elgacor(list &L, adr_list &P) {
    if (L.firstList == L.lastList) {
        P = L.firstList;
        L.firstList = nullptr;
        L.lastList = nullptr;
    } else if (L.firstList == nullptr && L.lastList == nullptr) {
        P = nullptr;
    } else {
        P = L.firstList;
        L.firstList = P->nextList;
        P->nextList = nullptr;
        L.firstList->prevList = nullptr;
    }
}

void deleteLast_Elgacor(list &L, adr_list &P) {
    if (L.firstList == L.lastList) {
        P = L.lastList;
        L.firstList = nullptr;
        L.lastList = nullptr;
    } else if (L.firstList == nullptr && L.lastList == nullptr) {
        P = nullptr;
    } else {
        P = L.lastList;
        L.lastList = P->prevList;
        P->prevList = nullptr;
        L.lastList->nextList = nullptr;
    }
}

void deleteAfter_Elgacor(list &L, adr_list prec, adr_list &P) {
    P = prec->nextList;
    prec->nextList = P->nextList;
    P->nextList->prevList = prec;
    P->nextList = nullptr;
    P->prevList = nullptr;
}

void addByCursor(list &L, adr_list P, adr_list &cursor) {
    if (cursor == nullptr) {
        insertFirst_Elgacor(L, P);
        cursor = L.firstList;
    } else if (cursor == L.firstList) {
        if (cursor->nextList == nullptr) {
            insertLast_Elgacor(L, P);
            cursor = cursor->nextList;
        } else {
            insertAfter_Elgacor(L, cursor, P);
            cursor = cursor->nextList;
        }
    } else if (cursor->nextList == nullptr) {
        insertLast_Elgacor(L, P);
        cursor = cursor->nextList;
    } else {
        insertAfter_Elgacor(L, cursor, P);
        cursor = cursor->nextList;
    }
}

void delByCursor(list &L, adr_list &P, adr_list &cursor) {
    if (cursor == nullptr) {
        P = nullptr;
    } else if (cursor == L.firstList) {
        if (cursor->nextList == nullptr) {
            deleteLast_Elgacor(L, P);
            cursor = nullptr;
        } else {
            deleteFirst_Elgacor(L, P);
            cursor = L.firstList;
        }
    } else if (cursor == L.lastList) {
        deleteLast_Elgacor(L, P);
        cursor = L.lastList;
    } else {
        adr_list prevCursor = cursor->prevList;
        deleteAfter_Elgacor(L, prevCursor, P);
        cursor = prevCursor;
    }
}

void addBaris(list &currentBaris, list *&newBaris) {
    newBaris = new list;
    createList_Elgacor(*newBaris);

    newBaris->nextBaris = currentBaris.nextBaris;
    newBaris->prevBaris = &currentBaris;

    if (currentBaris.nextBaris != nullptr) {
        currentBaris.nextBaris->prevBaris = newBaris;
    }

    currentBaris.nextBaris = newBaris;
}

void showAllBaris(list &L) {
    list *currentBaris = &L;
    int barisNum = 1;
    while (currentBaris != nullptr) {
        cout << "Baris " << barisNum << ": ";
        adr_list current = currentBaris->firstList;
        while (current != nullptr) {
            cout << current->infoList;
            current = current->nextList;
        }
        cout << endl;
        currentBaris = currentBaris->nextBaris;
        barisNum++;
    }
}

void moveCursorUp(list* &currentBaris, adr_list &cursor) {
    if (currentBaris->prevBaris != nullptr) {
        currentBaris = currentBaris->prevBaris;
        cursor = currentBaris->lastList;
    }
}

void moveCursorDown(list* &currentBaris, adr_list &cursor) {
    if (currentBaris->nextBaris != nullptr) {
        currentBaris = currentBaris->nextBaris;
        cursor = currentBaris->lastList;
    }
}

void moveCursorLeft(list &L, adr_list &cursor) {
    if (cursor->prevList != nullptr) {
        cursor = cursor->prevList;
    }
}

void moveCursorRight(list &L, adr_list &cursor) {
    if (cursor->nextList != nullptr) {
        cursor = cursor->nextList;
    }
}

void showWithCursor(list &textEditor, list *currentBaris, adr_list cursor) {
    system("cls");

    cout << "Selamat Datang! Ini adalah text editor El Gacor" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Tekan '.' untuk keluar | Gunakan panah untuk navigasi" << endl;
    cout << endl;

    list *tempBaris = &textEditor;
    int barisNum = 1;

    while (tempBaris != nullptr) {
        cout << "Baris " << barisNum << ": ";

        adr_list tempList = tempBaris->firstList;

        while (tempList != nullptr) {
            if (tempBaris == currentBaris && tempList == cursor) {
                cout << "[" << tempList->infoList << "]";
            } else {
                cout << tempList->infoList;
            }
            tempList = tempList->nextList;
        }

        if (tempBaris == currentBaris && cursor == nullptr) {
            cout << "[_]";
        }

        cout << endl;
        tempBaris = tempBaris->nextBaris;
        barisNum++;
    }
}
