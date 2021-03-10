inherit "/std/food.c";

#include <std.h>
#include "../yntala.h"


void create(){
   ::create();
  set_name("%^RESET%^%^MAGENTA%^a small grape%^RESET%^");
  set_id(({"grape","fruit","food"}));
  set_strength(1);
  set_weight(0);
  set_short("%^RESET%^%^MAGENTA%^a small grape%^RESET%^");
  set_destroy();
  set_long("%^RESET%^%^MAGENTA%^This small grape is perfectly round and no bigger than perhaps a blueberry.  It is firm to the touch and without any bruising.%^RESET%^");
  set_your_mess("%^RESET%^%^MAGENTA%^seems to really enjoy the grape.%^RESET%^");
  set_my_mess("%^RESET%^%^MAGENTA%^Mmm, this grape is soft, sweet and full of flavor.%^RESET%^");
  }
