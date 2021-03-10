inherit "/std/food.c";
#include <std.h>
void create(){
   ::create();
  set_name("mushroom");
  set_id(({"mushroom","shroom","food"}));
  set_short("Mushroom");
  set_long("Mottled grey and brown with a large solid cap this fungus looks different from the other mushrooms in the area.");
  set_destroy();
  set_strength(40);
  set_my_mess("You close your eyes and eat the fungus hoping for the best.");
  set_your_mess("eats the unidentified fungus.");
  if(!random(3)) set_poison(10);
  }











