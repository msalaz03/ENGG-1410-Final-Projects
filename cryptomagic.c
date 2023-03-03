#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
void encrypt();
void decrypt();
 
int main(int arg1, char *arg2[])
{
 
    if (arg1 == 1) //default argument "file name"
    {
        printf("Please type in cryptoMagic -E to encrypt or cryptoMagic -D to decrypt the file\n");
    }
 
    if (arg1 == 2)
    {
        if (strcmp(arg2[1], "-E") == 0){ //look for '-E' when user input is prompted
            encrypt();                   // When '-E' is entered run function encrypt()
                                         // If a2[1] is equal to '-E' return value is 0
        }
        else if (strcmp(arg2[1], "-D") == 0){ //look for '-E' when user input is prompted
            decrypt();                        // When '-E' is entered run function encrypt()
                                             // If a2[1] is equal to '-D' return value is 0
        }
        else{
            encrypt();                      // Default is to encrypt
        }
    }
}
 


void encrypt()  //encrypt function
{
 char inFile[100] ;
 char varFile[100];
 char ch;
 int outChar;
 
 FILE *var1, *var2;
 
 printf("Enter the name of the file that will be encrypted: "); //manually enter the file
 scanf("%s", inFile);
 
 strcpy(varFile, inFile);    //copy file name into new variable
 varFile[strlen(inFile) - 3] = 'c';  //change characters of extension
 varFile[strlen(inFile) - 2] = 'r';
 varFile[strlen(inFile) - 1] = 'p';
 


 var1 = fopen(inFile,"r");  //open userFile
 
 if (var1 == NULL){
    printf("\nThis File Does not exist...\n");
    exit(0);
 }
 else{
    var2=fopen(varFile,"w"); //write into File
    ch=fgetc(var1);
    while(ch!=EOF){ //read into end of File
 
        outChar = (int) ch - 16; //character interger value to ascii value


        if (ch == 9){
            fprintf(var2, "TT");
        }


        else if (ch == 10){
            fprintf(var2, "%c", ch);
        }


        else if (outChar < 32){
            outChar = (outChar - 32) + 144; //ASCII input PART
        }


        if (ch != 9 && ch != 10){
        fprintf(var2,"%x", outChar);
        }
        ch = fgetc (var1);
    }
    fclose(var2);
 
 }
 fclose(var1);
 remove(inFile);
 printf("The file has been encrypted with the name: %s ", varFile);
 
}




void decrypt() // decrypt function
{
FILE *var1, *var2;


     char input[100];
     char outfile[100];


     char text1st;
     char text2nd;
     int text;


 printf("Please Enter the name of file to be decrypted: "); //manually enter the file
 scanf("%s", input);


 strcpy(outfile, input);    //store into temp
 
 outfile[strlen(input) - 3] = 't';  //change characters of extension
 outfile[strlen(input) - 2] = 'x';
 outfile[strlen(input) - 1] = 't';




     var1 = fopen(input,"r");  //open userFile
 
 if (var1 == NULL){
    printf("This File Does not exist...\n");
    exit(0);
 }


 else{
    var2=fopen(outfile,"w"); //write into File






        do{
       
        int text1FV = 0;
        int text2FV = 0;
        text1st = fgetc(var1); //get a character from file


            if(text1st == EOF){ //check if at the end of the file
            break;
            }
         
            else if(text1st == 10){ //check if it's an enter
            fprintf(var2, "%c", text1st);
            }


            else{
            text2nd = fgetc(var1); //gets the next charater
   
                if(text1st == 'T' && text2nd == 'T'){ //checks if its a tab
                fprintf(var2, "%c", 9);
                }
                 else{
                    switch(text1st){ //get the first charater's face value
                    case '0':
                        text1FV = 0;
                        break;
                    case '1':
                        text1FV = 1;
                        break;
                    case '2':
                        text1FV = 2;
                        break;
                    case '3':
                        text1FV = 3;
                        break;
                    case '4':
                        text1FV = 4;
                        break;
                    case '5':
                        text1FV = 5;
                        break;
                    case '6':
                        text1FV = 6;
                        break;
                    case '7':
                        text1FV = 7;
                        break;
                    case '8':
                        text1FV = 8;
                        break;
                    case '9':
                        text1FV = 9;
                        break;
                    case 'a':
                        text1FV = 10;
                        break;
                    case 'b':
                        text1FV = 11;
                        break;
                    case 'c':
                        text1FV = 12;
                        break;
                    case 'd':
                        text1FV = 13;
                        break;
                    case 'e':
                        text1FV = 14;
                        break;
                    case 'f':
                        text1FV = 15;
                        break;
                    default:
                        printf("\nFV1 error with: %c", text1st);
                    }


                    switch(text2nd){ //get the second charater's face value
                    case '0':
                        text2FV = 0;
                        break;
                    case '1':
                        text2FV = 1;
                        break;
                    case '2':
                        text2FV = 2;
                        break;
                    case '3':
                        text2FV = 3;
                        break;
                    case '4':
                        text2FV = 4;
                        break;
                    case '5':
                        text2FV = 5;
                        break;
                    case '6':
                        text2FV = 6;
                        break;
                    case '7':
                        text2FV = 7;
                        break;
                    case '8':
                        text2FV = 8;
                        break;
                    case '9':
                        text2FV = 9;
                        break;
                    case 'a':
                        text2FV = 10;
                        break;
                    case 'b':
                        text2FV = 11;
                        break;
                    case 'c':
                        text2FV = 12;
                        break;
                    case 'd':
                        text2FV = 13;
                        break;
                    case 'e':
                        text2FV = 14;
                        break;
                    case 'f':
                        text2FV = 15;
                        break;
                    default:
                        printf("\nFV2 error with: %c", text2nd);
                    }


                text = (((text1FV*16)+text2FV)+16); //apply decryption key


                    if(text>127){ //apply another decryption rule
                    text = (text-144)+32;
                    }


                fprintf(var2, "%c", text);} //print decrypted charater
                }
        }while(1);


 }


    fclose(var2);
    fclose(var1);
   
    remove(input);


    printf("The file has been decrypted with the name: %s ", outfile);
 
}


