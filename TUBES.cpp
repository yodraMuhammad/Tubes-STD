#include "TUBES.h"

void CreateListFoto(listfoto &L){
    first(L) = NULL;
}

void CreateListRelasi(listrelasi &L){
    first(L) = NULL;
}

void CreateListUser(listuser &L){
    first(L) = NULL;
}

address AlokasiFoto(infotypefoto X){
    address P = new elmlistfoto;
    info(P) = X;
    next(P) = NULL;
    CreateListRelasi(relasi(P));
    return P;
}

address_user AlokasiUser(infotypeuser X){
    address_user P = new elmlistuser;
    info(P) = X;
    next(P) = NULL;
    return P;
}

address_relasi AlokasiRelasi(address_user X){
    address_relasi P = new elmlistrelasi;
    next(P) = NULL;
    user(P) = X;
    return P;
}

address_user CariUser(infotypeuser X,listuser L){
    address_user P = first(L);
    while (P != NULL && info(P) != X){
        P = next(P);
    }
    if (info(P) == X){
        return P;
    }else{
        return NULL;
    }
}

address CariFoto(infotypefoto X, listfoto L){
    address P = first(L);
    while (P != NULL && info(P) != X){
        P = next(P);
    }
    if (info(P) == X){
        return P;
    }else{
        return NULL;
    }
}

void InsertFoto(listfoto &L, address P){
    next(P) = first(L);
    first(L) = P;
}

void InsertUser(listuser &L, address_user P){
    next(P) = first(L);
    first(L) = P;
}

void InsertRelasi(listrelasi &L, address_relasi P){
    next(P) = first(L);
    first(L) = P;
}

void DeleteFoto(listfoto &L,infotypefoto X){
    address P = first(L);
    address Q;
    if (info(P) == X){
        first(L) = next(P);
        delete P;
    }else{
        while ((info(next(P)) != X) && (next(P) != NULL)){
            P = next(P);
        }
        if (next(P) != NULL){
            Q = next(P);
            next(P) = next(Q);
            delete Q;
        }
    }
}

void DeleteUser(listuser &L,infotypeuser X){
    address_user P = first(L);
    address_user Q;
    if (info(P) == X){
        first(L) = next(P);
        delete P;
    }else{
        while ((info(next(P)) != X) && (next(P) != NULL)){
            P = next(P);
        }
        if (next(P) != NULL){
            Q = next(P);
            next(P) = next(Q);
            delete Q;
        }
    }
}

void PrintAllFoto(listfoto L){
    address P = first(L);
    address_relasi R;
    int a=1;
    if(P == NULL){
        cout<<" Foto Kosong "<<endl;
    }else{
        cout<<" Daftar Foto "<<endl;
        while (P != NULL){
            cout<<" "<<a<<". "<< info(P) <<endl;
            R = first(relasi(P));
            while (R != NULL){
                cout << "  -" << info(user(R)) << endl;
                R = next(R);
            }
            P = next(P);
            a++;
        }
    }
    cout<<endl;
}
void PrintUser(listuser L){
    address_user P = first(L);
    address_relasi R;
    int a=1;
    if(P == NULL){
        cout<<" User Kosong "<<endl;
    }else{
        cout<<" Daftar User "<<endl;
        while (P != NULL){
            cout<<" "<<a<<". "<< info(P) <<endl;
            P = next(P);
            a++;
        }
    }
    cout<<endl;
}

void PrintFoto(listfoto L){
   address P = first(L);
    int a=1;
    if(P == NULL){
        cout<<" Foto Kosong "<<endl;
    }else{
        cout<<" Daftar Foto "<<endl;
        while (P != NULL){
            cout<<" "<<a<<". "<< info(P) <<endl;
            P = next(P);
            a++;
        }
    }
    cout<<endl;
}

int HitungTag (listrelasi L){
    address_relasi P = first(L);
    int jml = 0;
    while (P != NULL){
        jml++;
        P = next(P);
    }
    return jml;
}

void PrintFotoTagTerbanyak (listfoto L){
    if(first(L)!=NULL){
        address P = first(L);
        address Q = next(P);
        int a,b;
        a = HitungTag(relasi(P));
        while (Q != NULL){
            b = HitungTag(relasi(Q));
            if (b > a){
                P = Q;
                a = b;
            }
            Q = next(Q);
        }
        cout <<" Foto: " << info(P) <<endl;
        cout <<" Dengan Jumlah Tag: " << a << endl;
    }else{
        cout<<"Foto Kosong"<<endl;
    }
}

int FoundUser (listrelasi L, address_user X){
    address_relasi P = first(L);
    bool found = false;
    int jml = 0;
    while (P != NULL && found == false){
        if (user(P) == X){
            found = true;
            jml = 1;
        }
        P = next(P);
    }
    return jml;
}

void PrintUserTagTerbanyak (listuser L1, listfoto L2){
    if((first(L1)!=NULL)&&(first(L2)!=NULL)){
        address Q;
        address_user P = first(L1);
        int a,jmla,b,jmlb = 0;
        Q = first(L2);
        while (Q != NULL ){
            a = FoundUser(relasi(Q),P);
            jmla = jmla + a;
            Q = next(Q);
        }
        address_user R = next(P);
        while (R != NULL){
            Q = first(L2);
            while (Q != NULL){
                b = FoundUser(relasi(Q),R);
                jmlb = jmlb + b;
                Q = next(Q);
            }
            if (jmla < jmlb){
                P = R;
                jmla = jmlb;
                jmlb = 0;
            }else{
                jmlb = 0;
            }
            R = next(R);
        }
        cout << "User Dengan Tag Terbanyak: " << info(P) << endl;
    }else{
        cout<<"List Kosong"<<endl;
    }
}

void PrintAllUserDalamSatuFoto(listfoto L, infotypefoto X){
    if(first(L)!=NULL){
        address P = first(L);
        address_relasi R;
        while (P != NULL && info(P) != X){
            P = next(P);
        }
        if (info(P) == X){
            R = first(relasi(P));
            if (first(relasi(P)) == NULL){
                cout << "Tag Tidak Ada" << endl;
            }else{
                while (R != NULL){
                    cout <<" -"<< info(user(R))<<endl;
                    R = next(R);
                }
            }
        }
    }
}
void Menu(){
        cout<<"-----------  MENU  -----------"<<endl;
        cout<<"  1.Menambah Foto Baru"<<endl;
        cout<<"  2.Menambah Teman Baru"<<endl;
        cout<<"  3.Menghubungkan Foto dengan Teman"<<endl;
        cout<<"  4.Menghapus Foto"<<endl;
        cout<<"  5.Menghapus Teman"<<endl;
        cout<<"  6.Menampilkan Semua Foto Dengan Tag-nya"<<endl;
        cout<<"  7.Menampilkan Foto Yang Memiliki Tag Terbanyak"<<endl;
        cout<<"  8.Menampilkan Teman dengan Tag Terbanyak"<<endl;
        cout<<"  9.Menampilkan Teman-Teman DiFoto Tertentu"<<endl;
        cout<<"  0.Exit"<<endl;
};
