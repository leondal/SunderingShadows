

inherit "/std/food.c";

#include <std.h>

void create(){
   ::create();
  set_name("bread");
   set_id(({"bread","loaf of bread","food"}));
  set_strength(10);
  set_weight(1);
   set_short("A loaf of bread");
  set_destroy();
   set_long("This is a fresh baked loaf of bread that is still a bit warm.");
   set_my_mess("The bread is warm, soft, and filling.");
   set_your_mess("eats a loaf of bread.");
  }
