/*
Author : Butrahandisya - 1301190206 - IF-43-08
*/
#include "header.h"
//Untuk list
// -> Untuk customer
void createlistCustomer(listCustomer &LC) {
    firstC(LC) = NULL;
}
addressCustomer createElemenCustomer(string username_customer) {
    addressCustomer pointerBaru = new elmCustomer;
    nextC(pointerBaru) = NULL;
    userName(pointerBaru) = username_customer;
    return pointerBaru;
}
void insertFirstCustomer(listCustomer &LC, addressCustomer P) {
    nextC(P) = firstC(LC);
    firstC(LC) = P;
}
void insertLastCustomer(listCustomer &LC, addressCustomer P) {
    addressCustomer pencariLast = firstC(LC);
    if (pencariLast == NULL) {
        insertFirstCustomer(LC, P);
    } else {
        while (nextC(pencariLast) != NULL) {
            pencariLast = nextC(pencariLast);
        }
        nextC(pencariLast) = P;
    }
}
void insertAfterCustomer(addressCustomer &addressPrec, addressCustomer P) {
    nextC(P) = nextC(addressPrec);
    nextC(addressPrec) = P;
}
void insertAscendingCustomer(listCustomer &LC, addressCustomer P) {
    if (firstC(LC) == NULL) {
        insertFirstCustomer(LC, P);
    } else {
        if (userName(P) < userName(firstC(LC))) {
            insertFirstCustomer(LC, P);
        } else {
            addressCustomer pointerPencari = firstC(LC);
            while (nextC(pointerPencari) != NULL && userName(P) > userName(nextC(pointerPencari))) {
                pointerPencari = nextC(pointerPencari);
            }
            if (nextC(pointerPencari) == NULL) {
                insertLastCustomer(LC, P);
            } else {
                insertAfterCustomer(pointerPencari, P);
            }
        }
    }
}
bool checkUsernameSama(listCustomer &LC, string username_customer) {
    addressCustomer pointerMencari = firstC(LC);
    if (pointerMencari == NULL) {
        return false;
    } else {
        while (pointerMencari != NULL && userName(pointerMencari) != username_customer) {
            pointerMencari = nextC(pointerMencari);
        }
        return pointerMencari != NULL;
    }
}
void printCustomer(listCustomer LC) {
    addressCustomer pointerPrint = firstC(LC);
    if (pointerPrint == NULL) {
        cout << "Tidak ada customer yang terdaftar..." << endl;
    } else {
        int penghitung = 1;
        while (pointerPrint != NULL) {
            cout << "[" << penghitung << "] Username : " << userName(pointerPrint) << endl;
            penghitung++;
            pointerPrint = nextC(pointerPrint);
        }
        cout << endl;
    }
}
addressCustomer searchCustomer(listCustomer LC, string username_customer) {
    addressCustomer pointerPencari = firstC(LC);
    if (firstC(LC) == NULL) {
        return NULL;
    } else {
        while (nextC(pointerPencari) != NULL && userName(nextC(pointerPencari)) != username_customer) {
            pointerPencari = nextC(pointerPencari);
        }
        if (nextC(pointerPencari) == NULL) {
            return NULL;
        } else {
            return pointerPencari;
        }
    }
}
addressCustomer searchCustomerLogin(listCustomer LC, string username_customer) {
    addressCustomer pointerPencari = firstC(LC);
    if (firstC(LC) == NULL) {
        return NULL;
    } else {
        while (nextC(pointerPencari) != NULL && userName(pointerPencari) != username_customer) {
            pointerPencari = nextC(pointerPencari);
        }
        if (userName(pointerPencari) == username_customer) {
            return pointerPencari;
        } else {
            return NULL;
        }
    }
}
void deleteCustomer(listCustomer &LC, string username, addressCustomer &addressTampung) {
    if (firstC(LC) == NULL) {
        cout << "Username " << username << " tidak ditemukan..." << endl;
        addressTampung = NULL;
    } else {
        if (userName(firstC(LC)) == username) {
            addressTampung = firstC(LC);
            firstC(LC) = nextC(addressTampung);
            nextC(addressTampung) = NULL;
            cout << "Customer dengan username " << username << " berhasil dihapus!" << endl;
        } else {
            addressCustomer pointerCari = searchCustomer(LC, username);
            if (pointerCari == NULL) {
                cout << "Username " << username << " tidak ditemukan..." << endl;
                addressTampung = NULL;
            } else {
                addressTampung = nextC(pointerCari);
                nextC(pointerCari) = nextC(addressTampung);
                nextC(addressTampung) = NULL;
                cout << "Customer dengan username " << username << " berhasil dihapus!" << endl;
            }
        }
    }
}
// -> Untuk produk
void createlistProduk(listProduk &LP) {
    firstP(LP) = NULL;
}
void insertLastProduk(listProduk &LP, addressProduk P) {
    if (firstP(LP) == NULL) {
        firstP(LP) = P;
    } else {
        addressProduk pointerPencariLast = firstP(LP);
        while (nextP(pointerPencariLast) != NULL) {
            pointerPencariLast = nextP(pointerPencariLast);
        }
        nextP(pointerPencariLast) = P;
    }
}
addressProduk createElemenProduk(string nama_produk) {
    addressProduk pointerBaru = new elmProduk;
    nextP(pointerBaru) = NULL;
    namaProduk(pointerBaru) = nama_produk;
    return pointerBaru;
}
void printProduk(listProduk LP) {
    addressProduk pointerPrint = firstP(LP);
    if (firstP(LP) != NULL) {
        int nomoR = 1;
        while (pointerPrint != NULL) {
            cout << "[" << nomoR << "] " << namaProduk(pointerPrint) << endl;
            nomoR++;
            pointerPrint = nextP(pointerPrint);
        }
    } else {
        cout << "Belum ada produk yang terdaftar..." << endl;
    }
}
addressProduk searchProduk(listProduk LP, string nama_produk) {
    addressProduk pointerPencari = firstP(LP);
    if (pointerPencari == NULL) {
        return NULL;
    } else {
        while (nextP(pointerPencari) != NULL && namaProduk(pointerPencari) != nama_produk) {
            pointerPencari = nextP(pointerPencari);
        }
        if (namaProduk(pointerPencari) == nama_produk) {
            return pointerPencari;
        } else {
            return NULL;
        }
    }
}
void deleteFirstProduk(listProduk &LP, addressProduk &pointerPenampung) {
    pointerPenampung = firstP(LP);
    if (next(firstP(LP)) == NULL) {
        firstP(LP) = NULL;
    } else {
        firstP(LP) = nextP(pointerPenampung);
        nextP(pointerPenampung) = NULL;
    }
}
void deleteLastProduk(listProduk &LP, addressProduk &pointerPenampung) {
    addressProduk pointerPencariLast = firstP(LP);
    if (nextP(pointerPencariLast) == NULL) {
        deleteFirstProduk(LP, pointerPenampung);
    } else {
        while (nextP(nextP(pointerPencariLast)) != NULL) {
            pointerPencariLast = nextP(pointerPencariLast);
        }
        pointerPenampung = nextP(pointerPencariLast);
        nextP(pointerPencariLast) = NULL;
    }
}
void deleteAfterProduk(listProduk &LP, addressProduk pointerHapus, addressProduk &pointerPenampung) {
    addressProduk pointerPencari = firstP(LP);
    while (nextP(pointerPencari) != pointerHapus) {
        pointerPencari = nextP(pointerPencari);
    }
    pointerPenampung = nextP(pointerPencari);
    nextP(pointerPencari) = nextP(pointerPenampung);
    nextP(pointerPenampung) = NULL;
}
// end of produk
// ->Untuk relasi
void createlistRelasi(listRelasi &LR) {
    firstR(LR) = NULL;
}
void insertRating(listRelasi &LR, addressRelasi P) {
    nextR(P) = firstR(LR);
    firstR(LR) = P;
}
addressRelasi createElemenRelasi(addressCustomer addressC, addressProduk addressP, Rating rating_user) {
    addressRelasi pointerBaru = new elmRelasi;
    rating(pointerBaru) = rating_user;
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
            cout << "[" << penghitung << "] Nama produk : " << namaProduk(produkRating(pointerPrint)) << endl;
            cout << "Rating yang anda berikan : " << rating(pointerPrint) << endl << endl;
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
                cout << "[" << penghitung << "] Nama produk : " << namaProduk(addressP) << endl;
                penghitung++;
            }
            addressP = nextP(addressP);
        }
    }
}
//Kebutuhan non-list
void mainMenu() {
    cout << "[Product Rating]" << endl;
    cout << "[1] Log-in Admin" << endl;
    cout << "[2] Log-in Customer" << endl;
    cout << "[3] Non Log-in User" << endl;
    cout << "[4] Exit" << endl;
    cout << "Decision : ";
}
void menuLoginAdmin(string &username, string &password) {
    cout << "[Log-in Admin]" << endl;
    cout << "Username : ";
    cin >> username;
    cout << "Password : ";
    cin >> password;
}
bool cekInfoAdmin(string username, string password) {
    return (username == "admin" && password == "admin777");
}
void menuAdmin() {
    cout << "[Menu Admin]" << endl;
    cout << "[1] Insert data produk" << endl;
    cout << "[2] Lihat produk" << endl;
    cout << "[3] Update data produk" << endl;
    cout << "[4] Hapus data produk" << endl;
    cout << "[5] Lihat data customer" << endl;
    cout << "[6] Hapus data customer" << endl;
    cout << "[7] Lihat rata-rata rating dan detail rating setiap produk" << endl;
    cout << "[8] Lihat detail rating setiap customer" << endl;
    cout << "[9] Back" << endl;
    cout << "Decision : ";
}
string pilihanAdmin1() {
    string nama_produk;
    cout << "[Insert data produk]" << endl;
    cout << "Nama produk : ";
    cin >> nama_produk;
    return nama_produk;
}
void printAverageProdukRating(listRelasi LR, listProduk LP) {
    if (firstP(LP) != NULL) {
        addressProduk pointerMaju = firstP(LP);
        addressRelasi pointerRelasi;
        Rating totalRating;
        int penghitung = 1;
        double jumlahOrang;
        bool pendeteksi;
        cout << "[Produk yang sudah pernah di-rate setidaknya oleh 1 orang]" << endl;
        while (pointerMaju != NULL)  {
            totalRating = 0;
            jumlahOrang = 0;
            pendeteksi = false;
            pointerRelasi = firstR(LR);
            while (pointerRelasi != NULL) {
                if (produkRating(pointerRelasi) == pointerMaju) {
                    totalRating = totalRating + rating(pointerRelasi);
                    jumlahOrang++;
                }
                pointerRelasi = nextR(pointerRelasi);
            }
            cout << "[" << penghitung << "] Nama produk : " << namaProduk(pointerMaju) << endl;
            if (jumlahOrang > 0) {
                cout << "Rata-rata rating : " << totalRating/jumlahOrang << endl;
                cout << "Customer yang me-rating : ";
                pointerRelasi = firstR(LR);
                while (pointerRelasi != NULL) {
                    if (produkRating(pointerRelasi) == pointerMaju) {
                        if (!pendeteksi) {
                            cout << userName(customerRating(pointerRelasi)) << endl;
                            pendeteksi = true;
                        } else {
                            cout << "                          " << userName(customerRating(pointerRelasi)) << endl;
                        }
                    }
                    pointerRelasi = nextR(pointerRelasi);
                }
            } else {
                cout << "Produk ini belum di-rate oleh siapapun." << endl;
            }
            cout << endl;
            penghitung++;
            pointerMaju = nextP(pointerMaju);
        }

    }
}
void printDetailedCustomerRating(listRelasi LR, listCustomer LC) {
    if (firstC(LC) != NULL) {
        addressCustomer pointerMaju = firstC(LC);
        addressRelasi pointerRelasi;
        int penghitung = 1;
        while (pointerMaju != NULL) {
            pointerRelasi = firstR(LR);
            cout << "[" << penghitung << "] Username : " << userName(pointerMaju) << endl;
            cout << "[Produk-produk yang sudah di-rate oleh " << userName(pointerMaju) << "]" << endl;
            while (pointerRelasi != NULL) {
                if (customerRating(pointerRelasi) == pointerMaju) {
                    cout << "Nama produk : " << namaProduk(produkRating(pointerRelasi)) << endl;
                    cout << "Rating      : " << rating(pointerRelasi) << endl << endl;
                }
                pointerRelasi = nextR(pointerRelasi);
            }
            pointerMaju = nextC(pointerMaju);
        }
    }
}
void printBySearch(listRelasi LR, addressCustomer P) {
    if (firstR(LR) != NULL) {
        cout << "Username : " << userName(P) << endl;
        cout << "[Produk-produk yang sudah di-rate oleh " << userName(P) << "]" << endl;
        addressRelasi pointerMaju = firstR(LR);
        int penghitung = 1;
        while (pointerMaju != NULL) {
            if (customerRating(pointerMaju) == P) {
                cout << "[" << penghitung << "] Nama produk : " << namaProduk(produkRating(pointerMaju)) << endl;
                cout << "Rating : " << rating(pointerMaju) << endl << endl;
                penghitung++;
            }
            pointerMaju = nextR(pointerMaju);
        }
    }
}
// ->Untuk non-login user
void menuNonLoginUser() {
    cout << "[Menu non-login user]" << endl;
    cout << "[1] Sign-up customer" << endl;
    cout << "[2] Lihat semua produk (dengan ratingnya)" << endl;
    cout << "[3] Back" << endl;
    cout << "Decision : ";
}
void printSortRating(listRelasi LR, listProduk LP) {
    listRelasi listPrint;
    createlistRelasi(listPrint);
    addressProduk pointerMaju;
    addressRelasi pointerRelasi, pointerTumbal;
    Rating rataRata;
    double jumlahOrang;
    pointerMaju = firstP(LP);
    while (pointerMaju != NULL) {
        pointerRelasi = firstR(LR);
        rataRata = 0;
        jumlahOrang = 0;
        while (pointerRelasi != NULL) {
            if (produkRating(pointerRelasi) == pointerMaju) {
                rataRata = rataRata + rating(pointerRelasi);
                jumlahOrang++;
            }
            pointerRelasi = nextR(pointerRelasi);
        }
        pointerTumbal = createElemenRelasi(NULL, pointerMaju, rataRata/jumlahOrang);
        if (firstR(listPrint) == NULL) {
            //Insert first
            firstR(listPrint) = pointerTumbal;
        } else {
            if (nextR(firstR(listPrint)) == NULL) {
                if (rating(pointerTumbal) >  rating(firstR(listPrint))) {
                    //Insert first
                    nextR(pointerTumbal) = firstR(listPrint);
                    firstR(listPrint) = pointerTumbal;
                } else {
                    //Insert last
                    nextR(firstR(listPrint)) = pointerTumbal;
                }
            } else {
                if (rating(pointerTumbal) >  rating(firstR(listPrint))) {
                    //Insert first
                    nextR(pointerTumbal) = firstR(listPrint);
                    firstR(listPrint) = pointerTumbal;
                } else {
                    addressRelasi pencariPrec = firstR(listPrint);
                    while (nextR(pencariPrec) != NULL && rating(nextR(pencariPrec)) > rating(pointerTumbal)) {
                        pencariPrec = nextR(pencariPrec);
                    }
                    if (nextR(pencariPrec) == NULL) {
                        //Insert last
                        nextR(pencariPrec) = pointerTumbal;
                    } else {
                        //Insert after
                        nextR(pointerTumbal) = nextR(pencariPrec);
                        nextR(pencariPrec) = pointerTumbal;
                    }
                }
            }
        }
        pointerMaju = nextP(pointerMaju);
    }
    pointerRelasi = firstR(listPrint);
    int penghitung = 1;
    while (pointerRelasi != NULL) {
        cout << "[" << penghitung << "] Nama produk : " << namaProduk(produkRating(pointerRelasi)) << endl;
        cout << "Dengan rata-rata rating : " << rating(pointerRelasi) << endl;
        penghitung++;
        pointerRelasi = nextR(pointerRelasi);
    }
}
// ->Untuk login user
void menuLoginUser(string &username_user) {
    cout << "[Log-in user]" << endl;
    cout << "Username : ";
    cin >> username_user;
}
void menuUser() {
    cout << "[Menu user]" << endl;
    cout << "[1] Rate produk" << endl;
    cout << "[2] Hapus rating-an" << endl;
    cout << "[3] Lihat produk yang telah di-rate" << endl;
    cout << "[4] Lihat produk yang belum di-rate" << endl;
    cout << "[5] Update data akun" << endl;
    cout << "[6] Back" << endl;
    cout << "Decision : ";
}
