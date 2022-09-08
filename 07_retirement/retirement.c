#include <stdio.h>
#include <stdlib.h>

typedef struct retirement_info_t {
    int age; // In months
    double contribution; // Dollars sent/taken from account each month
    double rate_of_return; // Return rate percent of the account, saved as a fraction of 100
} retire_info;

double calculate_balance(int age, double account_balance, retire_info period_info);

void retirement(int startAge, double initial, retire_info working, retire_info retired);

int main() {
    // retire_info struct holding work period info
    retire_info work_period;
    work_period.age = 489;
    work_period.contribution = 1000;
    work_period.rate_of_return = (4.5 / 100.0) / 12.0; // Monthly return rate calculated from yearly one
    
    // retire_info struct holding retirement period info
    retire_info retire_period;
    retire_period.age = 384;
    retire_period.contribution = -4000;
    retire_period.rate_of_return = (1.0 / 100.0) / 12.0; // Monthly return rate calculated from yearly one

    // Starting parameters
    int age = 327; // In months
    double savings = 21345.0;

    retirement(age, savings, work_period, retire_period);

    return EXIT_SUCCESS;
}

// Calculates and prints the account balance over time, according to the given period info
double calculate_balance(int age, double account_balance, retire_info period_info) {
    
    // FOR each month in age:
    for (int i=0; i < period_info.age; i++) {
        // print age (in years) and account_balance
        printf("Age %3d month %2d you have $%.2lf\n", (age + i) / 12, (age + i) % 12, account_balance);

        // update account balance to (account_balance * (1 + rate_of_return)) + contribution
        account_balance = (account_balance * (1 + period_info.rate_of_return)) + period_info.contribution;
    }
    return account_balance;
}

void retirement(int startAge, double initial, retire_info working, retire_info retired) {
    
    // Calculate and print account_balance over working period
    double account_balance = calculate_balance(startAge, initial, working);
    
    // Calculate and print account_balance over retirement period
    calculate_balance(startAge + working.age, account_balance, retired);
}
