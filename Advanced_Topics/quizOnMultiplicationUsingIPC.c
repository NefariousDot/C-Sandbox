#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#include <process.h>
#else
#include <unistd.h>
#include <pthread.h>
#endif

int score = 0, count = 1;
volatile sig_atomic_t timeout = 0;  // Timer flag

void finalScore() {
    printf("\n==================================================================\n");
    printf("                    .....GAME OVER.....                          \n\n");
    printf("TOTAL ROUNDS PLAYED : %d                  FINAL SCORE : %d \n", count - 1, score);
    printf("==================================================================\n\n");
    exit(0);
}

#ifdef _WIN32
void timerThread(void *arg) {
    Sleep(5000);  // Sleep for 5 seconds
    timeout = 1;
    _endthread();
}
#else
void timerHandler(int sig) {
    timeout = 1;
}
#endif

void startTimer() {
    timeout = 0;
#ifdef _WIN32
    _beginthread(timerThread, 0, NULL);
#else
    alarm(5);  // Set a 5-second alarm
#endif
}

void stopTimer() {
#ifdef _WIN32
    // No explicit timer stop needed for thread-based timer
#else
    alarm(0);  // Cancel any active alarm
#endif
}

void answerQuiz(int a, int b) {
    char answer[8];
    printf("What is %d multiplied by %d? ", a, b);
    fflush(stdout);

    startTimer();

    if (fgets(answer, sizeof(answer), stdin) == NULL || timeout) {
        printf("\nTime's Up!!\n");
        finalScore();
    }

    stopTimer();

    int result = atoi(answer);
    if (result == a * b) {
        printf("PASS. Next Question\n");
        score++;
    } else {
        printf("WRONG! Score: %d\n", score);
    }
    count++;
}

void easyLevel() {
    int a = (rand() % 8) + 2;
    int b = (rand() % 8) + 2;
    answerQuiz(a, b);
}

void mediumLevel() {
    int a = (rand() % 89) + 11;
    int b = (rand() % 89) + 11;
    answerQuiz(a, b);
}

void hardLevel() {
    int a = (rand() % 899) + 101;
    int b = (rand() % 899) + 101;
    answerQuiz(a, b);
}

#ifdef _WIN32
BOOL CtrlHandler(DWORD fdwCtrlType) {
    if (fdwCtrlType == CTRL_C_EVENT) {
        finalScore();
        return TRUE;
    }
    return FALSE;
}
#else
void terminationHandler(int sig) {
    finalScore();
}
#endif

int main() {
    srand(time(NULL));
    int option = 0;

#ifdef _WIN32
    SetConsoleCtrlHandler(CtrlHandler, TRUE);
#else
    signal(SIGINT, terminationHandler);
    signal(SIGALRM, timerHandler);
#endif

    printf("==================================================================\n");
    printf("                         LET'S BEGIN                              \n");
    printf("==================================================================\n\n");
    printf("Please Choose Difficulty...........\n");
    printf("    1 --> EASY\n");
    printf("    2 --> MEDIUM\n");
    printf("    3 --> HARD\n\n");

    while (1) {
        printf("Enter your choice: ");
        if (scanf("%d", &option) != 1 || option < 1 || option > 3) {
            printf("Invalid option. Please choose 1, 2, or 3.\n");
            while (getchar() != '\n');  // Clear invalid input
            continue;
        }

        while (1) {
            fflush(stdin);
            switch (option) {
                case 1: easyLevel(); break;
                case 2: mediumLevel(); break;
                case 3: hardLevel(); break;
            }
        }
    }

    return 0;
}
