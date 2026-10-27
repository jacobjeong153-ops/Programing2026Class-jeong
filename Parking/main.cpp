#include <stdio.h>

int input_Vehicle_Count();
int Vehicle_type();
int input_Parking_Time();
int calculate_Fee(int minutes);
int apply_Discount(int fee, int type, int* discount_percent);

int main()
{
    int number;
    int time;
    int type;
    int fee;
    int discount_percent;
    int discount_fee;

    while (1) 
    {
        number = input_Vehicle_Count();

        int total_revenue = 0;
        int max_fee = -1;
        int max_fee_car_index = -1;

        for (int i = 1; i <= number; i++)
        {
            discount_percent = 0;
            fee = 0;
            printf("\n[Number %d Vehicle]\n", i);

            type = Vehicle_type();
            time = input_Parking_Time();

            fee = calculate_Fee(time);
            discount_fee = apply_Discount(fee, type, &discount_percent);

            printf("Fee: %d won (Discount %d%%)\n", discount_fee, discount_percent);

            total_revenue += discount_fee;
            if (discount_fee > max_fee) {
                max_fee = discount_fee;
                max_fee_car_index = i;
            }
        }

        printf("\nTotal Settlement Amount: %d won\n", total_revenue);
        if (max_fee_car_index != -1) {
            printf("Highest Fee: Number %d Vehicle (%d won)\n\n", max_fee_car_index, max_fee);
        }

        break;
    }
    return 0;
}

int input_Vehicle_Count()
{
    int number = 0;
    printf("Number of Vehicles to Be Settled(1~10): ");
    scanf_s("%d", &number);

    while (number > 10 || number < 1) {
        printf("-> Please enter a value between 1 and 10.\n");
        printf("Number of Vehicles to Be Settled(1~10): ");
        scanf_s("%d", &number);
    }
    return number;
}

int Vehicle_type()
{
    int type;
    printf("Vehicle Type(1: Compact Car 2: Standard 3: Electric Vehicle): ");
    scanf_s("%d", &type);

    while (type != 1 && type != 2 && type != 3) {
        printf("Invalid input. Please try again.\n");
        printf("Vehicle Type(1: Compact Car 2: Standard 3: Electric Vehicle): ");
        scanf_s("%d", &type);
    }
    return type;
}

int input_Parking_Time()
{
    int time;
    printf("Parking Time(min): ");
    scanf_s("%d", &time);

    while (time < 0) {
        printf("-> Invalid input. Please enter a value of 0 or greater: ");
        scanf_s("%d", &time);
    }
    return time;
}

int calculate_Fee(int minutes)
{
    int fee = 0;

    if (minutes <= 30) {
        return 0;
    }

    int over_time = minutes - 30;
    fee = ((over_time + 9) / 10) * 500;

    if (fee > 20000) {
        fee = 20000;
    }

    return fee;
}

int apply_Discount(int fee, int type, int* discount_percent)
{
    switch (type)
    {
    case 1:
        *discount_percent = 50;
        fee = (int)(fee * 0.5);
        break;
    case 2:
        *discount_percent = 0;
        break;
    case 3:
        *discount_percent = 30;
        fee = (int)(fee * 0.7);
        break;
    default:
        *discount_percent = 0;
        break;
    }
    return fee;
}
