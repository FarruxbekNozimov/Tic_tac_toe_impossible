#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif



char kvadrat[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char kvadrat1[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int player_score = 0, bot_score = 0; 

void show_board();
int tekshiruv();
void bots_move();

int main(){
    int qayta_game = 1;
    while (qayta_game){

        int choose;
        
        while (!tekshiruv(kvadrat)){
            show_board();   
            printf("\033[0;34m"); 
            int a = 0;
            do {
                if (a > 0) {printf(" \n\n 1...9 gacha son kiriting!\n");}
                printf("\n\n >>>>> ");
                scanf(" %d", &choose);

                if (kvadrat[choose] == 'X' || kvadrat[choose] == 'O'){
                    printf(" \n\n Bu yer band !!!\n");
                    choose = 0;
                    a = -1;
                }
                a++;
            } while (choose < 1 || choose > 9);
            kvadrat[choose] = 'X';
            bots_move();
            printf("\033[0m");

        }
        show_board();
        printf("\033[0;32m");

        if (tekshiruv(kvadrat) == 2){
            bot_score++;
            player_score++;
            printf("\n\n ****************************************\n");
            printf(" *              TIE !!!                 *\n");
            printf(" ****************************************\n");
        }else if (tekshiruv(kvadrat) == -1){    
            bot_score += 3;
            printf("\n\n ****************************************\n");
            printf(" *         Computer WIN !!!             *\n");
            printf(" ****************************************\n");
        }else{
            player_score += 3;
            printf("\n\n ****************************************\n");
            printf(" *           Human WIN !!!              *\n");
            printf(" ****************************************\n");
        }
        printf("\033[0m");
        Sleep(1000);
        printf("\033[0;34m");
        printf(" \n\n Yana o'ynashni xoxlaysizmi [1/0] >>> ");
        scanf(" %d", &qayta_game);
        strcpy(kvadrat,kvadrat1);
    }
    printf(" Good Byeee !!!");
    Sleep(2000);

}


void show_board(){
    system(CLEAR);
    printf("\033[0;32m");
    printf("\n ****************************************\n");
    printf(" *   Human (X) | %d : %d | Computer (O)   *\n", player_score, bot_score);
    printf(" ****************************************\n");
    printf("\033[0m");

    printf(" \t    _________________\n");
    printf(" \t   |     |     |     |\n");
    printf(" \t   |  %c  |  %c  |  %c  |\n", kvadrat[7], kvadrat[8], kvadrat[9]);
    printf(" \t   |_____|_____|_____|\n");
    printf(" \t   |     |     |     |\n");
    printf(" \t   |  %c  |  %c  |  %c  |\n", kvadrat[4], kvadrat[5], kvadrat[6]);
    printf(" \t   |_____|_____|_____|\n");
    printf(" \t   |     |     |     |\n");
    printf(" \t   |  %c  |  %c  |  %c  |\n", kvadrat[1], kvadrat[2], kvadrat[3]);
    printf(" \t   |_____|_____|_____|\n");

}


void bots_move() {
    if (kvadrat[5] == '5' && ((kvadrat[1] == kvadrat[9] && kvadrat[1] == 'O') || kvadrat[3] == kvadrat[7] && kvadrat[3] == 'O' || kvadrat[6] == kvadrat[4] && kvadrat[6] == 'O' || kvadrat[2] == kvadrat[8])){
        kvadrat[5] = 'O';
    }else if (kvadrat[1] == '1' && ((kvadrat[2] == kvadrat[3] && kvadrat[2] == 'O') || (kvadrat[7] == kvadrat[4] && kvadrat[7] == 'O') || (kvadrat[9] == kvadrat[5] && kvadrat[9] == 'O'))){
        kvadrat[1] = 'O';
    }else if (kvadrat[2] == '2' && ((kvadrat[1] == kvadrat[3] && kvadrat[1] == 'O') || (kvadrat[8] == kvadrat[5] && kvadrat[8] == 'O'))){
        kvadrat[2] = 'O';
    }else if (kvadrat[3] == '3' && ((kvadrat[1] == kvadrat[2] && kvadrat[1] == 'O') || (kvadrat[9] == kvadrat[6] && kvadrat[9] == 'O') || (kvadrat[7] == kvadrat[5] && kvadrat[7] == 'O'))){
        kvadrat[3] = 'O';
    }else if (kvadrat[4] == '4' && ((kvadrat[1] == kvadrat[7] && kvadrat[1] == 'O') || (kvadrat[5] == kvadrat[6] && kvadrat[5] == 'O'))){
        kvadrat[4] = 'O';
    }else if (kvadrat[6] == '6' && ((kvadrat[3] == kvadrat[9] && kvadrat[3] == 'O') || (kvadrat[5] == kvadrat[4] && kvadrat[5] == 'O'))){
        kvadrat[6] = 'O';
    }else if (kvadrat[7] == '7' && ((kvadrat[1] == kvadrat[4] && kvadrat[1] == 'O') || (kvadrat[3] == kvadrat[5] && kvadrat[3] == 'O') || (kvadrat[8] == kvadrat[9] && kvadrat[8] == 'O'))){
        kvadrat[7] = 'O';
    }else if (kvadrat[8] == '8' && ((kvadrat[2] == kvadrat[5] && kvadrat[2] == 'O') || (kvadrat[7] == kvadrat[9] && kvadrat[7] == 'O'))){
        kvadrat[8] = 'O';
    }else if (kvadrat[9] == '9' && ((kvadrat[3] == kvadrat[6] && kvadrat[3] == 'O') || (kvadrat[1] == kvadrat[5] && kvadrat[1] == 'O') || (kvadrat[7] == kvadrat[8] && kvadrat[7] == 'O'))){
        kvadrat[9] = 'O';
    }
    
    else if (kvadrat[5] == '5' && ((kvadrat[1] == kvadrat[9] && kvadrat[1] == 'X') || kvadrat[3] == kvadrat[7] && kvadrat[3] == 'X' || kvadrat[6] == kvadrat[4] && kvadrat[6] == 'X' || kvadrat[2] == kvadrat[8])){
        kvadrat[5] = 'O';
    }else if (kvadrat[1] == '1' && ((kvadrat[2] == kvadrat[3] && kvadrat[2] == 'X') || (kvadrat[7] == kvadrat[4] && kvadrat[7] == 'X') || (kvadrat[9] == kvadrat[5] && kvadrat[9] == 'X'))){
        kvadrat[1] = 'O';
    }else if (kvadrat[2] == '2' && ((kvadrat[1] == kvadrat[3] && kvadrat[1] == 'X') || (kvadrat[8] == kvadrat[5] && kvadrat[8] == 'X'))){
        kvadrat[2] = 'O';
    }else if (kvadrat[3] == '3' && ((kvadrat[1] == kvadrat[2] && kvadrat[1] == 'X') || (kvadrat[9] == kvadrat[6] && kvadrat[9] == 'X') || (kvadrat[7] == kvadrat[5] && kvadrat[7] == 'X'))){
        kvadrat[3] = 'O';
    }else if (kvadrat[4] == '4' && ((kvadrat[1] == kvadrat[7] && kvadrat[1] == 'X') || (kvadrat[5] == kvadrat[6] && kvadrat[5] == 'X'))){
        kvadrat[4] = 'O';
    }else if (kvadrat[6] == '6' && ((kvadrat[3] == kvadrat[9] && kvadrat[3] == 'X') || (kvadrat[5] == kvadrat[4] && kvadrat[5] == 'X'))){
        kvadrat[6] = 'O';
    }else if (kvadrat[7] == '7' && ((kvadrat[1] == kvadrat[4] && kvadrat[1] == 'X') || (kvadrat[3] == kvadrat[5] && kvadrat[3] == 'X') || (kvadrat[8] == kvadrat[9] && kvadrat[8] == 'X'))){
        kvadrat[7] = 'O';
    }else if (kvadrat[8] == '8' && ((kvadrat[2] == kvadrat[5] && kvadrat[2] == 'X') || (kvadrat[7] == kvadrat[9] && kvadrat[7] == 'X'))){
        kvadrat[8] = 'O';
    }else if (kvadrat[9] == '9' && ((kvadrat[3] == kvadrat[6] && kvadrat[3] == 'X') || (kvadrat[1] == kvadrat[5] && kvadrat[1] == 'X') || (kvadrat[7] == kvadrat[8] && kvadrat[7] == 'X'))){
        kvadrat[9] = 'O';
    }

    else if (kvadrat[1] == '1' && kvadrat[2] == 'X' && kvadrat[7] == 'X' && kvadrat[8] == 'O'){
        kvadrat[1] = 'O';
    }else if (kvadrat[1] == '1' && kvadrat[2] == 'X' && kvadrat[9] == 'X' && kvadrat[8] == 'O'){
        kvadrat[1] = 'O';
    }else if (kvadrat[4] == '4' && kvadrat[7] == 'X' && kvadrat[2] == 'X' && kvadrat[5] == 'O'){
        kvadrat[4] = 'O';
    }else if (kvadrat[4] == '4' && kvadrat[9] == 'X' && kvadrat[2] == 'X' && kvadrat[5] == 'O'){
        kvadrat[4] = 'O';
    }else if (kvadrat[4] == '4' && kvadrat[6] == 'X' && kvadrat[8] == 'X' && kvadrat[9] == 'O'){
        kvadrat[4] = 'O';
    }else if (kvadrat[1] == '1' && kvadrat[8] == 'X' && kvadrat[6] == 'X' && kvadrat[7] == 'O'){
        kvadrat[1] = 'O';
    }else if (kvadrat[4] == '4' && kvadrat[9] == 'X' && kvadrat[7] == 'X' && kvadrat[8] == 'O' && kvadrat[5] == 'O'){
        kvadrat[4] = 'O';
    }else if (kvadrat[1] == '1' && kvadrat[2] == 'X' && kvadrat[4] == 'X' && kvadrat[8] == 'O'){
        kvadrat[1] = 'O';
    }else if (kvadrat[1] == '1' && kvadrat[2] == 'X' && kvadrat[6] == 'X' && kvadrat[8] == 'O'){
        kvadrat[1] = 'O';
    }else if (kvadrat[9] == '9' && kvadrat[4] == 'X' && kvadrat[2] == 'X' && kvadrat[7] == 'O'){
        kvadrat[9] = 'O';
    }else if (kvadrat[7] == '7' && kvadrat[6] == 'X' && kvadrat[2] == 'X' && kvadrat[9] == 'O'){
        kvadrat[7] = 'O';
    }else if (kvadrat[5] == '5' && (kvadrat[1] == 'X' || kvadrat[3] == 'X' || kvadrat[9] == 'X' || kvadrat[7] == 'X')){
        kvadrat[5] = 'O';    
    }else if (kvadrat[7] == '7' && (kvadrat[5] == 'X' || kvadrat[4] == 'X' || kvadrat[8] == 'X')){
        kvadrat[7] = 'O';
    }else if (kvadrat[9] == '9' && (kvadrat[6] == 'X')){
        kvadrat[9] = 'O';
    }else if (kvadrat[8] == '8' && (kvadrat[2] == 'X')){
        kvadrat[8] = 'O';
    }else if (kvadrat[8] == '8' && kvadrat[7] == 'X' && kvadrat[3] == 'X' && kvadrat[5] == 'O'){
        kvadrat[8] = 'O';
    }else if (kvadrat[8] == '8' && kvadrat[1] == 'X' && kvadrat[9] == 'X' && kvadrat[5] == 'O'){
        kvadrat[8] = 'O';
    }else if (kvadrat[5] == '5' && kvadrat[4] == 'X' && kvadrat[8] == 'X' && kvadrat[7] == 'O'){
        kvadrat[5] = 'O';
    }else if (kvadrat[9] == '9' && kvadrat[4] == 'X' && kvadrat[8] == 'X' && kvadrat[7] == 'O' && kvadrat[3] == 'X' && kvadrat[5] == 'O'){
        kvadrat[9] = 'O';
    }else if (kvadrat[9] == '9' && kvadrat[5] == 'X' && kvadrat[3] == 'X' && kvadrat[7] == 'O'){
        kvadrat[9] = 'O';
    }else{
        if (kvadrat[1] == '1')
            kvadrat[1] = 'O';
        else if (kvadrat[2] == '2')
            kvadrat[2] = 'O';
        else if (kvadrat[3] == '3')
            kvadrat[3] = 'O';
        else if (kvadrat[4] == '4')
            kvadrat[4] = 'O';
        else if (kvadrat[5] == '5')
            kvadrat[5] = 'O';
        else if (kvadrat[6] == '6')
            kvadrat[6] = 'O';
        else if (kvadrat[7] == '7')
            kvadrat[7] = 'O';
        else if (kvadrat[8] == '8')
            kvadrat[8] = 'O';
        else if (kvadrat[9] == '9')
            kvadrat[9] = 'O';
        
    }


}

int tekshiruv(char kvadrat[]){
    if (kvadrat[1] == 'X' && kvadrat[2] == 'X' && kvadrat[3] == 'X' || 
        kvadrat[4] == 'X' && kvadrat[5] == 'X' && kvadrat[6] == 'X' || 
        kvadrat[7] == 'X' && kvadrat[8] == 'X' && kvadrat[9] == 'X' ||
        kvadrat[1] == 'X' && kvadrat[4] == 'X' && kvadrat[7] == 'X' || 
        kvadrat[2] == 'X' && kvadrat[5] == 'X' && kvadrat[8] == 'X' ||
        kvadrat[3] == 'X' && kvadrat[6] == 'X' && kvadrat[9] == 'X' ||
        kvadrat[1] == 'X' && kvadrat[5] == 'X' && kvadrat[9] == 'X' ||
        kvadrat[3] == 'X' && kvadrat[5] == 'X' && kvadrat[7] == 'X')
        return 1;
    else if (kvadrat[1] == 'O' && kvadrat[2] == 'O' && kvadrat[3] == 'O' || 
             kvadrat[4] == 'O' && kvadrat[5] == 'O' && kvadrat[6] == 'O' ||
             kvadrat[7] == 'O' && kvadrat[8] == 'O' && kvadrat[9] == 'O' ||
             kvadrat[1] == 'O' && kvadrat[4] == 'O' && kvadrat[7] == 'O' ||
             kvadrat[2] == 'O' && kvadrat[5] == 'O' && kvadrat[8] == 'O' ||
             kvadrat[3] == 'O' && kvadrat[6] == 'O' && kvadrat[9] == 'O' ||
             kvadrat[1] == 'O' && kvadrat[5] == 'O' && kvadrat[9] == 'O' ||
             kvadrat[3] == 'O' && kvadrat[5] == 'O' && kvadrat[7] == 'O')
        return -1;
    else if (kvadrat[1] != '1' && kvadrat[2] != '2' && kvadrat[3] != '3' && kvadrat[4] != '4' && kvadrat[5] != '5' && kvadrat[6] != '6' && kvadrat[7] != '7' && kvadrat[8] != '8' && kvadrat[9] != '9')
        return 2;
    else
        return 0;
    
}
