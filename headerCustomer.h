#ifndef HEADERCUSTOMER_H_INCLUDED
#define HEADERCUSTOMER_H_INCLUDED

#include <iostream>
using namespace std;

#define firstC(L) L.firstCustomer
#define infoCustomer(P) P->infoCustomer
#define nextC(P) P->nextCustomer
typedef struct elmCustomer *addressCustomer;
struct infotypeCustomer {
    string username;
    string password;
    string namaLengkap;
    string emailAddress;
};
struct elmCustomer {
    infotypeCustomer infoCustomer;
    addressCustomer nextCustomer;
};
struct listCustomer {
    addressCustomer firstCustomer;
};
void createlistCustomer(listCustomer &LC);
addressCustomer createElemenCustomer(string username_customer, string password_customer, string namaLengkap_customer, string email_customer);
void insertFirstCustomer(listCustomer &LC, addressCustomer P);
void insertLastCustomer(listCustomer &LC, addressCustomer P);
void insertAfterCustomer(addressCustomer &addressPrec, addressCustomer P);
void insertAscendingCustomer(listCustomer &LC, addressCustomer P);
bool checkUsernameSama(listCustomer &LC, string username_customer);
void printCustomer(listCustomer LC);
addressCustomer searchCustomer(listCustomer LC, string username_customer);
addressCustomer searchCustomerLogin(listCustomer LC, string username_customer, string password_customer);
addressCustomer searchCustomerPrint(listCustomer LC, string username_customer);
void deleteCustomer(listCustomer &LC, string username, addressCustomer &addressTampung);

#endif // HEADERCUSTOMER_H_INCLUDED
