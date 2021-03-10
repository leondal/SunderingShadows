//picnic_basket.c by ~Circe~ 12/13/07 for new Seneca
#include <std.h>

inherit BAG;

void create(){
   ::create();
   set_name("picnic basket");
   set_id(({"basket","picnic basket"}));
   set_short("%^RESET%^%^ORANGE%^a wicker picnic basket%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This wicker basket features a top "+
      "that can be opened or closed with a %^YELLOW%^wooden toggle"+
      "%^RESET%^%^ORANGE%^.  The inside of the basket is lined with "+
      "%^BOLD%^%^RED%^red %^RESET%^%^ORANGE%^and %^BOLD%^%^WHITE%^"+
      "white %^RESET%^%^ORANGE%^cloth in a %^BOLD%^%^RED%^c%^WHITE%^h"+
      "%^RED%^e%^WHITE%^c%^RED%^k%^WHITE%^e%^RED%^r%^WHITE%^e%^RED%^d "+
      "%^RESET%^%^ORANGE%^pattern.  Thin leather straps are arranged "+
      "throughout the basket, each holding a different item in "+
      "place.  Topping it all is a thin, soft %^BOLD%^%^RED%^p%^WHITE%^i"+
      "%^RED%^c%^WHITE%^n%^RED%^i%^WHITE%^c %^RED%^b%^WHITE%^l%^RED%^a"+
      "%^WHITE%^n%^RED%^k%^WHITE%^e%^RED%^t%^RESET%^%^ORANGE%^ that "+
      "has been carefully folded to take up as little room as possible.%^RESET%^");
   set_value(500);
   set_weight(5);
   set_max_internal_encumbrance(20);
}
