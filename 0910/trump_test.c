#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
typedef struct trump {
    int order;      // 0:♠, 1:◆, 2:♥, 3:♣ (우선순위/분류용)
    char shape[3];  // 완성형 2바이트 + '\0' (환경에 따라 [4]로 늘려도 됨)
    int number;     // 1~13 (1:A, 11:J, 12:Q, 13:K)
} trump;

// 만약 콘솔에서 기호가 깨지면 아래를 {"S","D","H","C"} 로 바꾸세요.
static const char SUITS[4][3] = {"♠","◆","♥","♣"};

// ---------- 유틸 ----------
static void swap_card(trump* a, trump* b) {
    trump t = *a; *a = *b; *b = t;
}

// 출력용 랭크 문자열 생성 (A, 2~10, J, Q, K)
static const char* rank_str(int n, char buf[4]) {
    switch (n) {
        case 1:  return "A";
        case 11: return "J";
        case 12: return "Q";
        case 13: return "K";
        default:
            snprintf(buf, sizeof(char)*4, "%d", n);
            return buf;
    }
}

// 게임 비교용 랭크값 (A를 최상위로 취급: 1 -> 14)
static int rank_value(int n) {
    return (n == 1) ? 14 : n;
}

// ---------- 덱 생성/출력/셔플 ----------
void make_deck(trump deck[52]) {
    // order: 0~3 (모양), number: 1~13
    // deck 인덱스: suit*13 + (rank-1)
    for (int s = 0; s < 4; ++s) {
        for (int r = 1; r <= 13; ++r) {
            int idx = s * 13 + (r - 1);
            deck[idx].order = s;
            strcpy(deck[idx].shape, SUITS[s]);
            deck[idx].number = r;
        }
    }
}

void display_deck(const trump deck[52]) {
    for (int i = 0; i < 52; ++i) {
        char buf[4];
        printf("%s%-2s ", deck[i].shape, rank_str(deck[i].number, buf));
        if ((i + 1) % 13 == 0) printf("\n");
    }
}

void shuffle_deck(trump deck[52]) {
    // Fisher–Yates
    srand((unsigned)time(NULL));
    for (int i = 51; i > 0; --i) {
        int j = rand() % (i + 1);
        swap_card(&deck[i], &deck[j]);
    }
}

// ---------- 미니게임: 하이카드(2인, 10라운드) ----------
void play_highcard(trump deck[52]) {
    // 덱 맨 앞부터 차례로 2장씩 소모
    int p1_score = 0, p2_score = 0;
    int cursor = 0;
    printf("\n=== High Card (2인, 10라운드) ===\n");
    for (int round = 1; round <= 10; ++round) {
        trump p1 = deck[cursor++];
        trump p2 = deck[cursor++];
        char b1[4], b2[4];

        int v1 = rank_value(p1.number);
        int v2 = rank_value(p2.number);

        printf("R%02d) P1: %s%-2s  vs  P2: %s%-2s  -> ",
               round,
               p1.shape, rank_str(p1.number, b1),
               p2.shape, rank_str(p2.number, b2));

        if (v1 > v2) {
            printf("P1 승리\n");
            ++p1_score;
        } else if (v2 > v1) {
            printf("P2 승리\n");
            ++p2_score;
        } else {
            // 랭크 동률 시 모양 우선순위로 결정 (♠ > ◆ > ♥ > ♣) 가정
            if (p1.order < p2.order) { // order: 0이 최고
                printf("P1 승리(모양)\n");
                ++p1_score;
            } else if (p2.order < p1.order) {
                printf("P2 승리(모양)\n");
                ++p2_score;
            } else {
                printf("무승부\n");
            }
        }
    }

    printf("\n결과: P1 %d승  -  P2 %d승 -> ", p1_score, p2_score);
    if (p1_score > p2_score)      printf("최종 승자: P1\n");
    else if (p2_score > p1_score) printf("최종 승자: P2\n");
    else                          printf("최종 결과: 무승부\n");
}

// ---------- 메인 ----------
int main(void) {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    trump deck[52];

    // 1) 덱 생성
    make_deck(deck);

    // 2) 원본 덱 출력
    printf("=== 원본 덱 ===\n");
    display_deck(deck);

    // 3) 셔플
    shuffle_deck(deck);

    // 4) 셔플된 덱 출력
    printf("\n=== 셔플된 덱 ===\n");
    display_deck(deck);

    // 5) 하이카드 미니게임 진행
    play_highcard(deck);

    return 0;
}
