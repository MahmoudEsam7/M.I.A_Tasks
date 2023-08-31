/*
 *      Author:Mahmoud Esam Ali
 *      Description :Takes the number to start the countdown from that input
 *      Date : 2023-Aug-11
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  /* sleep function is provided by unistd.h library in Linux*/


/**************************************Global Decleration Start***************************************/
unsigned int starting_Number=0 ;
/***************************************Global Decleration End****************************************/

int main (void)
{
    printf("Enter The Starting Number :");
    scanf(" %i",&starting_Number);
    while (starting_Number>0)  
    {
        printf("%i\n",starting_Number);
        starting_Number--;
        sleep(1);  //delay 1 sec
    }
    printf("Blast off to the moon!");
    
    return 0;
}