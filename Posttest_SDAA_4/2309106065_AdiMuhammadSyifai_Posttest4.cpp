#include <iostream>
using namespace std;

struct Task {
    string title;
    string description;
    string status; 
};

struct Node {
    Task data;
    Node* next;
};

Node* createNode();
void push(Node** top);
void pop(Node** top);
void displayStack(Node* top);
void enqueue(Node** front, Node** rear);
void dequeue(Node** front);
void displayQueue(Node* front);

void clearScreen() {
    system("cls||clear");
}

void enterContinue() {
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

int main() {
    Node* TOP = NULL;          
    Node* FRONT = NULL;        
    Node* REAR = NULL;         
    int menu, subMenu;

    do {
        clearScreen();
        cout << "\n>> Program Stack dan Queue <<" << endl;
        cout << "1. Operasi Stack\n2. Operasi Queue\n3. Exit\nMasukan pilihan: ";
        cin >> menu;

        switch (menu) {
            case 1: 
                do {
                    clearScreen();
                    cout << "\n>> Operasi Stack <<" << endl;
                    cout << "1. Push\n2. Pop\n3. Display Stack\n4. Kembali\nMasukan pilihan: ";
                    cin >> subMenu;
                    switch (subMenu) {
                        case 1: 
                            push(&TOP); 
                            enterContinue();
                            break;
                        case 2: 
                            pop(&TOP); 
                            enterContinue();    
                            break;
                        case 3: 
                            displayStack(TOP); 
                            enterContinue();
                            break;
                        case 4: break;
                        default: 
                            cout << "Pilihan tidak ada\n";
                            enterContinue();
                    }
                } while (subMenu != 4);
                break;

            case 2: 
                do {
                    clearScreen();
                    cout << "\n>> Operasi Queue <<" << endl;
                    cout << "1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Kembali\nMasukan pilihan: ";
                    cin >> subMenu;
                    switch (subMenu) {
                        case 1:
                            enqueue(&FRONT, &REAR);
                            enterContinue();
                            break;
                        case 2: 
                            dequeue(&FRONT); 
                            enterContinue();
                            break;
                        case 3: 
                            displayQueue(FRONT); 
                            enterContinue();
                            break;
                        case 4: break;
                        default: 
                            cout << "Pilihan tidak ada\n";
                            enterContinue();
                    }
                } while (subMenu != 4);
                break;

            case 3:
                cout << "Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak ada\n";
                enterContinue();
        }
    } while (menu != 3);

    return 0;
}

Node* createNode() {
    Node* newNode = new Node();
    cout << "Judul Task: ";
    cin.ignore();
    getline(cin, newNode->data.title);
    cout << "Deskripsi Task: ";
    getline(cin, newNode->data.description);
    cout << "Status Task (Backlog/In Progress/Done): ";
    getline(cin, newNode->data.status);

    newNode->next = NULL;
    return newNode;
}

void push(Node** top) {
    Node* nodeBaru = createNode();
    nodeBaru->next = *top;
    *top = nodeBaru;
}

void pop(Node** top) {
    if (*top == NULL) {
        cout << "Stack underflow\n";
        return;
    }
    Node* temp = *top;
    *top = (*top)->next;
    delete temp;
}

void displayStack(Node* top) {
    cout << "\n== Daftar Task ==" << endl;
    if (!top) {
        cout << "Stack kosong\n";
        return;
    }
    while (top) {
        cout << "Judul Task\t: " << top->data.title << endl;
        cout << "Deskripsi Task\t: " << top->data.description << endl;
        cout << "Status Task\t: " << top->data.status << endl;
        cout << endl;
        top = top->next;
    }
}

void enqueue(Node** front, Node** rear) {
    Node* nodeBaru = createNode();
    if (!*front) {
        *front = nodeBaru;
    } else {
        (*rear)->next = nodeBaru;
    }
    *rear = nodeBaru;
}

void dequeue(Node** front) {
    if (!*front) {
        cout << "Antrian Kosong\n";
        return;
    }
    Node* temp = *front;
    *front = (*front)->next;
    delete temp;
}

void displayQueue(Node* front) {
    cout << "\n== Daftar Task ==" << endl;
    if (!front) {
        cout << "Antrian Kosong\n";
        return;
    }
    while (front) {
        cout << "Judul Task\t: " << front->data.title << endl;
        cout << "Deskripsi Task\t: " << front->data.description << endl;
        cout << "Status Task\t: " << front->data.status << endl;
        cout << endl;
        front = front->next;
    }
}
