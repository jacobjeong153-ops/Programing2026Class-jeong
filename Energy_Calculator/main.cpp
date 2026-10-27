#include <stdio.h>

#define G 9.81

double get_positive_input(const char* prompt);

void print_energy(double energy_j);

void print_menu(void);

int main() 
{
    int choice;
    double mass, speed, height, start_height;
    double ke, pe, total, h;

    print_menu();

    while (1) 
    {
        printf("Select: ");
        scanf_s("%d", &choice);

        if (choice == 0) {
            printf("Exiting the program...\n");
            break;
        }

        switch (choice) 
        {
        case 1:
            mass = get_positive_input("Mass (kg): ");
            speed = get_positive_input("Speed (m/s): ");
            ke = 0.5 * mass * speed * speed;
            print_energy(ke);
            printf("\n");
            break;

        case 2:
            mass = get_positive_input("Mass (kg): ");
            height = get_positive_input("Height (m): ");
            pe = mass * G * height;
            print_energy(pe);
            printf("\n");
            break;

        case 3:
            mass = get_positive_input("Mass (kg): ");
            start_height = get_positive_input("Start height (m): ");

            printf("%10s %10s %10s %10s\n", "h(m)", "PE(J)", "KE(J)", "Total(J)");

            for (int i = 0; i <= 5; i++) 
            {
                h = start_height * (5 - i) / 5.0;
                pe = mass * G * h;
                ke = mass * G * (start_height - h);
                total = pe + ke;
                printf("%10.3f %10.3f %10.3f %10.3f\n", h, pe, ke, total);
            }
            printf("\n");
            break;

        default:
            printf("Invalid selection. Try again.\n\n");
            break;
        }
    }

    return 0;
}

double get_positive_input(const char* prompt) 
{
    double value;
    while (1) 
    {
        printf("%s", prompt);
        scanf_s("%lf", &value);
        if (value > 0) 
        {
            return value;
        }
        else 
        {
            printf("-> Value must be positive. Enter again: \n");
        }
    }
}

void print_energy(double energy_j) 
{
    if (energy_j >= 1000.0) 
    {
        double energy_kj = energy_j / 1000.0;
        printf("Energy = %.3f J (%.3f kJ)\n", energy_j, energy_kj);
    }
    else 
    {
        printf("  Energy = %.3f J\n", energy_j);
    }
}

void print_menu(void) 
{
    printf("===== Mechanical Energy Calculator =====\n");
    printf("1. Kinetic energy  2. Potential energy  3. Free-fall table  0. Exit\n");
}
