#include <stdio.h>
#include "cards.h"

void test_card_from_num(void);

void test_assert_card(void);

void test_value_letter(void);

int main(void) {
    // test_card_from_num();
    // test_assert_card();
    test_value_letter();
}

void test_card_from_num(void) {
    for (int i = 0; i < 52; i++) {
        printf("i: %d card: ", i);
        print_card(card_from_num(i));
        printf("\n");
    }
    printf("\n");
}

void test_assert_card(void) {
    //card_t c0;
    //c0.value = VALUE_ACE;
    //c0.suit = SPADES;

    //card_t c1;
    //c1.value = 1;
    //c1.suit = SPADES;

    card_t c2;
    c2.value = 2;
    c2.suit = 'S';

    //assert_card_valid(c0);
    //assert_card_valid(c1);
    assert_card_valid(c2);
}

void test_value_letter() {
    card_t c;
    for (int i = 2; i <= VALUE_ACE; i++) {
        c.value = i;
        printf("i: %d, value: %c\n", i, value_letter(c));
    }
    printf("\n");
}
