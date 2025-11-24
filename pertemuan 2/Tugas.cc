#include <iostream>
using namespace std;

// Struktur node untuk linked list
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk membuat stack baru
Node* createStack() {
    return nullptr;
}

// Fungsi push (menambahkan elemen ke stack)
Node* push(Node* top, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = top;
    cout << "Push: " << data << endl;
    return newNode;
}

// Fungsi pop (menghapus elemen dari stack)
Node* pop(Node* top) {
    if (top == nullptr) {
        cout << "Stack kosong!" << endl;
        return nullptr;
    }
    
    Node* temp = top;
    int poppedData = temp->data;
    top = top->next;
    delete temp;
    cout << "Pop: " << poppedData << endl;
    return top;
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Node* top) {
    return top == nullptr;
}

// Fungsi untuk menampilkan isi stack
void display(Node* top) {
    if (top == nullptr) {
        cout << "Stack kosong" << endl;
        return;
    }
    
    cout << "Isi stack (dari top ke bottom): ";
    Node* current = top;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Fungsi untuk menghapus semua elemen stack
void clearStack(Node* top) {
    Node* current = top;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

// Fungsi utama
int main() {
    Node* stack = createStack();
    
    cout << "IMPLEMENTASI STACK DENGAN LINKED LIST" << endl;
    cout << "=====================================" << endl << endl;
    
    // Push 3 angka
    cout << "PUSH 3 ANGKA:" << endl;
    stack = push(stack, 10);
    stack = push(stack, 20);
    stack = push(stack, 30);
    
    cout << endl;
    display(stack);
    cout << endl;
    
    // Pop 1 angka
    cout << "POP 1 ANGKA:" << endl;
    stack = pop(stack);
    
    cout << endl;
    display(stack);
    
    // Bersihkan memory sebelum program berakhir
    clearStack(stack);
    
    return 0;
}