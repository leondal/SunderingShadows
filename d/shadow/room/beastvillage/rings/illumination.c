#include <std.h>
inherit "/d/shadow/room/beastvillage/rings/base_inherit";

void create(){
   ::create();
   add_id("ring of illumination");
   add_id("Ring of Illumination");
   set_short("%^RESET%^%^ORANGE%^Ring of Il%^GREEN%^l%^ORANGE%^umin%^YELLOW%^a%^RESET%^%^ORANGE%^tion%^RESET%^");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_mylong("owl");
   set_mylore("owl, whose wide eyes allow it to see in the darkest of nights");
   set_item_bonus("sight bonus",5);
}

int wear_fun() {
   if(owned && (string)ETO->query_name() != owner && !avatarp(ETO)) {
     tell_object(ETO,"The ring doesn't seem to fit you.");
     return 0;
   }
   if(ETO->query_level() < 15) { // tier 2 ring
     tell_object(ETO,"The ring doesn't seem to fit you.");
     return 0;
   }
   return 1;
}

int remove_fun() {
   return 1;
}