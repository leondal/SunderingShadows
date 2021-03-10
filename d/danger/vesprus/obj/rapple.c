inherit "/std/food.c";

#include <std.h>
#include "../vesprus.h"


void create(){
   ::create();
  set_name("%^BOLD%^%^RED%^A ripe red apple%^RESET%^");
  set_id(({"apple","fruit","food"}));
  set_strength(3);
  set_weight(1);
  set_short("%^BOLD%^%^RED%^A ripe red apple%^RESET%^");
  set_destroy();
  set_long("%^BOLD%^%^RED%^This a perfectly shaped red apple.  It looks to be ripened to perfection and is without bruises or blemishes. In fact, it is so perfect in appearance that you can almost see your reflection in the sheen the skin gives off.  It is firm to the touch and seems like it would be very good to eat.%^RESET%^");
  set_your_mess("%^BOLD%^%^RED%^bites into the apple with a soft crunch.%^RESET%^");
  set_my_mess("%^BOLD%^%^RED%^You bite into the firm apple and realize just exactly how good this piece of fruit is.%^RESET%^");
  }
