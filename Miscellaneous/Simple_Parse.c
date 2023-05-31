#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int simpleParse(const char *exp);



int main() {
    char exp1[] = "1 + 1";
    char exp2[] = "3 + 7 - 4 * 1";
    char exp3[] = "9 * 13 / 2 + 18 * 110 - 812 % 97 + 3";
    
    printf("%s = %d\n", exp1, simpleParse(exp1));
    printf("%s = %d\n", exp2, simpleParse(exp2));
    printf("%s = %d\n", exp3, simpleParse(exp3));

}



int simpleParse(const char *exp)
{
    //seperate the str with "+" and "-"
    const char m[3] = "+-";
    //initializng an empty list to receive copied info
    char dup[strlen(exp)+1]; 

    //copying contents of exp into dup
    strcpy(dup, exp);
    char *token = strtok(dup,m);

    //initializing numbers to perform operations on
    int num1;
    int num2;

    //token loops
    int loops = 0;

    //total of operation
    int total;


    //we are gonna find a token of a token to separate the #s from the operations "*%/"
    while (token != NULL)
    {
        //printf("TOKEN1 in loop: %s\n",token);
        char arr[strlen(token)+1];
        strcpy(arr,token); 

        //counting number of numbers
        int countops = 0;
        //int flag = 0;
        for (int i=0 ; i<strlen(token) ; i++) {
            /*
            if (isdigit(*(token+i))  && !flag) {
                //there is a num
                //flag = 1;
                printf("TOKEN DIGIT: %c \n",*(token+i));
            }
            */
            //detects spaces => stops counting and you have reached end of #
            //*(token+i+1) checking character ahead of it b/c never gonna reach it
            if ((*(token+i) == '*') || (*(token+i) == '/') || (*(token+i) == '%')) {
                //flag = 0;
                countops++;
                //printf("TOKEN count: %d \n",countnum);
            }
        }
        //printf("countops: %d\n", countops);
        char *trash = malloc(sizeof(char)*strlen(token));

        //getting first number and turns it into an integer
        //from token the rest gets sent to trash
        //looks for first legal # and anything after that is sent to &trash adn kept as string
        num1 = strtol(token, &trash, 10);
        char op;

        if (countops > 0) {

            while (strlen(trash)>0) {

                for (int j=0 ; j<strlen(trash) ; j++) {
                    //getting addy for first arguement
                    //calculates new strlen of trash
                    if ((*(trash+j)=='*') || (*(trash+j)=='/') || (*(trash+j)=='%')) {
                        op = *(trash+j);
                        num2 = strtol((trash+j+1),&trash,10);
                
                    if (op == '*') {
                        num1 = num1*num2;
                    }

                    else if (op == '/') {
                        if (num2 == 0) {
                            total = -1;
                            return total;
                        }
                        else {
                            num1 = num1/num2;
                        }
                    }

                    else if (op == '%') {
                        num1 = num1%num2;
                    }

                    countops--;

                    if (countops == 0) {
                        strcpy(trash,"");
                    }
                    
                    break;

                    }

                }   

            }
        }
        //count how many +/- operations there are
        int outops = 0;

        if (loops > 0) {
            for (int i=0 ; i<strlen(exp) ; i++) {
                //counts the number of outside operations (+/-)
                if ((exp[i] == '+') || (exp[i] == '-')) {
                    outops++;
                }
                //if it's not an op we have done before, then it will compute the sum/diff
                if (outops == loops) {
                    if (exp[i] == '+') {
                        total = total + num1;
                    }

                    else if (exp[i] == '-') {
                        total = total - num1;
                    }
                    //if it has found an operation then stop the loop
                    break;

                }
    
            }

        }
        
        else {
            total = num1;
        }
        //printf("TOTAL: %d\n", total);


        //gets the next token
        token = strtok(NULL, m);
        loops++;
        //printf("NUM1: %d\n", num1);
    }

    return total;

}


