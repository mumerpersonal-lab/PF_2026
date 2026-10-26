#include <stdio.h>

int deposit(float *balance, float amount)
{
    if (amount <= 0)
        return 0;

    *balance = *balance + amount;

    return 1;
}

int withdraw(float *balance, float amount)
{
    if (amount <= 0 || amount > *balance)
        return 0;

    *balance = *balance - amount;

    return 1;
}

int main()
{
    float balance = 1000.0, amount;
    int choice;

    do
    {
        printf("\n1 Deposit\n");
        printf("2 Withdraw\n");
        printf("3 Check balance\n");
        printf("4 Exit\n");
        printf("Choose option (1-4): ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter amount: ");
                scanf("%f", &amount);

                if (deposit(&balance, amount))
                    printf("Amount deposited successfully.\n");
                else
                    printf("Invalid amount.\n");

                break;

            case 2:
                printf("Enter amount: ");
                scanf("%f", &amount);

                if (withdraw(&balance, amount))
                    printf("Amount withdrawn successfully.\n");
                else
                    printf("Insufficient funds or invalid amount.\n");

                break;

            case 3:
                printf("Current balance: %.2f\n", balance);
                break;

            case 4:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid option\n");
        }

    } while (choice != 4);

    return 0;
}