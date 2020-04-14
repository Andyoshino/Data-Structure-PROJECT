/*
Author : Butrahandisya - 1301190206 - IF-43-08
*/
#include "header.h"

using namespace std;

int main() {
    //Informasi Admin
    string usernameAdmin, passwordAdmin;
    int decisionAdmin = -1;
    //Non-login user
    int decisionNonLoginUser = -1;
    //Log-in customer
    int decisionLoginUser = -1;
    //Untuk Produk
    addressProduk addressP, addressDelete;
    string namaProduk;
    listProduk listProduct;
    //Untuk relasi
    listRelasi listRate;
    addressRelasi addressR, addressPenampungRelasi;
    Rating ratingProduk;
    //Untuk customer
    listCustomer listPelanggan;
    string usernameCustomer;
    addressCustomer addressC, addressLogin;
    int decisionCustomer;
    //Start program
    createlistProduk(listProduct);
    createlistCustomer(listPelanggan);
    createlistRelasi(listRate);
    //Untuk main
    int decisionPengguna = -1, decisionKembali;
    while (decisionPengguna != 4) {
        mainMenu();
        cin >> decisionPengguna;
        cls();
        if (decisionPengguna == 1) {
            menuLoginAdmin(usernameAdmin, passwordAdmin);
            decisionAdmin = -1;
            if (cekInfoAdmin(usernameAdmin, passwordAdmin)) {
                cls();
                cout << "Log-in berhasil!" << endl;
                while (decisionAdmin != 9) {
                    menuAdmin();
                    cin >> decisionAdmin;
                    while (decisionAdmin > 9 && decisionAdmin < 1) {
                        cout << "Inputan tidak valid..." << endl;
                        cout << "Input ulang : ";
                        cin >> decisionAdmin;
                    }
                    cls();
                    if (decisionAdmin == 1) {
                        //Insert last data produk
                        decisionKembali = -1;
                        while (decisionKembali != 2) {
                            cout << "[Insert data produk]" << endl;
                            cout << "Nama produk : ";
                            cin >> namaProduk;
                            addressP = createElemenProduk(namaProduk);
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
                    } else if (decisionAdmin == 2) {
                        //View data produk
                        decisionKembali = -1;
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
                    } else if (decisionAdmin == 3) {
                        //Update data produk (WTF?)
                        cout << "[Update data produk]" << endl;
                        cout << "[1] Nama produk" << endl;
                        cout << "Data apa yang ingin anda hapus?" << endl;
                        cout << "Decision : ";
                        cin >> decisionAdmin;
                        while (decisionAdmin != 1) {
                            cout << "Inputan anda tidak valid..." << endl;
                            cout << "Input ulang : ";
                            cin >> decisionAdmin;
                        }
                        cls();
                        if (decisionAdmin == 1) {
                            //Ganti nama produk
                            cout << "[Produk-produk]" << endl;
                            printProduk(listProduct);
                            cout << "Nama produk yang ingin anda ganti : ";
                            cin >> namaProduk;
                            addressP = searchProduk(listProduct, namaProduk);
                            cls();
                            if (addressP == NULL) {
                                cout << "Produk dengan nama " << namaProduk << " tidak terdaftar." << endl;
                            } else {
                                cout << "[Ganti nama produk]" << endl;
                                cout << "Nama baru untuk produk : ";
                                cin >> namaProduk;
                                namaProduk(addressP) = namaProduk;
                            }
                        }
                    } else if (decisionAdmin == 4) {
                        //Hapus data produk
                        decisionKembali = -1;
                        while (decisionKembali != 2) {
                            cout << "[Hapus produk]" << endl;
                            cout << "Nama produk : ";
                            cin >> namaProduk;
                            addressP = searchProduk(listProduct, namaProduk);
                            cls();
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
                    } else if (decisionAdmin == 5) {
                        //Lihat data customer
                        decisionKembali = -1;
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
                    } else if (decisionAdmin == 6) {
                        //Hapus data customer
                        decisionKembali = -1;
                        while (decisionKembali != 2) {
                            cout << "[Hapus customer]" << endl;
                            cout << "Username : ";
                            cin >> usernameCustomer;
                            cls();
                            deleteCustomer(listPelanggan, usernameCustomer, addressC);
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
                    } else if (decisionAdmin == 7) {
                        //Lihat rata-rata rating dan detail rating setiap produk
                        cout << "[Rata-rata rating dari setiap produk dan customer yang me-rating]" << endl;
                        printAverageProdukRating(listRate, listProduct);
                        decisionKembali = -1;
                        while (decisionKembali != 1) {
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
                    } else if (decisionAdmin == 8) {
                        //Lihat detail rating setiap customer
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
                            cout << "[Lihat berdasar username]" << endl;
                            cout << "Nama customer : ";
                            cin >> usernameCustomer;
                            cls();
                            addressC = searchCustomerLogin(listPelanggan, usernameCustomer);
                            if (addressC == NULL) {
                                cout << "Customer dengan username " << usernameCustomer << " tidak terdaftar." << endl;
                            } else {
                                printBySearch(listRate, addressC);
                            }
                        }
                        decisionKembali = -1;
                        while (decisionKembali != 1) {
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
                }
            } else {
                cls();
                cout << "Log-in gagal..." << endl;
                cout << "Username atau password salah." << endl;
            }
        } else if (decisionPengguna == 2) {
            //Login customer
            menuLoginUser(usernameCustomer);
            addressLogin = searchCustomerLogin(listPelanggan, usernameCustomer);
            cls();
            if (addressLogin == NULL) {
                cout << "Log-in gagal..." << endl;
                cout << "Customer dengan username " << usernameCustomer << " tidak ditemukan..." << endl;
            } else {
                cout << "Log-in berhasil!" << endl;
                cout << "Halo " << userName(addressLogin) << "!" << endl;
                decisionCustomer = -1;
                while (decisionCustomer != 6) {
                    menuUser();
                    cin >> decisionCustomer;
                    while (decisionCustomer > 6 && decisionCustomer < 1) {
                        cout << "Inputan anda tidak valid..." << endl;
                        cout << "Input ulang : ";
                    }
                    cls();
                    if (decisionCustomer == 1) {
                        //Rate Produk
                        decisionKembali = -1;
                        while (decisionKembali != 2) {
                            cout << "[Rate produk]" << endl;
                            printProduk(listProduct);
                            cout << "Nama produk yang ingin anda rate : ";
                            cin >> namaProduk;
                            addressP = searchProduk(listProduct, namaProduk);
                            cls();
                            if (addressP == NULL) {
                                cout << "Produk dengan nama " << namaProduk << " tidak ditemukan..." << endl;
                            } else {
                                cout << "Nama produk : " << namaProduk << endl;
                                cout << "Dari 0 hingga 10, nilai berapa yang ingin anda beri untuk produk " << namaProduk << "?" << endl;
                                cout << "Rating : " << endl;
                                cin >> ratingProduk;
                                addressR = createElemenRelasi(addressLogin, addressP, ratingProduk);
                                insertRating(listRate, addressR);
                                cls();
                                cout << "Produk " << namaProduk << " berhasil anda rate!" << endl;
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
                    } else if (decisionCustomer == 2) {
                        //Hapus ratingan
                        decisionKembali = -1;
                        while (decisionKembali != 2) {
                            cout << "[Hapus rating produk]" << endl;
                            printRatingan(listRate, addressLogin);
                            cout << "Nama produk yang ingin dihapus ratingnya : ";
                            cin >> namaProduk;
                            addressP = searchProduk(listProduct, namaProduk);
                            cls();
                            if (addressP == NULL) {
                                cout << "Produk dengan nama " << namaProduk << " tidak terdaftar..." << endl;
                            } else {
                                addressR = searchRating(listRate, addressLogin, addressP);
                                if (addressR == NULL) {
                                    cout << "Produk dengan nama " << namaProduk << " belum pernah anda rate..." << endl;
                                } else {
                                    deleteRating(listRate, addressR, addressPenampungRelasi);
                                    cout << "Rating anda dari produk " << namaProduk << " berhasil dihapus!" << endl;
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
                    } else if (decisionCustomer == 3) {
                        //Menampilkan produk yang sudah dirate
                        cout << "[Produk yang sudah dirate]" << endl;
                        printRatingan(listRate, addressLogin);
                        decisionKembali = -1;
                        while (decisionKembali != 1) {
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
                    } else if (decisionCustomer == 4) {
                        //Menampilkan produk yang belum dirate
                        cout << "[Produk yang belum dirate]" << endl;
                        printBelumRate(listRate, addressLogin, listProduct);
                        decisionKembali = -1;
                        while (decisionKembali != 1) {
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
                    } else if (decisionCustomer == 5) {
                        //Update data customer (WTF?)
                        cout << "[Update data akun]" << endl;
                        cout << "[1] Username" << endl;
                        cout << "Data apa yang ingin anda hapus?" << endl;
                        cout << "Decision : ";
                        cin >> decisionCustomer;
                        while (decisionCustomer != 1) {
                            cout << "Inputan anda tidak valid..." << endl;
                            cout << "Input ulang : ";
                            cin >> decisionCustomer;
                        }
                        cls();
                        if (decisionCustomer == 1) {
                            decisionCustomer = 5;
                            cout << "[Mengganti username]" << endl;
                            cout << "Username baru : ";
                            cin >> usernameCustomer;
                            while (checkUsernameSama(listPelanggan, usernameCustomer)) {
                                cout << "Username telah terpakai! gunakan username yang lain..." << endl;
                                cout << "Username : ";
                                cin >> usernameCustomer;
                            }
                            userName(addressLogin) = usernameCustomer;
                            cls();
                            cout << "Username anda berhasil diganti!" << endl;
                        }
                    }
                }
            }
        } else if (decisionPengguna == 3) {
            //Register Customer
            decisionNonLoginUser = -1;
            while (decisionNonLoginUser != 3) {
                menuNonLoginUser();
                cin >> decisionNonLoginUser;
                cls();
                if (decisionNonLoginUser == 1) {
                    //Register
                    cout << "[Mendaftar menjadi customer]" << endl;
                    cout << "Username : ";
                    cin >> usernameCustomer;
                    while (checkUsernameSama(listPelanggan, usernameCustomer)) {
                        cout << "Username telah terpakai! gunakan username yang lain..." << endl;
                        cout << "Username : ";
                        cin >> usernameCustomer;
                    }
                    addressC = createElemenCustomer(usernameCustomer);
                    insertAscendingCustomer(listPelanggan, addressC);
                    cout << "Berhasil mendaftar!" << endl;
                } else if (decisionNonLoginUser == 2) {
                    //View produk dan ratingnya, dan terurut berdasar rating
                    cout << "[Daftar produk terurut berdasar rata-rata rating]" << endl;
                    printSortRating(listRate, listProduct);
                    decisionKembali = -1;
                    while (decisionKembali != 1) {
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
            }
        }
    }
    return 0;
}
