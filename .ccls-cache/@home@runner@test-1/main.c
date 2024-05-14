#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    int n = 0;
    char cut[3][100] = {0};
    struct {
        char fullname[100]; // 전체이름
        char* lastname; // 성을 가리키는 포인터
        char* firstname; // 이름을 가리키는 포인터
        int age;
        char sex;
    } student;

    while (1) {
        printf("Provide your personal information:\n- Name: ");
        scanf(" %[^\n]", student.fullname); // 이름 성 순으로 입력받음
        rewind(stdin);
        if (strcmp(student.fullname, "stop") == 0)
            break;
        printf("- Age: ");
        scanf(" %d", &student.age);
        printf("- Sex(m/f): ");
        scanf(" %c", &student.sex);
        rewind(stdin);

        // 성 이름 순으로 출력하기
        char* ptr = strtok(student.fullname, " ");
        int i = 0;
        while (ptr != NULL) {
            strcpy(cut[i], ptr);
            ptr = strtok(NULL, " ");
            i++;
        }
        student.firstname = cut[0];
        student.lastname = cut[1];

        // 나이
        n = (student.age / 10) * 10;

        printf("Your name is %s %s,", student.lastname, student.firstname);
        printf(" you are in %ds, ", n);
        printf("your sex is %c\n", student.sex);
    }

    return 0;
}