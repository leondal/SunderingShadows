#include <std.h>
inherit "/d/shadow/room/beastvillage/rings/base_inherit";

void create(){
   ::create();
   add_id("ring of water breathing");
   add_id("Ring of Water Breathing");
   set_short("%^RESET%^%^ORANGE%^Ring of Wat%^GREEN%^e%^ORANGE%^r Br%^YELLOW%^e%^RESET%^%^ORANGE%^ath%^GREEN%^i%^ORANGE%^ng%^RESET%^");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_mylong("fish");
   set_mylore("fish, which needs no air to breathe beneath the water");
}

int wear_fun() {
   if(owned && (string)ETO->query_name() != owner && !avatarp(ETO)) {
     tell_object(ETO,"The ring doesn't seem to fit you.");
     return 0;
   }
   ETO->set_property("water breather",1);
   return 1;
}

int remove_fun() {
   ETO->set_property("water breather",-1);
   return 1;
}