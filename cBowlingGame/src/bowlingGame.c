#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 운영체제 확인을 위한 매크로 추가
#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

typedef struct{
    short firstShot;
    short secondShot;
    short frameScore;
    unsigned short spare;
    unsigned short stike;
} Frame;

static char board[7][64] = {
    "|================= BOWLING GAME  SCORE BOARD =================|",
    "|  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  10   |",
    "|-------------------------------------------------------------|",
    "|     |     |     |     |     |     |     |     |     |       |",
    "|-------------------------------------------------------------|",
    "|     |     |     |     |     |     |     |     |     |       |",
    "|-------------------------------------------------------------|"
};

void printBoard();
void setFrameScore(Frame *frames, int frame);

int main(void)
{
    Frame frames[10];
    int bonusShot;
    int score = 0;
    srand(time(NULL));

    //정규 프레임 점수 생성
    for(int i = 0; i < 10;i++)
    {
        //첫번째 투구
        frames[i].spare = 0;
        frames[i].stike = 0;
        frames[i].firstShot = rand() % 11;//2 + 9;
        //첫번째 투구 점수 출력
        board[3][i * 6 + 2] = frames[i].firstShot == 10 ? 'X' : frames[i].firstShot == 0 ? '-' : frames[i].firstShot + 48;
        printBoard();
        //첫번째 투구 점수 합산
        if(i > 1){
            if(frames[i - 2].stike && frames[i - 1].stike){
                frames[i - 2].frameScore += frames[i].firstShot;
                frames[i - 1].frameScore += frames[i].firstShot * 2;
            }
            else if(frames[i - 1].stike || frames[i - 1].spare){
                frames[i - 1].frameScore += frames[i].firstShot;
            }
            frames[i].frameScore = frames[i - 1].frameScore + frames[i].firstShot;
        }
        else if(i > 0){
            if(frames[i - 1].stike || frames[i - 1].spare){
                frames[i - 1].frameScore += frames[i].firstShot;
            }
            frames[i].frameScore = frames[i - 1].frameScore + frames[i].firstShot;
        }
        else{
            frames[i].frameScore = frames[i].firstShot;
        }
        //두번째 투구
        if(i == 9){
            if(frames[i].firstShot == 10){
                frames[i].secondShot = rand() % 11;
            }
            else{
                frames[i].secondShot = rand() % (11 - frames[i].firstShot);
            }
        }
        else{
            if(frames[i].firstShot == 10){
                frames[i].secondShot = 0;
                frames[i].stike = 1;
            }
            else{
                frames[i].secondShot = rand() % (11 - frames[i].firstShot);
            }
            //스페어여부 처리
            if(frames[i].firstShot + frames[i].secondShot == 10 && frames[i].firstShot != 10){
                frames[i].spare = 1;
            }
        }
        //두번째 투구 점수 출력
        if(i == 9){
            if(frames[i].firstShot == 10){
                board[3][i * 6 + 4] = frames[i].secondShot == 10 ? 'X' : frames[i].secondShot == 0 ? '-' : frames[i].secondShot + 48;
            }
            else{
                board[3][i * 6 + 4] = frames[i].firstShot + frames[i].secondShot == 10 ? '/' : frames[i].secondShot == 0 ? '-' : frames[i].secondShot + 48;
            }
        }
        else{
            board[3][i * 6 + 4] = frames[i].stike ? ' ' : frames[i].spare ? '/' : frames[i].secondShot == 0 ? '-' : frames[i].secondShot + 48;
        }
        printBoard();
        //두번째 투구 점수 합산
        if(i > 0){
            if(frames[i - 1].stike){
                frames[i - 1].frameScore += frames[i].secondShot;
                frames[i].frameScore += frames[i].secondShot;
            }
            frames[i].frameScore += frames[i].secondShot;
        }
        else{
            frames[i].frameScore += frames[i].secondShot;
        }
        //프레임 합산 점수 출력
        setFrameScore(frames, i);
        printBoard();

        fflush(stdout);
        sleep(1);
    }
    //보너스 투구 점수 생성 및 합산
    if((frames[9].firstShot == 10 && frames[9].secondShot == 10)
        || (frames[9].firstShot + frames[9].secondShot == 10)){
        bonusShot = rand() % 11;
        frames[9].frameScore += bonusShot;
        board[3][60] = bonusShot == 10 ? 'X' : bonusShot == 0 ? '-' : bonusShot + 48;
        setFrameScore(frames, 9);
        printBoard();
    }
    else if(frames[9].firstShot == 10 && frames[9].secondShot < 10){
        bonusShot = rand() % (11 - frames[9].secondShot);
        frames[9].frameScore += bonusShot;
        board[3][60] = bonusShot + frames[9].secondShot == 10 ? '/' : bonusShot == 0 ? '-' : bonusShot + 48;
        setFrameScore(frames, 9);
        printBoard();
    }
    else{
        bonusShot = 0;
        frames[9].frameScore += bonusShot;
    }

    // for(int i = 0; i < 10; i++)
    // {
    //     printf("%d %d >> %d, strike: %d, spare: %d\n", frames[i].firstShot, frames[i].secondShot, frames[i].frameScore, frames[i].stike, frames[i].spare);
    // }
    // printf("bonusShot: %d, finalScore: %d\n", bonusShot, frames[9].frameScore);

    return 0;
}

void printBoard()
{
    system(CLEAR_SCREEN); // 콘솔화면 초기화

    for (int i = 0; i < 7; i++)
    {
        printf("%s\n", board[i]);
    }
}

void setFrameScore(Frame *frames, int frame)
{
    char buf[4];
    if(frame == 9){
        for (int i = 0; i < frame; i++)
        {
            sprintf(buf, "%3d", (frames + i)->frameScore);
            strncpy(board[5] + (i * 6 + 3), buf, 3);
        }
        sprintf(buf, "%3d", (frames + 9)->frameScore);
        strncpy(board[5] + 59, buf, 3);
    }
    else{
        for (int i = 0; i < frame + 1; i++)
        {
            sprintf(buf, "%3d", (frames + i)->frameScore);
            strncpy(board[5] + (i * 6 + 3), buf, 3);
        }
    }
    
}