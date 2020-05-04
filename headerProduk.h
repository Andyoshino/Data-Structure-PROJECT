#ifndef HEADERPRODUK_H_INCLUDED
#define HEADERPRODUK_H_INCLUDED

#include "iostream"
using namespace std;

#define nextP(P) P->nextProduk
#define infoProduk(P) P->infoProduk
#define firstP(L) L.firstProduk
typedef struct elmProduk *addressProduk;
struct infotypeProduk {
    string namaProduk;
    string deskripsiProduk;
    string produsen;
};
struct elmProduk {
    infotypeProduk infoProduk;
    addressProduk nextProduk;
};
struct listProduk {
    addressProduk firstProduk;
};
void createlistProduk(listProduk &LP);
void insertLastProduk(listProduk &LP, addressProduk P);
addressProduk createElemenProduk(string namaProduk, string deskripsiProduk, string produsen);
void printProduk(listProduk LP);
addressProduk searchProduk(listProduk LP, string nama_produk);
void deleteFirstProduk(listProduk &LP, addressProduk &pointerPenampung);
void deleteLastProduk(listProduk &LP, addressProduk &pointerPenampung);
void deleteAfterProduk(listProduk &LP, addressProduk pointerHapus, addressProduk &pointerPenampung);

#endif // HEADERPRODUK_H_INCLUDED
