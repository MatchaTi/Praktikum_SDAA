#include <iostream>
#include <string>

using namespace std;

const int MAX_TASKS = 100;

struct Task
{
    string title;
    string description;
    string status;
};

Task kanbanBoard[MAX_TASKS];
int taskCount = 0;

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
    cout << "1. Tambah Task" << endl;
    cout << "2. Lihat Semua Task" << endl;
    cout << "3. Edit Task" << endl;
    cout << "4. Hapus Task" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih opsi: ";
}

void addTask()
{
    if (taskCount < MAX_TASKS)
    {
        Task *newTask = &kanbanBoard[taskCount];
        cout << "\n== Tambah Task Baru ==" << endl;
        cout << "Judul Task: ";
        cin.ignore();
        getline(cin, newTask->title);
        cout << "Deskripsi Task: ";
        getline(cin, newTask->description);
        cout << "Status Task (Backlog/In Progress/Done): ";
        getline(cin, newTask->status);

        taskCount++;
        cout << "Task berhasil ditambahkan!" << endl;
    }
    else
    {
        cout << "Kanban Board penuh, tidak bisa menambah task." << endl;
    }
}

void viewTasks()
{
    if (taskCount == 0)
    {
        cout << "\nTidak ada task dalam Kanban Board." << endl;
    }
    else
    {
        cout << "\n== Daftar Task ==" << endl;
        for (int i = 0; i < taskCount; i++)
        {
            Task *t = &kanbanBoard[i];
            cout << "Task #" << (i + 1) << endl;
            cout << "Judul: " << t->title << endl;
            cout << "Deskripsi: " << t->description << endl;
            cout << "Status: " << t->status << endl;
            cout << "------------------" << endl;
        }
    }
}

void editTask()
{
    if (taskCount == 0)
    {
        cout << "\nTidak ada task untuk diedit." << endl;
        return;
    }

    int index;
    cout << "\nMasukkan nomor task yang akan diedit: ";
    cin >> index;

    if (index > 0 && index <= taskCount)
    {
        Task *t = &kanbanBoard[index - 1];
        cout << "Judul Task Baru: ";
        cin.ignore();
        getline(cin, t->title);
        cout << "Deskripsi Task Baru: ";
        getline(cin, t->description);
        cout << "Status Task Baru (Backlog/In Progress/Done): ";
        getline(cin, t->status);

        cout << "Task berhasil diedit!" << endl;
    }
    else
    {
        cout << "Task tidak ditemukan." << endl;
    }
}

void deleteTask()
{
    if (taskCount == 0)
    {
        cout << "\nTidak ada task untuk dihapus." << endl;
        return;
    }

    int index;
    cout << "\nMasukkan nomor task yang akan dihapus: ";
    cin >> index;

    if (index > 0 && index <= taskCount)
    {
        for (int i = index - 1; i < taskCount - 1; i++)
        {
            kanbanBoard[i] = kanbanBoard[i + 1];
        }
        taskCount--;
        cout << "Task berhasil dihapus!" << endl;
    }
    else
    {
        cout << "Task tidak ditemukan." << endl;
    }
}

int main()
{
    clearScreen();
    int pilihan;

    do
    {
        clearScreen();
        showMenu();
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            addTask();
            enterContinue();
            break;
        case 2:
            viewTasks();
            enterContinue();
            break;
        case 3:
            viewTasks();
            editTask();
            enterContinue();
            break;
        case 4:
            viewTasks();
            deleteTask();
            enterContinue();
            break;
        case 5:
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            enterContinue();
        }
    } while (pilihan != 5);

    return 0;
}
