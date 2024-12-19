#include <iostream>
#include <termios.h>
#include <unistd.h>
#include "list.h"
#include "stack.h"

char getch() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);          // Simpan pengaturan terminal lama
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);        // Nonaktifkan mode kanonikal dan echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Terapkan pengaturan baru
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Pulihkan pengaturan terminal lama
    return ch;
}

int main() {
    list textEditor;
    createList_Elgacor(textEditor);
    list *currentBaris = &textEditor;
    adr_list cursor = nullptr;
    
    Stack undoStack, redoStack;
    createStack_Elgacor(undoStack);
    createStack_Elgacor(redoStack);
    
    showWithCursor(textEditor, currentBaris, cursor);
    
    while (true) {
        char input = getch(); // getch untuk membaca input per karakter
        
        if (input == '.') { // karakter '.' untuk menyelesaikan program
            break;
            
        } else if (input == '\r' || input == '\n') { // ENTER
            list *newBaris = nullptr;
            addBaris(*currentBaris, newBaris);
            currentBaris = currentBaris->nextBaris;
            cursor = nullptr;
            
        } else if (input == 8 || input == 127) { // Backspace
            adr_list P = nullptr;
            delByCursorWithUndo(*currentBaris, P, cursor, undoStack);
            
        } else if (input == 27 || input == 0 || input == -32) { // Escape sequence Mac/Linux
            input = getch(); // Baca karakter berikutnya
            
            if (input == '[') {
                input = getch(); // Baca karakter setelah '['
                if (input == 'A' || input == 72) { // Arrow Up
                    moveCursorUp(currentBaris, cursor);
                } else if (input == 'B' || input == 80) { // Arrow Down
                    moveCursorDown(currentBaris, cursor);
                } else if (input == 'C' || input == 77) { // Arrow Right
                    moveCursorRight(*currentBaris, cursor);
                } else if (input == 'D' || input == 75) { // Arrow Left
                    moveCursorLeft(*currentBaris, cursor);
                }
            }
            
        } else if (input == '>') { // REDO
            redo_Elgacor(redoStack, undoStack, *currentBaris, cursor);
            
        } else if (input == '<') { // UNDO
            undo_Elgacor(undoStack, redoStack, *currentBaris, cursor);
            
        } else { // Input biasa
            adr_list P = createElmList_Elgacor(input);
            addByCursorWithUndo(*currentBaris, P, cursor, undoStack);
        }
        showWithCursor(textEditor, currentBaris, cursor);
    }
    cout << endl;
    showAllBaris(textEditor);
    return 0;
}

#include "list.h"
#include "stack.h"
#include <conio.h> // untuk fungsi getch()

int main() {
    list textEditor;
    createList_Elgacor(textEditor);
    list *currentBaris = &textEditor;
    adr_list cursor = nullptr;
    
    Stack undoStack, redoStack;
    createStack_Elgacor(undoStack);
    createStack_Elgacor(redoStack);
    
    showWithCursor(textEditor, currentBaris, cursor);

    char input;
    while (true) {
        input = getch();

        if (input == '.') {
            break; // Akhiri program
            
        } else if (input == '\r') { // ENTER
            list *newBaris = nullptr;
            addBaris(*currentBaris, newBaris);
            currentBaris = currentBaris->nextBaris;
            cursor = nullptr;
            
        } else if (input == 8) { // Backspace
            adr_list P = nullptr;
            delByCursorWithUndo(*currentBaris, P, cursor, undoStack);
            
        } else if (input == 0 || input == -32) { // Special keys
            input = getch(); // Baca key berikutnya
            if (input == 72) { // Arrow Up
                moveCursorUp(currentBaris, cursor);
            } else if (input == 80) { // Arrow Down
                moveCursorDown(currentBaris, cursor);
            } else if (input == 75) { // Arrow Left
                moveCursorLeft(*currentBaris, cursor);
            } else if (input == 77) { // Arrow Right
                moveCursorRight(*currentBaris, cursor);
            }
            
        } else if (input == '>') { // REDO
            redo_Elgacor(redoStack, undoStack, *currentBaris, cursor);
            
        } else if (input == '<') { // UNDO
            undo_Elgacor(undoStack, redoStack, *currentBaris, cursor);
            
        } else { // Input biasa
            adr_list P = createElmList_Elgacor(input);
            addByCursorWithUndo(*currentBaris, P, cursor, undoStack);
        }
        showWithCursor(textEditor, currentBaris, cursor);
    }
    cout << endl;
    showAllBaris(textEditor);
    return 0;
}

