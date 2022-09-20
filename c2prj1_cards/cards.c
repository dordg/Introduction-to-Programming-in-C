#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"

/* validates card_t:
 * Asserts if card_t.value is between 2 and ACE
 * Asserts if card_t.suit is between ACE and SPADES (suit is an Enum)
 */
void assert_card_valid(card_t c) {
    assert(c.value >= 2 && c.value <= VALUE_ACE);
    assert(c.suit >= SPADES && c.suit <= CLUBS);
}

// Returns the string corresponding to r's value
const char * ranking_to_string(hand_ranking_t r) {
    switch (r) {
        case STRAIGHT_FLUSH:
            return "Straight flush";
        case FOUR_OF_A_KIND:
            return "Four of a kind";
        case FULL_HOUSE:
            return "Full house";
        case FLUSH:
            return "Flush";
        case STRAIGHT:
            return "Straight";
        case THREE_OF_A_KIND:
            return "Three of a kind";
        case TWO_PAIR:
            return "Two pair";
        case PAIR:
            return "Pair";
        case NOTHING:
            return "Nothing";
    }
}

// Returns the letter corresponding to c.value
char value_letter(card_t c) {
    switch (c.value) {
        case VALUE_ACE:
            return 'A';
        case VALUE_KING:
            return 'K';
        case VALUE_QUEEN:
            return 'Q';
        case VALUE_JACK:
            return 'J';
        default:
            // Includes the case where value is 10 but return '0'
            // 48 is '0' ascii value
            return 48 + (c.value % 10);
    }
}

// Returns the letter corresponding to c.suit
char suit_letter(card_t c) {
    switch (c.suit) {
        case SPADES:
            return 's';
        case HEARTS:
            return 'h';
        case DIAMONDS:
            return 'd';
        case CLUBS:
            return 'c';
    }
}

// Prints c
void print_card(card_t c) {
    printf("%c%c", value_letter(c.value), suit_letter(c.suit));
}

// Creates a card_t from the given letters and returns it
card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  temp.value = let_to_value(value_let);
  temp.suit = let_to_suit(suit_let);
  return temp;
}

// Returns value_let's numeric value
char let_to_value(char value_let) {
    switch (value_let) {
        case 'A':
            return VALUE_ACE;
        case 'K':
            return VALUE_KING;
        case 'Q':
            return VALUE_QUEEN;
        case 'J':
            return VALUE_JACK;
        case '0':
            return 10;
        default:
            // 48 is '0' ascii value
            return value_let - 48;
    }
}

// Returns suit_let's numric value
char let_to_suit(char suit_let) {
    switch (suit_let) {
        case 's':
            return SPADES;
        case 'h':
            return HEARTS;
        case 'd':
            return DIAMONDS;
        case 'c':
            return CLUBS;
    }
}

// Returns card_t corresponding to c
card_t card_from_num(unsigned c) {
  card_t temp;
  temp.value = num_to_value(c);
  temp.suit = num_to_suit(c);
  return temp;
}

// Returns c's corresponding value
char num_to_value(unsigned c) {
    return (c % 13) + 2;
}

// Returns c's corresponding suit
char num_to_suit(unsigned c) {
    return num / 13;
}
