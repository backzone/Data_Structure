#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 함수 선언
double calculateAverage(int scores[], int size);
int getStudentScore(int scores[], int size, int studentNumber);
void printScore(int score[], int option, double average, int size);

int main() {
    int scores[30]; // 30명의 학생 성적 저장
    int studentNumber;
    double average;
    int option;

    // 난수 생성 초기화
    srand(time(0));

    // 성적 데이터 초기화
    for (int i = 0; i < 30; i++) {
        scores[i] = rand() % 101; // 0 ~ 100 사이의 난수 생성
    }
    // 평균 계산
    average = calculateAverage(scores, 30);
    printf("학급 평균 점수: %.2f\n", average);

    // 특정 학생 점수 검색
    printf("학생 번호를 입력하세요 (1 ~ 30): ");
    scanf("%d", &studentNumber);

    int score = getStudentScore(scores, 30, studentNumber);
    if (score != -1) {
        printf("%d번 학생의 점수: %d\n", studentNumber, score);
    }
    else {
        printf("유효하지 않은 학생 번호입니다.\n");
    }
    printScore(scores, 0, average, 30);
    printScore(scores, 1, average, 30);
    printScore(scores, 2, average, 30);

    return 0;
}

// 평균 계산 함수
double calculateAverage(int scores[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return sum / (double)size;
}

// 특정 학생 점수 검색 함수
int getStudentScore(int scores[], int size, int studentNumber) {
    if (studentNumber >= 1 && studentNumber <= size) {
        return scores[studentNumber - 1];
    }
    else {
        return -1; // 유효하지 않은 학생 번호
    }
}

void printScore(int score[],int option, double average, int size) {
    switch (option) {
    case 0:
        printf("<모든 학생>\n");
        for (int i = 0; i < size; i++) {
            if (option == 0) {
                printf("%d번 점수: %d\n", i + 1, score[i]);
            }
        }
        break;
    case 1:
        printf("<평균 이상 학생>\n");
        for (int i = 0; i < size; i++) {
            if (score[i] >= average) {
                printf("%d번 점수: %d\n", i + 1, score[i]);
            }
        }
        break;
    case 2:
        printf("<평균 미만 학생>\n");
        for (int i = 0; i < size; i++) {
            if (score[i] < average) {
                printf("%d번 점수: %d\n", i + 1, score[i]);
            }
        }
        break;
    default:
        printf("없는 번호입니다.");
        break;
    }
}