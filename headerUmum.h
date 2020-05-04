#ifndef HEADERUMUM_H_INCLUDED
#define HEADERUMUM_H_INCLUDED

#include "headerCustomer.h"
#include "headerProduk.h"
#include "headerRelasi.h"

#define cls() system("CLS")

string inputanBerspasiPrimitif();
void mainMenu();
void menuLoginAdmin(string &username, string &password);
bool cekInfoAdmin(string username, string password);
void menuAdmin();
void printAverageProdukRating(listRelasi LR, listProduk LP);
void printDetailedCustomerRating(listRelasi LR, listCustomer LC);
void printBySearch(listRelasi LR, addressCustomer P);

void menuLoginUser(string &username_user, string &password_user);
void menuUser();

void menuNonLoginUser();
void printSortRating(listRelasi LR, listProduk LP);

//Fungsional admin
void insertProduk(listProduk &listProduct);
void showProduk(listProduk listProduct);
void updateProduk(listProduk &listProduct);
void hapusProduk(listRelasi &listRate, listProduk &listProduct);
void showCustomer(listCustomer listPelanggan);
void hapusCustomer(listRelasi &listRate, listCustomer &listPelanggan);
void showAverageProductRating(listRelasi listRate, listProduk listProduct);
void showDetailRatingCustomer(listRelasi listRate, listCustomer listPelanggan);

//Fungsional user
void rateProduk(listProduk &listProduct, listRelasi &listRate, addressCustomer addressLogin);
void reviewProduk(listProduk &listProduct, listRelasi &listRate, addressCustomer addressLogin);
void hapusRating(listRelasi &listRate, listProduk listProduct, addressCustomer addressLogin);
void showRatedProduk(listRelasi listRate, addressCustomer addressLogin);
void showUnratedProduk(listRelasi listRate, listProduk listProduct, addressCustomer addressLogin);
void updateDataCustomer(addressCustomer &addressLogin, listCustomer &listPelanggan);

//Fungsional non-login user
void registrasiCustomer(listCustomer &listPelanggan);
void showProductSortedByRating(listProduk listProduct, listRelasi listRate);
#endif // HEADERUMUM_H_INCLUDED

