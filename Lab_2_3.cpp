#include <iostream>
using namespace std;

const int CAP = 10;

// Векторне представлення односпрямованого списку
struct VList {
    char data[CAP];
    int count;
};

// Вузол зв'язаного стеку
struct Node {
    int data;
    Node* next;
};

int main() {
    // п.3: індексовані змінні з 10 елементів
    char charSource[10] = { 'A','b','C','d','E','f','G','h','I','j' };
    int intSource[10] = { 12, -5, 43, 7, 19, -3, 88, 0, 25, 14 };

    // Список (векторне, char)
    VList list; // п.2: звичайна змінна
    list.count = 0;
    int N1 = 7; // 0..9
    int M1 = 3; // 0..15

    for (int i = 0; i < N1; i++) {
        if (list.count >= CAP) {
            cout << "Переповнення списку!\n";
            break;
        }
        list.data[list.count++] = charSource[i];
    }
    cout << "Список: ";
    for (int i = 0; i < list.count; i++) cout << list.data[i] << " ";
    cout << endl;

    for (int k = 0; k < M1; k++) {
        if (list.count == 0) {
            cout << "Список порожній, видалено лише " << k << " з " << M1 << endl;
            break;
        }
        for (int i = 1; i < list.count; i++) // видалення першого елемента
            list.data[i - 1] = list.data[i];
        list.count--;
    }
    cout << "Список після видалення: ";
    for (int i = 0; i < list.count; i++) cout << list.data[i] << " ";
    cout << "\n\n";

    // Стек (зв'язане, int)
    Node* top = nullptr; // п.2: вказівна змінна
    int N2 = 6; // 0..9
    int M2 = 8; // 0..15

    for (int i = 0; i < N2; i++) {
        top = new Node{ intSource[i], top }; // Push
    }
    cout << "Стек (від вершини): ";
    for (Node* c = top; c; c = c->next) cout << c->data << " ";
    cout << endl;

    for (int k = 0; k < M2; k++) {
        if (top == nullptr) {
            cout << "Стек порожній, видалено лише " << k << " з " << M2 << endl;
            break;
        }
        Node* t = top; // Pop
        top = top->next;
        delete t;
    }
    cout << "Стек після видалення: ";
    for (Node* c = top; c; c = c->next) cout << c->data << " ";
    cout << endl;

    while (top) { Node* t = top; top = top->next; delete t; } // очищення
    return 0;
}