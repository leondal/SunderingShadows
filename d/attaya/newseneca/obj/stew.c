//stew.c - stew for the mage tower of new Seneca
//~Circe~ 1/3/07
inherit "/std/food.c";

#include <std.h>

void create(){
   ::create();
   set_name("stew");
   set_id(({"stew","beef stew","hearty beef stew","bowl of stew","bowl of beef stew","bowl of hearty beef stew","food"}));
   set_strength(25);
   set_weight(1);
   set_short("%^RESET%^%^RED%^A bowl of hearty beef stew%^RESET%^");
   set_destroy();
   set_long("%^RESET%^%^ORANGE%^A sturdy ceramic bowl has been "+
      "filled with tantalizing %^RED%^beef stew%^ORANGE%^.  The "+
      "broth is a rich %^RED%^reddish brown%^ORANGE%^, hinting at "+
      "the %^RED%^tomatoes %^ORANGE%^used to make it.  Bits of "+
      "%^GREEN%^vegetables%^ORANGE%^ float within, lending their "+
      "strength and flavors to the robust dish.%^RESET%^");
   set_my_mess("The beef stew is piping hot and filled with a mixture of delicious flavors.");
   set_your_mess("eats a bowl of hearty beef stew.");
}
