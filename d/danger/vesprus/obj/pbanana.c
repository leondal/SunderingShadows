inherit "/std/food.c";

#include <std.h>
#include "../vesprus.h"
int peeled;

void create(){
   ::create();
  set_name("%^YELLOW%^Banana%^RESET%^");
  set_id(({"banana","fruit","food"}));
  set_strength(10);
  set_weight(1);
  set_short("%^BOLD%^%^WHITE%^A peeled banana%^RESET%^");
  set_destroy();
  set_long("%^BOLD%^This elongated piece of fruit is already peeled, exposing the soft, white fruit beneath.  There are no visible bruises on it, and it looks to be quite delicious.%^RESET%^");
  set_your_mess("%^BOLD%^devours the fresh fruit in a few big bites.%^RESET%^");
  set_my_mess("%^BOLD%^The semi-sweet fruit seems to melt in your mouth as you eat it.%^RESET%^");
  }
void init(){
  ::init();
  add_action("peel","peel");
}
int peel(string str){ 
   tell_object(TP,"%^BOLD%^This fruit has already been peeled!%^RESET%^");
   return 1;
}
