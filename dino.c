#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#endif

// Function to move cursor
void moveTo(int x, int y) {
#ifdef _WIN32
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#else
    printf("\033[%d;%dH", y + 1, x + 1);
    fflush(stdout);
#endif
}

// Pause function
void pause(unsigned int milliseconds) {
    clock_t goal = milliseconds + clock();
    while (goal > clock());
}

// Game info
void displayGameInfo() {
    system("cls");
    moveTo(10, 2);
    printf("Press X to Exit, Press Space to Jump");
    moveTo(62, 2);
    printf("SCORE : ");
    moveTo(1, 25);
    for (int x = 0; x < 79; x++)
        printf("п");
}

// Global vars
int jumpHeight, gameSpeed = 40;

// Character animation
void displayCharacter(int jumpType) {
    static int animationState = 1;

    if (jumpType == 0)
        jumpHeight = 0;
    else if (jumpType == 2)
        jumpHeight--;
    else
        jumpHeight++;

    moveTo(2, 15 - jumpHeight); printf("                ");
    moveTo(2, 16 - jumpHeight); printf("     мллл      ");
    moveTo(2, 17 - jumpHeight); printf("    ллллллл     ");
    moveTo(2, 18 - jumpHeight); printf("   ллллллллл    ");
    moveTo(2, 19 - jumpHeight); printf("  лллллплллл   ");
    moveTo(2, 20 - jumpHeight); printf(" млллллппллллм  ");
    moveTo(2, 21 - jumpHeight); printf(" ллллллпплллллл ");
    moveTo(2, 22 - jumpHeight); printf(" пллллллппллллп ");
    moveTo(2, 23 - jumpHeight);

    if (jumpType == 1 || jumpType == 2) {
        printf("   ллп плпппл   ");
        moveTo(2, 24 - jumpHeight); printf("   лм   лм      ");
    } else if (animationState == 1) {
        printf("  пллп  ппп     ");
        moveTo(2, 24 - jumpHeight); printf("     лм         ");
        animationState = 2;
    } else {
        printf("   плм пл       ");
        moveTo(2, 24 - jumpHeight); printf("         лм     ");
        animationState = 1;
    }

    moveTo(2, 25 - jumpHeight);
    if (jumpType != 0)
        printf("                ");
    else
        printf("ппппппппппппппппп");

    pause(gameSpeed);
}

// Obstacle
void displayObstacle() {
    static int obstaclePosition = 0;
    static int score = 0;

    if (obstaclePosition == 56 && jumpHeight < 4) {
        score = 0;
        gameSpeed = 40;
        moveTo(36, 8); printf("Game Over");
        getch();
        moveTo(36, 8); printf("         ");
    }

    moveTo(74 - obstaclePosition, 20);
    printf("л    л ");

    moveTo(62, 2);
    printf("SCORE : %d", score);

    obstaclePosition++;
    if (obstaclePosition == 73) {
        obstaclePosition = 0;
        score++;
        if (gameSpeed > 10)
            gameSpeed -= 2;
    }
}

#ifndef _WIN32
int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;
    tcgetattr(0, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &newt);
    oldf = fcntl(0, F_GETFL, 0);
    fcntl(0, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(0, TCSANOW, &oldt);
    fcntl(0, F_SETFL, oldf);
    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}
int getch(void) {
    struct termios oldt, newt;
    int ch;
    tcgetattr(0, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(0, TCSANOW, &oldt);
    return ch;
}
#endif

// Main
int main() {
#ifdef _WIN32
    system("mode con: lines=29 cols=82");
#endif
    char input;
    int i;
    displayGameInfo();

    while (1) {
        while (!kbhit()) {
            displayCharacter(0);
            displayObstacle();
        }

        input = getch();
        if (input == ' ') {
            for (i = 0; i < 10; i++) {
                displayCharacter(1);
                displayObstacle();
            }
            for (i = 0; i < 10; i++) {
                displayCharacter(2);
                displayObstacle();
            }
        } else if (input == 'x' || input == 'X') {
            break;
        }
    }

    return 0;
}
