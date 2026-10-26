#include <stdio.h>

int get_menu_choice();
double get_positive_double(const char* prompt);
void print_results(double v, double i, double r);
void calculate_voltage();
void calculate_current();
void calculate_resistance();

int main(void)
{
    int choice;
    while (1)
    {
        choice = get_menu_choice();

        if (choice == 0) {
            printf("Exit the program.\n");
            break;
        }

        switch (choice)
        {
        case 1:
            calculate_voltage();
            break;
        case 2:
            calculate_current();
            break;
        case 3:
            calculate_resistance();
            break;
        case 4:
            printf("Execute the Sweep table function.\n");
            break;
        default:
            printf("Invalid selection. Please choose a valid menu number.\n");
            break;
        }
    }
    return 0;
}

int get_menu_choice()
{
    int choice;
    printf("\n===== Ohm's Law Calculator =====\n");
    printf("1. Voltage  2. Current  3. Resistance  4. Sweep table  0. Exit\n");
    printf("Select: ");
    scanf_s("%d", &choice);
    return choice;
}

double get_positive_double(const char* prompt)
{
    double value;

    printf("%s", prompt);
    scanf_s("%lf", &value);

    while (value <= 0)
    {
        printf(" -> Value must be positive. Enter again: ");
        scanf_s("%lf", &value);
    }

    return value;
}

void print_results(double v, double i, double r)
{
    double p = v * i;
    printf(" V = %.3f V,  I = %.3f A,  R = %.3f ohm,  P = %.3f W\n", v, i, r, p);
}

void calculate_voltage()
{
    double i = get_positive_double("Current (A): ");
    double r = get_positive_double("Resistance (ohm): ");
    double v = i * r;
    print_results(v, i, r);
}

void calculate_current()
{
    double v = get_positive_double("Voltage (V): ");
    double r = get_positive_double("Resistance (ohm): ");
    double i = v / r;
    print_results(v, i, r);
}

void calculate_resistance()
{
    double v = get_positive_double("Voltage (V): ");
    double i = get_positive_double("Current (A): ");
    double r = v / i;
    print_results(v, i, r);
}