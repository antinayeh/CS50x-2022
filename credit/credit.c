#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long h = get_long("Number: ");

    //total sum
    int sum = 0;
    // counter to know if you are on odd or even digit
    int counter = 0;
    // current last digit
    int d;
    // used to find first 2 digit to determine type of card
    int dd;

    while (h > 0)
    {
        counter ++;
        if (h < 99 && h > 9)
        {
            dd = h;
        }
        d = h % 10;
        if (counter % 2 != 0)
        {
            sum = sum + d;
        }
        else
        {
            int double_d = d * 2;
            if (double_d > 9)
            {
                double_d = double_d % 10;
                double_d ++;
            }
            sum = sum + double_d;
        }
        h = h / 10;
    }

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        if (d == 4 && (counter == 13 || counter == 16))
        {
            printf("VISA\n");
        }
        else if (d == 3 && (dd == 34 || dd == 37) && counter == 15)
        {
            printf("AMEX\n");
        }
        else if (d == 5 && counter == 16)
        {
            if (dd == 51 || dd == 52 || dd == 53 || dd == 54 || dd == 55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
}