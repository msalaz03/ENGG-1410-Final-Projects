/*
Author: Matthew Salazar
Date 01/16/23
Assignment: #1

The purpose is to find the numbers that divide perfectly into a number given by the user and to add those numbers
and if the difference between the sum and number is equal to the original number then this number is defined as perfect. 
NOTE: The actual function is int checkPerfect(int n).
*/


#include <stdio.h>

int checkPerfect(int n);

int main()
{
    
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    
    int check = checkPerfect(x);
    
     if (check == 1)
    {
        printf("Perfect");
        
    }
    
    else
    {
        printf("Not Perfect");
    }
    
    return 0;
}


int checkPerfect(int n)
{
    int sum = 0;
    
     for (int i = 1; i <= n; i++) //for the values between 1 and x
     { 
        
        if (n % i == 0) //perfectly divisible
        { 
            sum += i; //add it
           
        }
        
    }
    
    if (n == sum - n)
    {
        return 1; //if the number meets the conditions return 1
    }
    
    else 
    {
        return 0; //else return 0
    }
    
}
