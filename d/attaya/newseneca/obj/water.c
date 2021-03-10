//water.c - Water for the mage tower of new Seneca
//~Circe~ 1/4/07
inherit "/std/drink.c";

#include <std.h>

void create(){
   ::create();
   set_name("water");
   set_id(({"water","refreshing water","glass of water","glass of refreshing water","drink"}));
   set_strength(30);
   set_weight(1);
   set_type("water");
   set_empty_name("glass");
   set_short("%^RESET%^%^CYAN%^A glass of refreshing %^BOLD%^water%^RESET%^");
   set_destroy();
   set_long("%^RESET%^%^CYAN%^This thick glass is filled with cool, "+
      "refreshing %^BOLD%^water%^RESET%^%^CYAN%^.  Tiny little air "+
      "bubbles dance their way to the top, enticing you to drink.%^RESET%^");
   set_my_mess("The cool water is refreshing and thirst-quenching.");
   set_your_mess("drinks water from a thick glass.");
}
