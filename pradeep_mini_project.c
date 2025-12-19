#include <stdio.h>
#include <string.h>

struct Vehicle {
    char name[30];
    int pricePerHour;
    int pricePerDay;
    int damageFine;
};

int main() {
    int type, model, rentType, time, damaged, total = 0;

    
    struct Vehicle bikes[3] = {
        {"Honda Shine", 50, 300, 500},
        {"TVS Apache", 80, 500, 700},
        {"Royal Enfield", 120, 700, 1000}
    };

    
    struct Vehicle cars[3] = {
        {"Maruti Alto", 150, 1000, 2000},
        {"Hyundai i20", 200, 1500, 2500},
        {"Mahindra Thar", 400, 2500, 4000}
    };

    printf("----- VEHICLE RENTAL MANAGEMENT SYSTEM -----\n");
    printf("1. Bike\n2. Car\nChoose Vehicle Type: ");
    scanf("%d", &type);

    if(type == 1) {
        printf("\n--- Available Bikes ---\n");
        for(int i=0; i<3; i++)
            printf("%d. %s (Per Hour: %d, Per Day: %d)\n", 
                i+1, bikes[i].name, bikes[i].pricePerHour, bikes[i].pricePerDay);

        printf("\nChoose Bike Model: ");
        scanf("%d", &model);

        struct Vehicle v = bikes[model-1];

        printf("\n1. Rent Per Hour\n2. Rent Per Day\nChoose Rent Type: ");
        scanf("%d", &rentType);

        printf("Enter Hours/Days: ");
        scanf("%d", &time);

        if(rentType == 1)
            total += v.pricePerHour * time;
        else
            total += v.pricePerDay * time;

        printf("Is the vehicle damaged? (1-Yes / 0-No): ");
        scanf("%d", &damaged);

        if(damaged == 1)
            total += v.damageFine;

    }
    else if(type == 2) {
        printf("\n--- Available Cars ---\n");
        for(int i=0; i<3; i++)
            printf("%d. %s (Per Hour: %d, Per Day: %d)\n",
                i+1, cars[i].name, cars[i].pricePerHour, cars[i].pricePerDay);

        printf("\nChoose Car Model: ");
        scanf("%d", &model);

        struct Vehicle v = cars[model-1];

        printf("\n1. Rent Per Hour\n2. Rent Per Day\nChoose Rent Type: ");
        scanf("%d", &rentType);

        printf("Enter Hours/Days: ");
        scanf("%d", &time);

        if(rentType == 1)
            total += v.pricePerHour * time;
        else
            total += v.pricePerDay * time;

        printf("Is the vehicle damaged? (1-Yes / 0-No): ");
        scanf("%d", &damaged);

        if(damaged == 1)
            total += v.damageFine;
    }
    else {
        printf("Invalid Choice!\n");
        return 0;
    }

    printf("\n------------------------------\n");
    printf("TOTAL RENTAL AMOUNT = %d\n", total);
    printf("------------------------------\n");

    return 0;
}