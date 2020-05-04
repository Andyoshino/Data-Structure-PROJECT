#include "headerCustomer.h"

void createlistCustomer(listCustomer &LC) {
    firstC(LC) = NULL;
}
addressCustomer createElemenCustomer(string username_customer, string password_customer, string namaLengkap_customer, string email_customer) {
    addressCustomer pointerBaru = new elmCustomer;
    nextC(pointerBaru) = NULL;
    infoCustomer(pointerBaru).namaLengkap = namaLengkap_customer;
    infoCustomer(pointerBaru).emailAddress = email_customer;
    infoCustomer(pointerBaru).username = username_customer;
    infoCustomer(pointerBaru).password = password_customer;
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
        if (infoCustomer(P).username < infoCustomer(firstC(LC)).username) {
            insertFirstCustomer(LC, P);
        } else {
            addressCustomer pointerPencari = firstC(LC);
            while (nextC(pointerPencari) != NULL && infoCustomer(P).username > infoCustomer(nextC(pointerPencari)).username) {
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
        while (pointerMencari != NULL && infoCustomer(pointerMencari).username != username_customer) {
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
            cout << "[" << penghitung << "] " << infoCustomer(pointerPrint).username << endl;
            cout << "Nama lengkap : " << infoCustomer(pointerPrint).namaLengkap << endl;
            cout << "Username     : " << infoCustomer(pointerPrint).username << endl;
            cout << "Password     : " << infoCustomer(pointerPrint).password << endl;
            cout << "E-Mail       : " << infoCustomer(pointerPrint).emailAddress << endl << endl;
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
        while (nextC(pointerPencari) != NULL && infoCustomer(nextC(pointerPencari)).username != username_customer) {
            pointerPencari = nextC(pointerPencari);
        }
        if (nextC(pointerPencari) == NULL) {
            return NULL;
        } else {
            return pointerPencari;
        }
    }
}
addressCustomer searchCustomerLogin(listCustomer LC, string username_customer, string password_customer) {
    addressCustomer pointerPencari = firstC(LC);
    if (firstC(LC) == NULL) {
        return NULL;
    } else {
        while (nextC(pointerPencari) != NULL && infoCustomer(pointerPencari).username != username_customer) {
            pointerPencari = nextC(pointerPencari);
        }
        if (infoCustomer(pointerPencari).username == username_customer && infoCustomer(pointerPencari).password == password_customer) {
            return pointerPencari;
        } else {
            return NULL;
        }
    }
}
addressCustomer searchCustomerPrint(listCustomer LC, string username_customer) {
    addressCustomer pointerPencari = firstC(LC);
    if (firstC(LC) == NULL) {
        return NULL;
    } else {
        while (nextC(pointerPencari) != NULL && infoCustomer(pointerPencari).username != username_customer) {
            pointerPencari = nextC(pointerPencari);
        }
        if (infoCustomer(pointerPencari).username == username_customer) {
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
        if (infoCustomer(firstC(LC)).username == username) {
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
