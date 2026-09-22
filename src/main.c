#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int account_number;
    char name[50];
    float balance;
} Account;

typedef struct
{
    int account_number;
    char type[50];
    float amount;
} Transaction;

void add_account(Account accounts[], int *account_count)
{
    printf("Enter your account number: ");

    scanf("%d", &accounts[*account_count].account_number);

    printf("Enter your name: ");
    scanf("%s", accounts[*account_count].name);

    printf("Enter bank Balance: ");
    scanf("%f", &accounts[*account_count].balance);

    (*account_count)++;
}

void display_accounts(Account accounts[], int account_count)
{
    for (int i = 0; i < account_count; i++)
    {
        printf("Your Account Number is: %d\n", accounts[i].account_number);

        printf("Your Account Name is: %s\n", accounts[i].name);

        printf("Your Bank Balance is: %.2f\n", accounts[i].balance);
    }
}

void search_account(Account accounts[], int account_count)
{
    int search_account;
    int found = 0;
    printf("Enter Account Number that you want to find: ");
    scanf("%d", &search_account);

    for (int i = 0; i < account_count; i++)
    {
        if (search_account == accounts[i].account_number)
        {
            printf("Account Found! \n");
            printf("Your Account Number is: %d\n", accounts[i].account_number);
            printf("Your Account Name is: %s\n", accounts[i].name);
            printf("Your Account Balance is: %.2f\n", accounts[i].balance);
            found = 1;
        }
    }
    if (found == 0)
    {
        printf("Account not found! \n");
    }
}

void deposit_money(Account accounts[], int account_count, Transaction transactions[], int *transaction_count)
{
    int account_number;
    float deposit_ammaount;
    int found = 0;
    printf("Enter your Account Number: ");
    scanf("%d", &account_number);

    for (int i = 0; i < account_count; i++)
    {
        if (account_number == accounts[i].account_number)
        {
            printf("Enter your Deposit Ammaunt: ");
            scanf("%f", &deposit_ammaount);
            accounts[i].balance = accounts[i].balance + deposit_ammaount;
            printf("Your Bank balance after deposit %.2f is: %.2f\n", deposit_ammaount, accounts[i].balance);
            transactions[*transaction_count].account_number = account_number;
            strcpy(transactions[*transaction_count].type, "Deposit");
            transactions[*transaction_count].amount = deposit_ammaount;
            (*transaction_count)++;
            found = 1;
        }
    }
    if (found == 0)
    {
        printf("Account not found! \n");
    }
}

void withdraw_money(Account accounts[], int account_count, Transaction transactions[], int *transaction_count)
{
    int account_number;
    float withdraw_ammaount;
    int found = 0;
    printf("Enter your Account Number: ");
    scanf("%d", &account_number);
    for (int i = 0; i < account_count; i++)
    {
        if (account_number == accounts[i].account_number)
        {
            printf("Enter your Withdraw Ammaount: ");
            scanf("%f", &withdraw_ammaount);
            if (withdraw_ammaount <= accounts[i].balance)
            {
                accounts[i].balance = accounts[i].balance - withdraw_ammaount;
                printf("Your bank balance after withdraw %.2f is: %.2f\n", withdraw_ammaount, accounts[i].balance);
                transactions[*transaction_count].account_number = account_number;
                strcpy(transactions[*transaction_count].type, "Withdraw");
                transactions[*transaction_count].amount = withdraw_ammaount;
                (*transaction_count)++;
            }
            else
            {
                printf("Insaficeint balance for withdraw!\n");
            }

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("Account not found! \n");
    }
}

void display_transaction_history(Transaction transactions[], int transaction_count)
{

    if (transaction_count == 0)
    {
        printf("No transactions found! \n");
        return;
    }
    for (int i = 0; i < transaction_count; i++)
    {
        printf("Your Account Number is: %d\n", transactions[i].account_number);
        printf("Your Transaction Type: %s\n", transactions[i].type);
        printf("Your Ammaount: %.2f\n", transactions[i].amount);
    }
}

int main()
{
    printf("====================================\n");
    printf("       BANK MANAGEMENT SYSTEM       \n");
    printf("====================================\n");

    Account accounts[100];
    int account_count = 0;
    int choice;
    Transaction transactions[500];
    int transaction_count = 0;

    while (1)
    {

        printf("1. Add Account:\n");
        printf("2. Display Account:\n");
        printf("3. Search Account:\n");
        printf("4. Deposit money:\n");
        printf("5. Withdraw money:\n");
        printf("6. Transaction History: \n");
        printf("7. Exit:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_account(accounts, &account_count);
            break;
        case 2:
            display_accounts(accounts, account_count);
            break;
        case 3:
            search_account(accounts, account_count);
            break;
        case 4:
            deposit_money(accounts, account_count, transactions, &transaction_count);
            break;
        case 5:
            withdraw_money(accounts, account_count, transactions, &transaction_count);
            break;
        case 6:
            display_transaction_history(transactions, transaction_count);
            break;
        case 7:
            exit(0);
        default:
            break;
        }
    }

    return 0;
}