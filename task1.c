#include <stdio.h>
int main ()
{
    FILE *fp;
    int itemNo , qty;
    int fileItemNo , stock;
    char name[25];
    float price;
    float Totalbill = 0.0;

    fp = fopen("item.txt" , "w");
    if(fp==NULL){
        printf("Error crating file!");
        return 1;
    }
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 1, "Rice", 250.00, 40);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 2, "Sugar", 160.00, 25);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 3, "Milk", 220.00, 30);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 4, "CookingOil", 560.00, 12);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 5, "Tea", 450.00, 18);
    fclose(fp);

    fp=fopen("item.txt" , "rb+");
        if(fp==NULL)
        {
            printf("Error opening file!\n");
        return 1;
        }
    printf("=== Welcome to FreshMart Cashier System ===\n");
    while(1)
    {
        printf("Enter the item number: ");
        scanf("%d", &itemNo);

        if(itemNo==0)
        {
            break;
        }
        if(itemNo<1 || itemNo>5)
        {
            printf("Invalid item number! Please enter 1 to 5.\n");
            continue;
        }

        printf("Enter quantity: ");
        scanf("%d", &qty);

        fseek(fp , (itemNo -1)*42 , SEEK_SET);
        fscanf(fp, "%d %s %f %d" , &fileItemNo , name , &price , &stock);


        if (stock >= qty) {
            float lineCost = price * qty;
            Totalbill += lineCost;
            stock -= qty; // Reduce the stock

            printf("Added: %s x %d = %.2f\n", name, qty, lineCost);

            // Jump BACK to the start of this same record and overwrite it
            fseek(fp, (itemNo - 1) * 42, SEEK_SET);
            fprintf(fp, "%-4d %-20s %9.2f %5d\n", fileItemNo, name, price, stock);
        } else {
            printf("Sorry! Not enough stock for %s (Available: %d)\n", name, stock);
        }
    }

    printf("Total Bill: %.2f\n", Totalbill);

    fclose(fp);



    return 0;


}