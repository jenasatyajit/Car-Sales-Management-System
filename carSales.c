/*
 * Car Sales Management System
 * Author: Satyajit Jena
 * Date: 03/01/2025
 * Description: This is a simple car sales management system that allows users to buy cars, view sales data, and leave feedback.
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_CUSTOMER 100

// Car data arrays
float price[MAX_CUSTOMER];
char model[MAX_CUSTOMER][30];
int yearOfManufacture[MAX_CUSTOMER];
int remainingAmt[MAX_CUSTOMER];
int carCount = 23;

// Sales data structure
typedef struct
{
    char model[30];
    float totalPrice;
    char customerName[50];
    int customerAge;
    float discount;
    char date[20];
    int quantityBought;
} Sale;

// Feedback data structure
typedef struct
{
    char model[30];
    char feedback[100];
    int rating;
} Feedback;

// Initialize sales and feedback arrays
Sale sales[MAX_CUSTOMER];
Feedback feedbacks[MAX_CUSTOMER];
int saleCount = 0, feedbackCount = 0;

// Function to initialize sample car data
void sampleCarData()
{
    strcpy(model[0], "Bugatti");
    price[0] = 320000;
    yearOfManufacture[0] = 2010;
    remainingAmt[0] = 5;

    strcpy(model[1], "Mercedes");
    price[1] = 40000;
    yearOfManufacture[1] = 2020;
    remainingAmt[1] = 20;

    strcpy(model[2], "Audi");
    price[2] = 40000;
    yearOfManufacture[2] = 2015;
    remainingAmt[2] = 25;

    strcpy(model[3], "Ford");
    price[3] = 25000;
    yearOfManufacture[3] = 2024;
    remainingAmt[3] = 15;

    strcpy(model[4], "Kia");
    price[4] = 28000;
    yearOfManufacture[4] = 2024;
    remainingAmt[4] = 22;

    strcpy(model[5], "Toyota");
    price[5] = 27500;
    yearOfManufacture[5] = 2024;
    remainingAmt[5] = 18;

    strcpy(model[6], "Volkswagen");
    price[6] = 27000;
    yearOfManufacture[6] = 2024;
    remainingAmt[6] = 20;

    strcpy(model[7], "Nissan");
    price[7] = 29000;
    yearOfManufacture[7] = 2024;
    remainingAmt[7] = 25;

    strcpy(model[8], "Hyundai");
    price[8] = 30000;
    yearOfManufacture[8] = 2024;
    remainingAmt[8] = 19;

    strcpy(model[9], "Dacia");
    price[9] = 20000;
    yearOfManufacture[9] = 2024;
    remainingAmt[9] = 12;

    strcpy(model[10], "Honda");
    price[10] = 29000;
    yearOfManufacture[10] = 2024;
    remainingAmt[10] = 17;

    strcpy(model[11], "Skoda");
    price[11] = 28000;
    yearOfManufacture[11] = 2024;
    remainingAmt[11] = 24;

    strcpy(model[12], "Mazda");
    price[12] = 32000;
    yearOfManufacture[12] = 2024;
    remainingAmt[12] = 28;

    strcpy(model[13], "BMW");
    price[13] = 85000;
    yearOfManufacture[13] = 2024;
    remainingAmt[13] = 30;

    strcpy(model[14], "Mercedes Benz");
    price[14] = 100000;
    yearOfManufacture[14] = 2024;
    remainingAmt[14] = 25;

    strcpy(model[15], "Rolls Royce");
    price[15] = 400000;
    yearOfManufacture[15] = 2024;
    remainingAmt[15] = 18;

    strcpy(model[16], "Bentley");
    price[16] = 200000;
    yearOfManufacture[16] = 2024;
    remainingAmt[16] = 22;

    strcpy(model[17], "Tesla");
    price[17] = 100000;
    yearOfManufacture[17] = 2024;
    remainingAmt[17] = 14;

    strcpy(model[18], "Aston Martin");
    price[18] = 200000;
    yearOfManufacture[18] = 2024;
    remainingAmt[18] = 16;

    strcpy(model[19], "Porsche");
    price[19] = 90000;
    yearOfManufacture[19] = 2024;
    remainingAmt[19] = 19;

    strcpy(model[20], "McLaren");
    price[20] = 185000;
    yearOfManufacture[20] = 2024;
    remainingAmt[20] = 13;

    strcpy(model[21], "Bugatti Veyron");
    price[21] = 1195000;
    yearOfManufacture[21] = 2008;
    remainingAmt[21] = 26;

    strcpy(model[22], "Ferrari");
    price[22] = 950000;
    yearOfManufacture[22] = 2017;
    remainingAmt[22] = 20;
}

// Function to validate integer input
void validateNum(int *num)
{
    int correctInput = 0;
    do
    {
        int numOfCapturedValue = scanf("%d", num);
        while (getchar() != '\n')
            ;

        if (numOfCapturedValue == 0)
        {
            printf("\nPlease only enter whole numbers: ");
        }
        else
        {
            correctInput = 1;
        }
    } while (correctInput == 0);
}

// Function to validate float input
void validateFloat(float *num)
{
    int correctInput = 0;
    do
    {
        int numOfCapturedValue = scanf("%f", num);
        while (getchar() != '\n')
            ;

        if (numOfCapturedValue == 0)
        {
            printf("\nPlease only enter float numbers: ");
        }
        else
        {
            correctInput = 1;
        }
    } while (correctInput == 0);
}

// Function to convert a string to lowercase
void toLowerStr(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Function to view car stock
void viewStock()
{
    // Sort cars by year of manufacture in descending order
    for (int i = 0; i < carCount - 1; i++)
    {
        for (int j = i + 1; j < carCount; j++)
        {
            if (yearOfManufacture[i] < yearOfManufacture[j])
            {
                // Swap years
                int tempYear = yearOfManufacture[i];
                yearOfManufacture[i] = yearOfManufacture[j];
                yearOfManufacture[j] = tempYear;

                // Swap models
                char tempModel[30];
                strcpy(tempModel, model[i]);
                strcpy(model[i], model[j]);
                strcpy(model[j], tempModel);

                // Swap prices
                float tempPrice = price[i];
                price[i] = price[j];
                price[j] = tempPrice;

                // Swap quantities
                int tempQty = remainingAmt[i];
                remainingAmt[i] = remainingAmt[j];
                remainingAmt[j] = tempQty;
            }
        }
    }

    // Display car stock
    printf("\n--- Cars Stock ---\n");
    for (int i = 0; i < carCount; i++)
    {
        printf("%s | Year: %d | Price: %.2f | Quantity: %d\n", model[i], yearOfManufacture[i], price[i], remainingAmt[i]);
    }
}

// Function to save sales data to file
void saveSalesToFile()
{
    FILE *file = fopen("sales_data.txt", "w");
    if (!file)
    {
        printf("Error: Could not open file for saving sales data.\n");
        return;
    }

    for (int i = 0; i < saleCount; i++)
    {
        fprintf(file, "%s,%d,%s,%d,%.2f,%.2f,%s\n",
                sales[i].customerName, sales[i].customerAge, sales[i].model,
                sales[i].quantityBought, sales[i].totalPrice, sales[i].discount,
                sales[i].date);
    }

    fclose(file);
}

// Function to load sales data from file
void loadSalesFromFile()
{
    FILE *file = fopen("sales_data.txt", "r");
    if (!file)
    {
        printf("No previous sales data found.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "%[^,],%d,%[^,],%d,%f,%f,%[^\n]",
               sales[saleCount].customerName, &sales[saleCount].customerAge,
               sales[saleCount].model, &sales[saleCount].quantityBought,
               &sales[saleCount].totalPrice, &sales[saleCount].discount,
               sales[saleCount].date);
        saleCount++;
    }

    fclose(file);
    printf("Previous sales data loaded successfully\n");
}

// Function to handle car purchase
void buyCar()
{
    char selectedModel[30], name[50];
    int age, quantity;
    float totalPrice, discount = 0.0;
    time_t t;
    time(&t);

    // Clear input buffer
    while (getchar() != '\n' && getchar() != EOF)
        ;
    printf("\nEnter Car Model: ");
    if (fgets(selectedModel, sizeof(selectedModel), stdin) != NULL)
    {
        char *newline = strchr(selectedModel, '\n');
        if (newline)
        {
            *newline = '\0';
        }
    }
    toLowerStr(selectedModel);
    int carIndex = -1;
    for (int i = 0; i < carCount; i++)
    {
        char tempModel[30];
        strcpy(tempModel, model[i]);
        toLowerStr(tempModel);
        if (strcasecmp(tempModel, selectedModel) == 0)
        {
            carIndex = i;
            break;
        }
    }

    if (carIndex == -1)
    {
        printf("Model not found\n");
        return;
    }

    printf("Enter Your Name: ");
    scanf("%s", name);
    printf("Enter Your Age: ");
    validateNum(&age);
    printf("Enter Quantity: ");
    validateNum(&quantity);

    if (quantity > remainingAmt[carIndex])
    {
        printf("Insufficient stock.\n");
        return;
    }

    remainingAmt[carIndex] -= quantity;
    totalPrice = (float)price[carIndex] * quantity;

    printf("Discount Applied: ");
    validateFloat(&discount);

    // Save sale details
    strcpy(sales[saleCount].customerName, name);
    sales[saleCount].customerAge = age;
    strcpy(sales[saleCount].model, model[carIndex]);
    sales[saleCount].quantityBought = quantity;
    sales[saleCount].totalPrice = totalPrice - discount;
    sales[saleCount].discount = discount;
    strftime(sales[saleCount].date, 20, "%Y-%m-%d", localtime(&t));
    saleCount++;

    saveSalesToFile();

    printf("Purchase successful. Total: %.2f (Discount: %.2f)\n", totalPrice - discount, discount);

    // Ask for feedback
    printf("\nWould you like to leave feedback? (1 for Yes, 0 for No): ");
    int leaveFeedback;
    int correctInput = 0, numOfCapturedValue;
    do
    {
        numOfCapturedValue = scanf("%d", &leaveFeedback);
        while (getchar() != '\n')
            ;

        if (numOfCapturedValue == 0)
        {
            printf("Please only enter (1 for Yes, 0 for No): ");
        }
        else
        {
            if (leaveFeedback == 1 || leaveFeedback == 0)
            {
                correctInput = 1;
            }
            else
            {
                printf("Please only enter (1 for Yes, 0 for No): ");
            }
        }
    } while (correctInput == 0);

    if (leaveFeedback)
    {
        printf("Enter a rating (1-5): ");
        int rating;
        validateNum(&rating);
        printf("Enter a short feedback: ");
        fgets(feedbacks[feedbackCount].feedback, 100, stdin);
        feedbacks[feedbackCount].rating = rating;
        strcpy(feedbacks[feedbackCount].model, model[carIndex]);
        feedbackCount++;
    }
}

// Function to view customer feedback
void viewFeedback()
{
    printf("\n--- Customer Feedback ---\n");
    for (int i = 0; i < feedbackCount; i++)
    {
        printf("Model: %s | Rating: %d | Feedback: %s",
               feedbacks[i].model, feedbacks[i].rating, feedbacks[i].feedback);
    }
}

// Function to sort sales data by total price in descending order
void sortSalesData()
{
    for (int i = 0; i < saleCount - 1; i++)
    {
        for (int j = i + 1; j < saleCount; j++)
        {
            if (sales[i].totalPrice < sales[j].totalPrice)
            {
                Sale temp = sales[i];
                sales[i] = sales[j];
                sales[j] = temp;
            }
        }
    }
}

// Function to view sales data
void viewSalesData()
{
    printf("\n--- Sales Data ---\n");
    sortSalesData();
    for (int i = 0; i < saleCount; i++)
    {
        printf("\nCustomer: %s | Model: %s | Quantity: %d | Total: %.2f | Discount: %.2f | Date: %s\n",
               sales[i].customerName, sales[i].model, sales[i].quantityBought,
               sales[i].totalPrice, sales[i].discount, sales[i].date);
    }

    printf("\n--- Model Wise Data ---\n");
    for (int i = 0; i < carCount; i++)
    {
        int totalUnits = 0;
        float totalRevenue = 0.0;

        for (int j = 0; j < saleCount; j++)
        {
            if (strcmp(model[i], sales[j].model) == 0)
            {
                totalUnits += sales[j].quantityBought;
                totalRevenue += sales[j].totalPrice;
            }
        }

        if (totalUnits > 0)
        {
            printf("%s sold %d units for total of %.2f\n",
                   model[i], totalUnits, totalRevenue);
        }
    }
}

// Function to display the menu options
void showMenu()
{
    printf("\n\t-- WELCOME TO SATYAJIT CAR SALES --\n");
    printf("\n0. Show Menu\n");
    printf("1. View Car Stock\n");
    printf("2. Buy Cars\n");
    printf("3. View Sales Data\n");
    printf("4. Customer Feedback\n");
    printf("5. Exit\n");
}

int main()
{
    // Initialize sample car data
    sampleCarData();

    // Load previous sales data from file
    loadSalesFromFile();

    int opt = 0;
    while (opt != 5)
    {
        switch (opt)
        {
        case 0:
            showMenu();
            break;
        case 1:
            viewStock();
            break;
        case 2:
            buyCar();
            break;
        case 3:
            viewSalesData();
            break;
        case 4:
            viewFeedback();
            break;
        case 5:
            printf("\n\t-- THANK YOU FOR VISITING !! --\t\n");
            break;
        default:
            printf("Enter a valid input !!\n");
            break;
        }
        printf("\nEnter your choice: ");
        validateNum(&opt);
    }
}