#include <stdio.h>
#include <conio.h>
#include <math.h> 

void serial_number(long number);
void reverse_number(long number);

int main(void)
{
    long number = 12345698;
    
    printf("입력 숫자 : %ld\n\n", number);
    
    printf("높은 단위부터 출력\n");
    serial_number(number);
    
    printf("\n낮은 단위부터 출력\n");
    reverse_number(number);
    
    printf("press any key to continue.......");
    getch();
    
    return 0;
}

// 높은 단위부터 출력 (재귀 호출 사용)
void serial_number(long number)
{
    if (number > 0)
    {
        // 재귀 호출을 먼저 해서 가장 높은 단위까지 간 후,
        serial_number(number / 10);
        // 복귀하면서 낮은 단위부터 차례로 출력
        printf("%ld\n", number % 10);
    }
    else
    {
        return;
    }
}

// 낮은 단위부터 출력 (재귀 호출 사용)
void reverse_number(long number)
{
    // 현재 가장 낮은 단위를 먼저 출력하고,
    printf("%ld\n", number % 10);
    
    // 다음 단위를 재귀 호출
    if ((number / 10) > 0)
    {
        reverse_number(number / 10);
    }
    else
    {
        return;
    }
}
