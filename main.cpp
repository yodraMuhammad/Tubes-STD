#include <iostream>
#include "TUBES.h"
using namespace std;

int main()
{
    string zxc;
    int pil;
    listfoto F;
    listuser U;
    infotypefoto FoBar;
    infotypefoto Foto;
    infotypeuser UsBar;
    infotypeuser Userr;
    CreateListFoto(F);
    CreateListUser(U);
    address P;
    cout<<("                                              ")<<endl;
    cout<<("================ Selamat Datang ==============")<<endl;
    cout<<("================  Di Instagram  ==============")<<endl;
    cout<<("                                              ")<<endl;
    cout<<("| Log In                                      ")<<endl;
    cout<<("| Username : ");
    string nama;
    cin>> nama;
    cout<<endl;
    cout<<endl;
    system("CLS");
    cout<< "Hi "<<nama<< " ^_^"<<endl;
    cout<<"Apa Yang Ingin Anda Lakukan : "<<endl;
    cout<<"Tekan 'ENTER'";
    cin;

    do{
        system("CLS");
        Menu();
        cout<<" Pilihan : ";
        cin>>pil;
        switch(pil){
        case 1:
            system("CLS");
            cout <<"--- Tambakan Foto Baru ---"<<endl;
            cout <<"   Nama Foto Baru: ";
            cin  >> FoBar;
            InsertFoto(F,AlokasiFoto(FoBar));
            break;
        case 2:
            system("CLS");
            cout <<"--- Tambakan Teman Baru ---"<<endl;
            cout << "   Nama Teman Baru: ";
            cin >> UsBar;
            InsertUser(U,AlokasiUser(UsBar));
            break;
        case 3:
            system("CLS");
            cout <<"--- Hubungkan Foto ---"<<endl;
            cout <<"(Jika Foto atau Teman Kosong Tekan '0' Untuk Kembali)"<<endl;
            PrintAllFoto(F);
            PrintUser(U);
            cout << "   Foto Yang Ingin Dihubungkan : ";
            cin >> Foto;
            if(Foto!="0"){
                P = CariFoto(Foto,F);
                cout << "   User Yang Ingin Dihubungkan : ";
                cin >> Userr;
                InsertRelasi(relasi(P),AlokasiRelasi(CariUser(Userr,U)));
            }
            break;
        case 4:
            if(first(F)!=NULL){
                do{
                    system("CLS");
                    cout <<"--- Hapus Foto ---"<<endl;
                    PrintAllFoto(F);
                    cout <<" Tekan '0' Untuk Kembali"<<endl;
                    cout << "   Foto Yang Ingin Dihapus : ";
                    cin >> Foto;
                    if(Foto != "0"){
                        DeleteFoto(F,Foto);
                    }
                }while(Foto!="0");
            }else{
                system("CLS");
                cout <<"--- Hapus Foto ---"<<endl;
                PrintAllFoto(F);
                cout <<" Tekan '0' Untuk Kembali"<<endl;
                cout<<" ";
                cin >> Foto;
            }
            break;
        case 5:
            if(first(U)!=NULL){
                do{
                    system("CLS");
                    cout <<"--- Hapus Teman ---"<<endl;
                    PrintUser(U);
                    cout <<" Tekan '0' Untuk Kembali"<<endl;
                    cout <<"   Teman Yang Ingin Dihapus : ";
                    cin >> Userr;
                    if(Userr != "0"){
                        DeleteUser(U,Userr);
                    }
                }while(Userr!="0");
            }else{
                system("CLS");
                cout <<"--- Hapus Teman ---"<<endl;
                PrintUser(U);
                cout <<" Tekan '0' Untuk Kembali"<<endl;
                cout<<" ";
                cin >> Foto;
            }
            break;
        case 6:
            system("CLS");
            cout <<"--- Tampilkan Foto ---"<<endl;
            PrintAllFoto(F);
            cout <<" Tekan '0' Untuk Kembali"<<endl;
            cout<<" ";
            cin >> Foto;
            break;
        case 7:
            system("CLS");
            cout <<"--- Tampilkan Foto ---"<<endl;
            PrintFotoTagTerbanyak(F);
            cout <<" Tekan '0' Untuk Kembali"<<endl;
            cout<<" ";
            cin >>Foto;
            break;
        case 8:
            system("CLS");
            cout <<"--- Tampilkan Teman ---"<<endl;
            PrintUserTagTerbanyak(U,F);
            cout <<" Tekan '0' Untuk Kembali"<<endl;
            cout<<" ";
            cin >> Foto;
            break;
        case 9:
            system("CLS");
            cout <<"--- Tampilkan Foto ---"<<endl;
            PrintFoto(F);
            if(first(F)!=NULL){
                cout <<"Foto Yang Ingin Dilihat Tagnya: ";
                cin >> Foto;
            }
            PrintAllUserDalamSatuFoto(F,Foto);
            cout <<" Tekan '0' Untuk Kembali"<<endl;
            cout<<" ";
            cin >> Foto;
            break;
        }
    }while (pil != 0);

    return 0;
}
