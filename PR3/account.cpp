#include <iostream>
#include <string>

using namespace std;

/**
 * Structure describing a bank account with bank account number and amount
 */
struct BankAccount {
    string iban;
    double amount;
};

BankAccount& operator<< (BankAccount& acc, double amount) {
    acc.amount += amount;
    return acc;
}

BankAccount& operator<< (BankAccount& acc1, BankAccount& acc2) {
    if (acc2.amount > 0.0) {
        acc1.amount += acc2.amount;
    }
    return acc1;
}

void operator~ (BankAccount& acc) {
    acc.amount = 0.0;
}

BankAccount& operator| (BankAccount& acc1, BankAccount& acc2) {
    BankAccount acc3 = new BankAccount();
    acc3.iban = "DE12300000000456789012"
    acc3.amount = acc1.amount + acc2.amount;
    return acc3&;
}

bool operator< (BankAccount& acc1, BankAccount& acc2) {
    return acc1.amount < acc2.amount;
}

bool operator> (BankAccount& acc1, BankAccount& acc2) {
    return acc1.amount > acc2.amount;
}

bool operator== (BankAccount& acc1, BankAccount& acc2) {
    if (acc1.iban == acc2.iban) {
        if (acc1.amount == acc2.amount) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

BankAccount& operator*= (BankAccount& acc, double multiplier) {
    acc.amount += acc.amount * multiplier;
    return acc;
}

BankAccount& getMax (BankAccount& acc1, BankAccount& acc2) {
    return (acc1.amount >= acc2.amount) ? acc1 : acc2;
}

/**
 * Prints bank account
 */
void printBankAccount(const BankAccount& account) {
    cout << account.iban << " (" << account.amount << ")" << endl;
}

// TODO: Implement operators

/**
 * Main program
 */
int main(int argc, const char * argv[]) {

    // TODO: Implement main program

    return 0;
}