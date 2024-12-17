#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Khai bao nguyen mau ham
void inputString(char *str);
void printReverseString(char *str);
int countWords(char *str);
void compareStrings(char *str1);
void convertToUpper(char *str);
void concatenateStrings(char *str1);

int main() {
    char str[200]; 
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac va so sanh voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); // Loai bo ky tu xuong dong

        switch (choice) {
            case 1:
                inputString(str);
                break;
            case 2:
                printReverseString(str);
                break;
            case 3:
                printf("So luong tu trong chuoi: %d\n", countWords(str));
                break;
            case 4:
                compareStrings(str);
                break;
            case 5:
                convertToUpper(str);
                printf("Chuoi sau khi in hoa: %s\n", str);
                break;
            case 6:
                concatenateStrings(str);
                printf("Chuoi sau khi noi: %s\n", str);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    } while (choice != 7);

    return 0;
}

// Ham nhap chuoi
void inputString(char *str) {
    printf("Nhap chuoi: ");
    fgets(str, 200, stdin);
    str[strcspn(str, "\n")] = '\0'; 
}
// Ham in chuoi dao nguoc
void printReverseString(char *str) {
    int length = strlen(str);
    printf("Chuoi dao nguoc: ");
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}
// Ham dem so tu trong chuoi
int countWords(char *str) {
    int count = 0;
    char *p = str;
    while (*p != '\0') {
        while (*p == ' ' && *p != '\0') p++; 
        if (*p != '\0') count++;
        while (*p != ' ' && *p != '\0') p++; 
    }
    return count;
}

// Ham so sanh chuoi khac voi chuoi ban dau
void compareStrings(char *str1) {
    char str2[200];
    printf("Nhap chuoi khac: ");
    fgets(str2, 200, stdin);
    str2[strcspn(str2, "\n")] = '\0';

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 > len2) {
        printf("Chuoi moi ngan hon chuoi ban dau.\n");
    } else if (len1 < len2) {
        printf("Chuoi moi dai hon chuoi ban dau.\n");
    } else {
        printf("Hai chuoi co do dai bang nhau.\n");
    }
}
// Ham in hoa tat ca chu cai trong chuoi
void convertToUpper(char *str) {
    for (char *p = str; *p != '\0'; p++) {
        *p = toupper(*p);
    }
}
// Ham noi chuoi khac vao chuoi ban dau
void concatenateStrings(char *str1) {
    char str2[200];
    printf("Nhap chuoi khac: ");
    fgets(str2, 200, stdin);
    str2[strcspn(str2, "\n")] = '\0';

    strcat(str1, str2);
}


