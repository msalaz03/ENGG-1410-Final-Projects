
/*
Author: Matthew Salazar
Date 01/16/23
Assignment: #1

The purpose of this program is to take the user’s input of a four digit number and output a number that is reverse to what was inputted.
*/


#include <stdio.h>

int main()
{
  int x; //variable for userInput
  int reverse; //number in reverse
  int r; //placeholder for digit column
 
    printf("Please enter a four digit number: "); //ask for user input
    scanf("%d", &x); //scan users number
    
    
    if (x >= 1000 && x <= 9999) //check if four digits
    { 	        
        reverse = 0;
        
        while (x > 0)
        { 
            r = x % 10; // find first digit
            reverse = reverse * 10 + r; //add into number then shift over a decimal
            x = x / 10; // divide ten to iterate through the next digit.
        }
        
        printf("The reverse is:  %d", reverse);
    }
    
    else
    printf("\nPlease enter four digit number"); //non four digit case
    

    return 0;
}