#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int account_number;
    char name[50];
    float balance;
} Account;

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

int main()
{
    printf("====================================\n");
    printf("       BANK MANAGEMENT SYSTEM       \n");
    printf("====================================\n");

    Account accounts[100];
    int account_count = 0;
    int choice;

    while (1)
    {

        printf("1. Add Account: \n");
        printf("2. Display Account: \n");
        printf("3. Search Account: \n");
        printf("4. Exit: \n");
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
            exit(0);
        default:
            break;
        }
    }

    return 0;
}