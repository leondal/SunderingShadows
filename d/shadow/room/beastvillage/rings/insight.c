#include <std.h>
inherit "/d/shadow/room/beastvillage/rings/base_inherit";

void create(){
   ::create();
   add_id("ring of insight");
   add_id("Ring of Insight");
   set_short("%^RESET%^%^ORANGE%^Ring of I%^GREEN%^n%^ORANGE%^si%^YELLOW%^g%^RESET%^%^ORANGE%^ht%^RESET%^");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_mylong("crow");
   set_mylore("crow, whose sharp intellect places it above most animals in the realm");
   set_item_bonus("academics",3);
   set_item_bonus("spellcraft",3);
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