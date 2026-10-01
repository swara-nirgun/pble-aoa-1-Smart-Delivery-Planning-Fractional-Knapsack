#include <stdio.h>
#define MAX 100
struct Package
{
    int id;
    float value;
    float weight;
    float ratio;
    float fraction;
};
void calculateRatio(struct Package p[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (p[i].weight > 0)
            p[i].ratio = p[i].value / p[i].weight;
        else
            p[i].ratio = 0;
    }
}
void displayDetails(struct Package p[], int n)
{
    int i;
    if (n == 0)
    {
        printf("\nPlease enter package details first.\n");
        return;
    }
    calculateRatio(p, n);
    printf("\n---------------------------------------------\n");
    printf("ID\tValue\tWeight\tRatio\n");
    printf("---------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\n", p[i].id, p[i].value, p[i].weight, p[i].ratio);
    }
    printf("\n");
}
void enterDetails(struct Package p[], int *n)
{
    int i;
    printf("\nEnter number of packages: ");
    scanf("%d", n);
    for (i = 0; i < *n; i++)
    {
        p[i].id = i + 1;
        printf("\nEnter value of package %d: ", i + 1);
        scanf("%f", &p[i].value);
        printf("Enter weight of package %d: ", i + 1);
        scanf("%f", &p[i].weight);
        p[i].ratio = 0;
        p[i].fraction = 0;
    }
    printf("\nEnter maximum carrying capacity: ");
}
void showRatio(struct Package p[], int n)
{
    int i;
    if (n == 0)
    {
        printf("\nPlease enter package details first.\n");
        return;
    }
    calculateRatio(p, n);
    printf("\nValue/Weight Ratios:\n");
    printf("---------------------------------------------\n");
    printf("ID\tValue\tWeight\tRatio\n");
    printf("---------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\n", p[i].id, p[i].value, p[i].weight, p[i].ratio);
    }
    printf("---------------------------------------------\n");
}
void sortPackages(struct Package p[], int n)
{
    int i, j;
    struct Package temp;
    if (n == 0)
    {
        printf("\nPlease enter package details first.\n");
        return;
    }
    calculateRatio(p, n);
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].ratio < p[j + 1].ratio)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    printf("\nPackages sorted by decreasing Value/Weight Ratio:\n");
    printf("---------------------------------------------\n");
    printf("ID\tValue\tWeight\tRatio\n");
    printf("---------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\n", p[i].id, p[i].value, p[i].weight, p[i].ratio);
    }
    printf("---------------------------------------------\n");
}
void findMaximumValue(struct Package p[], int n, float capacity)
{
    int i;
    float remaining = capacity;
    float totalValue = 0;
    if (n == 0)
    {
        printf("\nPlease enter package details first.\n");
        return;
    }
    sortPackages(p, n);
    for (i = 0; i < n; i++)
        p[i].fraction = 0;
    for (i = 0; i < n; i++)
    {
        if (remaining <= 0)
            break;
        if (p[i].weight <= remaining)
        {
            p[i].fraction = 1;
            remaining = remaining - p[i].weight;
            totalValue = totalValue + p[i].value;
        }
        else
        {
            p[i].fraction = remaining / p[i].weight;
            totalValue = totalValue + (p[i].value * p[i].fraction);
            remaining = 0;
        }
    }
    printf("Total Weight Used : %.2f\n", capacity - remaining);
    printf("Maximum Value     : %.2f\n", totalValue);
    printf("=============================================\n");
}
void displaySelected(struct Package p[], int n)
{
    int i;
    float totalWeight = 0;
    float totalValue = 0;
    if (n == 0)
    {
        printf("\nPlease enter package details first.\n");
        return;
    }
    printf("\n---------------------------------------------------------------\n");
    printf("ID\tWeight\tFraction\tSelected Weight\tSelected Value\n");
    printf("---------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        if (p[i].fraction > 0)
        {
            float selectedWeight = p[i].weight * p[i].fraction;
            float selectedValue = p[i].value * p[i].fraction;
            printf("%d\t%.2f\t%.2f\t\t%.2f\t\t%.2f\n", p[i].id, p[i].weight, p[i].fraction, selectedWeight, selectedValue);
            totalWeight += selectedWeight;
            totalValue += selectedValue;
        }
    }
    printf("---------------------------------------------------------------\n");
    printf("Total Weight Used : %.2f\n", totalWeight);
    printf("Maximum Value     : %.2f\n", totalValue);
}
int main()
{
    struct Package p[MAX];
    int n = 0;
    int choice;
    float capacity = 0;
    do
    {
        printf("1. Enter Package Details\n");
        printf("2. Display Package Details\n");
        printf("3. Calculate Value/Weight Ratio\n");
        printf("4. Sort Packages by Ratio\n");
        printf("5. Find Maximum Value\n");
        printf("6. Display Selected Packages\n");
        printf("7. Exit\n");
        printf("=============================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                enterDetails(p, &n);
                scanf("%f", &capacity);
                if(n<0)
                    printf("Please enter a positive value");
                calculateRatio(p, n);
                displayDetails(p, n);
                break;
            case 2:
                displayDetails(p, n);
                break;
            case 3:
                showRatio(p, n);
                break;
            case 4:
                sortPackages(p, n);
                break;
            case 5:
                if (capacity <= 0)
                {
                    printf("\nPlease enter a valid capacity first.\n");
                }
                else
                {
                    findMaximumValue(p, n, capacity);
                }
                break;
            case 6:
                displaySelected(p, n);
                break;
            case 7:
                printf("\nProgram terminated successfully.\n");
                break;
            default:
                printf("\nInvalid choice, Please try again.\n");
        }
    } while (choice != 7);
    return 0;
}
