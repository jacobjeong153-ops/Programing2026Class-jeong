#include <stdio.h>

int main(void)
{
    int number;
    int total_sales_count = 0;
    int total_revenue = 0;  

    while (true)
    {
        printf("===== Drink Dispenser =====\n");
        printf("1. Cola(1200KRW) 2. Cider(1100KRW) 3. Coffee(800KRW) 0. END\n");
        printf("Select: ");
        scanf_s("%d", &number);

        if (number == 0)
        {
            printf("Today Sales: %d, Revenue: %dKRW\n", total_sales_count, total_revenue);
            break;
        }

        int price = 0;

        if (number == 1)
        {
            price = 1200;
        }
        else if (number == 2)
        {
            price = 1100;
        }
        else if (number == 3)
        {
            price = 800;
        }
        else
        {
            printf("Wrong Selection\n\n");
            continue;
        }

        int current_amount = 0;
        int coin = 0;

        while (current_amount < price)
        {
            printf("Insert (Current: %dKRW / Need: %dKRW): ", current_amount, price);
            scanf_s("%d", &coin);

            if (coin == 100 || coin == 500 || coin == 1000)
            {
                current_amount = current_amount + coin;
            }
            else
            {
                printf("-> %dKRW cannot be used.\n", coin);
            }
        }

        int change = current_amount - price;
        total_sales_count++;
        total_revenue = total_revenue + price;

        printf("Drink is out! Change: %dKRW\n", change);

        if (change == 0)
        {
            printf("No Change\n");
        }
        else
        {
            int count_500 = change / 500;
            int count_100 = (change % 500) / 100;

            printf("500KRW: ");
            for (int i = 0; i < count_500; i++) 
                printf("O");
            printf("\n");

            printf("100KRW: ");
            for (int i = 0; i < count_100; i++) 
                printf("O");
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}