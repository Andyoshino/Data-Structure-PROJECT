#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
using namespace std;
#define cls() system("CLS")
// untuk Customer
#define firstC(L) L.firstCustomer
#define userName(P) P->userName
#define nextC(P) P->nextCustomer
typedef struct elmCustomer *addressCustomer;
struct elmCustomer {
    string userName;
    addressCustomer nextCustomer;
};
struct listCustomer {
    addressCustomer firstCustomer;
};
void createlistCustomer(listCustomer &LC);
addressCustomer createElemenCustomer(string username_customer);
void insertFirstCustomer(listCustomer &LC, addressCustomer P);
void insertLastCustomer(listCustomer &LC, addressCustomer P);
void insertAfterCustomer(addressCustomer &addressPrec, addressCustomer P);
void insertAscendingCustomer(listCustomer &LC, addressCustomer P);
bool checkUsernameSama(listCustomer &LC, string username_customer);
void printCustomer(listCustomer LC);
addressCustomer searchCustomer(listCustomer LC, string username_customer);
addressCustomer searchCustomerLogin(listCustomer LC, string username_customer);
void deleteCustomer(listCustomer &LC, string username, addressCustomer &addressTampung);
// untuk Produk
#define nextP(P) P->nextProduk
#define namaProduk(P) P->produk
#define firstP(L) L.firstProduk
typedef struct elmProduk *addressProduk;
struct elmProduk {
    string produk;
    addressProduk nextProduk;
};
struct listProduk {
    addressProduk firstProduk;
};
void createlistProduk(listProduk &LP);
void insertLastProduk(listProduk &LP, addressProduk P);
addressProduk createElemenProduk(string nama_produk);
void printProduk(listProduk LP);
addressProduk searchProduk(listProduk LP, string nama_produk);
void deleteFirstProduk(listProduk &LP, addressProduk &pointerPenampung);
void deleteLastProduk(listProduk &LP, addressProduk &pointerPenampung);
void deleteAfterProduk(listProduk &LP, addressProduk pointerHapus, addressProduk &pointerPenampung);
// untuk Relasi
#define firstR(L) L.firstRelasi
#define rating(P) P->rating
#define nextR(P) P->nextRelasi
#define customerRating(P) P->customerPerating
#define produkRating(P) P->ratedProduk
typedef double Rating;
typedef struct elmRelasi *addressRelasi;
struct elmRelasi {
    addressRelasi nextRelasi;
    addressCustomer customerPerating;
    addressProduk ratedProduk;
    Rating rating;
};
struct listRelasi {
    addressRelasi firstRelasi;
};
void createlistRelasi(listRelasi &LR);
void insertRating(listRelasi &LR, addressRelasi P);
addressRelasi createElemenRelasi(addressCustomer addressC, addressProduk addressP, Rating rating_user);
void printRatingan(listRelasi LR, addressCustomer P);
addressRelasi searchRating(listRelasi LR, addressCustomer pointerC, addressProduk pointerP);
void deleteFirstRating(listRelasi &LR, addressRelasi &pointerPenampung);
void deleteLastRating(listRelasi &LR, addressRelasi &pointerPenampung);
void deleteAfterRating(listRelasi &LR, addressRelasi addressHapus, addressRelasi &pointerPenampung);
void deleteRating(listRelasi &LR, addressRelasi addressHapus, addressRelasi &pointerPenampung);
void printBelumRate(listRelasi LR, addressCustomer addressC, listProduk LP);
// untuk Non-list
void mainMenu();
// ->Untuk Admin
void menuLoginAdmin(string &username, string &password);
bool cekInfoAdmin(string username, string password);
void menuAdmin();
void printAverageProdukRating(listRelasi LR, listProduk LP);
void printDetailedCustomerRating(listRelasi LR, listCustomer LC);
void printBySearch(listRelasi LR, addressCustomer P);
// end of admin
// ->Untuk login user
void menuLoginUser(string &username_user);
void menuUser();
// ->Untuk non-login user
void menuNonLoginUser();
void printSortRating(listRelasi LR, listProduk LP);
#endif // HEADER_H_INCLUDED
