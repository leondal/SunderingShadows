// ice.c

#include <std.h>
#include "../vesprus.h"

inherit "/std/food.c";


void create(){
   ::create();
   set_id(({"ice","crushed ice"}));
   set_name("handful of crushed ice");
   set_short("%^BOLD%^%^WHITE%^handful of crushed i%^CYAN%^c%^WHITE%^e%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This is a handful of crushed i%^CYAN%^c%^WHITE%^e.  It doesn't appear to have melted yet and is quite cool to the touch.%^RESET%^");
   set_destroy();
   set_strength(0);
   set_my_mess("%^BOLD%^%^WHITE%^You eat the ice and realize it is quite cold. ..More than that, it does nothing to sate your hunger%^RESET%^.");
   set_your_mess("eats the ice and shivers.");
   set_weight(1);
}
