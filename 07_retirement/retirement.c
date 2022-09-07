#include <stdio.h>
#include <stdlib.h>

typedef struct retirement_info_t {
  int age;
  double contribution;
  double rate_of_return;
} retire_info;

void retirement (int startAge, double initial, retire_info working, retire_info retired);


