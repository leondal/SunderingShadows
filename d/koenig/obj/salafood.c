//salafood.c - food from the salamanders in Koenig.  Circe 11/22/03
inherit "/std/food.c";

#include <std.h>
#include "../koenig.h"

void create(){
  ::create();
  set_name("crunchy salamander");
  set_id(({"salamander","crunchy salamander","lizard","food"}));
  set_strength(5);
  set_weight(1);
  set_short("A crunchy salamander");
  set_destroy();
  set_long("This small salamander obviously met an untimely end.  Still, "+
     "his death could perhaps serve a higher purpose.  Although you would "+
     "have to be quite hungry, you could probably eat it if you wanted.");
   set_my_mess("The bones of the salamander crunch as you swallow it.");
   set_your_mess("eats the corpse of a salamander.");
}
