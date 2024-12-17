#include <stdio.h>
#include <string.h>

void inputString(char *str); 
void printString(char *str); 
int countLetters(char *str); 
int countDigits(char *str);  
int countSpecialChars(char *str); 

int main() {
    char str[100]; 
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap chuoi\n");
        printf("2. In chuoi\n");
        printf("3. Dem chu cai trong chuoi\n");
        printf("4. Dem chu so trong chuoi\n");
        printf("5. Dem ky tu dac biet trong chuoi\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                inputString(str);
                break;
            case 2:
                printString(str);
                break;
            case 3:
                printf("So luong chu cai trong chuoi: %d\n", countLetters(str));
                break;
            case 4:
                printf("So luong chu so trong chuoi: %d\n", countDigits(str));
                break;
            case 5:
                printf("So luong ky tu dac biet trong chuoi: %d\n", countSpecialChars(str));
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    } while (choice != 6);

    return 0;
}

void inputString(char *str) {
    printf("Moi ban nhap chuoi: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0'; 
}
void printString(char *str) {
    printf("Chuoi vua nhap la: %s\n", str);
}
int countLetters(char *str) {
    int count = 0;
    for (char *p = str; *p != '\0'; p++) {
        if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) {
            count++;
        }
    }
    return count;
}
int countDigits(char *str) {
    int count = 0;
    for (char *p = str; *p != '\0'; p++) {
        if (*p >= '0' && *p <= '9') {
            count++;
        }
    }
    return count;
}
int countSpecialChars(char *str) {
    int count = 0;
    for (char *p = str; *p != '\0'; p++) {
        if (!((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z') || (*p >= '0' && *p <= '9'))) {
            count++;
        }
    }
    return count;
}


