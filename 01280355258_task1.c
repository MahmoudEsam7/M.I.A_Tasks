/*
 *      Author:Mahmoud Esam Ali
 *      Description :print string "GRU" with stars
 *      Date : 2023-Aug-11
 */
#include <stdio.h>
#include <stdlib.h>
/*************************************Functions prototype Start*************************************/
void print_GRU(void);
/**************************************Functions prototype End**************************************/


/**************************************Global Decleration Start***************************************/
__uint8_t r_counter , c_counter ;
/***************************************Global Decleration End****************************************/

int main (void)
{
    puts("GRU");  //print the string "GRU" in the console
    print_GRU();

    return 0 ;
}

/*********************************Functions Definition Start*******************************************/
void print_GRU(void)
{
   for ( r_counter =0; r_counter<5; r_counter++)
   {
        switch (r_counter)
        {
        case 0:
            for ( c_counter =0; c_counter<25; c_counter++)
            {
                if (c_counter>=0 && c_counter<5 ||c_counter >=9 && c_counter<13 || c_counter ==19 ||c_counter==24)    
                {
                    printf("*");
                }else
                {
                    printf(" ");
                }
            }
            printf("\n");
            break;
        
        case 1:
            for ( c_counter =0; c_counter<25; c_counter++)
            {   
                if(c_counter ==0 ||c_counter ==9 ||c_counter ==13 ||c_counter ==19 ||c_counter ==24) 
                {
                    printf("*");
                }else 
                {
                    printf(" ");
                }
            }
            printf("\n");
            break;
        case 2:
            for ( c_counter =0; c_counter<25; c_counter++)
            {   
                if(c_counter ==0 ||c_counter ==3 ||c_counter ==4 ||c_counter>=9 &&c_counter<13 || c_counter ==19 ||c_counter ==24) 
                {
                    printf("*");
                }else 
                {
                    printf(" ");
                }
            }
            printf("\n");
            break;
        case 3:
            for ( c_counter =0; c_counter<25; c_counter++)
            {   
                if(c_counter ==0 ||c_counter ==4 ||c_counter ==9 ||c_counter ==13 ||c_counter ==19 ||c_counter ==24) 
                {
                    printf("*");
                }else 
                {
                    printf(" ");
                }
            }
            printf("\n");
            break;
        default:
            for (int c_counter =0; c_counter<25; c_counter++)
            {
                 
                if(c_counter >=0 && c_counter <5||c_counter ==9 ||c_counter ==14 ||c_counter >=19 && c_counter<25) 
                {
                    printf("*");
                }else 
                {
                    printf(" ");
                }
            }
            
            printf("\n");
        }
          
        
    }
}
/**********************************Functions Definition End********************************************/
