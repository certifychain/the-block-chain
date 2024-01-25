#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define print printf
#define scan scanf
#define fun void
#define elif else if
#define br break
#define size sizeof
#define let auto
#define name typedef
#define appuse true


fun clear_screen(){
    printf("\033[H\033[J");
    system("cls");
}

fun loop(){
    printf(" help menu \n");
    printf(" a - add block locally \n");
    printf(" l - list local blocks \n");
    printf(" f - add a peer \n");
    printf(" p - list peers \n");
    printf(" h - help \n");
    printf(" c - clear screen \n");
    printf(" q - quit \n\n");

}

int main(){
    clear_screen();
    print("type 'h' to list commands.\n");
    while(appuse){
        char x;
        scanf("%c", &x);
        if(x=='q'){
            return 0;
        }
        else if(x=='c'){
            clear_screen();
        }
        else if (x=='h'){
            loop();
        }
        // else if(x==3){
        //     peek();
        // }
        // else if(x==2){
        //     pop();
        // }
        // else if(x==1){
        //     int y;
        //     printf("enter the number: ");
        //     scanf("%d",&y);
        //     push(y);
        // }
        else{
            printf("command not found. type 'h' to list commands.");
        }
    }
    return 0;
}