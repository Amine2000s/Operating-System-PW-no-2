#include <stdio.h>
#include <stdlib.h>
#include "tpse2.h"


   // extern memo_parti* main_memory_pointer;//MAIN MEMORY POINTER TO THE MEMORY

   // extern int memory_parition_number;//NUMBER OF MEMORY PARITIONS

    //extern struct program* main_program;//MAIN POINTER OF PROGRAMS QUEUE

   // extern  program_number;//PROGRAM NUMBER




int main()
{
    //main_program=NULL;

    int user_choise,memory_paritionss;
    prgm *head , *tail ;

    printf("\t==========================================================\n");
    printf("\t\t   welcome to the Memory management \n\t\t(static paritioning) simulation program");
    printf("\n\t==========================================================\n");


    do{
        printf("\nCHOOSE AN OPERATION (-1 FOR EXIT )\n");

        printf("\n 1: ADD  PROGRAM/s IN THE QUEUE \n ");

        printf("\n 2: SHOW THE QUEUE OF PROGRAMS \n ");

        printf("\n 3: DEFINE ALLOCATION UNIT AND SIZE OF MEMORY   \n ");

        printf("\n 4: SHOW THE MEMORY  \n ");

        printf("\n 5: FIT THE PROGRRAMS FROM QUEUE INTO MEMORY PARITIONS (BEST  FIT )  \n");

        printf("\n 6: BIT MAP CREATION (LINKED LIST)  \n ");

        printf("\n 7: SHOW THE MEMORY(LINKED LIST FORMAT)  \n ");

        printf("\n 8: BIT MAP DISPLAY (MATRIX ) \n ");


        scanf("%d",&user_choise);

        switch(user_choise){
            case (1) :

                    add_program_to_queue();

                    break;
            case (2):

                   show_program();//show queue program

                    break;

            case (3):

                    allocation_unit_and_size();

                    break;

            case (4) :



                    break;

            case (5) :


                    break;
            case (6) :

                    bit_map_creation_list_type();
                    break;


            case (7):

                    show_memory_linked_list_form();
                    break;
            case (8):
                    matrix_display();
                    break;


        }

    }while(user_choise!=-1);

    return 0;
}



