

inherit "/std/food.c";

#include <std.h>

void create(){
   ::create();
  set_name("jerky");
   set_id(({"jerky","beef jerky","food"}));
  set_strength(10);
  set_weight(1);
   set_short("Some beef jerky");
  set_destroy();
   set_long("These are some strips of beef jerky, they're a bit hard but they smell delicious.");
   set_your_mess("You devour the beef jerky.");
   set_your_mess("eats some beef jerky.");
  }
