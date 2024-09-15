#include <iostream>
using namespace std;

void hanoi(int n, char asal, char tujuan, char sementara) {
    if (n == 1) {
        cout << "Pindahkan piringan 1 dari menara " << asal << " ke menara " << tujuan << endl;
        cout << n << " Pertama Debug" << endl;
        return;
    }

    hanoi(n - 1, asal, sementara, tujuan);

    cout << "Pindahkan piringan " << n << " dari menara " << asal << " ke menara " << tujuan << endl;
        cout << n << " Kedua Debug" << endl;

    hanoi(n - 1, sementara, tujuan, asal);
}

int main() {
    int n = 3; 

    cout << "Langkah-langkah penyelesaian Menara Hanoi untuk " << n << " piringan:" << endl;
    hanoi(n, 'A', 'C', 'B'); 


    cout << endl << "=============================" << endl;
    cout << "\tIlustrasi" << endl;
    cout << "=============================" << endl << endl;

    cout << "\tAwal\t\t\t\t\t\t\t\t\t\tTujuan"<< endl;
    cout << "\t   |\t\t\t\t\t|\t\t\t\t\t|"<< endl;
    cout << "\t   |\t\t\t\t\t|\t\t\t\t\t|"<< endl;
    cout << "\t  ===\t\t\t\t\t|\t\t\t\t\t|"<< endl;
    cout << "\t =====\t\t\t\t\t|\t\t\t\t\t|"<< endl;
    cout << "\t=======\t\t\t\t\t|\t\t\t\t\t|"<< endl;

    cout << endl;

    cout << "\t   |\t\t\t\t\t|\t\t\t\t\t |"<< endl;
    cout << "\t   |\t\t\t\t\t|\t\t\t\t\t |"<< endl;
    cout << "\t   |\t\t\t\t\t|\t\t\t\t\t |"<< endl;
    cout << "\t =====\t\t\t\t\t|\t\t\t\t\t |"<< endl;
    cout << "\t=======\t\t\t\t\t|\t\t\t\t\t==="<< endl;

    cout << endl;

    cout << "\t   |\t\t\t\t\t  |\t\t\t\t\t |"<< endl;
    cout << "\t   |\t\t\t\t\t  |\t\t\t\t\t |"<< endl;
    cout << "\t   |\t\t\t\t\t  |\t\t\t\t\t |"<< endl;
    cout << "\t   |\t\t\t\t\t  |\t\t\t\t\t |"<< endl;
    cout << "\t=======\t\t\t\t\t=====\t\t\t\t\t==="<< endl;

    cout << endl;

    cout << "\t   |\t\t\t\t\t  |\t\t\t\t\t |"<< endl;
    cout << "\t   |\t\t\t\t\t  |\t\t\t\t\t |"<< endl;
    cout << "\t   |\t\t\t\t\t  |\t\t\t\t\t |"<< endl;
    cout << "\t   |\t\t\t\t\t ===\t\t\t\t\t |"<< endl;
    cout << "\t=======\t\t\t\t\t=====\t\t\t\t\t |"<< endl;

    cout << endl;

    cout << "\t   |\t\t\t\t\t  |\t\t\t\t\t   |"<< endl;
    cout << "\t   |\t\t\t\t\t  |\t\t\t\t\t   |"<< endl;
    cout << "\t   |\t\t\t\t\t  |\t\t\t\t\t   |"<< endl;
    cout << "\t   |\t\t\t\t\t ===\t\t\t\t\t   |"<< endl;
    cout << "\t   |\t\t\t\t\t=====\t\t\t\t\t ====="<< endl;

    cout << endl;

    cout << "\t   |\t\t\t\t\t  |\t\t\t\t\t   |"<< endl;
    cout << "\t   |\t\t\t\t\t  |\t\t\t\t\t   |"<< endl;
    cout << "\t   |\t\t\t\t\t  |\t\t\t\t\t   |"<< endl;
    cout << "\t   |\t\t\t\t\t  |\t\t\t\t\t   |"<< endl;
    cout << "\t  ===\t\t\t\t\t=====\t\t\t\t\t======="<< endl;

    cout << endl;

    cout << "\t   |\t\t\t\t\t  |\t\t\t\t\t    |"<< endl;
    cout << "\t   |\t\t\t\t\t  |\t\t\t\t\t    |"<< endl;
    cout << "\t   |\t\t\t\t\t  |\t\t\t\t\t    |"<< endl;
    cout << "\t   |\t\t\t\t\t  |\t\t\t\t\t  ====="<< endl;
    cout << "\t  ===\t\t\t\t\t  |\t\t\t\t\t ======="<< endl;

    cout << endl;

    cout << "\t   |\t\t\t\t\t  |\t\t\t\t\t    |"<< endl;
    cout << "\t   |\t\t\t\t\t  |\t\t\t\t\t    |"<< endl;
    cout << "\t   |\t\t\t\t\t  |\t\t\t\t\t   ==="<< endl;
    cout << "\t   |\t\t\t\t\t  |\t\t\t\t\t  ====="<< endl;
    cout << "\t   |\t\t\t\t\t  |\t\t\t\t\t ======="<< endl;

    char flickering;
    cin >> flickering;
    return 0;
}
