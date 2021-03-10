inherit "/std/food.c";

#include <std.h>
#include "../vesprus.h"

void create(){
   ::create();
  set_name("berries");
  set_id(({"berries","berry","wildberries","food"}));
  set_strength(1);
  set_weight(1);
  set_short("%^RESET%^%^RED%^A handful of mixed berries%^RESET%^");
  set_destroy();
  set_long("%^RESET%^%^GREEN%^This is a large handful of assorted %^BOLD%^%^RED%^b%^RESET%^%^RED%^er%^MAGENTA%^r%^RESET%^%^RED%^ie%^BOLD%^%^RED%^s.  %^RESET%^%^GREEN%^The colors vary with the type, but all are in excellent condition and seem to be grown to perfection.%^RESET%^");
   set_my_mess("%^RESET%^%^GREEN%^The %^BOLD%^%^RED%^b%^RESET%^%^RED%^er%^MAGENTA%^r%^RED%^ie%^BOLD%^%^RED%^s %^RESET%^%^GREEN%^are %^RED%^tart %^GREEN%^and %^MAGENTA%^juicy%^GREEN%^.");
   set_your_mess("%^RESET%^%^RED%^quickly eats a handful of berries.");
  }