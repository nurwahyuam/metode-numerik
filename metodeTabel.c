#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>

// X awal = 0
// X akhir = 2
// Step = 0.1

// X awal = 0.5
// X akhir = 1
// Step = 0.005

// X awal = 0.67
// X akhir = 0.7
// Step = 0.00025

float fungsi(float x){
  return x * x - 5 * x + 3;
}

int main(){
  float x, y, f, e, step;
  system("cls");
  printf("\n==================================================================\n");
  printf("|                          Metode Tabel                          |\n");
  printf("==================================================================\n");
  printf("> Masukan Nilai Awal: ");
  scanf("%f", &x);
  printf("\n> Masukan Nilai Akhir: ");
  scanf("%f", &y);
  printf("\n> Masukan Nilai Step: ");
  scanf("%f", &step);
  printf("==================================================================");
  getch();

  system("cls");
  printf("\n==================================================================\n");
  printf("|                          Metode Tabel                          |\n");
  printf("==================================================================\n");
  printf("|              x               |               f(x)              |\n");
  printf("------------------------------------------------------------------\n");
  while(x <= y){
    f = fungsi(x);
    if (f > 0) {
      printf("|           %.4f             |              %.4f             |\n", x, f);
    } else {
      printf("|           %.4f             |             %.4f             |\n", x, f);
    }
    if (fabs(f) < 0.0005)
    {
      e = f;
      break;
    }
    x += step;
  }


  if (e != 0){
    printf("==================================================================\n");
    printf("Nilai Error: %.4f di X: %.4f\n", e, x);
    printf("==================================================================\n");
  } else {
    printf("==================================================================\n");
  }
  return 0;
}