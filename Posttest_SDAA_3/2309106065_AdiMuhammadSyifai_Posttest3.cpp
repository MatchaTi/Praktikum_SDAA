#include <iostream>
#include <string>

using namespace std;

struct Task {
    string title;
    string description;
    string status; 

    Task *next;
};

Task *head, *tail, *current, *newNode, *del;

void clearScreen() {
    system("cls||clear");
}

void enterContinue() {
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void showMenu() {
    cout << "\n== KANBAN BOARD ==" << endl;
    cout << "1. Lihat Semua Task" << endl;
    cout << "2. Tambah Task di Awal" << endl;
    cout << "3. Tambah Task di Akhir" << endl;
    cout << "4. Hapus Task di Awal" << endl;
    cout << "5. Hapus Task di Akhir" << endl;
    cout << "6. Edit Task" << endl;
    cout << "7. Keluar" << endl;
    cout << "Pilih opsi: ";
}

void createSingleLinkedList(string &title, string &description, string &status) {
    head = new Task();

    head->title = title;
    head->description = description;
    head->status = status;
    head->next = NULL;

    tail = head;
}

void addFirst() {
    newNode = new Task();

    cout << "Judul Task: ";
    cin.ignore();
    getline(cin, newNode->title);
    cout << "Deskripsi Task: ";
    getline(cin, newNode->description);
    cout << "Status Task (Backlog/In Progress/Done): ";
    getline(cin, newNode->status);

    newNode->next = head;
    head = newNode;

    cout << "Task berhasil ditambahkan." << endl;
}

void addLast() {
    newNode = new Task();

    cout << "Judul Task: ";
    cin.ignore();
    getline(cin, newNode->title);
    cout << "Deskripsi Task: ";
    getline(cin, newNode->description);
    cout << "Status Task (Backlog/In Progress/Done): ";
    getline(cin, newNode->status);

    tail->next = newNode;
    tail = newNode;

    cout << "Task berhasil ditambahkan." << endl;
}

void viewTasks() {
    current = head;
    cout << "\n== Daftar Task ==" << endl;
    if(current == NULL) cout << "Tidak ada task." << endl;
    while(current != NULL) {
        cout << "Judul Task\t: " << current->title << endl;
        cout << "Deskripsi Task\t: " << current->description << endl;
        cout << "Status Task\t: " << current->status << endl;
        cout << endl;
        current = current->next;
    }
}

void editTask() {
    string title, newTitle, newDescription, newStatus;
    current = head;
    cout << "Case Sensitive!" << endl;
    cout << "Judul Task yang akan diubah: ";
    cin.ignore();
    getline(cin, title);

    while(current != NULL) {
        if(current->title == title) {
            cout << "Judul Task Baru: ";
            getline(cin, newTitle);
            cout << "Deskripsi Task Baru: ";
            getline(cin, newDescription);
            cout << "Status Task Baru(Backlog/In Progress/Done): ";
            getline(cin, newStatus);

            current->title = newTitle;
            current->description = newDescription;
            current->status = newStatus;

            cout << "Task berhasil diubah." << endl;
            break;
        } else {
            cout << "Task tidak ditemukan." << endl;
            break;
        }
    }
}

void deleteFirst() {
    if (head == NULL) {
        cout << "\nTidak ada task untuk dihapus." << endl;
        return;
    }

    del = head;
    head = head->next;
    delete del;

    cout << "Task pertama berhasil dihapus." << endl;
}

void deleteLast() {
    del = tail;
    current = head;

    while(current->next != tail) {
        current = current->next;
    }

    tail = current;
    tail->next = NULL;
    delete del; cout << "Task terakhir berhasil dihapus." << endl;
}

int main() {
    clearScreen();
    string title = "Mengoding";
    string description = "Mengerjakan post test 3 struktur data menggunakan C++";
    string status = "In Progress"; 
    string *titlePtr = &title;
    string *descriptionPtr = &description;
    string *statusPtr = &status;

    createSingleLinkedList(*titlePtr, *descriptionPtr, *statusPtr);
    char pilihan;

    do {
        clearScreen();
        showMenu();
        cin >> pilihan;

        switch (pilihan) {
            case '1':
                viewTasks();
                enterContinue();
                break;
            case '2':
                addFirst();
                enterContinue();
                break;
            case '3':
                addLast();
                enterContinue();
                break;
            case '4':
                deleteFirst();
                viewTasks();
                enterContinue();
                break;
            case '5':
                deleteLast();
                viewTasks();
                enterContinue();
                break;
            case '6':
                viewTasks();
                editTask();
                enterContinue();
                break;
            case '7':
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                enterContinue();
        }
    } while (pilihan != '7');

    cout << "Program selesai." << endl;
    return 0;
}
