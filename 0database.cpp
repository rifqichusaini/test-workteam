#include "0database.h"



//->Eksekutor dari Program<-//
int main()
{
    //Wadah dari Kerangka Database//
    string **isi_data = new string *[0];
    for (int i = 0; i < 0; ++i)
    {
        isi_data[i] = new string[0];
    }
    /*Bagian atas adalah menyiapkan sebuah wadah untuk membuat kerangka,
    berbentuk array multidimensi*/

    //------------------------CRUD-----------------------//
    cout << "Selamat Datang di Aplikasi Database!\n";
    cout << endl;
    system("pause");
    system("cls");

    do
    {
        menu();
        cout << "Please choose a menu!\n> ";
            cin >> contain.pil;

            if(contain.pil == 1)
            {   
                system("cls");
                cout << "Inputkan Jumlah Header/Kolom!\n> ";
                cin >> contain.col;
                cout << "Inputkan Jumlah Data/Baris!\n> ";
                cin >> contain.row;
                contain.row++;

                //Pembentukan Kerangka dan Pengisian Data//
                isi_data = new string *[contain.row];
                for (int i = 0; i < contain.row; ++i)
                {
                    isi_data[i] = new string[contain.col];
                }

                isiData(isi_data, contain);
                system("cls");
                display(isi_data, contain);
            }
            else if(contain.pil == 2)
            {
                if(contain.row == 0 && contain.col == 0){
                    cout << "please create data before update data!"<<endl;
                    system("pause");
                    system("cls");
                } else {
                    //Panggil Fungsi Update//
                    change(isi_data, contain);
                    display(isi_data, contain);
                }
            }
            else if(contain.pil == 3)
            {
                if(contain.row == 0 && contain.col == 0){
                    cout << "please create data before save to file!"<<endl;
                    system("pause");
                    system("cls");
                } else {
                    //Panggil Fungsi Simpan Data ke .TXT//
                    save(isi_data, contain);
                }
            }
            else if (contain.pil == 4)
            {
                //Panggil Fungsi Baca Data dari .TXT//
                open(isi_data, contain);
            }
            else if (contain.pil == 5)
            {
                // Panggil Fungsi Baca Data dari .TXT//
                cout << "pilih file";
                cout << endl;
                system("pause");
                system("cls");
            }

    } while(contain.pil != 0);

    cout << endl;
    system("pause");
    system("cls");

    exit();

    return 0;
}