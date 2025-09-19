#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <windows.h>

static const double C1_BASE = 32.7032; // 1옥타브 도
static const double RATIO = 1.0594630943592953; // 12평균율 비율

// 주어진 옥타브와 반음 인덱스로 주파수 계산
int 주파수계산(int 옥타브, int 반음) {
    double f = C1_BASE * pow(2.0, (double)(옥타브 - 1));
    for (int i = 0; i < 반음; ++i) f *= RATIO;
    return (int)(f + 0.5);
}

// 한 옥타브 주파수 출력
void 옥타브출력(int 옥타브) {
    const char* 음이름[12] = {"도", "도#", "레", "레#", "미", "파",
                             "파#", "솔", "솔#", "라", "라#", "시"};
    printf("%d옥타브: ", 옥타브);
    for (int i = 0; i < 12; ++i) {
        int f = 주파수계산(옥타브, i);
        printf("%-4d ", f);
    }
    printf("\n");
}

// 전체 주파수표 출력
void 주파수표출력(void) {
    printf("=== 음계 주파수표 (A4=440Hz) ===\n");
    for (int 옥 = 1; 옥 <= 6; ++옥) {
        옥타브출력(옥);
    }
    printf("\n");
}

// 도레미파솔라시도 연주
void 도레미연주(void) {
    int 반음[8] = {0, 2, 4, 5, 7, 9, 11, 12};
    int freq[8];
    for (int i = 0; i < 8; ++i) freq[i] = 주파수계산(4, 반음[i]);

    for (int i = 0; i < 8; ++i) { Beep(freq[i], 500); Sleep(100); }
    Sleep(300);
    for (int i = 7; i >= 0; --i) { Beep(freq[i], 500); Sleep(100); }
}

// 피아노 연습
void 피아노연습(void) {
    int 반음[8] = {0, 2, 4, 5, 7, 9, 11, 12};
    int freq[8];
    for (int i = 0; i < 8; ++i) freq[i] = 주파수계산(4, 반음[i]);

    printf("1~8 키를 눌러 도~도 연주, ESC로 종료\n");
    int ch;
    do {
        ch = getch();
        if ('1' <= ch && ch <= '8') {
            int idx = ch - '1';
            Beep(freq[idx], 300);
        }
    } while (ch != 27);
}

int main(void) {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int 선택;
    for (;;) {
        printf("=== 음계 & 피아노 ===\n");
        printf("1) 주파수표 출력\n");
        printf("2) 도레미 연주\n");
        printf("3) 피아노 연습\n");
        printf("0) 종료\n> ");
        if (scanf("%d", &선택) != 1) { while (getchar() != '\n'); continue; }
        while (getchar() != '\n');

        if (선택 == 0) break;
        switch (선택) {
            case 1: 주파수표출력(); break;
            case 2: 도레미연주(); break;
            case 3: 피아노연습(); break;
            default: printf("잘못된 선택입니다.\n"); break;
        }
        printf("\n");
    }
    return 0;
}
