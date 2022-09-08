#include <stdio.h>
#include <stdlib.h>

typedef struct retirement_info_t {
    int age; // In months
    double contribution; // Dollars sent/taken from account each month
    double rate_of_return; // Return rate percent of the account, saved as a fraction of 100
} retire_info;

void retirement (int startAge, double initial, retire_info working, retire_info retired);

int main() {
    // retire_info struct holding work period info
    retire_info work_period;
    work_period.age = 489;
    work_period.contribution = 1000;
    work_period.rate_of_return = (4.5 / 100.0) / 12; // Monthly return rate calculated from yearly one
    
    // retire_info struct holding retirement period info
    retire_info retire_period;
    retire_period.age = 384;
    retire_period.contribution = -4000;
    retire_period.rate_of_return = (1 / 100.0) / 12; // Monthly return rate calculated from yearly one

    // Starting parameters
    int age = 327; // In months
    double savings = 21345;

    retirment(327, savings, work_period, retire_period);
