inherit "/std/food.c";

#include <std.h>
#include "../vesprus.h"
int tmr;

void create(){
   ::create();
   set_name("%^RESET%^fish");
  set_id(({"fish","raw fish","food"}));
  set_strength(10);
  set_weight(1);
  set_raw(3);
   set_short("%^RESET%^%^BLUE%^A decent sized fish%^RESET%^");
  set_destroy();
  set_long("%^BOLD%^This is an uncooked fish that looks as though it has been kept on ice to preserve its freshness."
"  %^BLACK%^Black beady eyes %^WHITE%^are still within its head, and its mouth is still held slightly open."
"  The scales on the fish are clean and shiny with no marks of deterioration.  It gives off little to no smell,"
" which is a good indication that it is still fairly fresh.%^RESET%^");
  set_your_mess("%^RESET%^%^CYAN%^picks up the raw fish and takes a bite right out of the side of it before gagging.%^RESET%^");
  set_my_mess("%^RESET%^%^CYAN%^You pick up the raw fish and take a bite right out of the side, scales and all.  The first thing you notice is that it is cold and incredibly salty.  Then you realize that the consistency is much like a rotten, gooey, slimey banana and you can't help but gag.%^RESET%^");
  tmr = random(40)+10;
  set_heart_beat(1);
}
void heart_beat(){
   if(tmr > 0){
      if(!present("ice",environment(TO))){
         tmr -=1;
         return ;
      }
      return 1;
   }
   if(!tmr){
      tell_object(ETO,"%^RESET%^%^ORANGE%^Something on your person begins to give off an aweful odor.%^RESET%^");
      tell_room(EETO,"%^RESET%^%^ORANGE%^Something begins to smell really badly, and it seems to be coming from "+ETO->query_cap_name()+".",ETO);
      new(VESPRUSOBJS+"rfish.c")->move(ETO);
      TO->remove();
      return 1;
   }
}

