#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/**
 * Structure describing a bank account with bank account number and amount
 */
struct BankAccount {
    string iban;
    double amount;
};

/**
 * Prints bank account
 */
void printBankAccount(const BankAccount& account) {
    cout << account.iban << " (" << account.amount << ")" << endl;
}

void operator<<(BankAccount& payee, const double amount){
    payee.amount += amount;
}

void operator<<(BankAccount& payee, BankAccount& payer){
    if(payer.amount > 0){
        payee.amount += payer.amount;
        payer.amount = 0;
    }
}

void operator~(BankAccount& account){
    account.amount = 0;
}

BankAccount operator|(BankAccount& bankAccount1, BankAccount& bankAccount2){
    BankAccount mergedAccount;
    mergedAccount.iban = "DE";
    for (int i = 0; i < 4; i++) {
        int number = (rand() % 9);
        mergedAccount.iban += to_string(number);
    }
    mergedAccount.amount = bankAccount1.amount + bankAccount2.amount;
    ~bankAccount1;
    ~bankAccount2;
    return mergedAccount;
}

bool operator>(const BankAccount& account1, const BankAccount& account2){
    return (account1.amount > account2.amount);
}

bool operator<(const BankAccount& account1, const BankAccount& account2){
    return (account1.amount < account2.amount);
}

bool operator==(const BankAccount& account1, const BankAccount& account2){
    return (account1.iban == account2.iban) && (account1.amount == account2.amount);
}

void operator*=(BankAccount& payee, const double interest){
    payee.amount += (interest / 100) * payee.amount;
}

const BankAccount& getMax(const BankAccount& account1, const BankAccount& account2){
    if(account1 > account2){
        return account1;
    } else{
        return account2;
    }
}

/**
 * Main program
 */
int main(int argc, const char * argv[]) {

    BankAccount account1;
    account1.iban = "DE1234";
    account1.amount = 123;

    BankAccount account2;
    account2.iban = "DE5678";
    account2.amount = 44;

    //Task 1a)
    int amountToAdd = 22;
    printf("Account before putting money on it: ");
    printBankAccount(account1);
    account1<<amountToAdd;
    printf("Account after putting %d on it: ", amountToAdd);
    printBankAccount(account1);
    printf("\n");

    //Task 1b)
    printf("Account1: ");
    printBankAccount(account1);
    printf("Account2: ");
    printBankAccount(account2);
    printf("Transferring all the money from Account2 to Account1 ...\n");

    account1<<account2;

    printf("Account1: ");
    printBankAccount(account1);
    printf("Account2: ");
    printBankAccount(account2);
    printf("\n");

    printf("Account1: ");
    printBankAccount(account1);
    printf("Account2: ");
    printBankAccount(account2);
    printf("Transferring all the money from Account2 to Account1 ...\n");

    account1<<account2;

    printf("Account1: ");
    printBankAccount(account1);
    printf("Account2: ");
    printBankAccount(account2);
    printf("\n");

    //Task 1c)
    printf("Account before putting it to zero: ");
    printBankAccount(account1);
    ~account1;
    printf("Account after putting it to zero: ");
    printBankAccount(account1);
    printf("\n");

    //Task 1d)
    account1.amount = 100;
    account2.amount = 189;

    printf("Merging Account1 and Account2:\n");
    printBankAccount(account1);
    printBankAccount(account2);
    BankAccount merged = account1 | account2;
    printf("The merged account is: ");
    printBankAccount(merged);
    printBankAccount(account1);
    printBankAccount(account2);
    printf("\n");

    //Task 1e)
    account1.amount = 100;
    account2.amount = 189;

    BankAccount account3;
    account3.iban = "DE1234";
    account3.amount = account1.amount;

    printf("Account1 and Account2 were compered with the >-Operator\n");
    printBankAccount(account1);
    printBankAccount(account2);
    printf("The greater one is ");

    if(account1 > account2){
        printBankAccount(account1);
    }else if(account2 > account1){
        printBankAccount(account2);
    }
    printf("\n");

    printf("Account1 and Account2 were compered with the <-Operator\n");
    printBankAccount(account1);
    printBankAccount(account2);
    printf("The smaller one is ");

    if(account1 < account2){
        printBankAccount(account1);
    }else if(account2 < account1){
        printBankAccount(account2);
    }
    printf("\n");

    printf("Account1 and Account3 were compered with the ==-Operator\n");
    printBankAccount(account1);
    printBankAccount(account3);

    if(account1 == account3){
        printf("They are the same!\n");
    }else{
        printf("They aren't the same!\n");
    }
    printf("\n");

    //Task 1f)
    double interest = 1.67;
    printf("Account before multiplying the interest: ");
    printBankAccount(account1);
    account1 *= interest;
    printf("Account after multiplying %.2f: ", interest);
    printBankAccount(account1);
    printf("\n");

    //Task 1g)
    printf("Account1 and Account2 were compered with the getMax()-function\n");
    printBankAccount(account1);
    printBankAccount(account2);
    BankAccount bigger = getMax(account1, account2);
    printf("The bigger one is: ");
    printBankAccount(bigger);

    return 0;
}