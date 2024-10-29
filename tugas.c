//Praktikum Modul blabala
//Annisa blablabla
#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk penjumlahan
double tambah(double a, double b) {
    return a + b;
}

// Fungsi untuk pengurangan
double kurang(double a, double b) {
    return a - b;
}

// Fungsi untuk perkalian
double kali(double a, double b) {
    return a * b;
}

// Fungsi untuk pembagian
double bagi(double a, double b) {
    if (b == 0) {
        printf("Error: Pembagian dengan 0 tidak diperbolehkan.\n");
        return 0;
    }
    return a / b;
}

// Fungsi untuk faktorial
unsigned long long faktorial(int n) {
    if (n < 0) {
        printf("Error: Faktorial tidak dapat dihitung untuk bilangan negatif.\n");
        return 0;
    }
    unsigned long long hasil = 1;
    for (int i = 1; i <= n; i++) {
        hasil *= i;
    }
    return hasil;
}

// Fungsi untuk menghitung FPB (Faktor Persekutuan Terbesar)
int fpb(int a, int b) {
    if (b == 0) {
        return a;
    }
    return fpb(b, a % b);
}

// Fungsi untuk menghitung KPK (Kelipatan Persekutuan Terkecil)
int kpk(int a, int b) {
    return (a * b) / fpb(a, b);
}

// Fungsi untuk menjalankan kalkulator
void jalankanKalkulator() {
    char operator;
    double operand1, operand2;
    char pilihan[10];

    while (1) {
        printf("======================\n");
        printf("      KALKULATOR\n");
        printf("======================\n");
        printf("\nMasukkan operasi seperti contoh dibawah ini");
        printf("\nPertambahan: 5 + 3\nPerkalian: 6 * 2\nPembagian 10 / 5\nFaktorial: 5! \nFPB: fpb 10 20\nKPK: 10 20\nKeluar: exit\n");
        printf("Masukkan operasi:");
        fgets(pilihan, sizeof(pilihan), stdin);

        // Jika pengguna memilih 'exit', keluar dari program
        if (sscanf(pilihan, "exit") == 1) {
            printf("Kalkulator dihentikan.\n");
            break;
        }

        // Memeriksa operasi faktorial
        if (sscanf(pilihan, "%lf !", &operand1) == 1) {
            int num = (int) operand1;
            printf("Faktorial dari %d adalah %llu\n", num, faktorial(num));
        }
        // Memeriksa operasi FPB
        else if (sscanf(pilihan, "fpb %lf %lf", &operand1, &operand2) == 2) {
            printf("FPB dari %.0lf dan %.0lf adalah %d\n", operand1, operand2, fpb((int)operand1, (int)operand2));
        }

        // Memeriksa operasi KPK
        else if (sscanf(pilihan, "kpk %lf %lf", &operand1, &operand2) == 2) {
            printf("KPK dari %.0lf dan %.0lf adalah %d\n", operand1, operand2, kpk((int)operand1, (int)operand2));
        }
        // Memeriksa operasi kabataku
        else if (sscanf(pilihan, "%lf %c %lf", &operand1, &operator, &operand2) == 3) {
            switch (operator) {
                case '+':
                    printf("%.2lf + %.2lf = %.2lf\n", operand1, operand2, tambah(operand1, operand2));
                    break;
                case '-':
                    printf("%.2lf - %.2lf = %.2lf\n", operand1, operand2, kurang(operand1, operand2));
                    break;
                case '*':
                    printf("%.2lf * %.2lf = %.2lf\n", operand1, operand2, kali(operand1, operand2));
                    break;
                case '/':
                    printf("%.2lf / %.2lf = %.2lf\n", operand1, operand2, bagi(operand1, operand2));
                    break;
                default:
                    printf("Operator tidak valid!\n");
                    break;
            }
        } else {
            printf("Input tidak valid. Mohon masukkan format yang benar.\n");
        }
    }
}

int main() {
    printf("Kalkulator Sederhana\n");
    jalankanKalkulator();
    return 0;
}
