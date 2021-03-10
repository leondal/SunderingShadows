inherit "/std/food.c";

#include <std.h>
#include "../yntala.h"

void create(){
   ::create();
  set_name("smoked fish");
  set_id(({"fish","smoked fish","food"}));
  set_strength(10);
  set_weight(1);
  set_short("%^RESET%^A %^BOLD%^%^BLACK%^smoked %^RESET%^fish");
  set_destroy();
  set_long("%^RESET%^This is a freshly cooked %^BOLD%^%^CYAN%^r%^CYAN%^i%^RESET%^v%^CYAN%^e%^BOLD%^%^CYAN%^r %^RESET%^trout.  It is still %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^am%^BOLD%^%^WHITE%^i%^RESET%^n%^BOLD%^%^BLACK%^g %^RESET%^and looks like it would taste pretty good.%^RESET%^");
   set_my_mess("%^RESET%^The fish is cooked to perfection and the flaky meat melts in your mouth as you eat it.");
   set_your_mess("seems to really enjoy the freshly cooked fish.");
  }