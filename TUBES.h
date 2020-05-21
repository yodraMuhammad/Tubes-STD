#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) ((L).first)
#define relasi(P) (P)->relasi
#define user(P) (P)->user

typedef string infotypefoto;
typedef string infotypeuser;

typedef struct elmlistfoto *address;
typedef struct elmlistuser *address_user;
typedef struct elmlistrelasi *address_relasi;

struct elmlistuser{
    infotypeuser info;
    address_user next;
};

struct listuser{
    address_user first;
};

struct elmlistrelasi{
    address_relasi next;
    address_user user;
};

struct listrelasi{
    address_relasi first;
};

struct elmlistfoto{
    infotypefoto info;
    address next;
    listrelasi relasi;
};

struct listfoto{
    address first;
};

void CreateListFoto(listfoto &L);
void CreateListRelasi(listrelasi &L);
void CreateListUser(listuser &L);
address AlokasiFoto (infotypefoto X);
address_user AlokasiUser(infotypeuser X);
address_relasi AlokasiRelasi(address_user X);
address_user CariUser(infotypeuser X,listuser L);
address CariFoto(infotypefoto X, listfoto L);
void InsertFoto(listfoto &L, address P);
void InsertUser(listuser &L, address_user P);
void InsertRelasi(listrelasi &L, address_relasi P);
void DeleteFoto(listfoto &L,infotypefoto X);
void DeleteUser(listuser &L,infotypeuser X);
void PrintAllFoto(listfoto L);
void PrintUser(listuser L);
void PrintFoto(listfoto L);
int HitungTag (listrelasi L);
void PrintFotoTagTerbanyak (listfoto L);
int FoundUser (listrelasi L, address_user X);
void PrintUserTagTerbanyak (listuser L1, listfoto L2);
void PrintAllUserDalamSatuFoto(listfoto L, infotypefoto X);
void Menu();

#endif // TUBES_H_INCLUDED
