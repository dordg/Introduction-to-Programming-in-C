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
        default:
            return "No such combination";
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
        case 10:
            return '0';
        default:
            return '0' + c.value;
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
        default:
            return '?';
    }
}

// Prints c
void print_card(card_t c) {
    printf("%c%c", value_letter(c), suit_letter(c));
}

// Creates a card_t from the given letters and returns it
card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  temp.value = let_to_value(value_let);
  temp.suit = let_to_suit(suit_let);
  assert_card_valid(temp);
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
            return value_let - '0';
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
        default:
            // Should only return in case of sn invalid letter
            return NUM_SUITS;
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
    return c / 13;
}
