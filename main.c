#include <stdio.h>
#include <stdlib.h>

// Define constants for bounce house pricing
#define MAGIC_CASTLE_3HR 58
#define MAGIC_CASTLE_HOURLY 8
#define MAGIC_CASTLE_DAILY 80

#define GIGANTIC_JUMP_3HR 85
#define GIGANTIC_JUMP_HOURLY 12
#define GIGANTIC_JUMP_DAILY 120

#define WET_DRY_SLIDE_3HR 100
#define WET_DRY_SLIDE_HOURLY 15
#define WET_DRY_SLIDE_DAILY 150

#define OBSTACLE_COMBO_3HR 180
#define OBSTACLE_COMBO_HOURLY 20
#define OBSTACLE_COMBO_DAILY 250

int main() {
    int selection, days, hours;
    int charge = 0;

    // Display the selection options
    printf("Please select from four bounce houses: 1, 2, 3, and 4\n");
    printf("1. Magic castle\n");
    printf("2. Gigantic jump\n");
    printf("3. Wet and dry slide\n");
    printf("4. Obstacle combo with pool\n");

    // User input for selection, days, and hours
    printf("Enter bounce house selection: ");
    scanf("%d", &selection);
    if (selection < 1 || selection > 4) {
        printf("Invalid selection. Select from 1 to 4.\n");
        return 1;
    }

    printf("Enter days: ");
    scanf("%d", &days);

    printf("Enter hours: ");
    scanf("%d", &hours);
    if (hours < 0 || hours >= 24) {
        printf("Invalid hours.\n");
        return 1;
    }

    // Calculate the charge based on selection
    switch (selection) {
        case 1: // Magic Castle
            if (days == 0) {
                if (hours <= 3) {
                    charge = MAGIC_CASTLE_3HR;
                } else {
                    charge = MAGIC_CASTLE_3HR + (hours - 3) * MAGIC_CASTLE_HOURLY;
                    if (charge > MAGIC_CASTLE_DAILY) {
                        charge = MAGIC_CASTLE_DAILY;
                    }
                }
            } else {
                charge = days * MAGIC_CASTLE_DAILY + hours * MAGIC_CASTLE_HOURLY;
                if (hours >= 3) {
                    if (charge > (days + 1) * MAGIC_CASTLE_DAILY) {
                        charge = (days + 1) * MAGIC_CASTLE_DAILY;
                    }
                }
            }
            break;

        case 2: // Gigantic Jump
            if (days == 0) {
                if (hours <= 3) {
                    charge = GIGANTIC_JUMP_3HR;
                } else {
                    charge = GIGANTIC_JUMP_3HR + (hours - 3) * GIGANTIC_JUMP_HOURLY;
                    if (charge > GIGANTIC_JUMP_DAILY) {
                        charge = GIGANTIC_JUMP_DAILY;
                    }
                }
            } else {
                charge = days * GIGANTIC_JUMP_DAILY + hours * GIGANTIC_JUMP_HOURLY;
                if (hours >= 3) {
                    if (charge > (days + 1) * GIGANTIC_JUMP_DAILY) {
                        charge = (days + 1) * GIGANTIC_JUMP_DAILY;
                    }
                }
            }
            break;

        case 3: // Wet and Dry Slide
            if (days == 0) {
                if (hours <= 3) {
                    charge = WET_DRY_SLIDE_3HR;
                } else {
                    charge = WET_DRY_SLIDE_3HR + (hours - 3) * WET_DRY_SLIDE_HOURLY;
                    if (charge > WET_DRY_SLIDE_DAILY) {
                        charge = WET_DRY_SLIDE_DAILY;
                    }
                }
            } else {
                charge = days * WET_DRY_SLIDE_DAILY + hours * WET_DRY_SLIDE_HOURLY;
                if (hours >= 3) {
                    if (charge > (days + 1) * WET_DRY_SLIDE_DAILY) {
                        charge = (days + 1) * WET_DRY_SLIDE_DAILY;
                    }
                }
            }
            break;

        case 4: // Obstacle Combo with Pool
            if (days == 0) {
                if (hours <= 3) {
                    charge = OBSTACLE_COMBO_3HR;
                } else {
                    charge = OBSTACLE_COMBO_3HR + (hours - 3) * OBSTACLE_COMBO_HOURLY;
                    if (charge > OBSTACLE_COMBO_DAILY) {
                        charge = OBSTACLE_COMBO_DAILY;
                    }
                }
            } else {
                charge = days * OBSTACLE_COMBO_DAILY + hours * OBSTACLE_COMBO_HOURLY;
                if (hours >= 3) {
                    if (charge > (days + 1) * OBSTACLE_COMBO_DAILY) {
                        charge = (days + 1) * OBSTACLE_COMBO_DAILY;
                    }
                }
            }
            break;

        default:
            printf("Invalid selection. Select from 1 to 4.\n");
            return 1;
    }

    // Output the final charge
    printf("Charge($): %d\n", charge);

    return 0;
}
