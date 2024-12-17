#include <stdio.h>

void nhapMang(int *arr, int n);
void hienThiMang(int *arr, int n);
int tinhTong(int *arr, int n);
int timMax(int *arr, int n);

int main() {
    int n, luaChon;
    int arr[100]; 

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                printf("Nhap so phan tu cua mang: ");
                scanf("%d", &n);
                nhapMang(arr, n);
                break;
            case 2:
                hienThiMang(arr, n);
                break;
            case 3:
                printf("Do dai cua mang la: %d\n", n);
                break;
            case 4:
                printf("Tong cac phan tu trong mang: %d\n", tinhTong(arr, n));
                break;
            case 5:
                printf("Phan tu lon nhat trong mang: %d\n", timMax(arr, n));
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    } while (luaChon != 6);

    return 0;
}
void nhapMang(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", (arr + i)); 
    }
}

void hienThiMang(int *arr, int n) {
    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i)); 
    }
    printf("\n");
}

int tinhTong(int *arr, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += *(arr + i);
    }
    return tong;
}

int timMax(int *arr, int n) {
    int max = *arr; 
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}

