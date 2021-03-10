inherit "/std/food.c";

#include <std.h>
#include "../vesprus.h"


void create(){
   ::create();
  set_name("%^BOLD%^%^RED%^A juicy cherry%^RESET%^");
  set_id(({"cherry","fruit","food"}));
  set_strength(1);
  set_weight(0);
  set_short("%^BOLD%^%^RED%^A large red cherry%^RESET%^");
  set_destroy();
  set_long("%^BOLD%^%^RED%^This small piece of fruit is almost heart shaped and a very %^RESET%^%^RED%^deep red %^BOLD%^%^RED%^in color.  A single %^GREEN%^green %^RED%^stem sticks out from the top.%^RESET%^");
  set_your_mess("%^BOLD%^%^RED%^pulls the stem off of the cherry and eats it with a smile.%^RESET%^");
  set_my_mess("%^BOLD%^%^RED%^You pull the stem off of the cherry before placing it in your mouth... Mmm, it's soft, juicy and sweet.%^RESET%^");
  }

