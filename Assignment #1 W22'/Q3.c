/*
Author: Matthew Salazar
Date 01/16/23
Assignment: #1

 The purpose of this program is to ask for five numbers and arrange them from descending order.
*/



#include <stdio.h>

int main()
    {
        
    int i, j, temp, num[5];
        
 
 printf("Enter the five numbers: \n");

    for (i = 0; i < 5; ++i)
        scanf("%d", &num[i]); //get array elements
            
            
 
        for (i = 0; i < 5; ++i) //compare first element
        {
            for (j = i + 1; j < 5; ++j) //compare next element of i
            {
                if (num[i] < num[j]) // if less swap places
                {
                    temp =  num[i]; //temp
                    num[i] = num[j]; //swap
                    num[j] = temp; //swap
                }
            }
        }
 
        printf("Descending order:\n"); //print in descending order
        for (i = 0; i < 5; ++i)
            printf("%d\n", num[i]);
            
    return 0;
    
    }
