#include <stdio.h> // 표준 입출력 헤더 파일

// 5x4 형태의 디지털 숫자 패턴 (1은 채우기, 0은 공백)
int zero[20] =
{
    1, 1, 1, 1,
    1, 0, 0, 1,
    1, 0, 0, 1,
    1, 0, 0, 1,
    1, 1, 1, 1
};

int one[20] =
{
    0, 0, 1, 0,
    0, 0, 1, 0,
    0, 0, 1, 0,
    0, 0, 1, 0,
    0, 0, 1, 0
};

int two[20] =
{
    1, 1, 1, 1,
    0, 0, 0, 1,
    1, 1, 1, 1,
    1, 0, 0, 0,
    1, 1, 1, 1
};

int three[20] =
{
    1, 1, 1, 1,
    0, 0, 0, 1,
    1, 1, 1, 1,
    0, 0, 0, 1,
    1, 1, 1, 1
};

int four[20] =
{
    1, 0, 0, 1,
    1, 0, 0, 1,
    1, 1, 1, 1,
    0, 0, 0, 1,
    0, 0, 0, 1
};

int five[20] =
{
    1, 1, 1, 1,
    1, 0, 0, 0,
    1, 1, 1, 1,
    0, 0, 0, 1,
    1, 1, 1, 1
};

int six[20] =
{
    1, 0, 0, 0,
    1, 0, 0, 0,
    1, 1, 1, 1,
    1, 0, 0, 1,
    1, 1, 1, 1
};

int seven[20] =
{
    1, 1, 1, 1,
    0, 0, 0, 1,
    0, 0, 0, 1,
    0, 0, 0, 1,
    0, 0, 0, 1
};

int eight[20] =
{
    1, 1, 1, 1,
    1, 0, 0, 1,
    1, 1, 1, 1,
    1, 0, 0, 1,
    1, 1, 1, 1
};

int nine[20] =
{
    1, 1, 1, 1,
    1, 0, 0, 1,
    1, 1, 1, 1,
    0, 0, 0, 1,
    0, 0, 0, 1
};

// 함수 프로토타입
void number_check(int k, int i);
void digit_print(int dim[], int line);

int main(void)
{
    int num, line;
    
    printf("디지털 숫자 출력 프로그램\n");
    printf("1 이상의 정수만 입력합니다. \n\n");
    printf("\n정수 숫자입력 후 Enter> ");
    scanf("%d", &num);
    printf("\n\n");

    // 0행부터 4행까지 5줄을 반복하며 출력
    for (line = 0; line <= 4; line++)
    {
        number_check(num, line);
        printf("\n"); // 한 행 출력 후 줄 바꿈
    }
    
    return 0;
}

// 개별 디지털 숫자 블록을 한 행씩 출력하는 함수
void digit_print(int dim[], int line)
{
    int i;
    // 해당 행의 4개 블록(열) 출력
    for (i = line * 4; i <= line * 4 + 3; i++)
    {
        if (dim[i] == 1)
            printf("■"); // 채우는 블록
        else
            printf(" ");  // 공백 블록
    }
    printf(" "); // 숫자 사이 간격
}

// 입력받은 숫자를 높은 자릿수부터 재귀적으로 확인하고 출력하는 함수
void number_check(int k, int i)
{
    if (k >= 1)
    {
        // 재귀 호출로 가장 높은 자릿수까지 이동
        number_check(k / 10, i);
        
        // 낮은 자릿수부터 차례로 출력 (재귀 호출의 복귀 순서 이용)
        switch (k % 10)
        {
            case 0 : digit_print(zero, i); break;
            case 1 : digit_print(one, i); break;
            case 2 : digit_print(two, i); break;
            case 3 : digit_print(three, i); break;
            case 4 : digit_print(four, i); break;
            case 5 : digit_print(five, i); break;
            case 6 : digit_print(six, i); break;
            case 7 : digit_print(seven, i); break;
            case 8 : digit_print(eight, i); break;
            case 9 : digit_print(nine, i); break;
        }
    }
}
