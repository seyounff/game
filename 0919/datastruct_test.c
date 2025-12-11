#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
// 연결리스트 노드
typedef struct Node {
    char data;
    struct Node* link;
} Node;

Node* head = NULL;

void 리스트초기화(void) {
    head = (Node*)malloc(sizeof(Node));
    head->link = NULL;
}

void 노드추가(char data) {
    Node* last = head;
    while (last->link != NULL) last = last->link;
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->link = NULL;
    last->link = node;
}

void 리스트출력(Node* now) {
    while (now != NULL) {
        printf("%c ", now->data);
        now = now->link;
    }
    printf("\n");
}

void 리스트역출력(Node* now) {
    if (now == NULL) return;
    리스트역출력(now->link);
    printf("%c ", now->data);
}

// 스택 노드
typedef struct StackNode {
    char data;
    struct StackNode* link;
} StackNode;

StackNode* top = NULL;

void 푸시(char data) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->data = data;
    node->link = top;
    top = node;
}

char 팝(void) {
    if (top == NULL) return 0;
    StackNode* temp = top;
    char d = temp->data;
    top = top->link;
    free(temp);
    return d;
}

// 연결리스트 데모
void 연결리스트데모(void) {
    리스트초기화();
    printf("키 입력 (ESC 종료):\n");
    int ch;
    do {
        ch = getch();
        노드추가((char)ch);
    } while (ch != 27);

    printf("\n정방향: ");
    리스트출력(head->link);
    printf("역방향: ");
    리스트역출력(head->link);
    printf("\n");
}

// 스택 데모
void 스택데모(void) {
    printf("키 입력 (ESC 종료):\n");
    int ch;
    do {
        ch = getch();
        푸시((char)ch);
    } while (ch != 27);

    printf("\n팝 순서: ");
    while (top != NULL) {
        char d = 팝();
        if (d != 27) printf("%c ", d);
    }
    printf("\n");
}

int main(void) {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int 선택;
    for (;;) {
        printf("=== 자료구조 데모 ===\n");
        printf("1) 연결리스트\n");
        printf("2) 스택\n");
        printf("0) 종료\n> ");
        if (scanf("%d", &선택) != 1) { while (getchar() != '\n'); continue; }
        while (getchar() != '\n');

        if (선택 == 0) break;
        switch (선택) {
            case 1: 연결리스트데모(); break;
            case 2: 스택데모(); break;
            default: printf("잘못된 선택입니다.\n"); break;
        }
        printf("\n");
    }
    return 0;
}
