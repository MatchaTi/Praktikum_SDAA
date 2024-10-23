#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Task
{
    string title;
    string description;
    string status;
    int deadline;

    Task *next;
    Task *prev;
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
    cout << "7. Urutkan Task ASC" << endl;
    cout << "8. Cari Task (Fibonacci Search - Deadline)" << endl;
    cout << "9. Cari Task (Jump Search - Deadline)" << endl;
    cout << "10. Cari Task (Boyer-Moore Search - Judul)" << endl;
    cout << "11. Keluar" << endl;
    cout << "Pilih opsi: ";
}

void createSingleLinkedList(string &title, string &description, string &status, int &deadline)
{
    head = new Task();

    head->title = title;
    head->description = description;
    head->status = status;
    head->deadline = deadline;
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
    cout << "Deadline Task (hari): ";
    cin >> newNode->deadline;

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
    cout << "Deadline Task (hari): ";
    cin >> newNode->deadline;

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
        cout << "Deadline Task\t: " << current->deadline << " hari" << endl;
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
            cout << "Deadline Task Baru (hari): ";
            cin >> current->deadline;

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

// Helper function to get length of linked list
int length(Task *head)
{
    int count = 0;
    Task *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// Fibonacci Search
int min(int x, int y) { return (x <= y) ? x : y; }

int fibMonaccianSearch(Task *head, int x, int n)
{
    Task *temp = head;
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < n)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1)
    {
        int i = min(offset + fibMMm2, n - 1);

        temp = head;
        for (int j = 0; j < i; j++)
        {
            temp = temp->next;
        }

        if (temp->deadline < x)
        {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (temp->deadline > x)
        {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else
            return i;
    }

    temp = head;
    for (int j = 0; j < offset + 1; j++)
    {
        temp = temp->next;
    }

    if (fibMMm1 && temp->deadline == x)
        return offset + 1;

    return -1;
}

// Jump Search
int findTask(Task *head, int idx)
{
    for (int i = 0; i < idx; i++)
    {
        head = head->next;
    }
    return head->deadline;
}

int jumpSearch(Task *head, int x, int n)
{
    int step = sqrt(n);
    int prev = 0;
    int idx = min(step, n) - 1;

    while (findTask(head, idx) < x)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
        idx = min(step, n) - 1;
    }

    for (int i = prev; i <= idx; i++)
    {
        if (findTask(head, i) == x)
            return i;
    }

    return -1;
}

int max(int a, int b) { return (a > b) ? a : b; }

void BoyerMooreSearch(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();
    int badChar[256];

    for (int i = 0; i < 256; i++)
        badChar[i] = -1;

    for (int i = 0; i < M; i++)
        badChar[(int)pat[i]] = i;

    int s = 0;
    while (s <= (N - M))
    {
        int j = M - 1;

        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0)
        {
            cout << "\nTask ditemukan dengan judul: " << txt << endl;
            s += (s + M < N) ? M - badChar[txt[s + M]] : 1;
        }
        else
            s += max(1, j - badChar[txt[s + j]]);
    }
}


int main()
{
    clearScreen();
    string title = "Mengoding";
    string description = "Mengerjakan post test 3 struktur data menggunakan C++";
    string status = "In Progress";
    int deadline = 3;
    string *titlePtr = &title;
    string *descriptionPtr = &description;
    string *statusPtr = &status;
    int *deadlinePtr = &deadline;

    createSingleLinkedList(*titlePtr, *descriptionPtr, *statusPtr, *deadlinePtr);
    int option;
    do
    {
        clearScreen();
        showMenu();
        cin >> option;

        switch (option)
        {
        case 1:
            viewTasks();
            enterContinue();
            break;
        case 2:
            addFirst();
            enterContinue();
            break;
        case 3:
            addLast();
            enterContinue();
            break;
        case 4:
            deleteFirst();
            enterContinue();
            break;
        case 5:
            deleteLast();
            enterContinue();
            break;
        case 6:
            editTask();
            enterContinue();
            break;
        case 7:
            head = mergeSort(head);
            cout << "Task berhasil diurutkan." << endl;
            enterContinue();
            break;
        case 8:
        {
            head = mergeSort(head);
            int deadline;
            cout << "Masukkan deadline yang dicari: ";
            cin >> deadline;
            int len = length(head);
            int result = fibMonaccianSearch(head, deadline, len);
            if (result == -1)
                cout << "Task tidak ditemukan dengan deadline tersebut." << endl;
            else
                cout << "Task ditemukan di indeks: " << result << endl;
            enterContinue();
            break;
        }
        case 9:
        {
            head = mergeSort(head);
            int deadline;
            cout << "Masukkan deadline yang dicari: ";
            cin >> deadline;
            int len = length(head);
            int result = jumpSearch(head, deadline, len);
            if (result == -1)
                cout << "Task tidak ditemukan dengan deadline tersebut." << endl;
            else
                cout << "Task ditemukan di indeks: " << result << endl;
            enterContinue();
            break;
        }
        case 10:
        {
            head = mergeSort(head);
            string title;
            cout << "Masukkan judul yang dicari: ";
            cin.ignore();
            getline(cin, title);
            current = head;
            while (current != NULL)
            {
                BoyerMooreSearch(title, current->title);
                current = current->next;
            }
            enterContinue();
            break;
        }
        case 11:
            cout << "Terima kasih telah menggunakan program ini!" << endl;
            break;
        default:
            cout << "Opsi tidak valid!" << endl;
            enterContinue();
        }
    } while (option != 11);

    return 0;
}
