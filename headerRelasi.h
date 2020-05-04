#ifndef HEADERRELASI_H_INCLUDED
#define HEADERRELASI_H_INCLUDED

#include "headerCustomer.h"
#include "headerProduk.h"

#define firstR(L) L.firstRelasi
#define infoRelasi(P) P->infoRelasi
#define nextR(P) P->nextRelasi
#define customerRating(P) P->customerPerating
#define produkRating(P) P->ratedProduk
typedef struct elmRelasi *addressRelasi;
struct infotypeRelasi {
    double rating;
    string review;
};
struct elmRelasi {
    addressRelasi nextRelasi;
    addressCustomer customerPerating;
    addressProduk ratedProduk;
    infotypeRelasi infoRelasi;
};
struct listRelasi {
    addressRelasi firstRelasi;
};
void createlistRelasi(listRelasi &LR);
void insertRating(listRelasi &LR, addressRelasi P);
addressRelasi createElemenRelasi(addressCustomer addressC, addressProduk addressP, double rating_user, string review_user);
void printRatingan(listRelasi LR, addressCustomer P);
addressRelasi searchRating(listRelasi LR, addressCustomer pointerC, addressProduk pointerP);
void deleteFirstRating(listRelasi &LR, addressRelasi &pointerPenampung);
void deleteLastRating(listRelasi &LR, addressRelasi &pointerPenampung);
void deleteAfterRating(listRelasi &LR, addressRelasi addressHapus, addressRelasi &pointerPenampung);
void deleteRating(listRelasi &LR, addressRelasi addressHapus, addressRelasi &pointerPenampung);
void printBelumRate(listRelasi LR, addressCustomer addressC, listProduk LP);
void hapusRelasiSebelumHapusCustomer(listRelasi &listRate, string usernameCustomer);
void hapusRelasiSebelumHapusProduk(listRelasi &listRate, string namaProduk);

#endif // HEADERRELASI_H_INCLUDED
