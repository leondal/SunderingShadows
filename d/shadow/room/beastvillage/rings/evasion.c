#include <std.h>
inherit "/d/shadow/room/beastvillage/rings/base_inherit";

int mytracker;

void create(){
   ::create();
   add_id("ring of evasion");
   add_id("Ring of Evasion");
   set_short("%^RESET%^%^ORANGE%^Ring of E%^GREEN%^v%^ORANGE%^as%^YELLOW%^i%^RESET%^%^ORANGE%^on%^RESET%^");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_mylong("hare");
   set_mylore("hare, a creature whose speed helps it avoid the many predators that hunt it");
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
   if(member_array("evasion",(string*)ETO->query_temporary_feats()) == -1) {
     ETO->add_temporary_feat("evasion");
     mytracker = 1;
   }
   return 1;
}

int remove_fun() {
   if(mytracker) {
     ETO->remove_temporary_feat("evasion");
     mytracker = 0;
   }
   return 1;
}