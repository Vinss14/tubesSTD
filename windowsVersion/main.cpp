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
