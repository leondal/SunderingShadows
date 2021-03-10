

inherit "/std/food.c";

#include <std.h>

void create(){
   ::create();
  set_name("fish");
   set_id(({"fish","dried fish","salty fish","fish strips","food"}));
  set_strength(15);
  set_weight(1);
   set_short("Some dried fish");
  set_destroy();
   set_long("These are some seasoned and dried fish strips, they're rather salty but look filling.");
   set_my_mess("The fish is chewy and salty but quite filling.");
   set_your_mess("eats some dried fish strips.");
  }
