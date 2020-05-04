#include "headerRelasi.h"

void createlistRelasi(listRelasi &LR) {
    firstR(LR) = NULL;
}
void insertRating(listRelasi &LR, addressRelasi P) {
    nextR(P) = firstR(LR);
    firstR(LR) = P;
}
addressRelasi createElemenRelasi(addressCustomer addressC, addressProduk addressP, double rating_user, string review_user) {
    addressRelasi pointerBaru = new elmRelasi;
    infoRelasi(pointerBaru).rating = rating_user;
    infoRelasi(pointerBaru).review = review_user;
    customerRating(pointerBaru) = addressC;
    produkRating(pointerBaru) = addressP;
    nextR(pointerBaru) = NULL;
    return pointerBaru;
}
void printRatingan(listRelasi LR, addressCustomer P) {
    addressRelasi pointerPrint = firstR(LR);
    int penghitung = 1;
    while (pointerPrint != NULL) {
        if (customerRating(pointerPrint) == P) {
            cout << "[" << penghitung << "] Nama produk : " << infoProduk(produkRating(pointerPrint)).namaProduk << endl;
            cout << "Produsen  : " << infoProduk(produkRating(pointerPrint)).produsen << endl;
            cout << "Deskripsi : " << infoProduk(produkRating(pointerPrint)).deskripsiProduk << endl;
            cout << "Rating yang anda berikan : " << infoRelasi(pointerPrint).rating << endl;
            cout << "Ulasan yang anda berikan : " << infoRelasi(pointerPrint).review << endl << endl;
            penghitung++;
        }
        pointerPrint = nextR(pointerPrint);
    }
}
addressRelasi searchRating(listRelasi LR, addressCustomer pointerC, addressProduk pointerP) {
    if (firstR(LR) == NULL) {
        return NULL;
    } else {
        addressRelasi pointerPencari = firstR(LR);
        while (nextR(pointerPencari) != NULL && (customerRating(pointerPencari) != pointerC || produkRating(pointerPencari)!= pointerP)) {
            pointerPencari = nextR(pointerPencari);
        }
        if (customerRating(pointerPencari) == pointerC && produkRating(pointerPencari) == pointerP) {
            return pointerPencari;
        } else {
            return NULL;
        }
    }
}
void deleteFirstRating(listRelasi &LR, addressRelasi &pointerPenampung) {
    if (firstR(LR) == NULL) {
        pointerPenampung = NULL;
    } else {
        pointerPenampung = firstR(LR);
        firstR(LR) = nextR(pointerPenampung);
        nextR(pointerPenampung) = NULL;
    }
}
void deleteLastRating(listRelasi &LR, addressRelasi &pointerPenampung) {
    if (firstR(LR) == NULL) {
        pointerPenampung = NULL;
    } else {
        if (nextR(firstR(LR)) == NULL) {
            deleteFirstRating(LR, pointerPenampung);
        } else {
            addressRelasi pointerPencari = firstR(LR);
            while (nextR(nextR(pointerPencari)) != NULL) {
                pointerPencari = nextR(pointerPencari);
            }
            pointerPenampung = nextR(pointerPencari);
            nextR(pointerPencari) = NULL;
        }
    }
}
void deleteAfterRating(listRelasi &LR, addressRelasi addressHapus, addressRelasi &pointerPenampung) {
    addressRelasi pointerPencari = firstR(LR);
    while (nextR(pointerPencari) != addressHapus) {
        pointerPencari = nextR(pointerPencari);
    }
    pointerPenampung = addressHapus;
    nextR(pointerPencari) = nextR(pointerPenampung);
    nextR(pointerPenampung) = NULL;
}
void deleteRating(listRelasi &LR, addressRelasi addressHapus, addressRelasi &pointerPenampung) {
    if (firstR(LR) == addressHapus) {
        deleteFirstRating(LR, pointerPenampung);
    } else if (nextR(addressHapus) == NULL) {
        deleteLastRating(LR, pointerPenampung);
    } else {
        deleteAfterRating(LR, addressHapus, pointerPenampung);
    }
}
void printBelumRate(listRelasi LR, addressCustomer addressC, listProduk LP) {
    if (firstP(LP) != NULL) {
        addressProduk addressP = firstP(LP);
        addressRelasi addressR;
        int penghitung = 1;
        while (addressP != NULL) {
            addressR = firstR(LR);
            while (addressR != NULL && (customerRating(addressR) != addressC || produkRating(addressR) != addressP)) {
                addressR = nextR(addressR);
            }
            if (addressR == NULL) {
                cout << "[" << penghitung << "] Nama produk : " << infoProduk(addressP).namaProduk << endl;
                cout << "Produsen  : " << infoProduk(addressP).produsen << endl;
                cout << "Deskripsi : " << infoProduk(addressP).deskripsiProduk << endl << endl;
                penghitung++;
            }
            addressP = nextP(addressP);
        }
    }
}
void hapusRelasiSebelumHapusCustomer(listRelasi &listRate, string usernameCustomer) {
    addressRelasi addressPenampungRelasi;
    addressRelasi addressR = firstR(listRate);
    while (addressR != NULL) {
        if (infoCustomer(customerRating(addressR)).username == usernameCustomer) {
            if (addressR == firstR(listRate)) {
                deleteFirstRating(listRate, addressPenampungRelasi);
                addressR = firstR(listRate);
            } else if (nextR(addressR) == NULL) {
                deleteLastRating(listRate, addressPenampungRelasi);
                addressR = firstR(listRate);
            } else {
                deleteAfterRating(listRate, addressR, addressPenampungRelasi);
                addressR = firstR(listRate);
            }
        } else {
            addressR = nextR(addressR);
        }
    }
}
void hapusRelasiSebelumHapusProduk(listRelasi &listRate, string namaProduk) {
    addressRelasi addressPenampungRelasi;
    addressRelasi addressR = firstR(listRate);
    while (addressR != NULL) {
        if (infoProduk(produkRating(addressR)).namaProduk == namaProduk) {
            if (addressR == firstR(listRate)) {
                deleteFirstRating(listRate, addressPenampungRelasi);
                addressR = firstR(listRate);
            } else if (nextR(addressR) == NULL) {
                deleteLastRating(listRate, addressPenampungRelasi);
                addressR = firstR(listRate);
            } else {
                deleteAfterRating(listRate, addressR, addressPenampungRelasi);
                addressR = firstR(listRate);
            }
        } else {
            addressR = nextR(addressR);
        }
    }
}

