#include "tpse2.h"


//////////////////////////////MEMORY/////////////////////////////////////////////////
    struct  memory_list *main_head;

    int memory_unit ;// for memory

    int memory_total_size;

    int memory_parition_number;
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////PROGRAM/////////////////////////
    struct program* main_program;

    int program_number;
/////////////////////////////////////////////////////////
////////////////MEMORY LIST (BIT MAP )//////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////QUEUE MANIPULATION ////////////////////////////////////////////////////////////////////////////////////////

/////////////////ADDING IN T THE QUEUE OF PROGRAMS /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

 void in_queue(struct program *temp){
    //good
    if(main_program==NULL){

        main_program=temp;

    }else{

        prgm *temporary;

        temporary=NULL;

        temporary=main_program;

        while(temporary->nxt!=NULL){

            temporary=temporary->nxt;
        }
        temporary->nxt=temp;

    }

   printf("\n SUCCESSFULLY ADDED !\n");


}


/////////////////////////////////////////////////////////////////
////////////////////REMOVING FROM THE QUEUE OF MEMORY ///////////

 void de_queue(){//good

    prgm *temp;
    temp= main_program;


    main_program=main_program->nxt;

    free(temp);

}




//////////////////////////////////////////////////////
////FIRST MILESTONE TO CREATE THE QUEUE OF MEMORY ////////////////


 void add_program_to_queue(){
            int program_numbers;

            printf("HOW MANY YOU PROGRAMS YOU WANT TO ADD ");
            scanf("%i",&program_numbers);

            for(int i=0;i<program_numbers;i++){
                prgm *temp;

                temp=NULL;

                temp=malloc(sizeof(struct program));

                printf("Name of program : ");

                scanf("%s",temp->program_name);

                printf("Program size : ");

                scanf("%d",&temp->program_size);

                printf("estimated time of execution :");

                scanf("%d",&temp->estimated_exec_time);

                temp->nxt=NULL;

                in_queue(temp);

                }

        }

void show_program()
    {

    if(main_program==NULL)
    {

        printf("\n NO PROGRAM ADDED PLEASE ADD PROGRAM AND TTRY AGAIN\n");

    }else
    {

        prgm *tempo;

        tempo=main_program;

    while(tempo!=NULL)
        {

        printf("\n===================================================\n");

        printf("program name is %s \n",tempo->program_name);

        printf("his size is : %i\n",tempo->program_size);

        printf("estimated process : %i",tempo->estimated_exec_time);

        printf("\n===================================================\n");

        tempo=tempo->nxt;

        }

    }

}
 //////////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////////
 ////////////////////////MEMORY PARITIONS ////////////////////////////////////////
 void allocation_unit_and_size(){
    printf("\n===============================\n");

    printf("DEFINE THE MEMORY TOTAL SIZE \n");
    scanf("%i",&memory_total_size);

    printf(" DEFINE THE ALLOCATION UNIT :\n");
    scanf("%i",&memory_unit);

    printf("\n===============================\n");

    memory_parition_number=memory_total_size / memory_unit ;

    if((memory_total_size % memory_unit) > 0){

        memory_parition_number++;
    }

    printf("THE NUMBER UNITS IN THE MEMORY IS :%i \n",memory_parition_number);


    ///////////program calulation/////////////////
    struct program *tmp;
    tmp =main_program;
    int i =0;
    while(tmp!=NULL){


        int sizee=tmp->program_size;

        sizee=sizee/memory_unit;

        if((sizee % memory_unit) > 0){
                sizee++;

        }

        printf("\n the number of units in the program number %i is %i \n",i+1,sizee) ;
        i++;
        tmp=tmp->nxt;
    }



}
////////////////////////////
///////////LINKED LIST MEMORY CREATION ///////////

void bit_map_creation_list_type(){

    struct memory_list *tmp ;
    main_head=NULL;
    int start =0;

    for(int i=0;i<memory_parition_number;i++){
            tmp=(struct memory_list*)malloc(sizeof(struct memory_list));

            tmp->starting_number=start;

            tmp->number_of_units=memory_unit;

            tmp->status='H';

            tmp->next=NULL;

            start=start+memory_unit;


            if(main_head==NULL){
                main_head=tmp;
            }else{


                struct memory_list *temporary;

                temporary=NULL;

                temporary=main_head;

                while(temporary->next!=NULL){

                    temporary=temporary->next;
                }
                    temporary->next=tmp;
            }

    }

}
////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

////MATRIX DISLAYING /////////////////////
void matrix_display(){

    struct memory_list * temporary;
    temporary=main_head;

    while(temporary!=NULL){

           for(int i=0 ; i < temporary->number_of_units ; i++){
             if(i % 8 == 0)
             printf("\n");

            if(temporary->status=='P'){
                //printf("\t");
                printf("1");
                //printf("\t");

            }
            if(temporary->status=='H')
                //printf("\t");
                printf("0");
                //printf("\t");

           }

           temporary=temporary->next;


        }

    }




/////////////////////////////////////////////////////////////////////////////


    void show_memory_linked_list_form(){
        struct memory_list *tmp;
        tmp=main_head;
        printf("\n===================================================\n");
        while(tmp!=NULL){
            printf("[ %c | %i | %i ] -->",tmp->status,tmp->starting_number,tmp->number_of_units);

            if(tmp->next==NULL)
                printf("NULL");

            tmp=tmp->next;

        };
       printf("\n===================================================\n");

    }

