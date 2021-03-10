#include <std.h>
inherit "/d/shadow/room/beastvillage/rings/base_inherit";

int mytracker;

void create(){
   ::create();
   add_id("ring of regeneration");
   add_id("Ring of Regeneration");
   set_short("%^RESET%^%^ORANGE%^Ring of Reg%^GREEN%^e%^ORANGE%^ner%^YELLOW%^a%^RESET%^%^ORANGE%^tion%^RESET%^");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_mylong("salamander");
   set_mylore("salamander, a creature that can recover from terrible wounds (though you realise it won't regenerate limbs for you!)");
}

int wear_fun() {
   if(owned && (string)ETO->query_name() != owner && !avatarp(ETO)) {
     tell_object(ETO,"The ring doesn't seem to fit you.");
     return 0;
   }
   if(ETO->query_level() < 25) { // tier 3 ring
     tell_object(ETO,"The ring doesn't seem to fit you.");
     return 0;
   }
   if(member_array("regeneration",(string*)ETO->query_temporary_feats()) == -1) {
     ETO->add_temporary_feat("regeneration");
     mytracker = 1;
   }
   return 1;
}

int remove_fun() {
   if(mytracker) {
     ETO->remove_temporary_feat("regeneration");
     mytracker = 0;
   }
   return 1;
}
