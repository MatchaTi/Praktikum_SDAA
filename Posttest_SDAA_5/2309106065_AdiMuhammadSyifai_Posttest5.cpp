#include <iostream>
#include <string>

using namespace std;

struct Task
{
    string title;
    string description;
    string status;

    Task *next;
    Task *prev; // Digunakan untuk quick sort
};

Task *head, *tail, *current, *newNode, *del;

void clearScreen()
{
    system("cls||clear");
}

void enterContinue()
{
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void showMenu()
{
    cout << "\n== KANBAN BOARD ==" << endl;
    cout << "1. Lihat Semua Task" << endl;
    cout << "2. Tambah Task di Awal" << endl;
    cout << "3. Tambah Task di Akhir" << endl;
    cout << "4. Hapus Task di Awal" << endl;
    cout << "5. Hapus Task di Akhir" << endl;
    cout << "6. Edit Task" << endl;
    cout << "7. Urutkan Task (Merge Sort ASC / Quick Sort DESC)" << endl; // Opsi baru untuk sorting
    cout << "8. Keluar" << endl;
    cout << "Pilih opsi: ";
}

void createSingleLinkedList(string &title, string &description, string &status)
{
    head = new Task();

    head->title = title;
    head->description = description;
    head->status = status;
    head->next = NULL;
    head->prev = NULL;

    tail = head;
}

void addFirst()
{
    newNode = new Task();

    cout << "Judul Task: ";
    cin.ignore();
    getline(cin, newNode->title);
    cout << "Deskripsi Task: ";
    getline(cin, newNode->description);
    cout << "Status Task (Backlog/In Progress/Done): ";
    getline(cin, newNode->status);

    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;

    cout << "Task berhasil ditambahkan." << endl;
}

void addLast()
{
    newNode = new Task();

    cout << "Judul Task: ";
    cin.ignore();
    getline(cin, newNode->title);
    cout << "Deskripsi Task: ";
    getline(cin, newNode->description);
    cout << "Status Task (Backlog/In Progress/Done): ";
    getline(cin, newNode->status);

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    tail->next = NULL;

    cout << "Task berhasil ditambahkan." << endl;
}

void viewTasks()
{
    current = head;
    cout << "\n== Daftar Task ==" << endl;
    if (current == NULL)
        cout << "Tidak ada task." << endl;
    while (current != NULL)
    {
        cout << "Judul Task\t: " << current->title << endl;
        cout << "Deskripsi Task\t: " << current->description << endl;
        cout << "Status Task\t: " << current->status << endl;
        cout << endl;
        current = current->next;
    }
}

void editTask()
{
    string title, newTitle, newDescription, newStatus;
    current = head;
    cout << "Case Sensitive!" << endl;
    cout << "Judul Task yang akan diubah: ";
    cin.ignore();
    getline(cin, title);

    while (current != NULL)
    {
        if (current->title == title)
        {
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
        }
        else
        {
            cout << "Task tidak ditemukan." << endl;
            break;
        }
    }
}

void deleteFirst()
{
    if (head == NULL)
    {
        cout << "\nTidak ada task untuk dihapus." << endl;
        return;
    }

    del = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    delete del;

    cout << "Task pertama berhasil dihapus." << endl;
}

void deleteLast()
{
    if (tail == NULL)
    {
        cout << "\nTidak ada task untuk dihapus." << endl;
        return;
    }

    del = tail;
    tail = tail->prev;
    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL;

    delete del;

    cout << "Task terakhir berhasil dihapus." << endl;
}

// Merge Sort (Ascending)
Task *merge(Task *left, Task *right)
{
    if (!left)
        return right;
    if (!right)
        return left;

    Task *result = NULL;

    if (left->title <= right->title)
    {
        result = left;
        result->next = merge(left->next, right);
        if (result->next)
            result->next->prev = result;
    }
    else
    {
        result = right;
        result->next = merge(left, right->next);
        if (result->next)
            result->next->prev = result;
    }

    return result;
}

Task *mergeSort(Task *head)
{
    if (!head || !head->next)
        return head;

    Task *middle = head;
    Task *fast = head->next;

    while (fast && fast->next)
    {
        middle = middle->next;
        fast = fast->next->next;
    }

    Task *left = head;
    Task *right = middle->next;
    middle->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

// Quick Sort (Descending)
Task *partition(Task *low, Task *high)
{
    string pivot = high->title;
    Task *i = low->prev;

    for (Task *j = low; j != high; j = j->next)
    {
        if (j->title >= pivot)
        {
            i = (i == NULL) ? low : i->next;
            swap(i->title, j->title);
            swap(i->description, j->description);
            swap(i->status, j->status);
        }
    }
    i = (i == NULL) ? low : i->next;
    swap(i->title, high->title);
    swap(i->description, high->description);
    swap(i->status, high->status);
    return i;
}

void quickSort(Task *low, Task *high)
{
    if (high != NULL && low != high && low != high->next)
    {
        Task *p = partition(low, high);
        quickSort(low, p->prev);
        quickSort(p->next, high);
    }
}

int main()
{
    clearScreen();
    string title = "Mengoding";
    string description = "Mengerjakan post test 3 struktur data menggunakan C++";
    string status = "In Progress";
    string *titlePtr = &title;
    string *descriptionPtr = &description;
    string *statusPtr = &status;

    createSingleLinkedList(*titlePtr, *descriptionPtr, *statusPtr);
    char pilihan;

    do
    {
        clearScreen();
        showMenu();
        cin >> pilihan;

        switch (pilihan)
        {
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
        case '7': // Opsi sorting
            cout << "Pilih metode sorting:\n1. Merge Sort (ASC)\n2. Quick Sort (DESC)\nPilih opsi: ";
            char sortPilihan;
            cin >> sortPilihan;
            if (sortPilihan == '1')
            {
                head = mergeSort(head);
                cout << "Task diurutkan secara ascending berdasarkan judul (Merge Sort)." << endl;
            }
            else if (sortPilihan == '2')
            {
                Task *tailTask = head;
                while (tailTask && tailTask->next != NULL)
                    tailTask = tailTask->next;
                quickSort(head, tailTask);
                cout << "Task diurutkan secara descending berdasarkan judul (Quick Sort)." << endl;
            }
            enterContinue();
            break;
        case '8':
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            enterContinue();
        }
    } while (pilihan != '8');

    cout << "Program selesai." << endl;
    return 0;
}
