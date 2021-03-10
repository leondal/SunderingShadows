//Updated by Lujke April 2007
#include <std.h>
#define FACES ({"CLUBS","SWORDS","GEMS","TOWERS"})
#define COUNTS ({"R","2","3","4","5","6","7","8","9","10","H","D","L"})
#define CARD "/d/shadow/obj/misc/card"

inherit OBJECT;

string * cards;

string id;


string query_deck_id();      // added by Lujke, to make these queries 
int query_num_cards();  // accessible to other objects.


void shuffle();

void create(){
    ::create();
    set_name("Deck of Cards");
      set_short("%^CYAN%^Deck of cards%^RESET%^");
    set_id(({"deck","deck of cards", "cards"}));
    set_long(
@OLI
    This is a deck of cards with the realm's typical 52 cards. The faces are the
typical clubs, swords, gems, and towers, all numbered from rogue to Lord. You
see that the art work is meticulously done.
   <shuffle> to shuffle the deck
   <add card> to add a card to the bottom of the deck 
   <deal> to player
   <return> to return a card from the table to the bottom of the deck
OLI
    );

    set_value(5);
    set_weight(2);
    id = ""+time();
    cards = ({"RC","2C","3C","4C","5C","6C","7C","8C","9C","10C","HC","DC","LC","RS","2S","3S","4S","5S","6S","7S","8S","9S","10S","HS","DS","LS","RG","2G","3G","4G","5G","6G","7G","8G","9G","10G","HG","DG","LG","RT","2T","3T","4T","5T","6T","7T","8T","9T","10T","HT","DT","LT"});

}

string query_deck_id(){
  return id;
}

int query_num_cards(){
  return sizeof(cards);
}
string query_long(string str){
    string slong = ::query_long(str);
    slong = slong +"\nThis deck currently has "+sizeof(cards)+" cards.";
    return slong;
}

int shuffle(){
    string card;
    string * cards2 = ({});
    int i;
    do {
        card = cards[random(sizeof(cards))];
        cards -= ({card});
        cards2 += ({card});
    } while (sizeof(cards));
    cards = cards2;
    tell_object(TP,"You shuffle the cards thoroughly.");
    tell_room(ETP,TPQCN+" shuffles the cards thoroughly.",TP);
    return 1;
}

int addCard(string str){
    object ob;
       
    if (!ob = present(str, TP)) {
         return notify_fail("That is not here.\n");
    }

    if(!ob->id(id)) {
        return notify_fail("You can only add cards from this deck to this deck.\n");
    }
    cards += ({ob->query_card()});
    ob->remove();
    tell_object(TP,"You add the card back to the deck on the bottom.\n");
    tell_room(ETO,TPQCN+" adds a card to the bottom of the deck.",TP);
    return 1;
}

//returnem added by Circe to fix confusion with the dealer's hand
int returnem(string str){
    object ob;
       
     if(!str){ return notify_fail("Return what?\n");
    }
    if (!ob = present(str, ETP)) {
         return notify_fail("That is not here.\n");
    }

    if(!ob->id(id)) {
        return notify_fail("You can only add cards from this deck to this deck.\n");
    }
    cards += ({ob->query_card()});
    ob->remove();
    tell_object(TP,"You add the card back to the deck on the bottom.\n");
    tell_room(ETO,TPQCN+" adds a card to the bottom of the deck.",TP);
    return 1;
}

int deal(string str){
    object card, target;
    string who, face;
    int bottom = 0;

    if(sizeof(cards) != 0) {
        if(!str) {
            target = TP;
        } else {
            if (sscanf(str, "to %s from bottom",who) != 1){
                if(sscanf(str, "to %s",who) != 1) {
                    return notify_fail("deal to <name> || deal to <name> from bottom.\n");
                }
            } else {
                bottom = sizeof(cards)-1;
            }
            target = present(who,ETP);
            if(!objectp(target) || (target->query_invis() && target != TP)) {
                return notify_fail("That person is not here.\n");
            }
        }

        card = new (CARD);
        face = cards[bottom];
        card->set_deck_id(id);
        cards -= ({face});
        card->set_face(face);
        if(target == TP) {
            tell_room(ETP,TPQCN+" deals a card to "+target->query_objective()+"self.",TP);
            tell_object(TP,"You deal a card to yourself"+((!bottom)?".":", from the bottom on the deck."));
        }
        else {
            tell_room(ETP,TPQCN+" deals a card to "+target->query_cap_name()+".",TP);
            tell_object(TP,"You deal a card to "+target->query_cap_name()+((!bottom)?".":", from the bottom on the deck."));
        }
        if(card->move(target)) {
            tell_room(ETP,target->query_cap_name()+" can't carry, the card to it falls to the ground.");
            card->move(ETP);
        }
    } else {
        return notify_fail("This deck has no cards.\n");
    }
    return 1;
}



init(){
    ::init();
    add_action("addCard","add");
    add_action("deal","deal");
    add_action("shuffle","shuffle");
    add_action("returnem","return");
}


