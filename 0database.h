//->Semua library yang dibutuhkan oleh keseluruhan program<-//

// #ifndef DATABASE_H
// #define DATABASE_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//->Inisialisasi Struct dan Variabel General<-//
int i, j;

struct Base
{
    int row;
    int col;
    int pil;
    int n_row;
    int n_col;
    string baru;
};
Base contain;

/*Selanjutnya adalah seluruh fungsi yang digunakan dalam program*/

//->Fungsi Tampilan Menu utama<-//
void menu()
{
    cout << "+---------------------+\n";
    cout << "|    MINI DATABASE    |\n";
    cout << "+---------------------+\n";
    cout << "|MENU:                |\n";
    cout << "| 1. Create Data      |\n";
    cout << "| 2. Update Data      |\n";
    cout << "| 3. Save to File     |\n";
    cout << "| 4. Open File        |\n";
    cout << "| 5. Update Data File |\n";
    cout << "| 6. Save to Cloud    |\n";
    cout << "| 0. Exit             |\n";
    cout << "+---------------------+\n";
}

//->Fungsi Input Data ke dalam Kerangka<-//
void isiData(string **isi_data, Base &contain)
{
    cin.ignore();
    for (int i = 0; i < contain.col; ++i)
    {
        cout << "Masukkan nama kolom ke-" << i + 1 << " : ";
            getline(cin, isi_data[0][i]);
    }

    system("cls");

    for (int i = 1; i < contain.row; ++i)
    {
        for (int j = 0; j < contain.col; ++j)
        {
            cout << "Masukkan " << isi_data[0][j] << " pada baris ke-" << i << " : ";
                getline(cin, isi_data[i][j]);
        }
    }
}

//->Fungsi Output Data dari Konsol<-//
void display(string **isi_data, Base &contain)
{
    int max[contain.col];
    for (int i = 0; i < contain.col; ++i)
    {
        max[i] = isi_data[0][i].length();
        for (int j = 0; j < contain.row; ++j)
        {
            if (max[i] < isi_data[j][i].length())
            {
                max[i] = isi_data[j][i].length();
            }
        }
    }

    int panjang = 1;
    for (int i = 0; i < contain.col; ++i)
    {
        panjang += max[i] + 3;
    }
    panjang += contain.col;

    for (int i = 0; i < panjang; ++i)
    {
        cout << "-";
    }
    cout << "\n|";

    for (int i = 0; i < contain.col; ++i)
    {
        cout << setiosflags(ios::left) << setw(max[i] + 3) << isi_data[0][i] << "|";
    }
    cout << endl;

    for (int i = 0; i < panjang; ++i)
    {
        cout << "-";
    }
    cout << endl;

    for (int j = 1; j < contain.row; ++j)
    {
        cout << "|";
        for (int i = 0; i < contain.col; ++i)
        {
            cout << setiosflags(ios::left) << setw(max[i] + 3) << isi_data[j][i] << "|";
        }
        cout << endl;
    }

    for (int i = 0; i < panjang; ++i)
    {
        cout << "-";
    }
    cout << endl;
}

//->Fungsi Update (Ubah Data) pada Konsol<-//
void change(string **isi_data, Base &contain)
{
    system("cls");
    int panjang[contain.col];
    for (j = 0; j < contain.col; ++j)
    {
        panjang[j] = isi_data[0][j].length();
        for (i = 0; i < contain.row; ++i)
        {
            if (isi_data[i][j].length() > panjang[j])
            {
                panjang[j] = isi_data[i][j].length();
            }
        }
    }
    cout << endl;

    //Tampilkan Data yang Bisa Diupdate (Edit)//
    for (i = 0; i < contain.row; ++i)
    {
        for (j = 0; j < contain.col; ++j)
        {
            cout << setiosflags(ios::left) << setw(panjang[j] + 3) << isi_data[i][j] << "[" << i << "][" << j << "] ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Inputkan dua index dari data yang ingin diubah! ([A][B])\n";
    cout << "A >_";
    cin >> contain.n_row;
    cout << "B >_";
    cin >> contain.n_col;

    cin.ignore();
    cout << "Masukkan data yang baru : ";
    getline(cin, contain.baru);
    isi_data[contain.n_row][contain.n_col] = contain.baru;

    system("cls");
}

//->Fungsi Save Data ke File Eksternal<-//
void save(string **isi_data, Base &contain)
{
    system("cls");
    //->Tulis ke Daftar Isi <-//
    string nama_file;
    string x;
    ofstream tulis;
    ofstream d_isi;

    cin.ignore();
    cout << "+-----------------------------+\n";
    cout << "|LIST NAMA FILE YANG SUDAH ADA|\n";
    cout << "+-----------------------------+\n";
//buat fungsi baca daftar isi?

    cout << endl;
    cout << "Masukkan nama file tanpa '.txt'!\n";
    cout << "Nama file dapat berupa karakter apapun, ada spasi, diawali angka, bebass pokonyah :)\n> ";
    getline(cin, nama_file);
    nama_file += ".txt";

    tulis.open(nama_file, ios::out);
    d_isi.open("1ndex.txt", ios::app);

    //Tulis Nama File Ke dalam Daftar Isi//
    ifstream baca("1ndex.txt");
    string z;

    int row = 0;
    while (getline(baca, z))
    {
        row++;
    }
    d_isi << row << ". " << nama_file << endl;

    //Menuliskan Isi Data ke dalam File .txt//
    int max[contain.col];
    for (int i = 0; i < contain.col; ++i)
    {
        max[i] = isi_data[0][i].length();
        for (int j = 0; j < contain.row; ++j)
        {
            if (max[i] < isi_data[j][i].length())
            {
                max[i] = isi_data[j][i].length();
            }
        }
    }

    int panjang = 1;
    for (int i = 0; i < contain.col; ++i)
    {
        panjang += max[i] + 3;
    }
    panjang += contain.col;

    for (int i = 0; i < panjang; ++i)
    {
        tulis << "-";
    }
    tulis << endl
          << "|";

    for (int i = 0; i < contain.col; ++i)
    {
        tulis << setiosflags(ios::left) << setw(max[i] + 3) << isi_data[0][i] << "|";
    }
    tulis << endl;

    for (int i = 0; i < panjang; ++i)
    {
        tulis << "-";
    }
    tulis << endl;

    for (int j = 1; j < contain.row; ++j)
    {
        tulis << "|";
        for (int i = 0; i < contain.col; ++i)
        {
            tulis << setiosflags(ios::left) << setw(max[i] + 3) << isi_data[j][i] << "|";
        }
        tulis << endl;
    }

    for (int i = 0; i < panjang; ++i)
    {
        tulis << "-";
    }
    tulis << endl;

    cout << "File berhasil dibuat!\nData berhasil disimpan!" << endl;
    cout << endl;

    system("pause");
    system("cls");
}

//->Fungsi Buka Data dari File Eksternal<-//
void open(string **isi_data, Base &contain)
{
    //Baca List File//
    cin.ignore();
    ifstream baca("1ndex.txt");
    string x, buka_file;

    system("cls");
    cout << "+---------+\n";
    cout << "|LIST FILE|\n";
    cout << "+---------+\n";

    while (getline(baca, x))
    {
        cout << x << endl;
    }

    cout << "\nTuliskan nama file tanpa '.txt'!\n> ";
    getline(cin, buka_file);
    buka_file += ".txt";

    system("cls");

    //Baca Isi dari File//
    if (buka_file == "0.txt" || buka_file == "kembali.txt")
    {
        contain.pil = 4;
    }
    else
    {
        ifstream baca_file(buka_file);
        string y;

        if (baca_file.is_open())
        {
            cout << "Isi dari file : " << buka_file << endl;
            cout << endl;
            while (getline(baca_file, y))
            {
                cout << y << endl;
            }
            cout << endl;
        }
        else
        {
            cout << "404 Error!\nFile Not Found!" << endl;
            cout << endl;
        }
        system("pause");
        system("cls");
    }
}

//->Fungsi Exit<-//
void exit()
{
    cout << "Bye. Enjoy the day!" << endl;
}

// #endif   DATABASE_H