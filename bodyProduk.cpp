#include "headerProduk.h"

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
addressProduk createElemenProduk(string namaProduk, string deskripsiProduk, string produsen) {
    addressProduk pointerBaru = new elmProduk;
    nextP(pointerBaru) = NULL;
    infoProduk(pointerBaru).namaProduk = namaProduk;
    infoProduk(pointerBaru).produsen = produsen;
    infoProduk(pointerBaru).deskripsiProduk = deskripsiProduk;
    return pointerBaru;
}
void printProduk(listProduk LP) {
    addressProduk pointerPrint = firstP(LP);
    int tambahanSpasi;
    if (firstP(LP) != NULL) {
        int nomorProduk = 1;
        while (pointerPrint != NULL) {
            tambahanSpasi = -1;
            cout << "[" << nomorProduk << "] Nama produk : " << infoProduk(pointerPrint).namaProduk << endl;
            for (int i = nomorProduk; i != 0; i = i/10) {
                tambahanSpasi = tambahanSpasi + 1;
            }
            for (int i = 0; i < tambahanSpasi; i++) {
                cout << " ";
            }
            cout << "    Produsen    : " << infoProduk(pointerPrint).produsen << endl;
            for (int i = 0; i < tambahanSpasi; i++) {
                cout << " ";
            }
            cout << "    Deskripsi   : " << infoProduk(pointerPrint).deskripsiProduk << endl;
            cout << endl;
            nomorProduk++;
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
        while (nextP(pointerPencari) != NULL && infoProduk(pointerPencari).namaProduk != nama_produk) {
            pointerPencari = nextP(pointerPencari);
        }
        if (infoProduk(pointerPencari).namaProduk == nama_produk) {
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

