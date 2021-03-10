#include <std.h>
inherit "/d/shadow/room/beastvillage/rings/base_inherit";

void create(){
   ::create();
   add_id("ring of stealth");
   add_id("Ring of stealth");
   set_short("%^RESET%^%^ORANGE%^Ring of S%^GREEN%^t%^ORANGE%^ea%^YELLOW%^l%^RESET%^%^ORANGE%^th%^RESET%^");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_mylong("chameleon");
   set_mylore("chameleon, who is a master at hiding in plain sight");
   set_item_bonus("stealth",6);
}

int wear_fun() {
   if(owned && (string)ETO->query_name() != owner && !avatarp(ETO)) {
     tell_object(ETO,"The ring doesn't seem to fit you.");
     return 0;
   }
   if(ETO->query_level() < 25) { // tier 2 ring
     tell_object(ETO,"The ring doesn't seem to fit you.");
     return 0;
   }
   return 1;
}

int remove_fun() {
   return 1;
}