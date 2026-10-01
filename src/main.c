#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
    char date_time[30];
} Transaction;

void add_account(Account accounts[], int *account_count)
{
    int new_acount_number;
    int result;
    if (*account_count >= 100)
    {
        printf("We dont have space to create new account! \n");
        return;
    }

    printf("Enter your account number: ");
    result = scanf("%d", &new_acount_number);
    if (result != 1)
    {
        printf("Invalid input!\n");
        while (getchar() != '\n')
            ;
        return;
    }
    if (new_acount_number <= 0)
    {
        printf("Account number must be greater than 0. \n");
        return;
    }

    for (int i = 0; i < *account_count; i++)
    {
        if (new_acount_number == accounts[i].account_number)
        {
            printf("Account already exists!\n");
            return;
        }
    }
    accounts[*account_count].account_number = new_acount_number;
    printf("Enter your name: ");
    while ((getchar()) != '\n')
        ;
    fgets(accounts[*account_count].name, 50, stdin);
    accounts[*account_count].name[strcspn(accounts[*account_count].name, "\n")] = '\0';
    printf("Enter bank Balance: ");
    scanf("%f", &accounts[*account_count].balance);

    if (accounts[*account_count].balance <= 0)
    {
        printf("Invalid Balance!\n");
        return;
    }

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
    int result;
    int found = 0;
    printf("Enter Account Number that you want to find: ");
    result = scanf("%d", &search_account);
    if (result != 1)
    {
        printf("Invalid input!\n");
        while (getchar() != '\n')
            ;
        return;
    }
    if (search_account <= 0)
    {
        printf("Invalid account number!\n");
        return;
    }

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
    int result;
    int found = 0;
    time_t now;
    struct tm *local_time;
    printf("Enter your Account Number: ");
    result = scanf("%d", &account_number);
    if (result != 1)
    {
        printf("invalid input!\n");
        while (getchar() != '\n')
            ;
        return;
    }
    if (account_number <= 0)
    {
        printf("Invalid account number!\n");
        return;
    }

    for (int i = 0; i < account_count; i++)
    {
        if (account_number == accounts[i].account_number)
        {
            if (*transaction_count >= 500)
            {
                printf("Transaction history is full!! \n");
                return;
            }

            printf("Enter your Deposit Ammaunt: ");
            result = scanf("%f", &deposit_ammaount);
            if (result != 1)
            {
                printf("Invalid input!\n");
                while (getchar() != '\n')
                    ;
                return;
            }
            if (deposit_ammaount <= 0)
            {
                printf("Invalid Deposit\n");
                return;
            }
            accounts[i].balance = accounts[i].balance + deposit_ammaount;
            printf("Your Bank balance after deposit %.2f is: %.2f\n", deposit_ammaount, accounts[i].balance);
            transactions[*transaction_count].account_number = account_number;
            strcpy(transactions[*transaction_count].type, "Deposit");
            transactions[*transaction_count].amount = deposit_ammaount;
            now = time(NULL);
            local_time = localtime(&now);
            strftime(
                transactions[*transaction_count].date_time,
                30,
                "%d-%m-%Y %H:%M:%S",
                local_time);
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
    int result;
    int found = 0;
    time_t now;
    struct tm *local_time;
    printf("Enter your Account Number: ");
    result = scanf("%d", &account_number);
    if (result != 1)
    {
        printf("Invalid input!\n");
        while (getchar() != '\n')
            ;
        return;
    }
    if (account_number <= 0)
    {
        printf("Invalid account number!\n");
        return;
    }

    for (int i = 0; i < account_count; i++)
    {
        if (account_number == accounts[i].account_number)
        {
            if (*transaction_count >= 500)
            {
                printf("Transaction history is full! \n");
                return;
            }

            printf("Enter your Withdraw Ammaount: ");
            result = scanf("%f", &withdraw_ammaount);

            if (result != 1)
            {
                printf("Invalid input!\n");
                while (getchar() != '\n')
                    ;
                return;
            }

            if (withdraw_ammaount <= 0)
            {
                printf("Invalid Withdraw!\n");
                return;
            }

            if (withdraw_ammaount <= accounts[i].balance)
            {
                accounts[i].balance = accounts[i].balance - withdraw_ammaount;
                printf("Your bank balance after withdraw %.2f is: %.2f\n", withdraw_ammaount, accounts[i].balance);
                transactions[*transaction_count].account_number = account_number;
                strcpy(transactions[*transaction_count].type, "Withdraw");
                transactions[*transaction_count].amount = withdraw_ammaount;
                now = time(NULL);
                local_time = localtime(&now);

                strftime(
                    transactions[*transaction_count].date_time,
                    30,
                    "%d-%m-%Y %H:%M:%S",
                    local_time);
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

    int account_number;
    int result;
    int found = 0;

    if (transaction_count == 0)
    {
        printf("No transactions found! \n");
        return;
    }

    printf("Enter Account Number: ");
    result = scanf("%d", &account_number);

    if (result != 1)
    {
        printf("Invalid input!\n");
        while (getchar() != '\n')
            ;
        return;
    }
    if (account_number <= 0)
    {
        printf("Invalid account number!\n");
        return;
    }

    for (int i = 0; i < transaction_count; i++)
    {
        if (transactions[i].account_number == account_number)
        {
            printf("Your Account Number is: %d\n", transactions[i].account_number);
            printf("Your Transaction Type: %s\n", transactions[i].type);
            printf("Your Ammaount: %.2f\n", transactions[i].amount);
            printf("Date & Time: %s\n", transactions[i].date_time);
            found = 1;
        }
    }
    if (found == 0)
    {
        printf("No transactions found for this account!\n");
    }
}

void save_accounts(Account accounts[], int account_count)
{
    FILE *file;
    file = fopen("../data/accounts.dat", "wb");
    if (file == NULL)
    {
        printf("Error opening accounts file!\n");
        return;
    }
    fwrite(accounts, sizeof(Account), account_count, file);
    fclose(file);
}

void load_accounts(Account accounts[], int *account_count)
{
    FILE *file;
    file = fopen("../data/accounts.dat", "rb");

    if (file == NULL)
    {
        *account_count = 0;
        return;
    }
    *account_count = fread(accounts, sizeof(Account), 100, file);
    fclose(file);
}

void save_transactions(Transaction transactions[], int transaction_count)
{
    FILE *file;
    file = fopen("../data/transactions.dat", "wb");
    if (file == NULL)
    {
        printf("Error opening transaction file!\n");

        return;
    }

    fwrite(transactions, sizeof(Transaction), transaction_count, file);
    fclose(file);
}

void load_transactions(Transaction transactions[], int *transaction_count)
{
    FILE *file;
    file = fopen("../data/transactions.dat", "rb");
    if (file == NULL)
    {
        *transaction_count = 0;
        return;
    }
    *transaction_count = fread(transactions, sizeof(Transaction), 500, file);
    fclose(file);
}

int update_account(Account accounts[], int account_count, Transaction transactions[], int transaction_count)
{
    int account_number;
    int new_account_number;
    char new_name[50];
    int result;
    int found = 0;
    printf("Enter your account number: ");
    result = scanf("%d", &account_number);

    if (result != 1)
    {
        printf("Invalid input!\n");
        while (getchar() != '\n')
            ;
        return 0;
    }
    if (account_number <= 0)
    {
        printf("Invalid account number!\n");
        return 0;
    }

    for (int i = 0; i < account_count; i++)
    {
        if (account_number == accounts[i].account_number)
        {
            printf("Enter your new name: ");
            while (getchar() != '\n')
                ;
            fgets(new_name, 50, stdin);
            new_name[strcspn(new_name, "\n")] = '\0';

            printf("Enter your new account number: ");
            result = scanf("%d", &new_account_number);

            if (result != 1)
            {
                printf("Invalid input!\n");
                while (getchar() != '\n')
                    ;
                return 0;
            }
            if (new_account_number <= 0)
            {
                printf("Invalid account number!\n");
                return 0;
            }

            for (int j = 0; j < account_count; j++)
            {
                if (j != i && new_account_number == accounts[j].account_number)
                {
                    printf("Account number already exists\n");
                    return 0;
                }
            }

            for (int k = 0; k < transaction_count; k++)
            {
                if (transactions[k].account_number == account_number)
                {
                    transactions[k].account_number = new_account_number;
                }
            }

            strcpy(accounts[i].name, new_name);
            accounts[i].account_number = new_account_number;
            found = 1;
        }
    }
    if (found == 0)
    {
        printf("Account not found!\n");
        return 0;
    }
    return 1;
}

void delete_account(Account accounts[], int *account_count,
                    Transaction transactions[], int *transaction_count)
{
    int account_number;
    int result;
    int found = 0;

    printf("Enter account number to delete: ");
    result = scanf("%d", &account_number);

    if (result != 1)
    {
        printf("Invalid input!\n");

        while (getchar() != '\n')
            ;

        return;
    }

    if (account_number <= 0)
    {
        printf("Invalid account number!\n");
        return;
    }

    for (int i = 0; i < *account_count; i++)
    {
        if (accounts[i].account_number == account_number)
        {
            found = 1;

            printf("Account found!\n");
            printf("Account Number: %d\n", accounts[i].account_number);
            printf("Account Name: %s\n", accounts[i].name);
            printf("Account Balance: %.2f\n", accounts[i].balance);
            for (int j = i; j < *account_count - 1; j++)
            {
                accounts[j] = accounts[j + 1];
            }

            (*account_count)--;

            for (int k = 0; k < *transaction_count; k++)
            {
                if (transactions[k].account_number == account_number)
                {
                    for (int j = k; j < *transaction_count - 1; j++)
                    {
                        transactions[j] = transactions[j + 1];
                    }

                    (*transaction_count)--;
                    k--;
                }
            }

            printf("Account deleted successfully!\n");
            break;
        }
    }
    if (found == 0)
    {
        printf("Account not found!\n");
        return;
    }
}

void transfer_money(Account accounts[], int account_count, Transaction transactions[], int *transaction_count)
{
    int sender_account_number;
    int receiver_account_number;
    int sender;
    int receiver;
    int sender_index = -1;
    int receiver_index = -1;
    int result;
    float amount;
    time_t now;
    struct tm *local_time;

    printf("Enter sender account number: ");
    sender = scanf("%d", &sender_account_number);

    if (sender != 1)
    {
        printf("Invalid input!\n");
        while (getchar() != '\n')
            ;
        return;
    }
    if (sender_account_number <= 0)
    {
        printf("Invalid account number!\n");
        return;
    }

    printf("Enter your receiver account number: ");
    receiver = scanf("%d", &receiver_account_number);

    if (receiver != 1)
    {
        printf("Invalid input!\n");
        while (getchar() != '\n')
            ;
        return;
    }
    if (receiver_account_number <= 0)
    {
        printf("Invalid account number!\n");
        return;
    }

    for (int i = 0; i < account_count; i++)
    {
        if (accounts[i].account_number == sender_account_number)
        {
            sender_index = i;
        }

        if (accounts[i].account_number == receiver_account_number)
        {
            receiver_index = i;
        }
    }
    if (sender_index == -1)
    {
        printf("Sender account not found!\n");
        return;
    }
    if (receiver_index == -1)
    {
        printf("Receiver account not found!\n");
        return;
    }
    if (sender_index == receiver_index)
    {
        printf("Cannot transfer money to the same account!\n");
        return;
    }
    printf("Enter transfer ammount: ");
    result = scanf("%f", &amount);

    if (result != 1)
    {
        printf("Invalid input!\n");
        while (getchar() != '\n')
            ;
        return;
    }
    if (amount <= 0)
    {
        printf("Invalid transfer ammount!\n");
        return;
    }

    if (accounts[sender_index].balance < amount)
    {
        printf("Insufficient balance to transfer!\n");
        return;
    }
    if (*transaction_count + 2 > 500)
    {
        printf("transaction history is full!\n");
        return;
    }
    now = time(NULL);
    local_time = localtime(&now);
    accounts[sender_index].balance -= amount;
    accounts[receiver_index].balance += amount;

    transactions[*transaction_count].account_number = sender_account_number;
    strcpy(transactions[*transaction_count].type, "Transfer Out");
    transactions[*transaction_count].amount = amount;

    strftime(transactions[*transaction_count].date_time, 30,
             "%d-%m-%Y %H:%M:%S", local_time);

    (*transaction_count)++;

    transactions[*transaction_count].account_number = receiver_account_number;
    strcpy(transactions[*transaction_count].type, "Transfer In");
    transactions[*transaction_count].amount = amount;

    strftime(transactions[*transaction_count].date_time, 30,
             "%d-%m-%Y %H:%M:%S", local_time);

    (*transaction_count)++;

    printf("Money transferred successfully!\n");
}

void account_summary(Account accounts[], int account_count, Transaction transactions[], int transaction_count)
{
    int account_number;
    float deposits = 0;
    float withdrawals = 0;
    float transfer_out = 0;
    float transfer_in = 0;

    printf("Enter Account number: ");
    scanf("%d", &account_number);

    for (int i = 0; i < transaction_count; i++)
    {
        if (transactions[i].account_number == account_number)
        {
            if (strcmp(transactions[i].type, "Deposit") == 0)
            {
                deposits += transactions[i].amount;
            }
            else if (strcmp(transactions[i].type, "Withdraw") == 0)
            {
                withdrawals += transactions[i].amount;
            }
            else if (strcmp(transactions[i].type, "Transfer Out") == 0)
            {
                transfer_out += transactions[i].amount;
            }
            else if (strcmp(transactions[i].type, "Transfer In") == 0)
            {
                transfer_in += transactions[i].amount;
            }
        }
    }
    for (int j = 0; j < account_count; j++)
    {
        if (accounts[j].account_number == account_number)
        {
            printf("\n========== Account Summary ==========\n");
            printf("Account Number: %d\n", accounts[j].account_number);
            printf("Name: %s\n", accounts[j].name);
            printf("Current Balance: %.2f\n", accounts[j].balance);

            printf("Total Deposits: %.2f\n", deposits);
            printf("Total Withdrawals: %.2f\n", withdrawals);
            printf("Total Transfer Out: %.2f\n", transfer_out);
            printf("Total Transfer In: %.2f\n", transfer_in);
        }
    }
}

int main()
{
    printf("====================================\n");
    printf("       BANK MANAGEMENT SYSTEM       \n");
    printf("====================================\n");
    Account accounts[100];
    int account_count = 0;
    load_accounts(accounts, &account_count);
    int choice;
    int result;
    Transaction transactions[500];
    int transaction_count = 0;
    load_transactions(transactions, &transaction_count);
    while (1)
    {

        printf("1. Add Account:\n");
        printf("2. Display Account:\n");
        printf("3. Search Account:\n");
        printf("4. Deposit money:\n");
        printf("5. Withdraw money:\n");
        printf("6. Transaction History:\n");
        printf("7. Update Account:\n");
        printf("8. Delete Account:\n");
        printf("9. Transfer Money:\n");
        printf("10. Account Summary:\n");
        printf("11. Exit:\n");
        result = scanf("%d", &choice);
        if (result != 1)
        {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        if (choice < 1 || choice > 11)
        {
            printf("Invalid input! Please enter 1-11.\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            add_account(accounts, &account_count);
            save_accounts(accounts, account_count);
            break;
        case 2:
            display_accounts(accounts, account_count);
            break;
        case 3:
            search_account(accounts, account_count);
            break;
        case 4:
            deposit_money(accounts, account_count, transactions, &transaction_count);
            save_accounts(accounts, account_count);
            save_transactions(transactions, transaction_count);
            break;
        case 5:
            withdraw_money(accounts, account_count, transactions, &transaction_count);
            save_accounts(accounts, account_count);
            save_transactions(transactions, transaction_count);
            break;
        case 6:
            display_transaction_history(transactions, transaction_count);
            break;
        case 7:
        {
            int updated = update_account(accounts, account_count, transactions, transaction_count);

            if (updated == 1)
            {
                save_accounts(accounts, account_count);
                save_transactions(transactions, transaction_count);
            }
            break;
        }
        case 8:
            delete_account(accounts, &account_count, transactions, &transaction_count);
            save_accounts(accounts, account_count);
            save_transactions(transactions, transaction_count);
            break;
        case 9:
            transfer_money(accounts, account_count, transactions, &transaction_count);
            save_accounts(accounts, account_count);
            save_transactions(transactions, transaction_count);
            break;
        case 10:
            account_summary(accounts, account_count, transactions, transaction_count);
            break;
        case 11:
            exit(0);
        default:
            break;
        }
    }

    return 0;
}