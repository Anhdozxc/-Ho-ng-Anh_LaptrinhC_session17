#include <stdio.h>
#include <string.h>

void nhapMang(int *a, int *n);
void inSoChan(int *a, int n);
int laSoNguyenTo(int x);
void inSoNguyenTo(int *a, int n);
void daoNguocMang(int *a, int n);
void sapXepMang(int *a, int n);
void timKiemPhanTu(int *a, int n);

int main() {
    int a[100];
    int n = 0; 
    int luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("6. Nhap vao mot phan tu va tim kiem trong mang\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapMang(a, &n);
                break;
            case 2:
                inSoChan(a, n);
                break;
            case 3:
                inSoNguyenTo(a, n);
                break;
            case 4:
                daoNguocMang(a, n);
                printf("Mang sau khi dao nguoc: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", *(a + i));
                }
                printf("\n");
                break;
            case 5:
                sapXepMang(a, n);
                break;
            case 6:
                timKiemPhanTu(a, n);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    } while (luaChon != 7);

    return 0;
}
void nhapMang(int *a, int *n) {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", n);
    printf("Nhap tung phan tu cua mang:\n");
    for (int i = 0; i < *n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", (a + i));
    }
}
void inSoChan(int *a, int n) {
    printf("Cac phan tu la so chan: ");
    for (int i = 0; i < n; i++) {
        if (*(a + i) % 2 == 0) {
            printf("%d ", *(a + i));
        }
    }
    printf("\n");
}
int laSoNguyenTo(int x) {
    if (x < 2) return 0; 
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1; 
}
void inSoNguyenTo(int *a, int n) {
    printf("Cac phan tu la so nguyen to: ");
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(*(a + i))) {
            printf("%d ", *(a + i));
        }
    }
    printf("\n");
}
void daoNguocMang(int *a, int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = *(a + i);
        *(a + i) = *(a + n - i - 1);
        *(a + n - i - 1) = temp;
    }
}
void sapXepMang(int *a, int n) {
    int luaChon;
    printf("\n--- MENU SAP XEP ---\n");
    printf("1. Tang dan\n");
    printf("2. Giam dan\n");
    printf("Lua chon cua ban: ");
    scanf("%d", &luaChon);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((luaChon == 1 && *(a + i) > *(a + j)) || (luaChon == 2 && *(a + i) < *(a + j))) {
                int temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            }
        }
    }

    printf("Mang sau khi sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(a + i));
    }
    printf("\n");
}
void timKiemPhanTu(int *a, int n) {
    int x;
    int found = 0; 

    printf("Nhap phan tu can tim: ");
    scanf("%d", &x);

    printf("Cac vi tri cua phan tu %d: ", x);
    for (int i = 0; i < n; i++) {
        if (*(a + i) == x) {
            printf("%d ", i); 
            found = 1; 
        }
    }
    if (found == 0) { // Ki?m tra bi?n d?m
        printf("Khong tim thay phan tu %d trong mang.", x);
    }
    printf("\n");
}



