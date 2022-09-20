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

void print_card(card_t c) {

}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  return temp;
}
