/*
Author: Matthew Salazar
Date 01/16/23
Assignment: #1

The purpose  Is to find the numbers that divide perfectly into a number given by the user and to add those numbers and output the sum. 
NOTE: The actual function is int findSum(int n).
*/
#include <stdio.h>

int findSum(int n);


int findSum(int n)
{
    int sum = 0;
    
     for (int i = 1; i <= n; i++) //for the values between 1 and x
     { 
        
        if (n % i == 0) //perfectly divisible
        { 
            sum += i; //add it
           
        }
    }
    
return sum;
}

int main()
{
    
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    
    int sum = findSum(x);
    printf("%d", sum);
    
    return 0;
}



