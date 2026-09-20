#include <stdio.h>
typedef struct
{
    int account_number;
    char name[50];
    float balance;
} Account;
int main()
{
    printf("====================================\n");
    printf("       BANK MANAGEMENT SYSTEM       \n");
    printf("====================================\n");

    Account accounts[100];
    int account_count = 0;

    printf("Enter your account number: ");
    scanf("%d", &accounts[account_count].account_number);

    printf("Enter your name: ");
    scanf("%s", accounts[account_count].name);

    printf("Enter your balance: ");
    scanf("%f", &accounts[account_count].balance);

    account_count++;

    printf("Account Number: %d\n", accounts[0].account_number);
    printf("Account Name: %s\n", accounts[0].name);
    printf("Account Balance: %.2f\n", accounts[0].balance);

    return 0;
}