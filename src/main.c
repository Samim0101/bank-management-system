#include <stdio.h>
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

    (*account_count++);
}
int main()
{
    printf("====================================\n");
    printf("       BANK MANAGEMENT SYSTEM       \n");
    printf("====================================\n");

    Account accounts[100];
    int account_count = 0;

    add_account(accounts, &account_count);

    printf("Account Number: %d\n", accounts[0].account_number);
    printf("Account Name: %s\n", accounts[0].name);
    printf("Account Balance: %.2f\n", accounts[0].balance);

    return 0;
}