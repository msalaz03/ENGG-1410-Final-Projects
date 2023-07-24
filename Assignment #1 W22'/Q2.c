/*
Author: Matthew Salazar
Date 01/16/23
Assignment: #1

The purpose of this program is to take two numbers from user and as well as a math operator and do following correct calculation
*/

#include <stdio.h>

int main()
{
  int a,b, sum; //first number, second number, sum
  char ch; //operator 
  
  printf("Please enter #1: "); //scanUser #1
  scanf("%d", &a);  
  
  printf("Please enter #2: "); //scanUser #2
  scanf("%d", &b);
  
  printf("Enter operator: "); //scanUser Operator 
  scanf(" %c", &ch);
  
  //do the correct math depending on operator.

 //This also could've been done using a switch statement 
  
  if (ch == '-')
  {   
      sum = a - b;
      printf("a - b = %d", sum);
  }
  
  else if (ch == '+')
  {
      sum = a + b;
      printf("a + b = %d", sum);
  }
  
   else if (ch == '*')
   {
      sum = a * b;
      printf("a * b = %d", sum);
  }
    //not an option
  else
  {
      printf("Error please enter either * - +");
  }    

    return 0;
}
