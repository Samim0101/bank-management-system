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

    Account account1;
    printf("Enter your account number: ");
    scanf("%d",&account1.account_number);

    printf("Enter your name: ");
    scanf("%s",account1.name);

    printf("Enter your balance: ");
    scanf("%f",&account1.balance);

    printf("Account Number: %d\n", account1.account_number);
    printf("Account Name: %s\n", account1.name);
    printf("Account Balance: %.2f\n", account1.balance);

    return 0;
}