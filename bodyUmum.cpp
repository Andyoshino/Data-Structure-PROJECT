#include "headerUmum.h"


string inputanBerspasiPrimitif() {
    string stringReturn;
    string penampung = "";
    int kataKe = 0;
    while (penampung != "$") {
        cin >> penampung;
        if (kataKe > 0) {
            if (penampung != "$") {
                stringReturn = stringReturn + " " + penampung;
            }
        } else {
            if (penampung != "$") {
                stringReturn = penampung;
            }
        }
        kataKe = kataKe + 1;
    }
    return stringReturn;
}
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
    return (username == "admin" && password == "admin");
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

void printAverageProdukRating(listRelasi LR, listProduk LP) {
    if (firstP(LP) != NULL) {
        addressProduk pointerMaju = firstP(LP);
        addressRelasi pointerRelasi;
        double totalRating;
        int penghitung = 1;
        double jumlahOrang;
        bool pendeteksi;
        while (pointerMaju != NULL)  {
            totalRating = 0;
            jumlahOrang = 0;
            pendeteksi = false;
            pointerRelasi = firstR(LR);
            while (pointerRelasi != NULL) {
                if (produkRating(pointerRelasi) == pointerMaju) {
                    totalRating = totalRating + infoRelasi(pointerRelasi).rating;
                    jumlahOrang++;
                }
                pointerRelasi = nextR(pointerRelasi);
            }
            cout << "[" << penghitung << "] Nama produk : " << infoProduk(pointerMaju).namaProduk << endl;
            cout << "Produsen  : " << infoProduk(pointerMaju).produsen << endl;
            cout << "Deskripsi : " << infoProduk(pointerMaju).deskripsiProduk << endl;
            if (jumlahOrang > 0) {
                cout << "Rata-rata rating : " << totalRating/jumlahOrang << endl;
                cout << "Customer yang me-rating : ";
                pointerRelasi = firstR(LR);
                while (pointerRelasi != NULL) {
                    if (produkRating(pointerRelasi) == pointerMaju) {
                        if (!pendeteksi) {
                            cout << infoCustomer(customerRating(pointerRelasi)).username << endl;
                            pendeteksi = true;
                        } else {
                            cout << "                          " << infoCustomer(customerRating(pointerRelasi)).username << endl;
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
            cout << "[" << penghitung << "] Username : " << infoCustomer(pointerMaju).username << endl;
            cout << "[Produk-produk yang sudah di-rate oleh " << infoCustomer(pointerMaju).username << "]" << endl;
            penghitung = penghitung + 1;
            while (pointerRelasi != NULL) {
                if (customerRating(pointerRelasi) == pointerMaju) {
                    cout << "Nama produk : " << infoProduk(produkRating(pointerRelasi)).namaProduk << endl;
                    cout << "Produsen    : " << infoProduk(produkRating(pointerRelasi)).produsen  << endl;
                    cout << "Deskripsi   : " << infoProduk(produkRating(pointerRelasi)).deskripsiProduk << endl;
                    cout << "Rating      : " << infoRelasi(pointerRelasi).rating << endl;
                    cout << "Ulasan      : " << infoRelasi(pointerRelasi).review << endl << endl;
                }
                pointerRelasi = nextR(pointerRelasi);
            }
            pointerMaju = nextC(pointerMaju);
            cout << endl;
        }
    }
}
void printBySearch(listRelasi LR, addressCustomer P) {
    if (firstR(LR) != NULL) {
        cout << "Username     : " << infoCustomer(P).username << endl;
        cout << "Nama lengkap : " << infoCustomer(P).namaLengkap << endl;
        cout << "[Produk-produk yang sudah di-rate oleh " << infoCustomer(P).username << "]" << endl;
        addressRelasi pointerMaju = firstR(LR);
        int penghitung = 1;
        while (pointerMaju != NULL) {
            if (customerRating(pointerMaju) == P) {
                cout << "[" << penghitung << "] Nama produk : " << infoProduk(produkRating(pointerMaju)).namaProduk << endl;
                cout << "Produsen  : " << infoProduk(produkRating(pointerMaju)).produsen << endl;
                cout << "Deskripsi : " << infoProduk(produkRating(pointerMaju)).deskripsiProduk << endl;
                cout << "Rating    : " << infoRelasi(pointerMaju).rating << endl;
                cout << "Ulasan    : " << infoRelasi(pointerMaju).review << endl << endl;
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
    double rataRata;
    double jumlahOrang;
    pointerMaju = firstP(LP);
    while (pointerMaju != NULL) {
        pointerRelasi = firstR(LR);
        rataRata = 0;
        jumlahOrang = 0;
        while (pointerRelasi != NULL) {
            if (produkRating(pointerRelasi) == pointerMaju) {
                rataRata = rataRata + infoRelasi(pointerRelasi).rating;
                jumlahOrang++;
            }
            pointerRelasi = nextR(pointerRelasi);
        }
        if (jumlahOrang > 0) {
            pointerTumbal = createElemenRelasi(NULL, pointerMaju, rataRata/jumlahOrang, "");
            if (firstR(listPrint) == NULL) {
                //Insert first
                firstR(listPrint) = pointerTumbal;
            } else {
                if (nextR(firstR(listPrint)) == NULL) {
                    if (infoRelasi(pointerTumbal).rating > infoRelasi(firstR(listPrint)).rating) {
                        //Insert first
                        nextR(pointerTumbal) = firstR(listPrint);
                        firstR(listPrint) = pointerTumbal;
                    } else {
                        //Insert last
                        nextR(firstR(listPrint)) = pointerTumbal;
                    }
                } else {
                    if (infoRelasi(pointerTumbal).rating > infoRelasi(firstR(listPrint)).rating) {
                        //Insert first
                        nextR(pointerTumbal) = firstR(listPrint);
                        firstR(listPrint) = pointerTumbal;
                    } else {
                        addressRelasi pencariPrec = firstR(listPrint);
                        while (nextR(pencariPrec) != NULL && infoRelasi(nextR(pencariPrec)).rating > infoRelasi(pointerTumbal).rating) {
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
        }
        pointerMaju = nextP(pointerMaju);
    }
    pointerMaju = firstP(LP);
    while (pointerMaju != NULL) {
        pointerRelasi = firstR(LR);
        rataRata = 0;
        jumlahOrang = 0;
        while (pointerRelasi != NULL) {
            if (produkRating(pointerRelasi) == pointerMaju) {
                rataRata = rataRata + infoRelasi(pointerRelasi).rating;
                jumlahOrang++;
            }
            pointerRelasi = nextR(pointerRelasi);
        }
        if (jumlahOrang == 0) {
            pointerTumbal = createElemenRelasi(NULL, pointerMaju, -1, "");
            if (firstR(listPrint) == NULL) {
                //Insert first
                firstR(listPrint) = pointerTumbal;
            } else {
                if (nextR(firstR(listPrint)) == NULL) {
                    if (infoRelasi(pointerTumbal).rating > infoRelasi(firstR(listPrint)).rating) {
                        //Insert first
                        nextR(pointerTumbal) = firstR(listPrint);
                        firstR(listPrint) = pointerTumbal;
                    } else {
                        //Insert last
                        nextR(firstR(listPrint)) = pointerTumbal;
                    }
                } else {
                    if (infoRelasi(pointerTumbal).rating > infoRelasi(firstR(listPrint)).rating) {
                        //Insert first
                        nextR(pointerTumbal) = firstR(listPrint);
                        firstR(listPrint) = pointerTumbal;
                    } else {
                        addressRelasi pencariPrec = firstR(listPrint);
                        while (nextR(pencariPrec) != NULL && infoRelasi(nextR(pencariPrec)).rating > infoRelasi(pointerTumbal).rating) {
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
        }
        pointerMaju = nextP(pointerMaju);
    }
    pointerRelasi = firstR(listPrint);
    int penghitung = 1;
    while (pointerRelasi != NULL) {
        cout << "[" << penghitung << "] Nama produk : " << infoProduk(produkRating(pointerRelasi)).namaProduk << endl;
        cout << "Produsen         : " << infoProduk(produkRating(pointerRelasi)).produsen << endl;
        cout << "Deskripsi produk : " << infoProduk(produkRating(pointerRelasi)).deskripsiProduk << endl;
        if (infoRelasi(pointerRelasi).rating == -1) {
            cout << "Produk ini belum pernah di-rate oleh siapapun." << endl << endl;
        } else {
            cout << "Dengan rata-rata rating : " << infoRelasi(pointerRelasi).rating << endl << endl;
        }
        penghitung++;
        pointerRelasi = nextR(pointerRelasi);
    }
}
// ->Untuk login user
void menuLoginUser(string &username_user, string &password_user) {
    cout << "[Log-in user]" << endl;
    cout << "Username : ";
    cin >> username_user;
    cout << "Password : ";
    cin >> password_user;
}
void menuUser() {
    cout << "[Menu user]" << endl;
    cout << "[1] Rate produk" << endl;
    cout << "[2] Review produk" << endl;
    cout << "[3] Hapus rating-an" << endl;
    cout << "[4] Lihat produk yang telah di-rate" << endl;
    cout << "[5] Lihat produk yang belum di-rate" << endl;
    cout << "[6] Update data akun" << endl;
    cout << "[7] Back" << endl;
    cout << "Decision : ";
}

void insertProduk(listProduk &listProduct) {
    int decisionKembali = -1;
    string namaProduk, deskripsiProduk, produsen, stringPenampung;
    addressProduk addressP;
    while (decisionKembali != 2) {
        cout << "[Insert data produk]" << endl;
        cout << "Nama produk (akhiri dengan '$')     : ";
        namaProduk = inputanBerspasiPrimitif();
        cout << "Produsen (akhiri dengan '$')        : ";
        produsen = inputanBerspasiPrimitif();
        cout << "Deskripsi produk (akhiri dengan '$'): ";
        deskripsiProduk = inputanBerspasiPrimitif();
        addressP = createElemenProduk(namaProduk, deskripsiProduk, produsen);
        insertLastProduk(listProduct, addressP);
        cls();
        cout << "Produk berhasil ditambahkan!" << endl << endl;
        cout << "Apa yang anda ingin lakukan?" << endl;
        cout << "[1] Insert data produk lagi" << endl;
        cout << "[2] Kembali" << endl;
        cout << "Decision : ";
        cin >> decisionKembali;
        while (decisionKembali != 1 && decisionKembali != 2) {
            cout << "Inputan anda tidak valid..." << endl;
            cout << "Input ulang : ";
            cin >> decisionKembali;
        }
        cls();
    }
}
void showProduk(listProduk listProduct) {
    int decisionKembali = -1;
    while (decisionKembali != 1) {
        cout << "[Produk-produk]" << endl;
        printProduk(listProduct);
        cout << "[----------]" << endl;
        cout << "Kembali ?" << endl;
        cout << "[1] Ya" << endl;
        cout << "[2] Tidak" << endl;
        cout << "Decision : ";
        cin >> decisionKembali;
        while (decisionKembali != 1 && decisionKembali != 2) {
            cout << "Inputan anda tidak valid..." << endl;
            cout << "Input ulang : ";
            cin >> decisionKembali;
        }
        cls();
    }
}

void updateProduk(listProduk &listProduct) {
    int decisionAdmin = -1;
    int decisionKembali = -1;
    addressProduk addressP;
    while (decisionKembali != 2 && decisionAdmin != 4) {
        cout << "[Update data produk]" << endl;
        cout << "[1] Nama produk" << endl;
        cout << "[2] Deskripsi produk" << endl;
        cout << "[3] Produsen produk" << endl;
        cout << "[4] Exit update data produk" << endl;
        cout << "Data apa yang ingin anda hapus?" << endl;
        cout << "Decision : ";
        cin >> decisionAdmin;
        while (decisionAdmin < 1 || decisionAdmin > 4) {
            cout << "Inputan anda tidak valid..." << endl;
            cout << "Input ulang : ";
            cin >> decisionAdmin;
        }
        cls();
        if (decisionAdmin == 1) {
            string namaProduk;
            //Ganti nama produk
            cout << "[Produk-produk]" << endl;
            printProduk(listProduct);
            cout << "Nama produk yang ingin anda ganti namanya (akhiri dengan '$') : ";
            namaProduk = inputanBerspasiPrimitif();
            addressP = searchProduk(listProduct, namaProduk);
            cls();
            if (addressP == NULL) {
                cout << "Produk dengan nama " << namaProduk << " tidak terdaftar." << endl;
            } else {
                cout << "[Ganti nama produk]" << endl;
                cout << "Nama baru untuk produk (diakhiri dengan '$') : ";
                namaProduk = inputanBerspasiPrimitif();
                infoProduk(addressP).namaProduk = namaProduk;
            }

        } else if (decisionAdmin == 2) {
            string namaProduk, deskripsiProduk;
            //Ganti deskripsi produk
            cout << "[Produk-produk]" << endl;
            printProduk(listProduct);
            cout << "Nama produk yang ingin anda ganti deskripsinya (akhiri dengan '$') : ";
            namaProduk = inputanBerspasiPrimitif();
            addressP = searchProduk(listProduct, namaProduk);
            cls();
            if (addressP == NULL) {
                cout << "Produk dengan nama " << namaProduk << " tidak terdaftar." << endl;
            } else {
                cout << "[Ganti deskripsi produk]" << endl;
                cout << "Input deskripsi baru untuk produk (diakhiri dengan '$') : ";
                deskripsiProduk = inputanBerspasiPrimitif();
                infoProduk(addressP).deskripsiProduk = deskripsiProduk;
            }
        } else if (decisionAdmin == 3) {
            string namaProduk, produsenProduk;
            //Ganti deskripsi produk
            cout << "[Produk-produk]" << endl;
            printProduk(listProduct);
            cout << "Nama produk yang ingin anda ganti produsennya (akhiri dengan '$') : ";
            namaProduk = inputanBerspasiPrimitif();
            addressP = searchProduk(listProduct, namaProduk);
            cls();
            if (addressP == NULL) {
                cout << "Produk dengan nama " << namaProduk << " tidak terdaftar." << endl;
            } else {
                cout << "[Ganti produsen produk]" << endl;
                cout << "Produsen baru untuk produk (akhiri dengan '$') : ";
                produsenProduk = inputanBerspasiPrimitif();
                infoProduk(addressP).produsen = produsenProduk;
            }
        }
        if (decisionAdmin != 4) {
            cls();
            cout << "Update data produk berhasil dilakukan!" << endl;
            cout << "[----------]" << endl;
            cout << "Apa yang anda ingin lakukan?" << endl;
            cout << "[1] Update data produk lagi" << endl;
            cout << "[2] Kembali" << endl;
            cout << "Decision : ";
            cin >> decisionKembali;
            while (decisionKembali != 1 && decisionKembali != 2) {
                cout << "Inputan anda tidak valid..." << endl;
                cout << "Input ulang : ";
                cin >> decisionKembali;
            }
        }
        cls();
    }
}

void hapusProduk(listRelasi &listRate, listProduk &listProduct) {
    int decisionKembali = -1;
    string namaProduk;
    addressProduk addressP, addressDelete;
    while (decisionKembali != 2) {
        cout << "[Hapus produk]" << endl;
        cout << "Nama produk (akhiri dengan '$') : ";
        namaProduk = inputanBerspasiPrimitif();
        addressP = searchProduk(listProduct, namaProduk);
        cls();
        hapusRelasiSebelumHapusProduk(listRate, namaProduk);
        if (addressP != NULL) {
            if (addressP == firstP(listProduct)) {
                //Delete first
                deleteFirstProduk(listProduct, addressDelete);
            } else if (nextP(addressP) == NULL) {
                //Delete last
                deleteLastProduk(listProduct, addressDelete);
            } else {
                //Delete after
                deleteAfterProduk(listProduct, addressP, addressDelete);
            }
            cout << "Produk berhasil dihapus!" << endl;
        } else {
            cout << "Produk tidak ditemukan..." << endl;
        }
        cout << "Apa yang anda ingin lakukan?" << endl;
        cout << "[1] Hapus produk lagi" << endl;
        cout << "[2] Kembali" << endl;
        cout << "Decision : ";
        cin >> decisionKembali;
        while (decisionKembali != 1 && decisionKembali != 2) {
            cout << "Inputan anda tidak valid..." << endl;
            cout << "Input ulang : ";
            cin >> decisionKembali;
        }
        cls();
    }
}

void showCustomer(listCustomer listPelanggan) {
    int decisionKembali = -1;
    while (decisionKembali != 1) {
        cout << "[Daftar customer]" << endl;
        printCustomer(listPelanggan);
        cout << "[----------]" << endl;
        cout << "Kembali ?" << endl;
        cout << "[1] Ya" << endl;
        cout << "[2] Tidak" << endl;
        cout << "Decision : ";
        cin >> decisionKembali;
        while (decisionKembali != 1 && decisionKembali != 2) {
            cout << "Inputan anda tidak valid..." << endl;
            cout << "Input ulang : ";
            cin >> decisionKembali;
        }
        cls();
    }
}

void hapusCustomer(listRelasi &listRate, listCustomer &listPelanggan) {
    int decisionKembali = -1;
    string usernameCustomer;
    addressCustomer addressCTampung;
    while (decisionKembali != 2) {
        cout << "[Hapus customer]" << endl;
        printCustomer(listPelanggan);
        cout << "Username customer yang ingin anda hapus : ";
        cin >> usernameCustomer;
        cls();
        hapusRelasiSebelumHapusCustomer(listRate, usernameCustomer);
        deleteCustomer(listPelanggan, usernameCustomer, addressCTampung);
        cout << "Apa yang anda ingin lakukan?" << endl;
        cout << "[1] Hapus data customer lagi" << endl;
        cout << "[2] Kembali" << endl;
        cout << "Decision : ";
        cin >> decisionKembali;
        while (decisionKembali != 1 && decisionKembali != 2) {
            cout << "Inputan anda tidak valid..." << endl;
            cout << "Input ulang : ";
            cin >> decisionKembali;
        }
        cls();
    }
}

void showAverageProductRating(listRelasi listRate, listProduk listProduct) {
    int decisionKembali = -1;
    while (decisionKembali != 1) {
        cout << "[Rata-rata rating dari setiap produk dan customer yang me-rating]" << endl;
        printAverageProdukRating(listRate, listProduct);
        cout << "[----------]" << endl;
        cout << "Kembali ?" << endl;
        cout << "[1] Ya" << endl;
        cout << "[2] Tidak" << endl;
        cout << "Decision : ";
        cin >> decisionKembali;
        while (decisionKembali != 1 && decisionKembali != 2) {
            cout << "Inputan anda tidak valid..." << endl;
            cout << "Input ulang : ";
            cin >> decisionKembali;
        }
        cls();
    }
}

void showDetailRatingCustomer(listRelasi listRate, listCustomer listPelanggan) {
    int decisionKembali = -1;
    int decisionAdmin;
    addressCustomer addressC;
    while (decisionKembali != 1) {
        cout << "[Lihat detail rating setiap cutsomer]" << endl;
        cout << "[1] Lihat semua" << endl;
        cout << "[2] Search customer" << endl;
        cout << "Decision : ";
        cin >> decisionAdmin;
        cls();
        while (decisionAdmin != 1 && decisionAdmin != 2) {
            cout << "Inputan anda tidak valid..." << endl;
            cout << "Input ulang : ";
            cin >> decisionAdmin;
        }
        if (decisionAdmin == 1) {
            cout << "[Lihat detail rating setiap cutsomer]" << endl;
            printDetailedCustomerRating(listRate, listPelanggan);
        } else if (decisionAdmin == 2) {
            string usernameCustomer;
            cout << "[Lihat berdasar username]" << endl;
            printCustomer(listPelanggan);
            cout << "Nama customer yang anda lihat detail produk rating-nya : ";
            cin >> usernameCustomer;
            cls();
            addressC = searchCustomerPrint(listPelanggan, usernameCustomer);
            if (addressC == NULL) {
                cout << "Customer dengan username " << usernameCustomer << " tidak terdaftar." << endl;
            } else {
                printBySearch(listRate, addressC);
            }
        }
        cout << "[----------]" << endl;
        cout << "Kembali ?" << endl;
        cout << "[1] Ya" << endl;
        cout << "[2] Tidak" << endl;
        cout << "Decision : ";
        cin >> decisionKembali;
        while (decisionKembali != 1 && decisionKembali != 2) {
            cout << "Inputan anda tidak valid..." << endl;
            cout << "Input ulang : ";
            cin >> decisionKembali;
        }
        cls();
    }
}

//Fungsional user
void rateProduk(listProduk &listProduct, listRelasi &listRate, addressCustomer addressLogin) {
    int decisionKembali = -1;
    addressProduk addressP;
    string namaProduk;
    addressRelasi addressR;
    int decisionCustomerMerating;
    double ratingProduk;
    while (decisionKembali != 2) {
        namaProduk = "";
        cout << "[Rate produk]" << endl;
        printProduk(listProduct);
        cout << "Nama produk yang ingin anda rate (akhiri dengan '$') : ";
        namaProduk = inputanBerspasiPrimitif();
        addressP = searchProduk(listProduct, namaProduk);
        cls();
        if (addressP == NULL) {
            cout << "Produk dengan nama " << namaProduk << " tidak ditemukan..." << endl;
        } else {
            addressR = searchRating(listRate, addressLogin, addressP);
            if (addressR != NULL) {
                cout << "Produk dengan nama " << infoProduk(addressP).namaProduk << " sudah anda rate." << endl;
                cout << "Apakah anda ingin mengganti ratingannya?" << endl;
                cout << "[1] Ya" << endl;
                cout << "[2] Tidak" << endl;
                cout << "Decision : ";
                cin >> decisionCustomerMerating;
                while (decisionCustomerMerating != 1 && decisionCustomerMerating != 2) {
                    cout << "Inputan invalid." << endl;
                    cout << "Input ulang : ";
                    cin >> decisionCustomerMerating;
                }
                if (decisionCustomerMerating == 1) {
                    cout << "Nama produk : " << infoProduk(addressP).namaProduk << endl;
                    cout << "Dari 0 hingga 10, nilai berapa yang ingin anda beri ulang untuk produk " << infoProduk(addressP).namaProduk << "?" << endl;
                    cout << "Rating : ";
                    cin >> ratingProduk;
                    infoRelasi(addressR).rating = ratingProduk;
                    cls();
                    cout << "Produk " << infoProduk(addressP).namaProduk << " berhasil anda rate ulang!" << endl;
                }
            } else {
                cout << "Nama produk : " << infoProduk(addressP).namaProduk << endl;
                cout << "Dari 0 hingga 10, nilai berapa yang ingin anda beri untuk produk " << infoProduk(addressP).namaProduk << "?" << endl;
                cout << "Rating : ";
                cin >> ratingProduk;
                addressR = createElemenRelasi(addressLogin, addressP, ratingProduk, "*user ini belum memberikan ulasan kepada produk ini*");
                insertRating(listRate, addressR);
                cls();
                cout << "Produk " << infoProduk(addressP).namaProduk << " berhasil anda rate!" << endl;
            }
        }
        cout << "Apa yang anda ingin lakukan?" << endl;
        cout << "[1] Rate produk lagi" << endl;
        cout << "[2] Kembali" << endl;
        cout << "Decision : ";
        cin >> decisionKembali;
        while (decisionKembali != 1 && decisionKembali != 2) {
            cout << "Inputan anda tidak valid..." << endl;
            cout << "Input ulang : ";
            cin >> decisionKembali;
        }
        cls();
    }
}
void reviewProduk(listProduk &listProduct, listRelasi &listRate, addressCustomer addressLogin) {
    string reviewUser, namaProduk;
    int decisionKembali = -1;
    addressProduk addressP;
    addressRelasi addressR;
    int decisionCustomerMereview;
    while (decisionKembali != 2) {
        cout << "[Review produk]" << endl;
        printProduk(listProduct);
        cout << "Nama produk yang ingin anda review (akhiri dengan '$') : ";
        namaProduk = inputanBerspasiPrimitif();
        addressP = searchProduk(listProduct, namaProduk);
        cls();
        if (addressP == NULL) {
            cout << "Produk dengan nama " << namaProduk << " tidak ditemukan..." << endl;
        } else {
            addressR = searchRating(listRate, addressLogin, addressP);
            if (addressR != NULL) {
                if (infoRelasi(addressR).review != "*user ini belum memberikan ulasan kepada produk ini*") {
                    cout << "Produk dengan nama " << infoProduk(addressP).namaProduk << " sudah pernah anda review." << endl;
                    cout << "Apakah anda ingin mengganti isi reviewnya?" << endl;
                    cout << "[1] Ya" << endl;
                    cout << "[2] Tidak" << endl;
                    cout << "Decision : ";
                    cin >> decisionCustomerMereview;
                    while (decisionCustomerMereview!= 1 && decisionCustomerMereview != 2) {
                        cout << "Inputan invalid." << endl;
                        cout << "Input ulang : ";
                        cin >> decisionCustomerMereview;
                    }
                    if (decisionCustomerMereview == 1) {
                        cout << "Nama produk : " << infoProduk(addressP).namaProduk << endl;
                        cout << "Rating yang anda berikan kepada produk ini : " << infoRelasi(addressR).rating << endl;
                        cout << "Review anda sebelumnya : " << infoRelasi(addressR).review << endl;
                        cout << "Input review anda yang baru (akhiri dengan '$') : ";
                        reviewUser = inputanBerspasiPrimitif();
                        infoRelasi(addressR).review = reviewUser;
                        cls();
                        cout << "Produk " << infoProduk(addressP).namaProduk << " berhasil anda review ulang!" << endl;
                    }
                } else {
                    cout << "Nama produk : " << infoProduk(addressP).namaProduk << endl;
                    cout << "Rating yang anda berikan kepada produk ini : " << infoRelasi(addressR).rating << endl;
                    cout << "Input review anda (akhiri dengan '$') : ";
                    reviewUser = inputanBerspasiPrimitif();
                    infoRelasi(addressR).review = reviewUser;
                    cls();
                    cout << "Produk " << infoProduk(addressP).namaProduk << " berhasil anda review!" << endl;
                }
            } else {
                cout << "Produk dengan nama " << infoProduk(addressP).namaProduk << " belum anda rate!" << endl;
                cout << "Berikan rating terdahulu sebelum anda bisa mereview." << endl;
            }
        }
        cout << "Apa yang anda ingin lakukan?" << endl;
        cout << "[1] Review produk lagi" << endl;
        cout << "[2] Kembali" << endl;
        cout << "Decision : ";
        cin >> decisionKembali;
        while (decisionKembali != 1 && decisionKembali != 2) {
            cout << "Inputan anda tidak valid..." << endl;
            cout << "Input ulang : ";
            cin >> decisionKembali;
        }
        cls();
    }
}

void hapusRating(listRelasi &listRate, listProduk listProduct, addressCustomer addressLogin) {
    int decisionKembali = -1;
    string namaProduk;
    addressProduk addressP;
    addressRelasi addressR, addressPenampungRelasi;
    while (decisionKembali != 2) {
        cout << "[Hapus rating produk]" << endl;
        printRatingan(listRate, addressLogin);
        cout << "Nama produk yang ingin dihapus ratingnya (akhiri dengan '$') : ";
        namaProduk = inputanBerspasiPrimitif();
        addressP = searchProduk(listProduct, namaProduk);
        cls();
        if (addressP == NULL) {
            cout << "Produk dengan nama " << namaProduk << " tidak terdaftar..." << endl;
        } else {
            addressR = searchRating(listRate, addressLogin, addressP);
            if (addressR == NULL) {
                cout << "Produk dengan nama " << infoProduk(addressP).namaProduk << " belum pernah anda rate..." << endl;
            } else {
                deleteRating(listRate, addressR, addressPenampungRelasi);
                cout << "Rating anda dari produk " << infoProduk(addressP).namaProduk << " berhasil dihapus!" << endl;
            }
        }
        cout << "Apa yang anda ingin lakukan?" << endl;
        cout << "[1] Hapus ratingan produk lagi" << endl;
        cout << "[2] Kembali" << endl;
        cout << "Decision : ";
        cin >> decisionKembali;
        while (decisionKembali != 1 && decisionKembali != 2) {
            cout << "Inputan anda tidak valid..." << endl;
            cout << "Input ulang : ";
            cin >> decisionKembali;
        }
        cls();
    }
}

void showRatedProduk(listRelasi listRate, addressCustomer addressLogin) {
    int decisionKembali = -1;
    while (decisionKembali != 1) {
        cout << "[Produk yang sudah dirate]" << endl;
        printRatingan(listRate, addressLogin);
        cout << "[----------]" << endl;
        cout << "Kembali ?" << endl;
        cout << "[1] Ya" << endl;
        cout << "[2] Tidak" << endl;
        cout << "Decision : ";
        cin >> decisionKembali;
        while (decisionKembali != 1 && decisionKembali != 2) {
            cout << "Inputan anda tidak valid..." << endl;
            cout << "Input ulang : ";
            cin >> decisionKembali;
        }
        cls();
    }
}

void showUnratedProduk(listRelasi listRate, listProduk listProduct, addressCustomer addressLogin) {
    int decisionKembali = -1;
    while (decisionKembali != 1) {
        cout << "[Produk yang belum dirate]" << endl;
        printBelumRate(listRate, addressLogin, listProduct);
        cout << "[----------]" << endl;
        cout << "Kembali ?" << endl;
        cout << "[1] Ya" << endl;
        cout << "[2] Tidak" << endl;
        cout << "Decision : ";
        cin >> decisionKembali;
        while (decisionKembali != 1 && decisionKembali != 2) {
            cout << "Inputan anda tidak valid..." << endl;
            cout << "Input ulang : ";
            cin >> decisionKembali;
        }
        cls();
    }
}

void updateDataCustomer(addressCustomer &addressLogin, listCustomer &listPelanggan) {
    int decisionKembali = -1;
    int decisionCustomer = -1;
    while (decisionKembali != 2 && decisionCustomer != 5) {
        cout << "[Update data akun]" << endl;
        cout << "[1] Username" << endl;
        cout << "[2] Password" << endl;
        cout << "[3] Nama lengkap" << endl;
        cout << "[4] E-Mail" << endl;
        cout << "[5] Exit update data customer" << endl;
        cout << "Data apa yang ingin anda update?" << endl;
        cout << "Decision : ";
        cin >> decisionCustomer;
        while (decisionCustomer < 1 || decisionCustomer > 5) {
            cout << "Inputan anda tidak valid..." << endl;
            cout << "Input ulang : ";
            cin >> decisionCustomer;
        }
        cls();
        if (decisionCustomer == 1) {
            string usernameCustomer;
            cout << "[Mengganti username]" << endl;
            cout << "Username baru : ";
            cin >> usernameCustomer;
            while (checkUsernameSama(listPelanggan, usernameCustomer)) {
                cout << "Username telah terpakai! gunakan username yang lain..." << endl;
                cout << "Username : ";
                cin >> usernameCustomer;
            }
            infoCustomer(addressLogin).username = usernameCustomer;
            //Sort ulang
            addressCustomer addLoginBackup = addressLogin;
            deleteCustomer(listPelanggan, infoCustomer(addressLogin).username, addressLogin);
            insertAscendingCustomer(listPelanggan, addLoginBackup);
            addressLogin = addLoginBackup;
        } else if (decisionCustomer == 2) {
            string passwordCustomer;
            cout << "[Mengganti password]" << endl;
            cout << "Password baru : ";
            cin >> passwordCustomer;
            while (passwordCustomer == infoCustomer(addressLogin).password) {
                cout << "Anda tidak bisa menggunakan password anda yang saat ini sebagai password baru!" << endl;
                cout << "Password baru : ";
                cin >> passwordCustomer;
            }
            infoCustomer(addressLogin).password = passwordCustomer;
        } else if (decisionCustomer == 3) {
            string namaCustomer;
            cout << "[Mengganti nama lengkap]" << endl;
            cout << "Nama lengkap baru (akhiri dengan '$') : ";
            namaCustomer = inputanBerspasiPrimitif();
            while (namaCustomer == infoCustomer(addressLogin).namaLengkap) {
                cout << "Anda tidak bisa menggunakan nama anda yang saat ini sebagai nama baru!" << endl;
                cout << "Nama lengkap baru (akhiri dengan '$') : ";
                namaCustomer = inputanBerspasiPrimitif();
            }
            infoCustomer(addressLogin).namaLengkap = namaCustomer;
        } else if (decisionCustomer == 4) {
            string emailCustomer;
            cout << "[Mengganti e-mail]" << endl;
            cout << "E-Mail baru (akhiri dengan '$') : ";
            emailCustomer = inputanBerspasiPrimitif();
            while (emailCustomer == infoCustomer(addressLogin).emailAddress) {
                cout << "Anda tidak bisa menggunakan e-mail anda yang saat ini sebagai e-mail baru!" << endl;
                cout << "E-Mail baru (akhiri dengan '$') : ";
                emailCustomer = inputanBerspasiPrimitif();
            }
            infoCustomer(addressLogin).emailAddress = emailCustomer;
        }
        if (decisionCustomer != 5) {
            cls();
            cout << "Update data akun anda berhasil dilakukan!" << endl;
            cout << "Apa yang anda ingin lakukan?" << endl;
            cout << "[1] Update data akun customer anda lagi" << endl;
            cout << "[2] Kembali" << endl;
            cout << "Decision : ";
            cin >> decisionKembali;
            while (decisionKembali != 1 && decisionKembali != 2) {
                cout << "Inputan anda tidak valid..." << endl;
                cout << "Input ulang : ";
                cin >> decisionKembali;
            }
            cls();
        }
    }
}

void registrasiCustomer(listCustomer &listPelanggan) {
    string usernameCustomer, passwordCustomer, namaLengkapCustomer, emailCustomer;
    addressCustomer addressC;
    cout << "[Mendaftar menjadi customer]" << endl;
    cout << "Nama lengkap (akhiri dengan '$'): ";
    namaLengkapCustomer = inputanBerspasiPrimitif();
    cout << "Username                        : ";
    cin >> usernameCustomer;
    while (checkUsernameSama(listPelanggan, usernameCustomer)) {
        cout << "Username telah terpakai! gunakan username yang lain..." << endl;
        cout << "Username                        : ";
        cin >> usernameCustomer;
    }
    cout << "Password                        : ";
    cin >> passwordCustomer;
    cout << "E-Mail                          : ";
    cin >> emailCustomer;
    addressC = createElemenCustomer(usernameCustomer, passwordCustomer, namaLengkapCustomer, emailCustomer);
    insertAscendingCustomer(listPelanggan, addressC);
    cls();
    cout << "Pendaftaran anda berhasil dilakukan!" << endl;
}

void showProductSortedByRating(listProduk listProduct, listRelasi listRate) {
    int decisionKembali = -1;
    while (decisionKembali != 1) {
        cout << "[Daftar produk terurut berdasar rata-rata rating]" << endl;
        printSortRating(listRate, listProduct);
        cout << "[----------]" << endl;
        cout << "Kembali ?" << endl;
        cout << "[1] Ya" << endl;
        cout << "[2] Tidak" << endl;
        cout << "Decision : ";
        cin >> decisionKembali;
        while (decisionKembali != 1 && decisionKembali != 2) {
            cout << "Inputan anda tidak valid..." << endl;
            cout << "Input ulang : ";
            cin >> decisionKembali;
        }
        cls();
    }
}

