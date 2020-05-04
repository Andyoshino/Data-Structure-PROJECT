#include "headerCustomer.h"
#include "headerProduk.h"
#include "headerRelasi.h"
#include "headerUmum.h"
//Project Rating
//Nama : Butrahandisya
//NIM  : 1301190206
using namespace std;

int main() {
    //Informasi Admin
    string usernameAdmin, passwordAdmin;
    int decisionAdmin;
    //Non-login user
    int decisionNonLoginUser = -1;
    //Customer
    int decisionCustomer;
    //List produk related
    string namaProduk;
    listProduk listProduct;
    //List relasi related
    listRelasi listRate;
    //List customer related
    listCustomer listPelanggan;
    string usernameCustomer, passwordCustomer;
    addressCustomer addressLogin;
    //Start program
    createlistProduk(listProduct);
    createlistCustomer(listPelanggan);
    createlistRelasi(listRate);
    int decisionPengguna = -1;
    while (decisionPengguna != 4) {
        mainMenu();
        cin >> decisionPengguna;
        cls();
        if (decisionPengguna == 1) {
            menuLoginAdmin(usernameAdmin, passwordAdmin);
            if (cekInfoAdmin(usernameAdmin, passwordAdmin)) {
                cls();
                decisionAdmin = -1;
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
                        insertProduk(listProduct);
                    } else if (decisionAdmin == 2) {
                        //View data produk
                        showProduk(listProduct);
                    } else if (decisionAdmin == 3) {
                        //Update data produk
                        updateProduk(listProduct);
                    } else if (decisionAdmin == 4) {
                        //Hapus data produk
                        hapusProduk(listRate, listProduct);
                    } else if (decisionAdmin == 5) {
                        //Lihat data customer
                        showCustomer(listPelanggan);
                    } else if (decisionAdmin == 6) {
                        //Hapus data customer
                        hapusCustomer(listRate, listPelanggan);
                    } else if (decisionAdmin == 7) {
                        //Lihat rata-rata rating dan detail rating setiap produk
                        showAverageProductRating(listRate, listProduct);
                    } else if (decisionAdmin == 8) {
                        //Lihat detail rating setiap customer
                        showDetailRatingCustomer(listRate, listPelanggan);
                    }
                }
            } else {
                cls();
                cout << "Log-in gagal..." << endl;
                cout << "Username atau password salah." << endl;
            }
        } else if (decisionPengguna == 2) {
            //Login customer
            menuLoginUser(usernameCustomer, passwordCustomer);
            addressLogin = searchCustomerLogin(listPelanggan, usernameCustomer, passwordCustomer);
            cls();
            if (addressLogin == NULL) {
                cout << "Log-in gagal..." << endl;
                if (searchCustomerPrint(listPelanggan, usernameCustomer) != NULL) {
                    cout << "Password yang anda inputkan salah." << endl;
                } else {
                    cout << "Customer dengan username " << usernameCustomer << " tidak ditemukan..." << endl;
                }
            } else {
                cout << "Log-in berhasil!" << endl;
                cout << "Halo " << infoCustomer(addressLogin).namaLengkap << "!" << endl;
                decisionCustomer = -1;
                while (decisionCustomer != 7) {
                    menuUser();
                    cin >> decisionCustomer;
                    while (decisionCustomer > 7 || decisionCustomer < 1) {
                        cout << "Inputan anda tidak valid..." << endl;
                        cout << "Input ulang : ";
                        cin >> decisionCustomer;
                    }
                    cls();
                    if (decisionCustomer == 1) {
                        //Rate Produk
                        rateProduk(listProduct, listRate, addressLogin);
                    } else if (decisionCustomer == 2) {
                        //Ulas produk
                        reviewProduk(listProduct, listRate, addressLogin);
                    } else if (decisionCustomer == 3) {
                        //Hapus ratingan
                        hapusRating(listRate, listProduct, addressLogin);
                    } else if (decisionCustomer == 4) {
                        //Menampilkan produk yang sudah dirate
                        showRatedProduk(listRate, addressLogin);
                    } else if (decisionCustomer == 5) {
                        //Menampilkan produk yang belum dirate
                        showUnratedProduk(listRate, listProduct, addressLogin);
                    } else if (decisionCustomer == 6) {
                        //Update data customer
                        updateDataCustomer(addressLogin, listPelanggan);
                    }
                }
            }
        } else if (decisionPengguna == 3) {
            //Register Customer
            decisionNonLoginUser = -1;
            while (decisionNonLoginUser != 3) {
                menuNonLoginUser();
                cin >> decisionNonLoginUser;
                while (decisionNonLoginUser < 1 || decisionNonLoginUser > 3) {
                    cout << "Inputan anda tidak valid..." << endl;
                    cout << "Input ulang : ";
                    cin >> decisionNonLoginUser;
                }
                cls();
                if (decisionNonLoginUser == 1) {
                    //Register
                    registrasiCustomer(listPelanggan);
                } else if (decisionNonLoginUser == 2) {
                    //View produk dan ratingnya, dan terurut berdasar rating
                    showProductSortedByRating(listProduct, listRate);
                }
            }
        }
    }
    return 0;
}
